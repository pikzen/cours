#include "harmonique.h"
#include "constantes.h"
#include "imp_flot.h"
#include <stdio.h>
#include <iostream>
#include <math.h>

harmonique::harmonique(double freq) :
    m_output(new imp_flot),
    m_freq(freq),
    m_dephase(0),
    m_sample_counter(0)
{

}

unsigned int harmonique::nbSorties() const
{
    return 1;
}

const counted_ptr<flot>& harmonique::getSortie(unsigned int sortie) const
{
    //assert (sortie < 1);

    return m_output;
}

void harmonique::calculer()
{
    double harm = sin((double)m_sample_counter / MixageSonore::frequency * 2 * MixageSonore::pi * m_freq + m_dephase);
    m_sample_counter++;

    m_output->inserer(harm);
}

void harmonique::connecterSortie(const counted_ptr<flot>& out, unsigned int sortie)
{
    m_output = out;
}
