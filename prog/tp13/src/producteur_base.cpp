#include "producteur_base.h"
#include "imp_flot.h"

producteur_base::producteur_base(unsigned int outputs) :
	m_max_output(outputs),
	m_output()
{
	for (unsigned int i = 0; i < m_max_output; i++)
	{
		counted_ptr<flot> ptr(new imp_flot);
		m_output.push_back(ptr);
	}
}

unsigned int producteur_base::nbSorties() const
{
	return m_max_output;
}

const counted_ptr<flot>& producteur_base::getSortie(unsigned int numsortie) const
{
	assert (numsortie < m_max_output);
	return m_output[numsortie];
}

void producteur_base::connecterSortie(const counted_ptr<flot>& fl, unsigned int nbOut)
{
	assert(nbOut < m_max_output);

	m_output[nbOut] = fl;
}