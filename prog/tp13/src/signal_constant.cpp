#include "signal_constant.h"
#include "imp_flot.h"
#include <assert.h>
#include <iostream>

/**
* Représente un signal constant (compris entre -1 et 1)
*/
signal_constant::signal_constant(double val) :
    producteur_base(1),
    m_val(val)
{
	assert (val >= -1 && val <= 1);
}

/**
* Calcule la prochaine valeur (toujours la même)
*/
void signal_constant::calculer()
{
    m_output[0]->inserer(m_val);
}
