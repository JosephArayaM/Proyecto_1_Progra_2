//
// Created by Christopher Blanco on 16/9/25.
//

#ifndef PROYECTO_1_TEST_PERSONA_H
#define PROYECTO_1_TEST_PERSONA_H

#include <ostream>
#include "InterfazPersona.h"

class Persona final : public InterfazPersona {
public:
    explicit Persona(const string& nombre = "", int id = 0, int indicePrioridadl = 0);
    ~Persona() override;

    [[nodiscard]] string getNombre() const override;
    void setNombre(const string& nombre) override;

    [[nodiscard]] int getId() const override;
    void setId(int newId) override;

    [[nodiscard]] int getIndicePrioridad() const override;
    void setIndicePrioridad(int newIndicePrioridad) override;

    friend std::ostream & operator<<(std::ostream &os, const Persona &obj) {
        return os
                 << "Nombre: " << obj.nombre << "\n"
                 << " Id: " << obj.id << "\n"
                 << " Indice de prioridad: " << obj.indicePrioridad << "\n";
    }
};

#endif //PROYECTO_1_TEST_PERSONA_H