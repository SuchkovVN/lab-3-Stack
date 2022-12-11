#include "Formula.h"
#include <iostream>

int main()
{
  try
  {
    TFormula test("a+b*(a+c)");
  }
  catch (const char* s)
  {
    cout << s << '\n';
  }
}