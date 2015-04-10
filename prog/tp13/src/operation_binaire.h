#pragma once

#include "filtre_base.h"
#include "counted_ptr.h"
#include "imp_flot.h"

template <class T>
class operation_binaire : public filtre_base
{
private:
    T m_op;
public:
    operation_binaire<T>(T op) :
        filtre_base(2, 1),
        m_op(op)
    {
    };

    void calculer()
    {
        m_output[0]->inserer(m_op(m_input[0]->extraire(), m_input[1]->extraire()));
    }
};
