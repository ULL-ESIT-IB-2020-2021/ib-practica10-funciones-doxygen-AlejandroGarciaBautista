/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file funciones_cripto.cc
  * @author Alejandro García Bautista
  * @date 17/12/20
  * @brief Este archivo .cc contiene todas las funciones necesarias
  *        para poder utilizar el programa ./cripto.
  * @bug La función Encrypted_XOR no funciona como se esperaba que funcionase.
*/
#include <iostream>
#include <string>
#include <fstream>
#include "funciones_cripto.h"
#include <algorithm>
#include <vector>

const std::string kHelpText = "Modo de uso: ./cripto fichero_entrada fichero_salida método password operación \n fichero_entrada: Fichero a codificar \n fichero_salida:  Fichero codificado \n método:         Indica el método de encriptado \n 1: Cifrado xor \n 2: Cifrado de César \n password:       Palabra secreta en el caso del método 1, Valor de K en el caso del método 2 \n operación:      Operación a realizar en el fichero \n +: encriptar el fichero \n -: desencriptar el fichero"; 
/**La funcion Usage va a comprobar el uso de los argumentos pasados por linea de comandos, 
  *y va a generar mensajes si son necesarios con con argumentos especiales como puede ser --help.
*/
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
///La funcion Encrypted_Cesar encriptara mediante el metodo cesar el texto de documento pasado por linea de comandos y luego lo grabara en otro archivo.
void Encrypted_Cesar(std::string to_encrypt, std::ofstream& out,int password){
  std::transform(to_encrypt.begin(),to_encrypt.end(),to_encrypt.begin(), ::toupper); /// https://stackoverflow.com/questions/735204/convert-a-string-in-c-to-upper-case 
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
///La funcion Desencrypt_Cesar hace todo lo contrario a Encrypted_Cesar.
void Desencrypt_Cesar(std::string to_desencrypt, std::ofstream& out,int pass){
  for (char character : to_desencrypt){
    if(isalpha(character)){
      character = character - pass;
      if (character < 'A'){
        character = character + 26;
      }
    }
    out << character;
  }
}

/**La función Encrypted_XOR deberia funcionar para recibir una string obtenida desde un fichero
  *para luego encriptarla usando el metodo XOR y luego grabar el resultado en un archivo elegido por
  *el usuario. Asimismo la función Desencrypt_XOR deberia hacer la funcionalidad contraria.
*/

void Encrypted_XOR (std::string lines_to_encrypt, std::ofstream& out, std::string secret){
  for (char character_password : secret){
    if(isalpha(character_password)){
      character_password = character_password ^ 128;    
    for (char character_string : lines_to_encrypt){
    character_string = character_string ^ character_password;
    out << character_string;
      }
    }
  }
}


void Desencrypt_XOR(std::string lines_to_desencrypt, std::ofstream& out, std::string secret){

}



void CountVowelI(std::ifstream& vowels){
  std::string my_str;
  std::getline(vowels, my_str);
  int counter = 0;
  for (char vowel_i : my_str){
    if (vowel_i == 'i' || vowel_i == 'I'){
      counter = ++counter;
    }
  }
  std::cout << "En el archivo de entrada hay este numero de I " << counter << std::endl;
}