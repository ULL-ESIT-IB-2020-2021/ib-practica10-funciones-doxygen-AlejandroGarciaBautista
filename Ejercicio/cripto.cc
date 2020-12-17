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
  *        un texto para encriptar o desencriptar ya sea con el Metodo XOR o el 
  *        Metodo Cesar. Para obtener información de como utilar el programa ejecute
  *        ./cripto --help para ver todas las opciones. El programa esta casi terminado
  *        solo a falta de terminar el metodo XOR ya que me da error de la manera que lo estoy haciendo.
  * @bug La función Encrypted_XOR no funciona como se esperaba que funcionase.
*/

#include <iostream>
#include <string>
#include <fstream>
#include "funciones_cripto.h"

int main (int argc, char* argv[]){
  Usage(argc, argv); 
  std::string how_to_operate = argv[5];
  int method_number = std::stoi(argv[3]);
  std::ifstream count_vowel (argv[1]);
  CountVowelI(count_vowel);
  if (method_number == 1){
    std::string secret_word = argv[4];
    std::ifstream file_1 (argv[1]);
    std::ofstream file_2 (argv[2]);
    std::string lines_to_get;
    if(how_to_operate == "+"){
      if(!file_1){
        std::cout << "No se puede abrir el archivo" << std::endl;
      }
      while(file_1){
        std::getline(file_1, lines_to_get);
      }
      Encrypted_XOR(lines_to_get, file_2, secret_word);
    }else if (how_to_operate == "-"){
      if(!file_1){
        std::cout << "No se puede abrir el archivo" << std::endl;
      }
      while(file_1){
        std::getline(file_1, lines_to_get);
      }
      Desencrypt_XOR(lines_to_get, file_2, secret_word);
    }  
  }else if (method_number == 2){
    int code = std::stoi(argv[4]);
    std::string lines;
    std::ifstream file_in (argv[1]);
    std::ofstream file_out (argv[2]);
    if (how_to_operate == "+"){
      if (!file_in){
        std::cerr << "No se puede abrir el archivo" << std::endl;
      }
      while (file_in){
        std::getline(file_in, lines);
      }
      Encrypted_Cesar(lines, file_out,code);
    }else if (how_to_operate == "-"){
      std::string copy_lines;
      if(!file_in){
        std::cerr << "No se puede abrir el archivo" << std::endl;
      }
      while (file_in){
        std::getline (file_in, copy_lines);
      }
      Desencrypt_Cesar(copy_lines, file_out, code);
    } 
  }
  return 0;
}