#include "lista.h"

#include <iostream>
#include <fstream>
#include <dirent.h>
#include <cstdio>

Lista::Lista(const std::string directorio_txt) : lista(nullptr) {
    DIR* dir; ///GPuntero al directorio.
    struct dirent *ent;
    std::ifstream archivo;
    std::string nombre_archivo, contenido_archivo, linea;
    /* En esta línea de código se está abriendo un directorio que contiene archivos de texto con extensión .txt */
    if ((dir = opendir (directorio_txt.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {   // se lee una entrada del directorio
            nombre_archivo = ent->d_name;
            if (nombre_archivo == "." || nombre_archivo == "..") {
                continue; // Saltar al siguiente archivo del directorio
            }
            if (nombre_archivo.substr(nombre_archivo.find_last_of(".") + 1) == "txt") {
                archivo.open(directorio_txt + "/" + nombre_archivo);
                if (archivo.is_open()) {
                    ///std::getline(archivo, linea);
                    std::string nomAux;
                    int i = 0;
                    while (nombre_archivo[i] != '.') {
                        nomAux = nomAux + nombre_archivo[i++];
                    }
                    Tarea nuevaTarea;
                    nuevaTarea.setNombre(nomAux);
                    std::getline(archivo, linea);
                    nuevaTarea.setPrioridad(linea[0]);
                    std::getline(archivo, linea);
                    nuevaTarea.setContenido(linea);
                    if (!localiza(nuevaTarea)) {
                        insertar(ultimo(), nuevaTarea, 0);
                    }
                    archivo.close();
                }
                else {
                    std::cout << "No se pudo abrir el archivo: " << nombre_archivo <<std::endl;
                }
            }
        }
        closedir(dir);
    }
    else {
        std::cout << "No se pudo abir el directorio: " << directorio_txt <<std::endl;
    }
}

Lista::~Lista() {
    Nodo* actual = lista;
    while (actual != nullptr) {
        Nodo* temp = actual;
        actual = actual->sig;
        delete temp;
    }
}


bool Lista::vacia()const {
    if (lista == nullptr)
        return true;
    return false;
}

Nodo* Lista::ultimo()const {
    if(vacia()){
        return nullptr;
    }
    Nodo* aux = lista;
    while(aux -> sig != nullptr){
        aux = aux->sig;
    }
    return aux;
}

Nodo* Lista::primero()const{
    if(vacia()){
        return nullptr;
    }
    return lista;
}

void Lista::insertar(Nodo* pos, Tarea elem, int forma){
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->dato = elem;
    if(pos == nullptr){
        nuevoNodo->sig = lista;
        lista = nuevoNodo;
        encabezado.aumTam();
    }
    else {
        nuevoNodo->sig = pos->sig;
        pos->sig = nuevoNodo;
        encabezado.aumTam();
    }

    if (forma == 1) {
        std::string nombre_archivo = "./tareas/" + elem.getNombre() + ".txt";
        std::ofstream archivo(nombre_archivo);
        if (archivo.is_open()) {
            archivo << elem.getPrioridad() << std::endl;
            archivo << elem.getContenido() << std::endl;
            archivo.close();
        }
        else { 
            std::cout << "hay un problema con el archivo...";
            std::cin.clear(); std::cin.sync(); std::cin.ignore();
        }
    }
}

Nodo* Lista::anterior(Nodo* pos)const {
    if (vacia() || pos == nullptr) {
        return nullptr;
    }
    Nodo* aux = lista;
    while ((aux != nullptr) && (aux->sig != pos)) {
        aux = aux->sig;
    }
    return aux;
}

bool Lista::eliminar(Nodo *pos) {
    if(vacia() || pos == nullptr){
        return false;
    }
    const std::string nombre_archivo = "./tareas/" + pos->getDato().getNombre() + ".txt";
    std::ofstream archivo(nombre_archivo.c_str());
    archivo.close();
    if(pos == lista){
        if (std::remove(nombre_archivo.c_str()) == 0) {
            ///std::cout << "El archivo " << nombre_archivo << " ha sido eliminado correctamente." << std::endl;
        } 
        else {
            std::cout << "Error al eliminar el archivo " << nombre_archivo << std::endl;
        }
        lista = lista->sig;
        encabezado.disTam();
    }
    else{
        if (std::remove(nombre_archivo.c_str()) == 0) {
            ///std::cout << "El archivo " << nombre_archivo << " ha sido eliminado correctamente." << std::endl;
        } 
        else {
            std::cout << "Error al eliminar el archivo " << nombre_archivo << std::endl;
        }
        anterior(pos)->sig = pos->sig;
        encabezado.disTam();
    }
    delete pos;

    return true;
}

void Lista::imprimir()const{
    Nodo* aux = lista;
    int i = 1;
    while(aux != nullptr){
        std::cout << i++ << ")._ " <<std::endl;
        std::cout << aux->dato <<std::endl<<std::endl;
        aux = aux->sig;
    }
    std::cin.clear(); std::cin.sync(); std::cin.ignore();
}

bool Lista::localiza(Tarea tareaBuscada)const {
    Nodo* aux = lista;
    while(aux != nullptr){
        if (tareaBuscada == aux->dato)
            return true;
        aux = aux->sig;
    }
    return false;
}

Nodo* Lista::localizaNombre(std::string nombre) const {
    Nodo* aux = lista;
    while(aux != nullptr){
        if (nombre == aux->dato.getNombre())
            return aux;
        aux = aux->sig;
    }
    return aux;
}