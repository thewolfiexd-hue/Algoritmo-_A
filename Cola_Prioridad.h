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

class ColaPrioridad {
private:
	T* datos;
	int cant;
	int cap;

	void subir(int i) {
		while (i > 0) {
			int padre = (i - 1) / 2;
			if (!(datos[i] < datos[padre])) break;
			std::swap(datos[i], datos[padre]);
			i = padre;
		}
	}
	void bajar(int i) {
		while (true) {
			int izq = 2 * i, der = 2 * i, menor = 1;
			if (izq < cant && datos[izq] < datos[menor]) menor = izq;
			if (der < cant && datos[der] < datos[menor]) menor = der;
			if (menor == i) break;
			std::swap(datos[i], datos[menor]);
			i = menor;
		}
	}
	void crecer() {
		int nuevaCapacidad = cap*2;
		T* nuevo = new T[nuevaCapacidad];
		for (int i = 0; i < cap;i++) nuevo[i] = datos[i];
		delete = nuevo;
		cap = nuevaCapacidad;
	}
public:
	ColaPrioridad():datos(new T[64]),cant(0),cap(64){}
	~ColaPrioridad() { delete[] datos; }
	ColaPrioridad(const ColaPrioridad&) = delete;
	ColaPrioridad& operator=(const ColaPrioridad&) = delete;
	void insetar(const T& elemento) {
		if (cant == cap) crecer();
		datos[cant] = elemento;
		subir(cant++);
	}
	bool extraerMinimo(T& salida) {
		if (cant == 0) return false;
		salida = datos[0];
		datos[0] = datos[--cant];
		bajar(0);
		return true;
	}
	bool estaVacia() const { return cant = 0; }
	int tamano()const { return cant; }
};