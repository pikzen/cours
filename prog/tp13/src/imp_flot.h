#pragma once

#include "flot.h"
#include <deque>

class imp_flot: public flot
{
private:
    std::deque<double> m_samples;

public:
    imp_flot();
    void inserer(double);
    double extraire();
    bool vide() const;
};
