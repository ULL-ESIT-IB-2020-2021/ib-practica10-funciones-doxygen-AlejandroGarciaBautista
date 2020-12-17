/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file cripto.cc
  * @author Alejandro García Bautista
  * @date 17/12/20
  * @brief El programa a partir de la linea de comandos obtiene una serie
  *        de instrucciones asi como dos ficheros en donde uno debera contener
  *        un texto para encritar o desencriptar ya sea con el Metodo XOR o el 
  *        Metodo Cesar. Para obtener información de como utilar el programa ejecute
  *        ./cripto --help para ver todas las opciones.
  * @bug No hay bugs conocidos.
*/

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
      Encrypted_Cesar(lines, file_encrypted,code);
    }else if (how_to_operate == "-"){
      std::string copy_lines;
      if(!file_to_encrypt){
        std::cerr << "No se puede abrir el archivo" << std::endl;
      }
      while (file_to_encrypt){
        std::getline (file_to_encrypt, copy_lines);
      }
      Desencrypt_Cesar(copy_lines, file_encrypted, code);
    } 
  }
  return 0;
}