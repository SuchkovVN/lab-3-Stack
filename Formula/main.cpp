#include "Formula.h"
#include <iostream>

int main()
{
  try
  {
    TPostfix p("((-1)-(1))");
  }
  catch(const char* s)
  {
    std::cout << s << '\n';
  }
  
}