#include <iostream>
#include "administrador.h"

using namespace std;

int main () {

    Administrador adm_program; short opc;
    adm_program.inicio();
    while ((opc = adm_program.menu()) != 0) { 
        switch (opc) {
            case SALIR: break;
            case INGRESAR: adm_program.ingresar(); break;
            case ELIMINAR: break;
            case MODIFICAR: break;
            case MOSTRAR: break;
            case 7: adm_program.imprimir(); break;
            default: adm_program.defaultError(); break;
        }
    }
    
    return 0;

}