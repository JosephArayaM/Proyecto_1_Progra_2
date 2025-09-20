//
// Created by Christopher Blanco on 20/9/25.
//

#ifndef PROYECTO_1_TEST_ARCHIVOSJSON_H
#define PROYECTO_1_TEST_ARCHIVOSJSON_H

#include "json.h"
#include "../Lista/Lista.h"
#include "../Utilidades.h"
#include "../Persona/Persona.h"

class ArchivosJSON {
public:
    template<class Tipo>
    static void save(const string& filename, Lista<Tipo>* lista) {
        Json::Value arreglo(Json::arrayValue);

        Nodo<Tipo>* temp = lista->getPrimero();
        while (temp != nullptr) {
            const Tipo& obj = temp->getCampoInfo();

            if constexpr (std::is_pointer_v<Tipo>) {
                if (obj != nullptr) {
                    if constexpr (requires { obj->toJson(); }) {
                        arreglo.append(obj->toJson());
                    } else {
                        arreglo.append(*obj);
                    }
                } else {
                    arreglo.append(Json::Value::null);
                }
            } else {
                if constexpr (requires { obj.toJson(); }) {
                    arreglo.append(obj.toJson());
                } else {
                    arreglo.append(obj);
                }
            }
            temp = temp->getNext();
        }

        Json::StreamWriterBuilder builder;
        builder["indentation"] = "   ";
        unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());

        ofstream salida(filename);
        writer->write(arreglo, &salida);
    }

    template<class Tipo>
    static void load(const string& filename, Lista<Tipo>* lista) {
        ifstream entrada(filename);
        if (!entrada.is_open()) {
            throw runtime_error("No se pudo abrir el archivo JSON.");
        }

        Json::Value arreglo;
        Json::CharReaderBuilder builder;
        string errors;
        Json::parseFromStream(builder, entrada, &arreglo, &errors);

        for (auto& item : arreglo) {
            if constexpr (std::is_pointer_v<Tipo>) {
                if (item.isNull()) {
                    lista->agregarNodo(nullptr);
                } else {
                    using ObjectType = std::remove_pointer_t<Tipo>;

                    if constexpr (std::is_same_v<ObjectType, InterfazPersona>) {
                        auto* obj = new Persona();
                        if constexpr (requires { obj->fromJson(item); }) {
                            obj->fromJson(item);
                        }
                        lista->agregarNodo(obj);
                    } else {
                        auto* obj = new ObjectType();
                        if constexpr (requires { obj->fromJson(item); }) {
                            obj->fromJson(item);
                        }
                        lista->agregarNodo(obj);
                    }
                }
            } else {
                if constexpr (requires { declval<Tipo>().fromJson(item); }) {
                    Tipo obj;
                    obj.fromJson(item);
                    lista->agregarNodo(move(obj));
                } else {
                    if constexpr (is_same_v<Tipo, int>) {
                        lista->agregarNodo(item.asInt());
                    } else if constexpr (is_same_v<Tipo, float>) {
                        lista->agregarNodo(item.asFloat());
                    } else if constexpr (is_same_v<Tipo, string>) {
                        lista->agregarNodo(item.asString());
                    } else if constexpr (is_same_v<Tipo, bool>) {
                        lista->agregarNodo(item.asBool());
                    } else if constexpr (is_same_v<Tipo, double>) {
                        lista->agregarNodo(item.asDouble());
                    }
                }
            }
        }
    }
};

#endif //PROYECTO_1_TEST_ARCHIVOSJSON_H