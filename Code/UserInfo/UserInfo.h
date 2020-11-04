#pragma once
#include <string>
#include <FileIO/JsonIO.h>
#include <Error/Error.h>

class UsernamePassword
{
public:
	void SetUsername(const std::string& Username);
	void SetPassword(const std::string& Password);
	bool GetIsValid() const;
	const std::string& GetUsername() const;
	const std::string& GetPassword() const;
private:
	enum class State
	{
		invalid,
		username_Set,
		password_Set,
		valid
	};

	State m_state = State::invalid;
	std::string m_Username = "Username";
	std::string m_Password = "Password";
};

class UserInfo
{
public:
	template <typename FilePath>
	void Initialize(const FilePath& FilePathIn);

	const UsernamePassword& GetPayPalUserInfo() const;
private:
	void ReadUserInfo(const rapidjson::Document& UserInfo);
	void ReadUserInfoV1(const rapidjson::Document& UserInfo);

	template <typename FilePath>
	bool CreateUserInfo(const FilePath FilePathIn);

	rapidjson::Document GetUserInfoInJson();

	static constexpr unsigned int m_version = 1;
	UsernamePassword m_PayPal;
};

template<typename FilePath>
inline void UserInfo::Initialize(const FilePath& FilePathIn)
{
	const auto& data_wrapper = ReadJson(FilePathIn);
	if (data_wrapper.has_value())
	{
		ReadUserInfo(data_wrapper.value());
	}
	else
	{
		auto sucess = CreateUserInfo(FilePathIn);
		if (sucess == false)
			AssertNoCrash("Can't create UserInfo");
	}
}

template<typename FilePath>
inline bool UserInfo::CreateUserInfo(const FilePath FilePathIn)
{
	//Can't take a life extension reference of document, therefore I'm doing a copy. I'm not sure why I can't just pass 
	//a GetUserInfoInJson function to the WriteJson function
	auto document = GetUserInfoInJson();
	return WriteJson(FilePathIn, document);
}

UserInfo& GetUserInfo();