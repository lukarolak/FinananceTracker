#pragma once
#include <string>
#include <optional>

class ExePath
{
public:
	void InitExePath(const wchar_t* arg);
	const std::wstring& GetExePath();
private:
	std::wstring exePath;
};

ExePath& GetExePathInstance();