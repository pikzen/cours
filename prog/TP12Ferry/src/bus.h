#pragma once
#include "vehicule.h"

class Bus : public Vehicule
{
	private:
		static const int tarif = 200;
		static const int tarifLongueur = 50;

	public:
		       Bus(unsigned int lg, unsigned int nbp);
		       ~Bus();
		double calculerTarif()         const;
		void   afficher(std::ostream&) const;
		Bus*   clone()                 const;
};