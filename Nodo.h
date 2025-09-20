//
// Created by Christopher Blanco on 17/9/25.
//

#ifndef PROYECTO_1_TEST_NODO_H
#define PROYECTO_1_TEST_NODO_H

template<typename Tipo>
class Nodo {
private:
    Tipo campoInfo;
    Nodo* next;
    Nodo* anterior;
public:
    explicit Nodo(const Tipo& obj) : campoInfo(obj), next(nullptr), anterior(nullptr) {}
    ~Nodo() = default;

    Tipo getCampoInfo() { return this->campoInfo; }
    void setCampoInfo(Tipo newCampoInfo) { this->campoInfo = newCampoInfo; }

    Nodo* getNext() { return this->next; }
    void setNext(Nodo* newNext) { this->next = newNext; }

    Nodo* getAnterior() { return this->anterior; }
    void setAnterior(Nodo* newAnterior) { this->anterior = newAnterior; }
};

#endif //PROYECTO_1_TEST_NODO_H