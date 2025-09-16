//
// Created by Christopher Blanco on 16/9/25.
//

#include <utility>

#include "../includes/Persona.h"

Persona::Persona(const string& nombre, int id, int indicePrioridad)
    : InterfazPersona(nombre, id, indicePrioridad) {}

Persona::~Persona() = default;

string Persona::getNombre() const { return this->nombre; }
void Persona::setNombre(const string& newNombre) { this->nombre = newNombre; }

int Persona::getId() const { return this->id; }
void Persona::setId(int newId) { this->id = newId; }

int Persona::getIndicePrioridad() const { return this->indicePrioridad; }
void Persona::setIndicePrioridad(int newIndicePrioridad) { this->indicePrioridad = newIndicePrioridad; }

