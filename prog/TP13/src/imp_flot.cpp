#include "imp_flot.h"
#include <assert.h>

imp_flot::imp_flot()
{	
}

void imp_flot::inserer(double echantillon)
{
	m_buffer.push_back(echantillon);
}

double imp_flot::extraire()
{
	assert (!vide());
	double cpy = m_buffer.front();
	m_buffer.pop_front();

	return cpy;
}

bool imp_flot::vide() const
{
	return m_buffer.size() == 0;
}