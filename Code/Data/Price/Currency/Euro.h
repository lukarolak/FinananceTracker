#pragma once

class Euro
{
public:
	bool SetAmount(const unsigned int Euro, const unsigned int Cent);
private:
	bool ValidateAmount(const unsigned int Euro, const unsigned int Cent) const;

	unsigned int m_Euro = 0;
	unsigned int m_Cent = 0;
};