#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include<allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
#include <sstream>
#include <exception>
#include<stdexcept>
#include<memory>
#include<utility>
#include<cstdlib>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<ctime>
#include <stdexcept>
template <typename T>
class Pila {
private:
    struct Nodo {
        T dato;
        Nodo* abajo;
        Nodo(const T& d, Nodo* a) : dato(d), abajo(a) {}
    };
    Nodo* cima;
    int cantidad;
public:
    Pila() : cima(nullptr), cantidad(0) {}
    ~Pila() { vaciar(); }
    Pila(const Pila&) = delete;
    Pila& operator=(const Pila&) = delete;
    void apilar(const T& elemento) { cima = new Nodo(elemento, cima); cantidad++; }
    bool desapilar(T& salida) {
        if (cima == nullptr) return false;
        Nodo* temporal = cima;
        salida = temporal->dato;
        cima = cima->abajo;
        delete temporal;
        cantidad--;
        return true;
    }
    bool estaVacia() const { return cima == nullptr; }
    int tamano() const { return cantidad; }
    void vaciar() { T descarte; while (desapilar(descarte)) {} }
};
