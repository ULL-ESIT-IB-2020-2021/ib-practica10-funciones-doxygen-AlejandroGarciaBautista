#include <iostream>
#include <string>
#include <fstream>
#include "funciones_cripto.h"



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
