#pragma once
<<<<<<< HEAD

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

=======
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
>>>>>>> be460bed2fc506bc8304f4a2b396f84db34ab6af
