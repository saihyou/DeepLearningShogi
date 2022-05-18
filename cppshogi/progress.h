#pragma once

#include <map>
#include <string>

#include "evaluate.h"
#include "square.hpp"
#include "usi.hpp"

class Position;

class Progress {
 public:
  Progress() {Load();}
  bool Load();
  double Estimate(const Position& pos);

 private:
  double weights_[SquareNum][EvalIndex::fe_end] = {};
};

extern Progress g_progress;
