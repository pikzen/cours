/** \brief Ce fichier doit contenir la déclaration de la classe vecteur
    Attention, elle ne doit contenir aucune implémentation de méthode / fonction
*/
#include <math.h>
#include <ostream>
#include <istream>

#ifndef _VECTEUR_H
#define _VECTEUR_H

// Déclaration de la classe vecteur
// constconstconstconstconstconstconstconst
class Vecteur {
private :
	float* m_values;
	int m_dim;

public :
	Vecteur(int dim = 3, float baseVal = 0.0f);
	Vecteur(const Vecteur&);
	~Vecteur();
	float get(const int) const;
	void set(const int, const float) const;
	int dimensions() const;
	friend Vecteur       operator+(const Vecteur&, const Vecteur&);
	friend float         operator*(const Vecteur&, const Vecteur&);
	friend std::ostream& operator<<(std::ostream&, const Vecteur&);
	friend std::istream& operator>>(std::istream&, Vecteur&);
	float&               operator[](const int);
	float const          operator[](const int) const;
	Vecteur&             operator=(const Vecteur&);
private :
  	void init(const int, const float);
};

void afficherVecteur(const Vecteur* v);
Vecteur* lireVecteur();
Vecteur add(const Vecteur*, const Vecteur*);
// ====================================================================
// Operator overloading
// ====================================================================
#endif
