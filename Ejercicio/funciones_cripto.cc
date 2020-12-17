#include <iostream>
#include <string>
#include <fstream>
#include "funciones_cripto.h"
#include <algorithm>



const std::string kHelpText = "Modo de uso: ./cripto fichero_entrada fichero_salida método password operación \n fichero_entrada: Fichero a codificar \n fichero_salida:  Fichero codificado \n método:         Indica el método de encriptado \n 1: Cifrado xor \n 2: Cifrado de César \n password:       Palabra secreta en el caso del método 1, Valor de K en el caso del método 2 \n operación:      Operación a realizar en el fichero \n +: encriptar el fichero \n -: desencriptar el fichero"; 

void Usage(int argc, char *argv[]) {
  if (argc > 6) {
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string parameter =argv[1];
  if (parameter == "--help") {
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
}

void Encrypted_Cesar(std::string to_encrypt, std::ofstream& out,int password){
  std::transform(to_encrypt.begin(),to_encrypt.end(),to_encrypt.begin(), ::toupper); // https://stackoverflow.com/questions/735204/convert-a-string-in-c-to-upper-case 
  for (char character : to_encrypt){
    if(isalpha(character)){
      character = character + password;
      if (character > 'Z'){
        character = character - 26;
      }
      if (character < 'A'){
        character = character + 26;
      }
    }
  std::string encrypted_sentence = " ";
  encrypted_sentence = encrypted_sentence + character;
  out << encrypted_sentence;
  }
}

void Desencrypt_Cesar(std::string to_desencrypt, std::ofstream& out,int pass){
  for (auto character : to_desencrypt){
    if(isalpha(character)){
      character = character - pass;
      if (character < 'A'){
        character = character + 26;
      }
    }
    out << character;
  }
}