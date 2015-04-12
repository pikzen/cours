#pragma once
#include "vehicule.h"

class Auto : public Vehicule
{
	protected:
		enum Type 
		{
			Normal = 0,
			ToutTerrain = 1
		};

		Type type;
		static const int tarif = 100;
		static const int tarifToutTerrain = 350;

	public:
		       Auto(unsigned int nbp, bool isToutTerrain);
		       Auto(const Auto& copy);
		       ~Auto();
		double calculerTarif()         const;
		void   afficher(std::ostream&) const;
		Auto*  clone()                 const;
};