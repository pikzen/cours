#pragma once

#include "consommateur.h"
#include "counted_ptr.h"
#include "flot.h"
#include <vector>

class consommateur_base : virtual public consommateur
{
protected:
	/**
	* Nombre d'entrées sur ce consommateur
	*/
	unsigned int m_max_input;

	/**
	* Liste des entrées
	*/
	std::vector<counted_ptr<flot> > m_input;
public:
    consommateur_base(unsigned int);
    virtual ~consommateur_base() {};
    virtual unsigned int nbEntrees() const;
    virtual const counted_ptr<flot>& getEntree(unsigned int) const;
    virtual void connecterEntree(const counted_ptr<flot>&, unsigned int);
    virtual bool yaDesEchantillons() const;
};
