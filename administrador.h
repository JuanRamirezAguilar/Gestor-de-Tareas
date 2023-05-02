#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <iostream>
#include "lista.h"

enum OPCIONES{SALIR = 0, INGRESAR, ELIMINAR, MODIFICAR, MOSTRAR};

class Administrador : public Lista {

    private:

        const std::string directorio_txt = "./tareas";
        Lista listaTareas;

    public:

        Administrador() : listaTareas(directorio_txt) {}
        void inicio();
        short menu();
        void defaultError();
        void ingresar();

};


#endif // ADMINISTRADOR_H