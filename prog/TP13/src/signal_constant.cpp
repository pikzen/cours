#include "signal_constant.h"
#include "imp_flot.h"

signal_constant::signal_constant(double note):
	m_num_sorties(1),
	m_sortie(new imp_flot()),
	m_note(note)

{

}

unsigned int signal_constant::nbSorties() const
{
	return m_num_sorties;
}

const counted_ptr<flot>& signal_constant::getSortie(unsigned int idx) const
{
	assert(idx < m_num_sorties && idx > 0);

	return m_sortie;
}

void signal_constant::calculer()
{
	m_sortie->inserer(this->m_note);
}