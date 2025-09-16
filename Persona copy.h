//
// Created by Christopher Blanco on 16/9/25.
//

#ifndef PROYECTO_1_BORRADOR_PERSONA_H
#define PROYECTO_1_BORRADOR_PERSONA_H

#include "InterfazPersona.h"
#include "../src/Archivos/json.h"

class Persona final : public InterfazPersona {
private:
    string nombre;
    int id;
    int indicePrioridad;
public:
    explicit Persona(const string& nombre = "", int id = 0, int indicePrioridad = 0);
    ~Persona() override;

    [[nodiscard]] string getNombre() const override;
    void setNombre(const string& newNombre) override;

    [[nodiscard]] int getId() const override;
    void setId(int newId) override;

    [[nodiscard]] int getIndicePrioridad() const override;
    void setIndicePrioridad(int newIndicePrioridad) override;
    /*
    [[nodiscard]] Json::Value toJson() const;
    void fromJson(const Json::Value& obj);
    */
    friend std::ostream & operator<<(std::ostream &os, const Persona &obj) {
        return os
                << "Nombre: " << obj.nombre << "\n"
                << "Id: " << obj.id << "\n"
                << "Indice de prioridad: " << obj.indicePrioridad << "\n";
    }
};

#endif //PROYECTO_1_BORRADOR_PERSONA_H