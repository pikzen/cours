#pragma once

#include "producteur_base.h"
#include "counted_ptr.h"
#include <deque>

class harmonique : public producteur_base
{
private:
    counted_ptr<flot> m_output;
    double m_freq;
    double m_dephase;
    int    m_sample_counter;
protected:
    void connecterSortie(const counted_ptr<flot>&, unsigned int);
public:
    harmonique(double);
    unsigned int nbSorties() const;
    const counted_ptr<flot>& getSortie(unsigned int) const;
    void calculer();
};
