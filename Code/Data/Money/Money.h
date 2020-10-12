#pragma once

class Money
{
public:
	void SetMoney(const Money& MoneyIn);
	void SetMoney(const int MoneyIn);
	int GetMoney() const;
private:
	int m_Amount = 0;
};