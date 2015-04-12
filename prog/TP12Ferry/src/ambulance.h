#include "auto.h"

class Ambulance : public Auto
{
public:
	Ambulance(int, bool);
	double calculerTarif() const;
	void afficher(std::ostream&) const;
	Ambulance* clone() const;
};