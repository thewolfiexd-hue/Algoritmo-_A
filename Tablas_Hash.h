#pragma once
// se usa para buscar rapidamente si un estado o una clave ya fue registrada
class TablaHash {
private:
	struct Nodo {
		long clave;
		int valor;
		Nodo* sig;
	};
	Nodo** cubetas; //arreglo de listas enlazadaas
	int numCubetas;
	int indiceDe(long clave) const; //funcion de hash
	static int sigPrimo(int n);
	void redistribuir(int nuvNumCubetas);
public: 
	explicit TablaHash(int cubetasInici = 1009);
	~TablaHash();
	TablaHash(const TablaHash&) = delete;
	TablasHash& operator=(const TablaHash&) = delete;
	bool obtener(long clave, int& valor) const;//busca la clave
	void poner(long clave, int valor);//insertar la clave
	bool eliminar(long clave);
	int tamano() const { return numElementos; }
	int numCubetas()const { return numCubetas; }
	double factorCarga()const { return static_cast<double>(numElem) / numCubetas; }
};