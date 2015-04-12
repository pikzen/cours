/** \brief Ce fichier doit contenir la déclaration de la classe vecteur
Attention, elle ne doit contenir aucune implémentation de méthode / fonction
*/
#include <math.h>
#include <ostream>
#include <istream>
#include <assert.h>

#ifndef _VECTEUR_H
#define _VECTEUR_H

// Déclaration de la classe vecteur
// constconstconstconstconstconstconstconst
template <typename T>
class Vecteur {
private :
	T* m_values;
	int m_dim;

public :
	Vecteur(const int dim = 3, const T baseVal = T());
	Vecteur(const Vecteur<T>&);
	~Vecteur();

	T get(const int) const;
	void set(const int, const T) const;

	int dimensions() const;

	friend Vecteur<T> operator+(const Vecteur<T>& vec1, const Vecteur<T>& vec2) {
		assert(vec1.dimensions() == vec2.dimensions());

		Vecteur<T> vec(vec1.dimensions());

		T sum;
		for (int i = 0; i < vec1.dimensions(); i++) {
			sum = vec1.get(i) + vec2.get(i);

			vec.set(i, sum);
		}

		return Vecteur<T>(vec);
	};
	friend T operator*(const Vecteur<T>& vec1, const Vecteur<T>& vec2) {
		assert(vec1.dimensions() == vec2.dimensions());

		T sum;
		for (int i = 0; i < vec1.dimensions(); i++)
		{
			sum += vec1.get(i) * vec2.get(i);
		}

		return sum;
	};

	friend std::ostream& operator<<(std::ostream& os, const Vecteur<T>& vec) {
		int dim = vec.dimensions();

		os << "[";
		for (int i = 0; i < dim; i++)
		{
			os << "" << vec.get(i) << ",";
		}
		os << "]" << std::endl;
		return os;
	};
	friend std::istream& operator>>(std::istream& is, Vecteur<T>& vec) {
		T currentVal;

		for (int i = 0; i < vec.dimensions(); i++)
		{
			is >> currentVal;

			vec.set(i, currentVal);
		}
		return is;
	};

	T& operator[](const int position) {
		assert(position < dimensions());

		return m_values[position];
	};
	T const operator[](const int position) const {
		assert(position < dimensions());

		return m_values[position];
	};
	Vecteur<T>& operator=(const Vecteur<T>& copy) {
		if (this == &copy)
			return *this;

		delete[] m_values;

		this->m_dim = copy.dimensions();
		this->m_values = new T[copy.dimensions()];
		for (int i = 0; i < this->m_dim; i++) {
			this->m_values[i] = copy.get(i);
		}
		return *this;
	};
private :
	void init(const int, const T);
};

#endif

