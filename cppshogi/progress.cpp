#include "progress.h"

#include "position.hpp"

Progress g_progress = Progress();

bool Progress::Load() {
  // std::string file_path = (std::string)Options["Progress_File"];
  std::string file_path = "progress.bin";
  std::ifstream ifs(file_path, std::ios_base::in | std::ios_base::binary);
  if (!ifs) {
    std::cerr << "info string Failed to open the progress file. file_path="
              << file_path << std::endl;
    return false;
  }

  if (!ifs.read(reinterpret_cast<char*>(weights_), sizeof(weights_))) {
    std::cerr << "info string Failed to read the progress file. file_path="
              << file_path << std::endl;
    return false;
  }

  return true;
}

double Progress::Estimate(const Position& pos) {
  Square sq_bk = pos.kingSquare(Black);
  Square sq_wk = inverse(pos.kingSquare(White));
  const auto list0 = pos.cplist0();
  const auto list1 = pos.cplist1();
  double sum = 0.0;
  for (int i = 0; i < pos.nlist(); ++i) {
    sum += weights_[sq_bk][list0[i]];
    sum += weights_[sq_wk][list1[i]];
  }
  return 1.0 / (1.0 + std::exp(-sum));
}