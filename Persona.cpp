//
// Created by Christopher Blanco on 16/9/25.
//

#include "Persona.h"

Persona::Persona(const string& nombre, const string& tipoPersona, int edad, bool indicePrioridad)
    : InterfazPersona(nombre, tipoPersona, edad, indicePrioridad) {}

Persona::~Persona() = default;

Json::Value Persona::toJson() const {
    Json::Value obj;
    obj["nombre"] = nombre;
    obj["tipoPersona"] = tipoPersona;
    obj["edad"] = edad;
    obj["indicePrioridad"] = indicePrioridad;
    return obj;
}

void Persona::fromJson(const Json::Value& obj) {
    nombre = obj["nombre"].asString();
    tipoPersona = obj["tipoPersona"].asString();
    edad = obj["edad"].asInt();
    indicePrioridad = obj["indicePrioridad"].asBool();
}
