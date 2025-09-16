//
// Created by Christopher Blanco on 16/9/25.
//

#ifndef PROYECTO_1_TEST_INTERFAZPERSONA_H
#define PROYECTO_1_TEST_INTERFAZPERSONA_H

#include <iostream>
using namespace std;

class InterfazPersona {
protected:
    string nombre;
    int id;
    int indicePrioridad;
public:
    explicit InterfazPersona(const string& nombre = "", int id = 0, int indicePrioridad = 0)
            : nombre(nombre), id(id), indicePrioridad(indicePrioridad) {}

    virtual ~InterfazPersona() = default;

    [[nodiscard]] virtual string getNombre() const = 0;
    virtual void setNombre(const string& newNombre) = 0;

    [[nodiscard]] virtual int getId() const = 0;
    virtual void setId(int newId) = 0;

    [[nodiscard]] virtual int getIndicePrioridad() const = 0;
    virtual void setIndicePrioridad(int newIndicePrioridad) = 0;
};

#endif //PROYECTO_1_TEST_INTERFAZPERSONA_H