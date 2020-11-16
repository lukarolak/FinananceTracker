#pragma once
#include <optional>
#include <string>
#include <FetchDataFromWeb/AuthorizationToken.h>
#include <rapidjson/document.h>
#include <httplib/httplib.h>
class PayPal
{
public:
	PayPal();
	void GetPayments();
	void Initialize();
private:
	std::optional<rapidjson::Document> GetPayments(const DateTime& StartDate, const DateTime& EndDate);
	void InitializePayPalClient();

	class PayPalAuthorizationTicket : public AuthorizationToken
	{
	public:
		virtual ~PayPalAuthorizationTicket() = default;
	private:
		const std::optional<PayPal::PayPalAuthorizationTicket::AuthorizationTokenData> GetAuthorizationToken() const override;
	};
	PayPalAuthorizationTicket m_AuthorizationTicket;

	httplib::Client m_PayPalClient;
};