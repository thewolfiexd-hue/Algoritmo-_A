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
template<typename T>

class Lista_Ligada {
private:
	struct Nodo {
		T dato;
		Nodo* sig; //siguiente
		explicit Nodo(const T& d):dato(d),sig(nullptr){}
	};
	Nodo* cabeza;
	Nodo* cola;
	int cant;
public:
	Lista_Ligada():cabeza(nullptr),cola(nullptr),cant(0){}
	~Lista_Ligada() { vaciar(); }
	Lista_Ligada(const Lista_Ligada&) = delete;
	Lista_Ligada& operator=(const Lista_Ligada&) = delete;

	void agregar(const T& dato) {
		Nodo* nuevo = new Nodo(dato);
		if (cola == nullptr) cabeza = cola = nuevo;
		else { 
			cola->sig = nuevo;
			cola = nuevo;
		}
		cant++;
	}
	T* obtener(int indice) {
		if (indice < 0 || indice >= cant) {
			throw std::out_of_range("Indice fuera de rango");
		}
		Nodo* actual = cabeza;
		for (int i = 0;i < indice; i++) actual = actual->sig;
		return actual->dato;
	}
	const T& obtener(int indice)const {
		if (indice < 0 || indice >= cant) {
			throw std::out_of_range("Indice fuera de rango");
		}
		const Nodo* actual = cabeza;
		for (int i = 0;i < indice;i++) actual = actual->sig;
		return actual->dato;
	}
	int tamano()const { return cant; }
	void vaciar() {
		while (cabeza != nullptr) {
			Nodo* temporal = cabeza;
			cabeza = cabeza->sig;
			delete temporal;
		}
		cola = nullptr;
		cant = 0;
	}
	void ordenar(bool(*precede)(const T&, const T&)) {
		cabeza = ordenarNodos(cabeza, precede);
		cola = cabeza;
		while (cola != nullptr && cola->sig != nullptr) {
			cola = cola->sig;
		}

	}
private:
	static Nodo* mezclar(Nodo* a, Nodo* b, bool(*precede)(const T&, const T&)) {
		Nodo* resultado = nullptr;
		Nodo** ultimo = &resultado;
		while (a != nullptr && b != nullptr) {
			if (precede(b->dato, a->dato)) { 
				*ultimo = b;
				b = b->sig;
			}
			else {
				*ultimo = a;
				a = a->sig;
			}
			ultimo = &(*ultimo)->sig;
		}
		*ultimo = (a != nullptr) ? a : b;
		resultado;
	}
	static Nodo* ordenarNodos(Nodo* inicio, bool(*precede)(const T&, const T&)) {
		if (inicio == nullptr || inicio->sig == nullptr) return inicio;
		Nodo* lento = inicio;
		Nodo* rapido = inicio->sig;
		while (rapido != nullptr && rapido->sig != nullptr) {
			lento = lento->sig;
			rapido = rapido->sig->sig;
		}
		Nodo* segundaMitad = lento->sig;
		lento->sig = nullptr;
		return mezclar(ordenarNodos(inicio, precede), ordenarNodos(segundaMitad, precede), precede);
	}
};