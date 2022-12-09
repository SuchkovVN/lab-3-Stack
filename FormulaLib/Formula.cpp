#include "Formula.h"
#include "Operations.h"

TFormula::TFormula(TString str) 
{
  if (!BracketsCheck(str)) throw "Error: invalid formula";

  formula = str;
  ConvertToPostfix();
}

bool TFormula::BracketsCheck(TString str)
{
  TStack<bool> brackets; 
  for (int i = 0; i < str.GetStrLen(); i++)
  {
    if (str[i] == '(')
    {
      brackets.Push(true);
    }
    else if (str[i] == ')')
    {
      if (brackets.IsEmpty()) return false;
      brackets.Pop();
    }
  }
  
  if (brackets.IsEmpty()) return true;
  return false; 
}

void TFormula::ConvertToPostfix()
{
  TStack<TString> opstack; 



}

