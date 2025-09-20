//
// Created by Christopher Blanco on 17/9/25.
//

#ifndef PROYECTO_1_TEST_LISTA_H
#define PROYECTO_1_TEST_LISTA_H

#include "Nodo.h"
template<typename Tipo>

class Lista {
private:
    Nodo<Tipo>* primero;
    Nodo<Tipo>* ultimo;
public:
    Lista() : primero(nullptr), ultimo(nullptr) {}
    virtual ~Lista() {
        Nodo<Tipo>* temp = primero;

        while (temp!= nullptr) {
            Nodo<Tipo>* aux = temp->getNext();

            delete temp;
            temp = aux;
        }
    }

    Nodo<Tipo>* getPrimero() { return this->primero; }
    void setPrimero(Nodo<Tipo>* newPrimero) { this->primero = newPrimero; }

    Nodo<Tipo>* getUltimo() { return this->ultimo; }
    void setUltimo(Nodo<Tipo>* newUltimo) { this->ultimo = newUltimo; }

    void agregarNodo(Tipo obj) {
        auto* nodo = new Nodo<Tipo>(obj);

        if (primero == nullptr) {
            primero = nodo;
            ultimo = nodo;
        }
        else {
            ultimo->setNext(nodo);
            nodo->setAnterior(ultimo);
            ultimo = nodo;
        }
    }

    void eliminarUltimoNodo() {
        if (primero == nullptr) {
            throw runtime_error("Lista vacia.");
        }
        Nodo<Tipo>* aux = ultimo->getAnterior();

        delete ultimo;
        ultimo = aux;

        if (ultimo != nullptr) {
            ultimo->setNext(nullptr);
        } else {
            primero = nullptr;
        }
    }

    friend std::ostream & operator<<(std::ostream& os, Lista& obj) {
        Nodo<Tipo>* aux = obj.getPrimero();

        if (aux == nullptr) {
            return os << "Lista vacia.";
        }

        while (aux != nullptr) {
            if constexpr (std::is_pointer_v<Tipo>) {
                if (aux->getCampoInfo())
                    os << *aux->getCampoInfo() << endl;
                else
                    os << "NULL" << endl;
            } else {
                os << aux->getCampoInfo() << endl;
            }

            os << "-->" << endl;
            aux = aux->getNext();
        }
        os << "NULL" << endl;

        return os;
    }
};

#endif //PROYECTO_1_TEST_LISTA_H