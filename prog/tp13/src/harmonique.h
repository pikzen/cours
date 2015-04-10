#pragma once

#include "producteur_base.h"
#include "counted_ptr.h"
#include <deque>

class harmonique : public producteur_base
{
private:
	/**
	* Fréquence de l'harmonique
	*/
    double m_freq;

    /**
    * Déphasage de l'harmonique
    * NOTE: je devrais peut-être proposer de le passer en paramètre.
    */
    double m_dephase;

    /**
    * Compteur de samples déjà générés, utilisé pour la génération de l'onde
    */
    int    m_sample_counter;
public:
    harmonique(double);
    virtual ~harmonique() {};
    virtual void calculer();
};
