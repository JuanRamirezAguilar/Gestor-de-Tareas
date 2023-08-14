#ifndef TAREA_H
#define TAREA_H

#include <iostream>

class Tarea {
    
    private:

        std::string nombre;
        std::string contenido;
        char prioridad;

    public:

	    Tarea();
        Tarea(std::string n, std::string c, char p);
	    ~Tarea() = default;
        /* Metodos Getters y Setters */
        void setNombre(std::string auxString);
        void setContenido(std::string auxString);
        void setPrioridad(char auxPrioridad);
        std::string getNombre();
        std::string getContenido();
        char getPrioridad();

        friend std::ostream& operator << (std::ostream& out, const Tarea& x);
        bool operator == (const Tarea& comparado) const {
            if (nombre == comparado.nombre)
                return true;      
            return false;
        }

};


#endif // TAREA_H
