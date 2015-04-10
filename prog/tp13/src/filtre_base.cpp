#include "filtre_base.h"

/**
* Filtre de base (à la fois producteur et consommateur)
*/
filtre_base::filtre_base(unsigned int in, unsigned int out) :
	producteur_base(out),
	consommateur_base(in)
{
}