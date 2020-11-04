#pragma once
#include <string>
#include <Data/Time/DateTime.h>
#include <optional>
class AuthorizationToken
{
public:
	const std::optional<std::string> GetToken();
protected:
	class AuthorizationTokenData
	{
	public:
		std::string m_Token;
		DateTime m_ExpirationDate;
	};
private:
	bool GetTokenExpired();
	bool UpdateAuthorizationToken();
	virtual const std::optional<AuthorizationTokenData> GetAuthorizationToken() const = 0;
	AuthorizationTokenData m_Data;
};