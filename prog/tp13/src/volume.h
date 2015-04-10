#pragma once
#include "filtre_base.h"
#include "signal_constant.h"
#include "multiplicateur.h"
#include "counted_ptr.h"
#include "flot.h"

class volume : public filtre_base
{
private:
    /**
    * Multiplicateur permettant d'appliquer le volume
    */
    multiplicateur m_mul;

    /**
    * Facteur de volume (uniquement descendant)
    */
    signal_constant m_vol;
public:
    volume(double);
    virtual ~volume() {};
    virtual void calculer();
    virtual void connecterEntree(const counted_ptr<flot>&, unsigned int);

};
