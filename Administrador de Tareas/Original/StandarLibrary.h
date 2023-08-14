#ifndef STANDARLIBRARY_H_INCLUDED
#define STANDARLIBRARY_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <time.h>

/* Pausa del programa portable */

void pausa () {

    std::cin.clear();
    std::cin.sync();
    std::cin.ignore();

}

/* Alternativa portable de system("CLS") */

void limpiarPantalla () {

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

    system (CLEAR);

}

/* Alternativa portable a fflush */

void limpiaBuffer (void) {

    int c;

    do {

        c = getchar();

    } while (c != '\n' && c != EOF);

}

/* Gotoxy */

void gotoxy (int x,int y) {

    printf("%c[%d;%df",0x1B,y,x);

}


/* Marco del programa(Cuadrado) */

void setborder (int columaTam, int filaTam) {

    int columnaX, FilaY;

    for (columnaX = 1; columnaX <= columaTam; columnaX++) {
            
        gotoxy(columnaX, 0);
        putchar('*');
        gotoxy(columnaX, filaTam);
        putchar('*');

    }

    for (FilaY = 1; FilaY <= filaTam; FilaY++) {
            
        gotoxy(0, FilaY);
        putchar('*');
        gotoxy(columaTam, FilaY);
        putchar('*');

    }

}

#endif // STANDARLIBRARY_H_INCLUDED