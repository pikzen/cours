#pragma once

#include "producteur_base.h"
#include "counted_ptr.h"
#include <deque>

class harmonique : public producteur_base
{
private:
    double m_freq;
    double m_dephase;
    int    m_sample_counter;
public:
    harmonique(double);
    void calculer();
};
