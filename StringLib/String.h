#pragma once
#include <iostream>

using namespace std;

int StrLen(char *str);

class TString {
private:
  int lenght;
  char *str;
public:
TString();
TString(int _lenght);
TString(char *_str);
TString(TString& obj);
~TString();

int GetStrLen();
char GetStrChar(int index);
void SetStr(int _lenght, char *_str);
int Find(char c);
int Find(const TString wrd);
void Split(TString **p, int& counter, char c);
void FindAll(const TString wrd, int& counter, int *indx);
char MostFreq();
void Characters(char *&ltrs, int& size);
void CharQuantity(char *&ltrs, int *&quant, int& size);

bool operator<(const TString& p);
bool operator>(const TString& p);
TString& operator=(const TString& p);
char& operator[](const int index);
const char& operator[](const int index) const;
TString operator*(int k);

friend bool operator==(const TString& p, const TString& q);
friend TString operator+(const TString& p, const TString& q);
friend TString operator+(const TString& p, const char c);
friend ostream& operator<<(ostream& t, const TString& p);
friend istream& operator>>(istream& t, TString& p);



};