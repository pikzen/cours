#include "afficher.h"

double plus (double first, double second) {
	afficher("plus  : ", first, second, first + second);
	return first + second;
}

double moins(double first, double second) {
	afficher("moins : ", first, second, first - second);
	return first - second;
} 

double mult (double first, double second) {
	afficher("mult  : ", first, second, first * second);
	return first * second;
} 