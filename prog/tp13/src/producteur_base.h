#pragma once

#include "producteur.h"
#include "counted_ptr.h"
#include <vector>
#include "flot.h"

class producteur_base : virtual public producteur
{
protected:
	/**
	* Nombre maximal de sorties
	*/
	unsigned int m_max_output;

	/**
	* Liste des sorties
	*/
	std::vector<counted_ptr<flot> > m_output;
public:
	producteur_base(unsigned int);
    virtual ~producteur_base() {}
    virtual unsigned int nbSorties() const;
    virtual const counted_ptr<flot> & getSortie(unsigned int numsortie) const;
    virtual void calculer() = 0;
    virtual void connecterSortie(const counted_ptr<flot>&, unsigned int);
};
