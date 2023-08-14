#include <iostream>
#include "administrador.h"

using namespace std;

int main () {
    
    Administrador adm_program; short opc;
    adm_program.AltEnter();
    adm_program.inicio();
    while ((opc = adm_program.menu()) != 0) { 
        switch (opc) {
            case SALIR: break;
            case INGRESAR: adm_program.ingresar(); break;
            case ELIMINAR: adm_program.eliminar(); break;
            case MODIFICAR: adm_program.enConstruccion(); break;
            case MOSTRAR: adm_program.imprimir(); break;
            default: adm_program.defaultError(); break;
        }
    }
    
    return 0;

}