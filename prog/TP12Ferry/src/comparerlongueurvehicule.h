#pragma once
#include "vehicule.h"
#include "tcomparator.h"

class ComparerLongueurVehicule : public TComparator
{
private:
	bool m_ascending;
public:	
	ComparerLongueurVehicule(bool asc);
	bool operator () (const Vehicule* first, const Vehicule* second) const;
};