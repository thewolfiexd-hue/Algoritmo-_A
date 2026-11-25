#pragma once
//mantiene datos ordenados en un arbol balaceado
#include<algorithm>
template<typename K, typename V>
class ArbolAVl {
private:
	struct Nodo {
		K clave;
		V valor;
		Nodo* izq;
		Nodo* der;
		int alt;{}
		Nodo(const K& k, const V& v):clave(k),valor(v),izq(nullptr),der(nullptr),alt(1)
	};
	Nodo* raiz;
	int cant;
	static int altura(const Nodo* n) { return n ? n->alt : 0; }
	static int factorEquilibrio(const Nodo* n) { return n ? altura(n->der) - altura(n->izq) : 0; }
	static void actualizarAlt(Nodo* n) { n->alt = 1 + std::max(altura(n->izq), altura(n->der)); }

	static Nodo* rotarIzq(Nodo* x) {
		Nodo* y = x->der;
		x->der = y->izq;
		y->izq = x;
		actualizarAlt(x);
		actualizarAlt(y);
		return y;
	}
	static Nodo* rotarDer(Nodo* y) {
		Nodo* x = y->izq;
		y->izq = x->der;
		x->der = y;
		actualizarAlt(y);
		actualizarAlt(x);
		return x;
	}
	static Nodo* equili(Nodo* n) {
		actualizarAlt(n);
		int b = factorEquilibrio(n);
		if (b > 1) {
			if(factorEquilibrio)
		}
	}
};