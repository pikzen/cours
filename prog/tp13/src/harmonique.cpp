#include "harmonique.h"
#include "constantes.h"
#include "imp_flot.h"
#include <stdio.h>
#include <iostream>
#include <math.h>

harmonique::harmonique(double freq) :
    producteur_base(1),
    m_freq(freq),
    m_dephase(0),
    m_sample_counter(0)
{

}

void harmonique::calculer()
{
    double harm = sin((double)m_sample_counter / MixageSonore::frequency * 2 * MixageSonore::pi * m_freq + m_dephase);
    m_sample_counter++;

    m_output[0]->inserer(harm);
}
