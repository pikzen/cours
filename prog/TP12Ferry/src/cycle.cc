#include "cycle.h"

Cycle::Cycle() :
	Vehicule(1, 1)
{
}

double Cycle::calculerTarif() const 
{
	return tarif + tarifPassager;
}

void Cycle::afficher(std::ostream& os) const
{
	os << *this;
	os << "Cycle" << std::endl;
}

Cycle* Cycle::clone() const
{
	return new Cycle();
}