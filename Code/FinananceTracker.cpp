#include <Tests/Tests.h>
#include <Error/Error.h>
int main()
{
	bool testSucess = RunAllTests();
	if (testSucess == false)
		AssertNoCrash("Tests Failed");
}