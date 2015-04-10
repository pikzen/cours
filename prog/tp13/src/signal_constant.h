#pragma once

#include "producteur_base.h"
#include "counted_ptr.h"

class signal_constant : public producteur_base
{
private:
	/**
	* Valeur à renvoyer à chaque fois.
	*/
    double m_val;
public:
    signal_constant(double);
    virtual ~signal_constant() {};
    virtual void calculer();
};
