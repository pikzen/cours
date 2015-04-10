#include "filtre_base.h"

filtre_base::filtre_base(unsigned int in, unsigned int out) :
	producteur_base(out),
	consommateur_base(in)
{
}