#pragma once

#include "filtre_base.h"
#include "counted_ptr.h"
#include "imp_flot.h"

/**
* Représente une opération binaire générique, fait pout être utilisé avec des
* functors (std::plus, etc.)
*/
template <class T>
class operation_binaire : public filtre_base
{
private:
    /**
    * Opération à appliquer
    */
    T m_op;
public:
    /**
    * Construit une opération binaire
    * applique T aux deux entrées et le renvoei sur la sortie
    */
    operation_binaire<T>() :
        filtre_base(2, 1),
        m_op(T())
    {
    };
    virtual void calculer();
};

/**
* Calcule la prochaine valeur en appliquant le foncteur
*/
template<typename T>
void operation_binaire<T>::calculer()
{
    m_output[0]->inserer(m_op(m_input[0]->extraire(), m_input[1]->extraire()));
}
