#include <iostream>
#include "vecteur.h"

int main(int argc, char** argv)
{
	std::cout << "[ctor] ===========================================" << std::endl;
	Vecteur<float> vec1;
	Vecteur<float> vec2;

	std::cout << "[cin]  ===========================================" << std::endl;
	std::cin >> vec1;
	std::cin >> vec2;

	std::cout << "[cout] ===========================================" << std::endl;
	std::cout << vec1 << std::endl;

	std::cout << "[+]    ===========================================" << std::endl;
	std::cout << vec1 + vec2 << std::endl;

	std::cout << "[*]    ===========================================" << std::endl;
	std::cout << vec1 * vec2 << std::endl;

	std::cout << "[=]    ===========================================" << std::endl;
	vec1 = vec2;
	std::cout << vec1 << std::endl;

	std::cout << "[[]]   ===========================================" << std::endl;
	std::cout << vec1[0] << std::endl;

	std::cout << "[std::string] ====================================" << std::endl;
	Vecteur<std::string> vecStr;
	std::cin >> vecStr;
	std::cout << vecStr + vecStr << std::endl;

	//std::cout << "[crashmoar] ======================================" << std::endl;
	//std::cout << vecStr * vecStr << std::endl;

	std::cout << "[intfloat] =======================================" << std::endl;
	Vecteur<int> vecInt;
	std::cin >> vecInt;

	std::cout << vec1 + vecInt << std::endl;

}