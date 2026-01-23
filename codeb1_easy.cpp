#include <iostream>
#include <string>

std::string code_land_user_name_validation(std::string str) {
  int len = str.length();
  std::cout<< "len is: " << len << std::endl;
  
  if (len >= 4 && len <=7 ) {
    int i = 0;
    while (true) {
      if (i == 0) {
        if (str[i] == '_') { 
          std::cout << "No inicia con letra" << std::endl;
          break;
        }
      }
      i++;
    }
  }
  else {
    std::cout << "Ingresa una cadena mas pequeña" << std::endl;
  }

  return str;
}

int main() { 
  std::string stdi_;
  stdi_ = "_hhlla";

  // keep this function call here
  std::cout << stdi_ << std::endl;
  std::cout << code_land_user_name_validation(stdi_);

  return 0;
}