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

class Estado{
private:
	int celdas[9];
	int contarInv() const;//contar inversiones
public:
	Estado();
	explicit Estado(const int valores[9]);
	int obtenerCelda(int indice) const;
	int posicionDe(int valor) const;//el indice de donde esta el valor del 1,2,3,etc.
	int posicionVacio() const;
	bool moverFicha(int indiceFicha);
	void intercambiarCeldas(int a, int b);
	bool esIgual(const Estado& otro) const;
	bool esAlcanzableH(const Estado& meta) const;//solo llega a otro si amos tiene las mismas paridad de inversiones
	long codificar() const;
	static Estado aleatorio(const Estado& base, int pasos);
};