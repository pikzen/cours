#include "bus.h"

Bus::Bus(unsigned int lg, unsigned int nbp) :
	Vehicule(lg, nbp)
{

}

Bus* Bus::clone() const
{
	return new Bus(this->getLongueur(), this->getPassagers());
}

Bus::~Bus() {}

double Bus::calculerTarif() const
{
	return tarif + tarifLongueur * this->getLongueur();
}

void Bus::afficher(std::ostream& os = std::cout) const
{
	os << *this;
	os << "Bus" << std::endl;
}

