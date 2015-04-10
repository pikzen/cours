#pragma once

#include "filtre.h"
#include "counted_ptr.h"
#include "producteur_base.h"
#include "consommateur_base.h"

class filtre_base : virtual public filtre, public producteur_base, public consommateur_base
{
public:
	filtre_base(unsigned int, unsigned int);
	virtual ~filtre_base() {}
	virtual void calculer() = 0;
};


