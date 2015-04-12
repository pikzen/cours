#include "producteur_base.h"
#include "imp_flot.h"

producteur_base::producteur_base() :
	m_sortie(new imp_flot())
{
}

unsigned int producteur_base::nbSorties()
{
	return 1;
}

const counted_ptr<flot>& producteur_base::getSortie(unsigned int idx)
{
	return this->m_sortie;
}