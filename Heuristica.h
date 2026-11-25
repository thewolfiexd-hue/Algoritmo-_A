#pragma once
// define el calculo que estima que tan lejos esta el tablero de la meta
class Heuristica{
public:
	virtual ~Heuristica(){}
	virtual int calcular(const Estado& meta) const = 0;
	virtual const char* nombre() const = 0;
};
class Manhattan :public Heuristica {
public: 
	int calcular(const Estado& actual, const Estado& meta) const override;
	const char* nombre() const override { return"Distancia Manhattan"; }
};
class HeuristicaCeo :public Heuristica {
public: 
	int calcular(const Estado&, const Estado&) const override {
		return 0;
	}
	const char* nombre()const override { return "h=0"; }
};
class Hamming :public Heuristica {
public:
	int calcular(const Estado& actual, const Estado& meta) const override;
	const char* nombre()const override { return"Piezas mal colocadas"; }
};