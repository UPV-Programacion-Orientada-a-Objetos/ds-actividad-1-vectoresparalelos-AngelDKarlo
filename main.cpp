#include <iostream>
#include <string>
#include <sstream> //libreria para conversion y manpulacion de texto
#include <fstream> //libreria para lectura y escritura de archivos

int main() {
    std::ifstream archivoParaTamano("olimpiadas.csv");
    std::string linea; //para leer cada una de las lineas del archivo
    int n = 0;
    int i = 0;
    char delimitador = ','; //delimitador quen usaremos en el csv 

    std::getline(archivoParaTamano, linea);
    
    while(std::getline(archivoParaTamano, linea)){
        n++;
    }
    archivoParaTamano.close();

    std::string nombre[n] = {};
    std::string pais[n] = {};
    std::string diciplina[n] = {};
    std::string genero[n] = {};
    std::string medallas[n] = {};

    std::ifstream archivo("olimpiadas.csv"); //definir el archivo como nuestro archivo csv

    std::getline(archivo, linea); //leemos la primera linea del archivo para descartarla por ser el encabezado
    //While para leer todas las lineas del archivo
    while(std::getline(archivo, linea)){

        std::stringstream stream(linea);
        
        std::getline(stream, nombre[i], delimitador);
        std::getline(stream, pais[i], delimitador);
        std::getline(stream, diciplina[i], delimitador);
        std::getline(stream, genero[i], delimitador);
        std::getline(stream, medallas[i], delimitador);
        
        i++;
    }
    archivoParaTamano.close();

    for(int i = 0; i <n; i++){
        std::cout << nombre[i] << std::endl;  
        std::cout << pais[i] << std::endl;    
        std::cout << diciplina[i] << std::endl;    
        std::cout << genero[i] << std::endl;    
        std::cout << medallas[i] << std::endl;      
    }

    return 0;
}
