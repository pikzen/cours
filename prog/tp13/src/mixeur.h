#include "filtre_compose.h"

class mixeur : public filtre_compose
{
public:
	mixeur(unsigned int, double[]);
	virtual ~mixeur() {};
};