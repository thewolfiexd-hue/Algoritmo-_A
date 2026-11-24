
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
class Hamming :public Hamming {
public:
	int calcular(const Estado& actual, const Estado& meta) const override;
	const char* nombre()const override { return"Piezas mal colocadas"; }
};