#include "Euro.h"

bool Euro::SetAmount(const unsigned int Euro, const unsigned int Cent)
{
	bool sucess = false;
	if (ValidateAmount(Euro, Cent))
	{
		m_Euro = Euro;
		m_Cent = Cent;
		sucess = true;
	}
	return sucess;
}

bool Euro::ValidateAmount(const unsigned int Euro, const unsigned int Cent) const
{
	return Cent < 100;
}
