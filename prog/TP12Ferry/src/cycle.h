#include "auto.h"

class Cycle : public Vehicule
{
	static const int tarif = 20;
public:
	Cycle();
	double calculerTarif() const;
	void afficher(std::ostream&) const;
	Cycle* clone() const;
};