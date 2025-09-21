//
// Created by Christopher Blanco on 17/9/25.
//

#include "InterfazPersona.h"

InterfazPersona::InterfazPersona(const string& nombre, const string& tipoPersona, int edad, bool indicePrioridad)
            : nombre(nombre), tipoPersona(tipoPersona), edad(edad), indicePrioridad(indicePrioridad) {}

InterfazPersona::~InterfazPersona() = default;

[[nodiscard]] string InterfazPersona::getNombre() const { return nombre; }
void InterfazPersona::setNombre(const string& newNombre) { this->nombre = newNombre; }

[[nodiscard]] string InterfazPersona::getTipoPersona() const { return tipoPersona; }
void InterfazPersona::setTipoPersona(const string& newTipo) { this->tipoPersona = newTipo; }

[[nodiscard]] int InterfazPersona::getEdad() const { return edad; }
void InterfazPersona::setEdad(int newEdad) { this->edad = newEdad; }

[[nodiscard]] bool InterfazPersona::getIndicePrioridad() const { return indicePrioridad; }
void InterfazPersona::setIndicePrioridad(bool newIndicePrioridad) { this->indicePrioridad = newIndicePrioridad; }

Json::Value InterfazPersona::toJson() const {
    Json::Value obj;
    obj["nombre"] = nombre;
    obj["tipoPersona"] = tipoPersona;
    obj["edad"] = edad;
    obj["indicePrioridad"] = indicePrioridad;
    return obj;
}

void InterfazPersona::fromJson(const Json::Value& obj) {
    nombre = obj["nombre"].asString();
    tipoPersona = obj["tipoPersona"].asString();
    edad = obj["edad"].asInt();
    indicePrioridad = obj["indicePrioridad"].asBool();
}
