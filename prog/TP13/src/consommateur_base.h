#include "consommateur.h"

class consommateur_base : public consommateur
{
public:
	unsigned int nbEntrees();
	const counted_ptr<flot>& getEntree(unsigned int idx) const;
	void connecterEntree(counted_ptr<flot>);
	bool yaDesEchantillons();

}