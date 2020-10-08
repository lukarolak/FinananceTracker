#pragma once

template<class Currency>
class Price
{
public:
	void SetCurrency(const Currency& CurrencyIn);
private:
	Currency m_Currency;
};
