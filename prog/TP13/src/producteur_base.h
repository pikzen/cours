#include "producteur.h"
#include "counted_ptr.h"
#include "flot.h"

class producteur_base : public producteur
{
private:
	counted_ptr<flot> m_sortie;
public:
	producteur_base();
	unsigned int nbSorties();
	const counted_ptr<flot>& getSortie(unsigned int);
};