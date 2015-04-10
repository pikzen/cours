#pragma once

#include "filtre_base.h"
#include "counted_ptr.h"
#include "imp_flot.h"

template <class T>
class operation_binaire : public filtre_base
{
private:
    counted_ptr<flot> m_input[2];
    counted_ptr<flot> m_output;
    T m_op;
protected:
    void connecterSortie(const counted_ptr<flot>& fl , unsigned int out)
    {
        m_output = fl;
    }

public:
    operation_binaire<T>(T op) :
        m_output(new imp_flot),
        m_op(op)
    {

    };
    unsigned int nbEntrees() const
    {
        return 2;
    }
    unsigned int nbSorties() const
    {
        return 1;
    }

    const counted_ptr<flot>& getSortie(unsigned int sortie) const
    {
        return m_output;
    };
    const counted_ptr<flot>& getEntree(unsigned int entree) const
    {
        return m_input[entree];
    }

    void connecterEntree(const counted_ptr<flot>& fl, unsigned int entree)
    {
        m_input[entree] = fl;
    }

    bool yaDesEchantillons() const
    {
        return !(m_input[0]->vide() || m_input[1]->vide());
    }

    void calculer()
    {
        m_output->inserer(m_op(m_input[0]->extraire(), m_input[1]->extraire()));
    }
};
