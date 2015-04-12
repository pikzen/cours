#include "producteur.h"
#include "flot.h"
#include "counted_ptr.h"

class signal_constant : public producteur
{
private:
	unsigned int           m_num_sorties;
	counted_ptr<flot> m_sortie;
	double                 m_note;
public:
	signal_constant(double note);
	unsigned int nbSorties() const;
	const counted_ptr<flot>& getSortie(unsigned int) const;
	void calculer();
};