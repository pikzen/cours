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
    counted_ptr<flot> m_output;
    counted_ptr<flot> m_input;
protected:
    void connecterSortie(const counted_ptr<flot>&, unsigned int);

public:
    volume(double);
    unsigned int nbEntrees() const;
    unsigned int nbSorties() const;
    const counted_ptr<flot>& getSortie(unsigned int) const;
    const counted_ptr<flot>& getEntree(unsigned int) const;

    void connecterEntree(const counted_ptr<flot>&, unsigned int);
    bool yaDesEchantillons() const;

    void calculer();
};
