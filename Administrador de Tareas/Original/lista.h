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
        Nodo* getNodo () { return sig; }
        friend class Lista;

};

class Encabezado {

    private:

        int tam;

    public:

        Encabezado() : tam(0){};
        void aumTam() { tam++; }
        void disTam() { tam--; }
        int getTam() { return tam;}
        friend class Lista;

};

class Lista : public Encabezado {

    private:

        Nodo *lista;

    public:

        Encabezado encabezado;
        Lista() : lista(nullptr){};
        Lista(std::string directorio_txt);
        ~Lista();
        bool vacia()const;
        Nodo* ultimo()const;
        Nodo* primero()const;
        Nodo* anterior(Nodo* pos)const;
        void insertar(Nodo* pos, Tarea elem, int forma);
        bool eliminar(Nodo* pos);
        void imprimir()const;
        friend class Tarea;
        bool localiza(Tarea tareaBuscada)const;
        Nodo* localizaNombre(std::string nombre) const;
        Nodo* getLista() { return lista; }
};

#endif // LISTA_H