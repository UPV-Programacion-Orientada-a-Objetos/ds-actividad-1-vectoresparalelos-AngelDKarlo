#include <iostream>
#include <string>
#include <sstream> //libreria para conversion y manpulacion de texto
#include <fstream> //libreria para lectura y escritura de archivos
#include <limits>


void mostrarInformacionAtleta(std::string nombre[], std::string pais[], std::string diciplina[], std::string genero[], int medallas[], std::string nombreAtleta, int n){

    for(int i = 0; i < n; i++){
        if(nombre[i] == nombreAtleta){
            std::cout << "-----------------------" << std::endl;
            std::cout << "Nombre: " << nombre[i] <<std::endl;   
            std::cout << "Pais de origen: " << pais[i] <<std::endl;        
            std::cout << "Diciplina que practica: " << diciplina[i] <<std::endl;        
            std::cout << "genero: " << genero[i] <<std::endl;        
            std::cout << "Medallas de oro: " << medallas[i] <<std::endl;
            std::cout << "-----------------------" << std::endl;
            return;
        }
    }

    std::cout << "No se encontro al Atleta" << std::endl;
}

void medallasTotalesPais(std::string pais[], int medallas[], int n){
   std::string paisesUnicos[n] ={};
   int contador = 0;


   for( int i = 0; i <n; i++){
        bool paisU = true;

        for(int j = 0; j <n;j++){
            if(pais[i] == paisesUnicos[j]){
                paisU  = false;
                break;
            }
        }

        if(paisU){
            paisesUnicos[contador] = pais[i];
            contador++;
        }         
    }


    for(int i = 0; i <contador; i++){
        std::string paisActual = paisesUnicos[i];
        int medallasTotales = 0;
        for(int j = 0; j < n; j++){
            if(paisActual == pais[j]){
                medallasTotales = medallasTotales + medallas[j];
            }
        }
        std::cout << "Las medallas de " << paisActual << " son " << medallasTotales << std::endl;
    }
}


void mayorCantMedallas(int medallas[], std::string atleta[], int n){
    int mayorCant = medallas[0];
    std::string atletaMayor = atleta[0];
    for(int i = 0; i <n; i++){
        if(medallas[i] > mayorCant){
            mayorCant = medallas[i];
            atletaMayor = atleta[i];
        }
    }

    for(int i = 0; i < n; i++){
        if(mayorCant == medallas[i]){
            std::cout << "El atleta " << atleta[i] << " tiene " << medallas[i] << " medallas"<< std::endl;
        }        
    }
}

int main(int s, char *args[]) {
    std::string linea; //para leer cada una de las lineas del archivo
    int n = 0;
    int i = 0;
    int opcion;
    std::string nom;
    std::string medallasString;
    char delimitador = ','; //delimitador quen usaremos en el csv 
    std::string nombreArchivo;
    
    
    if(s < 2) {
        std::cout << "No se ingreso un archivo" << std::endl;
        std::cin >> nombreArchivo;
            
    }else{
        nombreArchivo=args[1];
    }
    
    std::ifstream archivoParaTamano(nombreArchivo);
    std::getline(archivoParaTamano, linea);
    
    while(std::getline(archivoParaTamano, linea)){
        n++;
    }
    archivoParaTamano.close();

    std::string nombre[n] = {};
    std::string pais[n] = {};
    std::string diciplina[n] = {};
    std::string genero[n] = {};
    int medallas[n] = {};

    std::ifstream archivo(nombreArchivo); //definir el archivo como nuestro archivo csv

    std::getline(archivo, linea); //leemos la primera linea del archivo para descartarla por ser el encabezado
    //While para leer todas las lineas del archivo
    while(std::getline(archivo, linea)){

        std::stringstream stream(linea);
        
        std::getline(stream, nombre[i], delimitador);
        std::getline(stream, pais[i], delimitador);
        std::getline(stream, diciplina[i], delimitador);
        std::getline(stream, genero[i], delimitador);
        std::getline(stream, medallasString, delimitador);
        medallas[i] = std::stoi(medallasString);
        
        i++;
    }
    archivo.close();
    
    do{
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "Que desea hacer?" << std::endl;
        std::cout << "1- Mostrar informacion de un atleta" << std::endl;
        std::cout << "2- Medallas de oro totales de un pais" << std::endl;
        std::cout << "3- Atleta con la mayor cantidad de medallas" << std::endl;
        std::cout << "0- Salir" << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(opcion){
            case 1: 
                std::cout << "Cual es el nombre del atleta?" << std::endl;

                std::getline(std::cin, nom);
                mostrarInformacionAtleta(nombre, pais, diciplina, genero, medallas,nom,  n);
                break;
            case 2:
                medallasTotalesPais(pais, medallas, n);
                break;
            case 3:
                mayorCantMedallas( medallas, nombre, n);
                break;
            case 0: 
                break;
            default:
                std::cout << "Seleccione una opcion valida" << std::endl;
                break;
        }
    

    }while(opcion != 0);
    
    return 0;
}
