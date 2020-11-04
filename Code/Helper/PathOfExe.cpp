#include <Helper/PathOfExe.h>
#include <filesystem>
#include <locale>

ExePath ExePathInstance;

ExePath& GetExePathInstance()
{
    return ExePathInstance;
}

void ExePath::InitExePath(const wchar_t* arg)
{
    auto dir = std::filesystem::weakly_canonical(std::filesystem::path(arg)).parent_path();
    exePath = dir.c_str();
}

const std::wstring& ExePath::GetExePath()
{
    return exePath;
}
