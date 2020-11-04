#include <UserInfo/UserInfo.h>
void UsernamePassword::SetUsername(const std::string& Username)
{
	switch (m_state)
	{
	case UsernamePassword::State::invalid:
		m_state = UsernamePassword::State::username_Set;
		break;
	case UsernamePassword::State::password_Set:
		m_state = UsernamePassword::State::valid;
		break;
	default:
		AssertNoCrash("Unexpected state");
		break;
	}

	m_Username = Username;
}

void UsernamePassword::SetPassword(const std::string& Password)
{
	switch (m_state)
	{
	case UsernamePassword::State::invalid:
		m_state = UsernamePassword::State::password_Set;
		break;
	case UsernamePassword::State::username_Set:
		m_state = UsernamePassword::State::valid;
		break;
	default:
		AssertNoCrash("Unexpected state");
		break;
	}

	m_Password = Password;
}

bool UsernamePassword::GetIsValid() const
{
	return m_state == State::valid;
}

const std::string& UsernamePassword::GetUsername() const
{
	return m_Username;
}

const std::string& UsernamePassword::GetPassword() const
{
	return m_Password;
}

void UserInfo::ReadUserInfo(const rapidjson::Document& UserInfo)
{
	const auto& version = UserInfo["Version"];
	switch (version.GetInt())
	{
	case 1:
		ReadUserInfoV1(UserInfo);
		break;
	default:
		AssertNoCrash("UserInfo version not implemented");
		return;
	}
}

void UserInfo::ReadUserInfoV1(const rapidjson::Document& UserInfo)
{
	if (UserInfo.HasMember("PayPal"))
	{
		const auto& payPalInfo = UserInfo["PayPal"];
		const auto& setFlag = payPalInfo["IsSet"];

		if (setFlag.GetBool() == true)
		{
			const auto& username = payPalInfo["Username"];
			m_PayPal.SetUsername(username.GetString());

			const auto& password = payPalInfo["Password"];
			m_PayPal.SetPassword(password.GetString());
		}
	}
}

const UsernamePassword& UserInfo::GetPayPalUserInfo() const
{
	return m_PayPal;
}

rapidjson::Document UserInfo::GetUserInfoInJson()
{
	rapidjson::Document userInfo;
	auto& allocator = userInfo.GetAllocator();
	userInfo.SetObject();
	userInfo.AddMember("Version", m_version, allocator);

	rapidjson::Value object(rapidjson::Type::kObjectType);
	object.AddMember("IsSet", m_PayPal.GetIsValid(), allocator);
	object.AddMember("Username", m_PayPal.GetUsername(), allocator);
	object.AddMember("Password", m_PayPal.GetPassword(), allocator);

	userInfo.AddMember("PayPal", object, allocator);

	return userInfo;
}

UserInfo g_UserInfo;

UserInfo& GetUserInfo()
{
	return g_UserInfo;
}
