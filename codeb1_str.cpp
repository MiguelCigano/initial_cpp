#include <iostream>
#include <string>

using namespace std;

string CodelandUsernameValidation(string str) {
  // codigo va aquí
  int l;
  l = str.length();
  if(l<4 || l>25) return "false";
  if(!isalpha(str[0])) return  false;
  for(int i = 0; i < l; i++){
  }     
  return str;
}

int main(void) { 
  // keep this function call here
  cout << CodelandUsernameValidation(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}