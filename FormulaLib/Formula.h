#pragma once

#include "String.h"
#include <map>
#include "Stack.h"

class TFormula
{
private:
  TString formula; //Входная строка с формулой 
  TString postfixForm; //Постфиксная форма формулы 

  bool BracketsCheck(TString str);
  void ConvertToPostfix();
public:
  TFormula(TString str);
  TString GetVariables();

  double Calculate();




  

};

