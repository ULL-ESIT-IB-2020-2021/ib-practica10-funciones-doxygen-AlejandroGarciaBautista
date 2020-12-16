#include <iostream>
#include <string>
#include <fstream>
#include "funciones_cripto.h"

int main (int argc, char* argv[]){
  Usage(argc, argv); 
  std::string how_to_operate = argv[5];
  int method_number = std::stoi(argv[3]);
  if (method_number == 1){
    if(how_to_operate == "+"){

    }else if (how_to_operate == "-"){

    }  
  }else if (method_number == 2){
    int code = std::stoi(argv[4]);
    if (how_to_operate == "+"){
      std::ifstream file (argv[1]);
      std::ofstream out_file (argv[2]);
      Encrypted_Cesar(file, out_file, code);
    }else if (how_to_operate == "-"){

    } 
  }
  return 0;
}