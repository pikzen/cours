#include "harmonique.h"
#include "math.h"
#include "constantes.h"
#include "flot.h"

harmonique::harmonique(unsigned int freq, double dephase) :
	m_frequency(freq),
	m_dephasage(dephase),
	m_sortie(new flot()),
	m_sample(0);
{
}

unsigned int harmonique::nbSorties() 
{
	return 1;
}

const counted_ptr<flot>& harmonique::getSortie(unsigned int idx) const
{
	return m_sortie;
}

void harmonique::calculer() 
{
	m_sortie->inserer(sin((m_sample / frequency * ) * 2 * pi * m_frequency + m_dephasage));
	m_sample++;
}

