#pragma once

#include <map>
#include "String.h"

map<char*, int> opPriority = 
{
  {"sqrt", 3},
  {"sin", 3},
  {"cos", 3},
  {"*", 2},
  {"/", 2},
  {"+", 1},
  {"-", 1},
  {"(", 0},
  {")", 0}
};

map<char*, int> opArity = 
{
  {"sqrt", 1},
  {"sin", 1},
  {"cos", 1},
  {"*", 2},
  {"/", 2},
  {"+", 2},
  {"-", 2},
  {"(", 0},
  {")", 0}
};


