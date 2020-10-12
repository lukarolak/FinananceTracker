#include <Tests/Tests.h>
#include <Error/Error.h>
#include <Helper/PathOfExe.h>
int wmain(int argc, wchar_t** argv)
{
	if (argc >= 1)
		GetExePathInstance().InitExePath(argv[0]);

	bool testSucess = RunAllTests();
	if (testSucess == false)
		AssertNoCrash("Tests Failed");
}