#pragma once
#include "filtre_base.h"
#include "signal_constant.h"
#include "multiplicateur.h"
#include "counted_ptr.h"
#include "flot.h"

class volume : public filtre_base
{
private:
    multiplicateur m_mul;
    signal_constant m_vol;
public:
    volume(double);
    void calculer();
};
