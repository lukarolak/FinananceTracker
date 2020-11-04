#pragma once
#include <optional>
#include <string>
#include <FetchDataFromWeb/AuthorizationToken.h>

class PayPal
{
public:
	void GetPayments();

private:

	class PayPalAuthorizationTicket : public AuthorizationToken
	{
	public:
		virtual ~PayPalAuthorizationTicket() = default;
	private:
		const std::optional<PayPal::PayPalAuthorizationTicket::AuthorizationTokenData> GetAuthorizationToken() const override;
	};
	PayPalAuthorizationTicket m_AuthorizationTicket;
};