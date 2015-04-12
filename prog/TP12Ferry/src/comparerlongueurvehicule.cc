#include "comparerlongueurvehicule.h"

ComparerLongueurVehicule::ComparerLongueurVehicule(bool asc) :
	m_ascending(asc)
{
}

bool ComparerLongueurVehicule::operator () (const Vehicule* first, const Vehicule* second) const
{
	if (m_ascending)
		return first->getLongueur() < second->getLongueur();
	else
		return first->getLongueur() > second->getLongueur();
}