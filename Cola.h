#pragma once
// es donde almacena elementos y los entrega en el mismo orden en que se agregaron , como que explora los tableros por niveles
template<typename T>
class Cola {
private:
	struct Nodo {
		T dato;
		Nodo* sig;
		explicit Nodo(const T& d) :dato(d), sig(nullptr) {}
	};
	Nodo* frente;
	Nodo* fin;
	int cant;
public:
	Cola():frente(nullptr),fin(nullptr),cant(0){}
	~Cola() { vaciar(); }
	Cola(const Cola&)=delete;
	Cola& operator=(const Cola&) = delete;
	void encolar(const T& elem) {
		Nodo* nuevo = new Nodo(elem);
		if (fin == nullptr) frente = fin = nuevo;
		else {
			fin->sig = nuevo;
			fin = nuevo;
		}
		cant++;
	}
	bool desencolar(T& salida) {
		if (frente == nullptr) return false;
		Nodo* temporal = frente;
		salida = temporal->dato;
		frente = frente->sig;
		if (frente == nullptr) fin = nullptr;
		delete temporal;
		cant--;
		return true;
	}
	bool estaVacia()const { return frente = nullptr; }
	int tamano()const { return cant; }
	void vaciar() {
		T descarte;
		while(desencolar(descarte)){}
	}
};