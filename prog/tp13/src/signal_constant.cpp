#include "signal_constant.h"
#include "imp_flot.h"
#include <assert.h>

signal_constant::signal_constant(double val) :
    producteur_base(1),
    m_val(val)
{

}

void signal_constant::calculer()
{
    m_output[0]->inserer(m_val);
}
