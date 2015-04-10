#include "consommateur_base.h"
#include "imp_flot.h"

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

unsigned int consommateur_base::nbEntrees() const
{
	return m_max_input;
}

const counted_ptr<flot>& consommateur_base::getEntree(unsigned int nbOut) const
{
	assert(nbOut < m_max_input);
	return m_input[nbOut];
}

void consommateur_base::connecterEntree(const counted_ptr<flot>& fl, unsigned int nbIn)
{
	assert (nbIn < m_max_input);
	m_input[nbIn] = fl;
}

bool consommateur_base::yaDesEchantillons() const
{
	for (unsigned int i = 0; i < m_max_input; i++)
	{
		if (m_input[i]->vide()) return false;
	}

	return true;
}