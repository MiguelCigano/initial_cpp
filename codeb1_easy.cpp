#include <iostream>
#include <string>

std::string code_land_user_name_validation_letter(std::string str) {
  int len;
  len = str.length();
  
  if (len < 4 || len > 25) {
    return "false";
  }
  
  if (!isalpha(str[0])) { 
    return  "false";
  }

  for(int i = 0; i < len; i++) {
  
  }

  return str;
}


std::string code_land_user_name_validation(std::string str) {
  int len = str.length();
  std::cout<< "len is: " << len << std::endl;
  
  if (len >= 4 && len <= 7) {
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
  std::string str_;
  str_ = "_hhlla";

  // keep this function call here
  std::cout << str_ << std::endl;
  std::cout << code_land_user_name_validation(str_) << std::endl;

  return 0;
}