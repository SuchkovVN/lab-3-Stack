#include "String.h"

int StrLen(char *str) {
  if(str == 0)
    return -1;
  int i = 0;
  while(str[i] != '\0') 
    i++;
  return i;
}


TString::TString() {
  lenght = 0;
  str = 0;
}

TString::TString(int _lenght) {
  lenght = _lenght;
  str = new char[lenght + 1];
  for(int i = 0; i < lenght; i++) {
    str[i] = ' '; 
  }
  str[lenght] = '\0';
}

TString::TString(char *_str) {
  if(_str != 0) {
    lenght = StrLen(_str);
    str = new char[lenght + 1];
    for(int i = 0; i < lenght; i++ ) {
      str[i] = _str[i];
    }
    str[lenght] = '\0';
  }
  else {
    throw "Error: empty string init";
  }
}

TString::TString(TString& obj) {
  if(obj.lenght = 0){
    throw "Error: empty TString init";
  }
  lenght = obj.lenght;
  str = new char[lenght + 1];
  for (int i = 0; i < lenght + 1; i++) {
    str[i] = obj.str[i];
  }
}

TString::~TString() {
  if(str != 0) {
    delete [] str;
  }
  str = 0;
}

int TString::GetStrLen() {
  return lenght;
}

char TString::GetStrChar(int index) {
  if(index >= lenght || index < 0)
    throw "Error: invalid index";
  return str[index];
}

void TString::SetStr(int _lenght, char *_str) {
  lenght = _lenght;
  delete [] str;
  str = new char[lenght + 1];
  for(int i = 0; i < lenght; i ++) {
    str[i] = _str[i];
  }
  str[lenght] = '\0';
}

bool TString::operator<(const TString& p) {
  if(lenght < p.lenght)
    return true;
  return false;
}

bool TString::operator>(const TString& p) {
  if(lenght > p.lenght)
    return true;
  return false;
}

bool operator==(const TString& p, const TString& q) {
  if(p.lenght == q.lenght) {
    int k = 0;
    while(p.str[k] == q.str[k]) {
      k++;
    }
    if((k - 1) == p.lenght)
      return true;
  }
  return false;
}

TString& TString::operator=(const TString& p) {
  if(*this == p || p.str == 0)
    throw "Error: invalid copy";
  delete [] str;
  lenght = p.lenght;
  str = new char[lenght + 1];
  for(int i = 0; i < lenght + 1; i ++) {
    str[i] = p.str[i];
  }
  return *this;
}

char& TString::operator[](const int index) {
  if(index < 0 || index > (lenght + 1))
    throw "Error: index ran out of string";
  return str[index];
}

const char& TString::operator[](const int index) const {
  if(index < 0 || index > (lenght + 1))
    throw "Error: index ran out of string";
  return str[index];
}

TString operator+(const TString& p, const TString& q) {
  int len = p.lenght + q.lenght;   
  TString temp(len);
  if(len == 0)
    return temp;
  for(int i = 0; i < p.lenght; i ++) {
    temp[i] = p[i];
  }
  for(int i = p.lenght - 1; i < len; i ++) {
    temp[i] = q[i - p.lenght + 1];
  }
  return temp;
}
 TString operator+(const TString& p, const char c) {
   int len = p.lenght + 1;
   TString temp(len);
   for(int i = 0; i < p.lenght; i++) {
     temp[i] = p[i];
   }
   temp[len] = c;
 }

ostream& operator<<(ostream& t, const TString& p) {
  for(int i = 0; i < p.lenght; i++) {
    t << p[i];
  }
  return t;
}

istream& operator>>(istream& t, TString& p) {
  char *s = new char[256];
  t >> s;
  int k = 0;
  while(s[k] != '\0'){
    k++; 
  }
  
  TString temp;
  temp.SetStr(k, s);
  p = temp;
  return t;  
  
}

//допы

TString TString::operator*(int k) {
  if (k <= 0)
    throw "Error: invalid string multiplaing";

  TString temp(*this);

  if (k == 1)
    return *this;
  
  for(int i = 0; i < k - 1; i++) {
    temp = temp + *this;
  }
  return temp;

}

int TString::Find(char c) {

  for(int i = 0; i < lenght; i++) {
    if(str[i] == c)
      return i;
  }
  return -1;  

}

int TString::Find(const TString wrd) {
  if(wrd == 0)
    return -1;

  int count;

  for(int i = 0; i < lenght; i++) {
    count = 0;
    for(int j = 0; j < wrd.lenght; j ++) {
      if(this[j + i] == wrd[j])
        count++; 
    }
    if(count == wrd.lenght)
      return i;
  }
  return -1;
  
}

void TString::Split(TString **p, int& counter, char c) {
  if (p != 0) {
    delete [] p;
    p = 0;
  }
  int count = 0, pointer = 0, k, e;
  for(int i = 0; i < lenght; i++) {
    if(str[i] == c) 
      count++;
  }
  
  if (count == 0) {
    p = new TString*(this);
  }
  p = new TString*[count + 1];
  counter = count;
  

  for(int i = 0; i < count; i++) {
    k = pointer;
    while(str[pointer] != c)
      pointer++;
    
    p[i] = new TString(pointer - k);
    e = 0;
    for(int j = k; j < pointer; j++) {
      p[i][e] = this[j];
      e++;
    }

  }

}

void TString::FindAll(const TString wrd, int& counter, int *indx) {
  if (wrd == 0) {
    counter = 0;
    indx = 0;
    return;
  }
  if (indx != 0) {
    delete [] indx;
    indx = 0;
  }
  counter = 0;
  int check, count = 0;

  for(int i = 0; i < lenght; i++) {
    check = 0;
    for(int j = 0; j < wrd.lenght; j++) {
      if (this[j + i] == wrd[j])
        check++; 
    }
    if (check == wrd.lenght)
      counter++;
  }

indx = new int[counter];

 for(int i = 0; i < lenght; i++) {
    check = 0;
    for(int j = 0; j < wrd.lenght; j++) {
      if (this[j + i] == wrd[j])
        check++; 
    }
    if (check == wrd.lenght) {
      indx[count] = i;
      count++;
    }

  }

}

void TString::Characters(char *&ltrs, int& size) {
  if(this == 0) {
    ltrs = 0;
    size = 0;
    return;
  }
  if(ltrs != 0) {
    delete [] ltrs;
    ltrs = 0;
  }
  char *temp = new char[lenght];
  int count = lenght, k = 0;

  
 for(int i = 0; i < lenght; i ++) {
   if(temp[i] == -1)
    continue;

    temp[i] = str[i];

    for(int j = i + 1; j < lenght; j++) {
      if(temp[i] == str[j]) {
        temp[j] = -1;
        count--;
      }
    }   
 }

  ltrs = new char[count + 1];
  size = count;
  

   for(int i = 0; i < lenght; i++) {
     if(temp[i] != -1) {
       ltrs[k] = temp[i];
       k++;
     }
    }
    ltrs[count] = '\0'; 
  }

void TString::CharQuantity(char *&ltrs, int *&quant, int& size) {
  Characters(ltrs, size);
  if(size == 0)
    return;
  if(quant == 0) {
    delete [] quant;
    quant = 0;
  }
  
  quant = new int[size];

  for(int i = 0; i < size; i++) {
    quant[i] = 0;
    for(int j = 0; j < lenght; j++) {
      if(ltrs[i] == str[j])
        quant[i]++;
    }
  }
}

char TString::MostFreq() {
  char *ltrs;
  int *quan;
  int size, max = 0, k = 0;
  CharQuantity(ltrs, quan, size);

  for(int i = 0; i < size; i++) {
    if(quan[i] >= max) {
      max = quan[i];
      k = i;
    }
  }
  return ltrs[k];
}