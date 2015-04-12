#include "ambulance.h"

Ambulance::Ambulance(int nbp, bool isTT) :
	Auto(nbp, isTT)
{
}

double Ambulance::calculerTarif() const 
{
	return 0.0;
}

void Ambulance::afficher(std::ostream& os) const
{
	os << *this;
	os << "Ambulance" << std::endl;
}

Ambulance* Ambulance::clone() const
{
	return new Ambulance(this->getPassagers(), this->type == ToutTerrain);
}