#pragma once
#include "vehicule.h"
#include "tcomparator.h"

class ComparerPassagersVehicule : public TComparator
{
private:
	bool m_ascending;
public:	
	ComparerPassagersVehicule(bool asc);
	bool operator () (const Vehicule* first, const Vehicule* second) const;
};