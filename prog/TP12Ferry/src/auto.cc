#include "auto.h"

Auto::Auto(unsigned int nbp, bool isToutTerrain) :
	Vehicule(2, nbp),
	type(isToutTerrain ? ToutTerrain : Normal)
{
}

Auto::~Auto() {}

double Auto::calculerTarif() const
{
	return (type == Normal ? tarif : tarifToutTerrain) + (this->getPassagers() * tarifPassager);
}

void Auto::afficher(std::ostream& os = std::cout) const
{
	os << *this;
	os << "Voiture " << (type == Normal ? "normale" : "tout-terrains") << std::endl;
}

Auto* Auto::clone() const 
{
	return new Auto(getPassagers(), this->type == ToutTerrain);
}