#pragma once

#include "producteur.h"
#include "counted_ptr.h"

class signal_constant : public producteur
{
private:
    counted_ptr<flot> m_sample;
    double m_val;
public:
    signal_constant(double);
    unsigned int nbSorties() const;
    const counted_ptr<flot>& getSortie(unsigned int) const;
    void calculer();
};
