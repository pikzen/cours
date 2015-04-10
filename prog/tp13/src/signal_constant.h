#pragma once

#include "producteur_base.h"
#include "counted_ptr.h"

class signal_constant : public producteur_base
{
private:
    double m_val;
public:
    signal_constant(double);
    void calculer();
};
