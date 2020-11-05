#include <FetchDataFromWeb/PayPal/PayPal.h>
#include <httplib/httplib.h>
#include <Error/Error.h>
#include <rapidjson/document.h>
#include <UserInfo/UserInfo.h>
#include <Data/Time/DateTime.h>
void PayPal::GetPayments()
{
	httplib::Client client("https://api.paypal.com");

	const auto& token = m_AuthorizationTicket.GetToken();
	if (token.has_value() == false)
	{
		AssertNoCrash("Can't get authorization token");
		return;
	}

	client.set_bearer_token_auth(token.value().c_str());

	Assert("Sadasnji mjesec ima bug");

	auto currentDateTime = DateTime::GetCurrentDateTime();
	
	Time time;
	time.SetTime(0, 0, 0);

	Date date; 
	date.SetDate(currentDateTime.GetDate().GetYear(), currentDateTime.GetDate().GetMonth() - 1, 20);
	DateTime startDate(date, time);

	std::string getRequest = "/v1/reporting/transactions?start_date="+startDate.GetTimeStamp()+"&end_date=" + currentDateTime.GetTimeStamp();
	auto reponse = client.Get(getRequest.c_str());
	if (reponse)
	{
		auto text = reponse->body;
	}
	else
	{
		AssertNoCrash("No response from PayPal API");
	}
}

const std::optional<PayPal::PayPalAuthorizationTicket::AuthorizationTokenData> PayPal::PayPalAuthorizationTicket::GetAuthorizationToken() const
{
	httplib::Client client("https://api.paypal.com");

	const auto& payPalInfo = GetUserInfo().GetPayPalUserInfo();
	if (payPalInfo.GetIsValid() == false)
	{
		AssertNoCrash("PayPal user info not set");
		return {};
	
	}

	const auto& clientID = payPalInfo.GetUsername();
	const auto& secretID = payPalInfo.GetPassword();
	client.set_basic_auth(clientID, secretID);

	const auto& repsponse = client.Post("/v1/oauth2/token", "grant_type=client_credentials", "x-www-form-urlencoded");
	if (repsponse)
	{
		if (repsponse->status != 200)
		{
			AssertNoCrash("Can't obtain authorization token");
			return {};
		}

		rapidjson::Document document;
		document.Parse(repsponse->body.c_str());
		const bool hasAccessToken = document.HasMember("access_token");
		if (hasAccessToken == false)
		{
			AssertNoCrash("Json does not contain \"access_token\"");
			return {};
		}

		const auto& token = document["access_token"];
		if (token.IsString() == false)
		{
			AssertNoCrash("Access_token is of wrong type");
			return {};
		}

		const bool hasExpirationDate = document.HasMember("expires_in");
		if (hasExpirationDate == false)
		{
			AssertNoCrash("Json does not contain \"expires_in\"");
			return {};
		}

		const auto& expirationDate = document["expires_in"];
		if (expirationDate.IsInt() == false)
		{
			AssertNoCrash("expires_in is of wrong type");
			return {};
		}

		PayPal::PayPalAuthorizationTicket::AuthorizationTokenData authorizationToken;
		authorizationToken.m_Token = token.GetString();
		authorizationToken.m_ExpirationDate.SetDateTimeInSeconds(DateTime::GetCurrentDateTime().GetDateTimeInSeconds() + expirationDate.GetInt());

		return authorizationToken;
	}

	return {};
}
