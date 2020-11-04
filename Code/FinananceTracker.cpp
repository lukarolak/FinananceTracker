#include <Tests/Tests.h>
#include <Error/Error.h>
#include <Helper/PathOfExe.h>
#include <UserInfo/UserInfo.h>
#include <Data/Time/DateTime.h>
int wmain(int argc, wchar_t** argv)
{
	if (argc >= 1)
		GetExePathInstance().InitExePath(argv[0]);

	{
		auto UserInfoPath = GetExePathInstance().GetExePath();
		UserInfoPath.append(L"\\..\\..\\Data\\UserInfo\\UserInfo.json");
		GetUserInfo().Initialize(UserInfoPath);
	}

	bool testSucess = RunAllTests();
	if (testSucess == false)
		AssertNoCrash("Tests Failed");
}