#include "producteur_base.h"

class harmonique : public producteur_base 
{
private:
	unsigned int m_frequency;
	double m_dephasage;
	counted_ptr<flot> m_sortie;
	unsigned int m_sample;
public:
	harmonique(unsigned int, double);
	unsigned int nbSorties();
	const counted_ptr<flot>& getSortie(unsigned int) const;
};