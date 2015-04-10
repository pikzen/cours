#include "consommateur_base.h"
#include "imp_flot.h"

/**
* Construit un consommateur avec nbOut sorties
*/ 
consommateur_base::consommateur_base(unsigned int nbOut) : 
	m_max_input(nbOut),
	m_input()
{
	for (unsigned int i = 0; i < nbOut; i++)
	{
		counted_ptr<flot> ptr(new imp_flot);
		m_input.push_back(ptr);
	}
}

/**
* Renvoie le nombre d'entrées de ce consommateur
*/
unsigned int consommateur_base::nbEntrees() const
{
	return m_max_input;
}

/**
* Récupère le flot à l'entrée nbOut
*/
const counted_ptr<flot>& consommateur_base::getEntree(unsigned int nbOut) const
{
	assert(nbOut < m_max_input);
	return m_input[nbOut];
}

/**
* Connecte un flot fl à l'entrée nbIn
*/
void consommateur_base::connecterEntree(const counted_ptr<flot>& fl, unsigned int nbIn)
{
	assert (nbIn < m_max_input);
	m_input[nbIn] = fl;
}

/**
* Le flot possède-t-il des échantillons
*/
bool consommateur_base::yaDesEchantillons() const
{
	for (unsigned int i = 0; i < m_max_input; i++)
	{
		if (m_input[i]->vide()) return false;
	}

	return true;
}