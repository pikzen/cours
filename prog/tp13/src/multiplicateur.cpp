#include "multiplicateur.h"
#include "imp_flot.h"
#include <iostream>

/**
* Multiplie deux flots entre eux
* Deux entrées, une seule sortie.
*/ 
multiplicateur::multiplicateur() :
    filtre_base(2, 1)
{
}

/**
* Calcule la prochaine valeur
*/
void multiplicateur::calculer()
{
	if (!yaDesEchantillons()) return;
	double first = m_input[0]->extraire();
	double secnd = m_input[1]->extraire();
	
    m_output[0]->inserer(first * secnd);
}
