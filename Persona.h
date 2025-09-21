//
// Created by Christopher Blanco on 16/9/25.
//

#ifndef PROYECTO_1_TEST_PERSONA_H
#define PROYECTO_1_TEST_PERSONA_H

#include "InterfazPersona.h"
#include "json.h"

class Persona final : public InterfazPersona {
public:
    explicit Persona(const string& nombre = "", const string& tipoPersona = "", int edad = 0, bool indicePrioridad = false);
    ~Persona() override;

    [[nodiscard]] Json::Value toJson() const override;
    void fromJson(const Json::Value& obj) override;

    friend std::ostream & operator<<(std::ostream &os, const Persona& obj) {
        return os
        << "Nombre: " << obj.nombre << "\n"
        << "Tipo de persona: " << obj.tipoPersona << endl
        << "Edad: " << obj.edad << "\n"
        << "Indice de prioridad: " << obj.indicePrioridad << "\n";
    }
};

#endif //PROYECTO_1_TEST_PERSONA_H
