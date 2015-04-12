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
Vecteur::Vecteur(const int dim, const float baseVal) :
	m_values(new float[dim]),
	m_dim(dim)
{
	assert(dim > 0);
	for (int i = 0; i < dim; i++)	m_values[i] = baseVal;
}

Vecteur::Vecteur(const Vecteur& copy)
{
	this->m_values = new float[copy.dimensions()];
	this->m_dim = copy.dimensions();
	for (int i = 0; i < copy.dimensions(); i++) {
		m_values[i] = copy.get(i);
	}
}

Vecteur::~Vecteur()
{
	if (m_values != NULL && m_values != 0) {
		delete[] m_values;
	}
}

// Vecteur::get(int)
// ====================================================================
// Récupère la valeur à la dimension coord
float Vecteur::get(const int coord) const
{
	assert(coord < m_dim);
	return m_values[coord];
}

// Vecteur::set(int, float)
// ====================================================================
// Définit la valeur à la dimension coord comme étant val
void Vecteur::set(const int coord, const float val) const
{
	assert(coord < m_dim);
	this->m_values[coord] = val;
}

// Vecteur::dimension()
// ====================================================================
// Renvoie la dimension de ce vecteur
int Vecteur::dimensions() const
{
	return this->m_dim;
}

void afficherVecteur(const Vecteur* v)
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

Vecteur* lireVecteur()
{
	int dim = 0;
	float currentVal = 0.0f;

	std::cin >> dim;

	Vecteur* v = new Vecteur(dim);
	for (int i = 0; i < dim; i++)
	{
		std::cin >> currentVal;

		v->set(i, currentVal);
	}

	return v;
}

Vecteur add(const Vecteur* v1, const Vecteur* v2) {
	assert(v1->dimensions() == v2->dimensions());

	Vecteur vec(v1->dimensions());
	for (int i = 0; i < v1->dimensions() && i < v2->dimensions(); i++) {
		vec.set(i, v1->get(i) + v2->get(i));
	}

	return Vecteur(vec);
}

Vecteur operator+(const Vecteur& vec1, const Vecteur &vec2) {
	assert(vec1.dimensions() == vec2.dimensions());

	Vecteur vec(vec1.dimensions());

	float sum = 0.0f;
	for (int i = 0; i < vec1.dimensions(); i++) {
		sum = vec1.get(i) + vec2.get(i);

		vec.set(i, sum);
	}

	return Vecteur(vec);
}
float operator*(const Vecteur& vec1, const Vecteur& vec2)
{
	assert(vec1.dimensions() == vec2.dimensions());

	float sum = 0.0f;
	for (int i = 0; i < vec1.dimensions(); i++)
	{
		sum += vec1.get(i) * vec2.get(i);
	}

	return sum;
}

Vecteur& Vecteur::operator=(const Vecteur& copy)
{
	if (this == &copy)
		return *this;

	this->m_dim = copy.dimensions();
	this->m_values = new float[copy.dimensions()];
	for (int i = 0; i < this->m_dim; i++) {
		this->m_values[i] = copy.get(i);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Vecteur& vec)
{
	os << "Affichage du vecteur:" << std::endl;
	os << "		Dimensions: " << vec.dimensions() << std::endl;
	os << "		Valeurs: " << std::endl;
	int dim = vec.dimensions();

	for (int i = 0; i < dim; i++)
	{
		os << "			" << vec.get(i) << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream& is, Vecteur& vec)
{
	int dim = 0;
	float currentVal = 0.0f;

	for (int i = 0; i < vec.dimensions(); i++)
	{
		is >> currentVal;

		vec.set(i, currentVal);
	}
	return is;
}

float& Vecteur::operator[](const int position) {
	assert(position < dimensions());

	return m_values[position];
}

float const Vecteur::operator[](int const position) const {
	assert(position < dimensions());

	return m_values[position];
}
