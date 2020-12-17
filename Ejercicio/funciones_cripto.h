/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file cripto.cc
  * @author Alejandro García Bautista
  * @date 17/12/20
  * @brief Este fichero .h contiene todas las definiciones de las funciones
  *        necesarias para que el programa funcione.
  *        Si se quiere compilar el programa solo hace falta ejecutar el comando make.
  * @bug No hay bugs conocidos.
*/

void Usage(int argc, char *argv[]);
void Encrypted_Cesar(std::string input_file, std::ofstream& out,int code);
void Desencrypt_Cesar(std::string to_desencrypt, std::ofstream& out, int pass);
