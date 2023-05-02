#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Tarea.h"

class Nodo {

    private:

        Tarea dato;
        Nodo* sig;

    public:

        Nodo() : sig(nullptr){};
        void setDato (Tarea aux) {dato = aux;}
        Tarea getDato ()const {return dato;}
        friend class Lista;

};

class Encabezado {

    private:

        int tam;

    public:

        void aumTam() { tam++; }
        void disTam() { tam--; }
        int getTam() { return tam;}
        friend class Lista;

};

class Lista : public Tarea {

    private:

        Encabezado encabezado;
        Nodo *lista;
        

    public:

        Lista() : lista(nullptr){};
        ~Lista();
        Lista(std::string directorio_txt);
        bool vacia()const;
        Nodo* ultimo()const;
        Nodo* primero()const;
        Nodo* anterior(Nodo* pos)const;
        void insertar(Nodo* pos, Tarea elem, int forma);
        bool eliminar(Nodo* pos);
        void imprimir()const;
        ///Nodo *localiza(std::string datoBuscado)const;
};

#endif // LISTA_H