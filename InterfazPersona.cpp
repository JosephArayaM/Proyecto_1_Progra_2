//
// Created by Christopher Blanco on 17/9/25.
//

#include "InterfazPersona.h"

InterfazPersona::InterfazPersona(const string& nombre, bool indicePrioridad)
            : nombre(nombre), indicePrioridad(indicePrioridad) {}

InterfazPersona::~InterfazPersona() = default;

[[nodiscard]] string InterfazPersona::getNombre() const { return nombre; }
void InterfazPersona::setNombre(const string& newNombre) { this->nombre = newNombre; }

[[nodiscard]] bool InterfazPersona::getIndicePrioridad() const { return indicePrioridad; }
void InterfazPersona::setIndicePrioridad(bool newIndicePrioridad) { this->indicePrioridad = newIndicePrioridad; }

Json::Value InterfazPersona::toJson() const {
    Json::Value obj;
    obj["nombre"] = nombre;
    obj["indicePrioridad"] = indicePrioridad;
    return obj;
}

void InterfazPersona::fromJson(const Json::Value& obj) {
    nombre = obj["nombre"].asString();
    indicePrioridad = obj["indicePrioridad"].asBool();
}
