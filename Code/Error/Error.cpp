#include <Error/Error.h>
#include <Logging/Logging.h>
#include <cassert>
#include <Windows.h>
void AssertNoCrash(std::string Msg)
{
	Log(Msg);
#ifdef _DEBUG
	DebugBreak();
#endif // DEBUG
}

void Assert(std::string Msg)
{
	Log(Msg);
	assert(false);
}
