#include "vecteur.h"
#include <iostream>

/** \brief Programme principal */
int main()
{
	/**std::cout << "[Test] Vecteur::Vecteur" << std::endl;
	Vecteur* v1 = new Vecteur();

	std::cout << "[Test] Vecteur::Vecteur(int)" << std::endl;
	Vecteur* v2 = new Vecteur(3);

	std::cout << "[Test] Vecteur::Vecteur(int, float)" << std::endl;
	Vecteur* v3 = new Vecteur(5, 11.5f);

	std::cout << "[Test] Vecteur::get(int)" << std::endl;
	std::cout << v3->get(2) << std::endl;

	std::cout << "[Test] Vecteur::set(int, float)" << std::endl;
	v3->set(3, 99.9f);
	std::cout << v3->get(3) << std::endl;

	std::cout << "[Test] Vecteur::dimension" << std::endl;
	std::cout << v3->dimension() << std::endl;

	std::cout << "================================================================" << std::endl;
	Vecteur* vect = lireVecteur();
	afficherVecteur(vect);

	std::cout << "================================================================" << std::endl;
	std::cout << "Modification d'une valeur. Dimension visée : ";
	int target = 0;
	std::cin >> target;

	v3->set(target, 18.647);
	std::cout << "no coredump pls" << std::endl;

	std::cout << "================================================================" << std::endl;
	Vecteur* addTest = new Vecteur(4, 10.0f);
	Vecteur* vec = add(v3, addTest);
	afficherVecteur(vec);**/

	/**Vecteur add1(5, 3.4);
	Vecteur add2(3, 11.6);
	Vecteur sum = add1 + add2 + add1;

	Vecteur mult = add2 * add2;

	std::cout << &sum << std::endl;
	Vecteur write;**/

	Vecteur v1(2, 1);
	Vecteur v2(2, 2);
	Vecteur v3(2, 3);
	std::cout << "Affichage" << std::endl;
	std::cout << "==================================================================" << std::endl;
	std::cout << v1 << std::endl;

	std::cout << "Addition" << std::endl;
	std::cout << "==================================================================" << std::endl;
	Vecteur add = v1 + v2 + v3;
	std::cout << add << std::endl;

	std::cout << "Multiplication" << std::endl;
	std::cout << "==================================================================" << std::endl;
	Vecteur mult = v1 * v2 * v3;
	std::cout << mult << std::endl;

	std::cout << "Lecture" << std::endl;
	std::cout << "==================================================================" << std::endl;
	Vecteur vect;
	std::cin >> vect;
	std::cout << vect << std::endl;

	std::cout << "Operator[]" << std::endl;
	std::cout << "==================================================================" << std::endl;
	std::cout << mult[1] << std::endl;

	//std::cin >> write;

	/**delete v3;
	delete vec;
	delete addTest;
	delete vect;
	delete v2;
	delete v1;**/

  return 0 ;
}
