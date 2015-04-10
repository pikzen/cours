#include "signal_constant.h"
#include "imp_flot.h"
#include <assert.h>

signal_constant::signal_constant(double val) :
    m_sample(new imp_flot),
    m_val(val)
{

}

unsigned int signal_constant::nbSorties() const
{
    return 1;
}

const counted_ptr<flot>& signal_constant::getSortie(unsigned int sortie) const
{
    //assert( sortie == 1 );

    return m_sample;
}

void signal_constant::calculer()
{
    m_sample->inserer(m_val);
}
