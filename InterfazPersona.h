//
// Created by Christopher Blanco on 16/9/25.
//

#ifndef PROYECTO_1_TEST_INTERFAZPERSONA_H
#define PROYECTO_1_TEST_INTERFAZPERSONA_H

#include "json.h"
#include "Utilidades.h"

class InterfazPersona {
protected:
    string nombre;
    bool indicePrioridad;
public:
    explicit InterfazPersona(const string& nombre = "", bool indicePrioridad = false);
    virtual ~InterfazPersona() = 0;

    [[nodiscard]] virtual string getNombre() const;
    virtual void setNombre(const string& newNombre);

    [[nodiscard]] virtual bool getIndicePrioridad() const;
    virtual void setIndicePrioridad(bool newIndicePrioridad);

    [[nodiscard]] virtual Json::Value toJson() const;
    virtual void fromJson(const Json::Value& obj);

    friend std::ostream & operator<<(std::ostream& os, const InterfazPersona& obj) {
        return os
               << "Nombre: " << obj.nombre << endl
               << "Indice de prioridad: " << obj.indicePrioridad;
    }
};

#endif //PROYECTO_1_TEST_INTERFAZPERSONA_H
