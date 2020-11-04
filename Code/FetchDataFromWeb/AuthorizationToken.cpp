#include "AuthorizationToken.h"
#include <Error/Error.h>

const std::optional<std::string> AuthorizationToken::GetToken()
{
	if (GetTokenExpired() == false)
	{
		return m_Data.m_Token;
	}
	else
	{
		const bool sucess = UpdateAuthorizationToken();
		if (sucess)
		{
			return m_Data.m_Token;
		}
		else
		{
			return {};
		}
	}
}

bool AuthorizationToken::GetTokenExpired()
{
	return m_Data.m_ExpirationDate < DateTime::GetCurrentDateTime();
}

bool AuthorizationToken::UpdateAuthorizationToken()
{
	const auto& authorizationToken = GetAuthorizationToken();
	if (authorizationToken.has_value())
	{
		const auto& token = authorizationToken.value();
		m_Data.m_ExpirationDate = token.m_ExpirationDate;
		m_Data.m_Token = token.m_Token;
		return true;
	}
	else
	{
		return false;
	}
}


