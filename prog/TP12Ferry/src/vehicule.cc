#include <iostream>
#include "vehicule.h"

//------------------------------------------------------------------------
// classe Vehicule
//------------------------------------------------------------------------

// constructeur
Vehicule::Vehicule(unsigned int lg, unsigned int nbp) :
	longueur(lg),
	passagers(nbp)
{

}

// destructeur
Vehicule::~Vehicule() {}

// longueur d'un véhicule
unsigned int Vehicule::getLongueur() const
{
	return this->longueur;
}

// nombre de personnes dans le véhicule
unsigned int Vehicule::getPassagers() const
{
	return this->passagers;
}

// opérateur d'affichage
std::ostream& operator<< (std::ostream& sortie, const Vehicule& v)
{
	sortie << "Vehicule [" << v.getLongueur() << " unités, " << v.getPassagers() << " passagers]" << std::endl;
	return sortie;
}