#include "comparerpassagersvehicule.h"

ComparerPassagersVehicule::ComparerPassagersVehicule(bool asc) :
	m_ascending(asc)
{
}

bool ComparerPassagersVehicule::operator () (const Vehicule* first, const Vehicule* second) const
{
	if (m_ascending)
		return first->getPassagers() < second->getPassagers();
	else
		return first->getPassagers() > second->getPassagers();
}