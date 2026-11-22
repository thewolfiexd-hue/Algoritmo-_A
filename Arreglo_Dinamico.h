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

class Arreglo_Dinamico {
private:
	T* datos;
	int cant; //cantidad
	int cap; //capacidad

	void crecer() {
		int nuevaCapacidad = cap * 2;
		T* nuevo = new T[nuevaCapacidad];
		for (int i = 0; i < cant; i++) nuevo[i] = datos[i];
		delete[] datos;
		datos = nuevo;
		cap = nuevaCapacidad;
	}
public:
	Arreglo_Dinamico() :datos(new T[16]), cant(0), cap(16) {}
	~Arreglo_Dinamico() { delete[] datos; }
	Arreglo_Dinamico(const Arreglo_Dinamico&) = delete;//para evitar copias superficiales
	Arreglo_Dinamico& operator=(const Arreglo_Dinamico&) = delete;
	void agregar(const T& elemento) {
		if (cant == cap) crecer();
		datos[cant++] = elemento;
	}
	T& operator[](int indice) {
		if (indice < 0 || indice >= cant) {
			throw std::out_of_range("Indice fuera de rango");
		}
		return datos[indice];
	}
	const T& operator[](int indice)const {
		if (indice < 0 || indice >= cant) {
			throw std::out_of_range("Indice fuera de rango");
		}
		return datos[indice];
	}
	int tamano() const { return cant; }
	void vaciar() { cant = 0; }
};