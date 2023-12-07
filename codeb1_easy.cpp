#include <iostream>
#include <string>

using namespace std;

string CodelandUsernameValidation(string str) {
  
  // codigo va aquí
  int l;
  l = str.length();
  cout<< l << endl;
  if(l>=4 & l<=7){
    int i = 0;
    while(true){
      if(i==0){
        if(str[i] == '_'){ 
        cout<< "No inicia con letra";
        break;
        }
      }
      i++;
    }

  }

else{
    cout<<"Ingresa una cadena más pequeña"<<endl;

};

  return str;

}


int main(void) { 
 string std_;
 std_ = "_hhlla";

  // keep this function call here
  cout << std_;
  cout << CodelandUsernameValidation(std_);
  return 0;
    
}