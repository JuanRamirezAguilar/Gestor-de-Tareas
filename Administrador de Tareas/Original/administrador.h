#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <iostream>
#include "lista.h"

#define DIRECCION_CARPETA "./tareas"

enum OPCIONES{SALIR = 0, INGRESAR, ELIMINAR, MODIFICAR, MOSTRAR};

class Administrador {

    private:

        Lista listaTareas;

    public:

        Administrador() : listaTareas(DIRECCION_CARPETA) {}
        void inicio();
        short menu();
        void defaultError();
        void ingresar();
        void imprimir();
        void eliminar();
        void AltEnter();
        void enConstruccion();

};


#endif // ADMINISTRADOR_H