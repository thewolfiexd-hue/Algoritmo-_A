#pragma once
class Solucion {
private:
	const Heuristica* heuristica;
	int nodosExpandidos;
public:
	explicit Solucion(const Heuristica* heuristicaUsada);
	void cambiarHeuristica(const Heuristica* nueva);
	int obtNodosEx()const;// obtener nodos expandidos
	bool resolver(const& inicio, const Estado& meta, Pila<int>& camino, int limiteNodos = 1000000);
	int sugMovi(const Estado& actual, const Estado& meta);
};