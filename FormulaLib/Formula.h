#pragma once
#include "String.h"

class TFormula 
{
private:
  TString Formula; //строка с формулой 
  TString PostfixForm; //Постфиксная форма формулы 
public:
  TFormula(TString formula = nullptr);

  bool FormulaChecker()

};