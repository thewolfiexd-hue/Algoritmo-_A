#pragma once
/*presenta un tablero sus fichas, movimientos posibles y 
comparación con otro tablero*/
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
	int indiceVecVAcio(int direccion)const;
	bool moverVacio(int direccion);
	bool moverFicha(int indiceFicha);
	void intercambiarCeldas(int a, int b);
	bool esIgual(const Estado& otro) const;
	bool esAlcanzable(const Estado& meta) const;//solo llega a otro si amos tiene las mismas paridad de inversiones
	long codificar() const;
	static Estado aleatorio(const Estado& base, int pasos);
};