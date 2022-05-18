/*
  Apery, a USI shogi playing engine derived from Stockfish, a UCI chess playing
  engine. Copyright (C) 2004-2008 Tord Romstad (Glaurung author) Copyright (C)
  2008-2015 Marco Costalba, Joona Kiiski, Tord Romstad Copyright (C) 2015-2018
  Marco Costalba, Joona Kiiski, Gary Linscott, Tord Romstad Copyright (C)
  2011-2018 Hiraoka Takuya

  Apery is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Apery is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "piece.hpp"
#include "square.hpp"

class Position;
enum EvalIndex : int32_t;

struct EvalList {
  static const int ListSize = 38;

  EvalIndex list0[ListSize];
  EvalIndex list1[ListSize];
  Square listToSquareHand[ListSize];
  int squareHandToList[SquareHandNum];

  void set(const Position& pos);
};

extern const Square HandPieceToSquareHand[ColorNum][HandPieceNum];
