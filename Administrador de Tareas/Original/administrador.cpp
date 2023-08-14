#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h> 

#include "administrador.h"
#include "StandarLibrary.h"
#include "Colores.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void Administrador::enConstruccion() {
    gotoxy(5, 15);
    std::cout << RF << "Funcion en construccion..." <<RTNC; pausa();
}

void Administrador::AltEnter()
{
    keybd_event(VK_MENU,
                0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
    return;
} 

void Administrador::inicio () {
    system(CLEAR);
    std::cout << RB << R"(
_____/\\\\\\\\\________/\\\\\\\\\\\__________/\\\\\\\\\__/\\\\\\\\\\\__/\\\\\\\\\\\_        
 ___/\\\\\\\\\\\\\____/\\\/////////\\\_____/\\\////////__\/////\\\///__\/////\\\///__       
  __/\\\/////////\\\__\//\\\______\///____/\\\/_______________\/\\\_________\/\\\_____      
   _\/\\\_______\/\\\___\////\\\__________/\\\_________________\/\\\_________\/\\\_____     
    _\/\\\\\\\\\\\\\\\______\////\\\______\/\\\_________________\/\\\_________\/\\\_____    
     _\/\\\/////////\\\_________\////\\\___\//\\\________________\/\\\_________\/\\\_____   
      _\/\\\_______\/\\\__/\\\______\//\\\___\///\\\______________\/\\\_________\/\\\_____  
       _\/\\\_______\/\\\_\///\\\\\\\\\\\/______\////\\\\\\\\\__/\\\\\\\\\\\__/\\\\\\\\\\\_ 
        _\///________\///____\///////////___________\/////////__\///////////__\///////////__        
)" << '\n';
    std::cout << RTNC;
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

void Administrador::defaultError () {
    gotoxy(5, 15);
    std::cout << RF << "Opcion erronea, ingresa un numero valido..." <<RTNC; pausa();
}

short Administrador::menu () {
    
    short opc;

    system(CLEAR);
    std::cout<<ARB; setborder(120, 30); std::cout<<RTNC;
    gotoxy((120/2) - (15/2), 2);
    std::cout << RF << "TaskMaster v0.1" <<RTNC;
    gotoxy(5, 5);
    std::cout << AQF << "Escoge la opcion deseada." <<RTNC;
    gotoxy(50, 5);
    std::cout << AQF << "Numero de Nodos Encontrados: " << RF << listaTareas.encabezado.getTam() <<RTNC;
    gotoxy(5, 7);
    std::cout << RB << "1)._ " << AQB << "Ingresar una nueva tarea." <<RTNC;
    gotoxy(5, 8);
    std::cout << RB << "2)._ " << AQB << "Marcar completada una tarea." <<RTNC;
    gotoxy(5, 9);
    std::cout << RB << "3)._ " << AQB << "Modificar una Tarea." <<RTNC;
    gotoxy(5, 10);
    std::cout << RB << "4)._ " << AQB << "Mostar todas la tareas pendientes por prioridad." <<RTNC;
    gotoxy(5, 11);
    std::cout << RB << "0)._ " << AQB << "Salir." <<RTNC;

    gotoxy(5, 13);
    std::cout << AQB << "Tu opcion >>  " <<RTNC;
    std::cout<<RB; std::cin >> opc; std::cout<<RTNC;

    return opc;

}

void Administrador::imprimir () {
    Nodo* listaAux = listaTareas.getLista();
    if (listaAux == nullptr) {
        gotoxy(5, 15);
        std::cout << RF << "No hay ninguna tarea que mostrar..." <<RTNC; pausa();
    }
    else {
        short i = 1; int y = 0;
        system(CLEAR);
        while (listaAux != nullptr) {
            std::cout<<ARB; setborder(80, 6 + y); std::cout<<RTNC;
            gotoxy(3, 2 + y);
            std::cout << RB << i++ << ")._ " <<RTNC;
            gotoxy(3, 3 + y);
            std::cout << AQB << "Nombre: " << AB << listaAux->getDato().getNombre() << "." <<RTNC;
            gotoxy(3, 4 + y);
            std::cout << AQB << "Prioridad: " << NB << listaAux->getDato().getPrioridad() << "." <<RTNC;
            gotoxy(3, 5 + y);
            std::cout << AQB << "Descripcion: " << VB << listaAux->getDato().getContenido() << "." <<RTNC;
            listaAux = listaAux->getNodo();
            y = y + 5;
        }
        
        std::cin.clear(); std::cin.sync(); std::cin.ignore();
    }
    listaAux = nullptr;
    delete[] listaAux;



}

void Administrador::ingresar() {
    system(CLEAR);
    short opc;
    do {
        setborder(120, 30);
        gotoxy((120/2) - (11/2), 2);
        std::cout << RF << "TaskMaster v0.1" <<RTNC;
        gotoxy(5, 5);
        std::cout << AQF << "Quieres agreagar una nueva tarea?" <<RTNC;
        gotoxy(5, 7);
        std::cout << RB << "1)._ " << AQB << "Si." <<RTNC;
        gotoxy(5, 8);
        std::cout << RB << "0)._ " << AQB << "Regresar al menu." <<RTNC;
        gotoxy(5, 10);
        std::cout << AQB << "Tu opcion >>  " <<RTNC;
        std::cout<<RB; std::cin >> opc; std::cout<<RTNC;

        switch (opc) {
            case SALIR: break;
            case 1: {
                Tarea nuevaTarea;
                std::string auxString; char auxChar;
                gotoxy(50, 5);
                std::cout << AQB << "Que nombre le quieres dar?" <<RTNC;
                gotoxy(50, 6);
                std::cout << AQB << "Nombre >>  " <<RTNC;
                gotoxy(62, 6);
                fflush(stdin); std::getline(std::cin, auxString); nuevaTarea.setNombre(auxString);
                gotoxy(50, 8);
                std::cout << AQB << "Que prioridad tiene? (A = Alta, B = Media y C = Baja)" <<RTNC;
                gotoxy(50, 9);
                std::cout << AQB << "Prioridad >>  " <<RTNC;
                gotoxy(65, 9);
                std::cin >> auxChar; nuevaTarea.setPrioridad(auxChar);
                gotoxy(50, 11);
                std::cout << AQB << "Dame una breve descripcion de la tarea." <<RTNC;
                gotoxy(50, 12);
                std::cout << AQB << "Contenido:" <<RTNC;
                gotoxy(50, 13);
                fflush(stdin); std::getline(std::cin, auxString); nuevaTarea.setContenido(auxString);
                listaTareas.insertar(listaTareas.ultimo(), nuevaTarea, 1);
                gotoxy(50, 15);
                std::cout << VB << "Tarea agregada con exito..." <<RTNC; pausa();
                opc = 0;
            }
            default: break;
        }

    } while (opc != SALIR);
}

void Administrador::eliminar () {
        Nodo* listaAux = listaTareas.getLista();
        if (listaAux == nullptr) {
            gotoxy(5, 15);
            std::cout << RF << "No hay ninguna tarea que mostrar..." <<RTNC; pausa();
            return;
        }
        std::string auxString = ""; bool encontrado;
        while (auxString != "S" && !encontrado) {
            listaAux = listaTareas.getLista();
            int i = 1, y = 0;
            system(CLEAR);
            std::cout<<ARB; setborder(80, 4 - 1 + y);
            gotoxy((80/2) - (16/2), 2 + y); std::cout<<RTNC;
            std::cout << AQF << "Tareas Actuales" <<RTNC; y += 2;
            while (listaAux != nullptr) {
                std::cout<<ARB; setborder(80, 4 + y); std::cout<<RTNC;
                gotoxy(3, 2 + y);
                std::cout << RB << i++ << ")._ " <<RTNC;
                gotoxy(3, 3 + y);
                std::cout << AQB << "Nombre: " << AB << listaAux->getDato().getNombre() << "." <<RTNC;
                y = y + 3;
                listaAux = listaAux->getNodo();
            }

            std::cout<<ARB; setborder(80, 4 + y + 10); std::cout<<RTNC;
            int x = y;
            gotoxy(3, x + 2);
            std::cout << AQB << "Dame el nombre de la tarea que quieres borrar" <<RTNC;
            gotoxy(3, x + 3);
            std::cout << RB << "(para salir sin borrar nada escribe \"S\" en mayusculas)" <<RTNC;
            gotoxy(3, x + 5);
            std::cout << AQB << "Tu opcion >>  " <<RTNC;
            fflush(stdin); std::cout<<AB; std::getline(std::cin, auxString); std::cout<<RTNC;
            encontrado = listaTareas.localizaNombre(auxString);
        }
        
        listaTareas.eliminar(listaTareas.localizaNombre(auxString));
        pausa();

}
