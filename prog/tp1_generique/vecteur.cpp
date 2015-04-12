/** \brief Ce fichier doit contenir l'ensemble des implémentations
relatives à la classe vecteur et aux fonctionnalités la concernant */

#include <cassert>
#include <iostream>
#include "vecteur.h"
#include "math.h"

// Vecteur::Vecteur(int, float)
// ===================================================================
// Construit un Vecteur de dimension dim avec pour valeur de base pour
// chaque élément baseVal
template <typename T>
Vecteur<T>::Vecteur(const int dim, const T baseVal) :
		m_values(new T[dim]),
		m_dim(dim)
{
	assert(dim > 0);
	for (int i = 0; i < dim; i++)	m_values[i] = baseVal;
}

template <typename T>
Vecteur<T>::Vecteur(const Vecteur<T>& copy)
{
	this->m_values = new T[copy.dimensions()];
	this->m_dim = copy.dimensions();
	for (int i = 0; i < copy.dimensions(); i++) {
		m_values[i] = copy.get(i);
	}
}

template <typename T>
Vecteur<T>::~Vecteur()
{
	if (m_values != NULL && m_values != 0) {
		delete[] m_values;
	}
}

// Vecteur::get(int)
// ====================================================================
// Récupère la valeur à la dimension coord
template <typename T>
T Vecteur<T>::get(const int coord) const
{
	assert(coord < m_dim);
	return m_values[coord];
}

// Vecteur::set(int, float)
// ====================================================================
// Définit la valeur à la dimension coord comme étant val
template <typename T>
void Vecteur<T>::set(const int coord, const T val) const
{
	assert(coord < m_dim);
	this->m_values[coord] = val;
}

// Vecteur::dimension()
// ====================================================================
// Renvoie la dimension de ce vecteur
template <typename T>
int Vecteur<T>::dimensions() const
{
	return this->m_dim;
}

template <typename T>
void afficherVecteur(const Vecteur<T>* v)
{
	std::cout << "Affichage du vecteur:" << std::endl;
	std::cout << "		Dimension: " << v->dimensions() << std::endl;
	std::cout << "		Valeurs: " << std::endl;
	int dim = v->dimensions();

	for (int i = 0; i < dim; i++)
	{
		std::cout << "			" << v->get(i) << std::endl;
	}
	std::cout << std::endl;
}
template class Vecteur<int>;
template class Vecteur<std::string>;
template class Vecteur<float>;