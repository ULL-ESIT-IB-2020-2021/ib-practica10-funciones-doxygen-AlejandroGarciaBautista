#include <iostream>
#include <string>
#include <fstream>
#include "funciones_cripto.h"

int main (int argc, char* argv[]){
  Usage(argc, argv);
  int method_number = std::stoi(argv[3]);
  if (method_number == 1){
    std::cout << "Adios" << std::endl;
  }else if (method_number == 2){
     std::cout << "Hola" << std::endl;
  }
}