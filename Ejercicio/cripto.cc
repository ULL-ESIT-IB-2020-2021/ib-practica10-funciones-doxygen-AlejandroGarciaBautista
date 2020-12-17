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
    std::string lines;
    std::ifstream file_to_encrypt (argv[1]);
    std::ofstream file_encrypted (argv[2]);
    if (how_to_operate == "+"){
      if (!file_to_encrypt){
        std::cerr << "No se puede abrir el archivo" << std::endl;
      }
      while (file_to_encrypt){
        std::getline(file_to_encrypt, lines);
      }
      if (!file_encrypted){
        std::cerr << "No hemos encontrado el archivo en el que querias escribir el codigo codificado" << std::endl;
      }
      Encrypted_Cesar(lines, file_encrypted,code);
    }else if (how_to_operate == "-"){
      std::string copy_lines;
      if(!file_encrypted){
        std::cerr << "No se puede abrir el archivo" << std::endl;
      }
    } 
  }
  return 0;
}