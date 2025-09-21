//
// Created by Christopher Blanco on 16/9/25.
//

#include "Persona.h"
#include "Lista.h"
#include "ArchivosJSON.h"

int main() {
    auto* p1 = new Persona("chris", "mujer embarazada", 21, true);

    auto* l1 = new Lista<InterfazPersona*>();
    auto* l2 = new Lista<InterfazPersona*>();

    l1->agregarNodo(p1);
    ArchivosJSON::save("PersonaTEST.json", l1);

    cout << *l1 << endl;
    cout << *l2 << endl;

    ArchivosJSON::load("PersonaTEST.json", l2);

    cout << *l2 << endl;

    delete l1;
    delete l2;
    return 0;
}
