#include "imp_flot.h"
#include <assert.h>

imp_flot::imp_flot()
{

}

void imp_flot::inserer(double sample)
{
    m_samples.push_back(sample);
}

double imp_flot::extraire()
{
    assert( !vide() );
    double val = m_samples.front();
    m_samples.pop_front();

    return val;
}

bool imp_flot::vide() const
{
    return m_samples.size() == 0;
}
