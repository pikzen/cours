#include "ferry.h"
#include "comparerlongueurvehicule.h"

Ferry::Ferry(unsigned int lg, unsigned int nbp) :
	longueur(0),
	longueurMax(lg),
	personnes(0),
	personnesMax(nbp),
	vehicules(container_t())
{
}

Ferry::~Ferry()
{
	container_t::iterator begin = vehicules.begin();
	while (begin != vehicules.end())
	{
		delete (*begin);
		++begin;
	}

}

bool Ferry::ajouter(const Vehicule* pv)
{
	
	if (longueur + pv->getLongueur()  > longueurMax)
		return false;

	if (personnes + pv->getPassagers() > personnesMax)
		return false;

	vehicules.push_back(pv);
	
	longueur  += pv->getLongueur();
	personnes += pv->getPassagers();

	return true;
}

double Ferry::calculerTarif() const 
{
	double sum = 0.0;
	container_t::const_iterator begin = vehicules.begin();	
	container_t::const_iterator end   = vehicules.end();
	while (begin != vehicules.end())
	{
		sum += (*begin)->calculerTarif();
		++begin;
	}

	return sum;
}

void Ferry::afficher(std::ostream& os) const
{
	os << "Ferry [" << longueurMax << " unités max, " << personnesMax << " personnes max, " << longueur << " longueur, " << personnes << " personnes]" << std::endl;
	os << "Véhicules ======================================" << std::endl;
	container_t::const_iterator begin = vehicules.begin();	
	container_t::const_iterator end   = vehicules.end();
	while (begin != end)
	{
		(*begin)->afficher(os);
		++begin;
	}
}

std::ostream& operator<< (std::ostream& sortie, const Ferry& ferry)
{
	ferry.afficher(sortie);
	return sortie;
}