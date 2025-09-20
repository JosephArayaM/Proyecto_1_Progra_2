//
// Created by Christopher Blanco on 16/9/25.
//

#include "../../includes/Persona/Persona.h"

Persona::Persona(const string& nombre, bool indicePrioridad)
    : InterfazPersona(nombre, indicePrioridad) {}

Persona::~Persona() = default;

Json::Value Persona::toJson() const {
    Json::Value obj;
    obj["nombre"] = nombre;
    obj["indicePrioridad"] = indicePrioridad;
    return obj;
}

void Persona::fromJson(const Json::Value& obj) {
    nombre = obj["nombre"].asString();
    indicePrioridad = obj["indicePrioridad"].asBool();
}