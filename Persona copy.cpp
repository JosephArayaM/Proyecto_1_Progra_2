//
// Created by Christopher Blanco on 16/9/25.
//

#include "../includes/Persona/Persona.h"

Persona::Persona(const string& nombre, int id, int indicePrioridad)
         : nombre(nombre), id(id), indicePrioridad(indicePrioridad) {}

Persona::~Persona() = default;

string Persona::getNombre() const { return nombre; }
void Persona::setNombre(const string& newNombre) { nombre = newNombre; }

int Persona::getId() const { return id; }
void Persona::setId(int newId) { id = newId; }

int Persona::getIndicePrioridad() const { return indicePrioridad; }
void Persona::setIndicePrioridad(int newIndicePrioridad) {indicePrioridad = newIndicePrioridad; }
/*
Json::Value Persona::toJson() const {
    Json::Value obj;
    obj["nombre"] = nombre;
    obj["id"] = id;
    obj["indicePrioridad"] = indicePrioridad;
    return obj;
}
void Persona::fromJson(const Json::Value& obj) {
    nombre = obj["nombre"].asString();
    id = obj["id"].asInt();
    indicePrioridad = obj["indicePrioridad"].asInt();
}
*/