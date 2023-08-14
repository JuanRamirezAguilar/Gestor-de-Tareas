#include "Tarea.h"

#include <windows.h>

/* Constructor */
Tarea::Tarea() {
    nombre = contenido = ""; prioridad = ' ';
}
Tarea::Tarea(std::string n, std::string c, char p) {
    nombre = n; contenido = c; prioridad = p;
}

/* Metodos Getters y Setters */
void Tarea::setNombre(std::string auxString) { nombre = auxString; }
void Tarea::setContenido(std::string auxString) { contenido = auxString; }
void Tarea::setPrioridad(char auxPrioridad) { prioridad = auxPrioridad; }
std::string Tarea::getNombre() { return nombre; }
std::string Tarea::getContenido() { return contenido; }
char Tarea::getPrioridad() { return prioridad; }


std::ostream& operator << (std::ostream& out, const Tarea& x){
    out << "Nombre: " << x.nombre <<std::endl;
    out << "Prioridad: " << x.prioridad <<std::endl;
    out << "Contenido:" << std::endl << x.contenido <<std::endl;
    return out;
}

