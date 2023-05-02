#include <iostream>
#include <thread>
#include <chrono>

#include "administrador.h"
#include "StandarLibrary.h"
#include "Colores.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

const std::string directorio_txt = "./tareas";
Lista listaTareas(directorio_txt);

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
    setborder(120, 30);
    gotoxy((120/2) - (11/2), 2);
    std::cout << RF << "TaskMaster v01" <<RTNC;
    gotoxy(5, 5);
    std::cout << AQF << "Escoge la opcion deseada." <<RTNC;
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

void Administrador::ingresar() {
    system(CLEAR);
    short opc;
    do {
        setborder(120, 30);
        gotoxy((120/2) - (11/2), 2);
        std::cout << RF << "TaskMaster v01" <<RTNC;
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
                insertar(ultimo(), nuevaTarea, 1);
                gotoxy(50, 15);
                std::cout << VB << "Tarea agregada con exito..." <<RTNC; pausa();
                opc = 0;
            }
            default: break;
        }

    } while (opc != SALIR);
}