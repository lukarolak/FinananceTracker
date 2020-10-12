#pragma once
#include <string>
#include <Error/Error.h>
#include <Logging/Logging.h>
#include <cassert>

#ifdef _DEBUG
#include <Windows.h>
#endif // DEBUG

template <typename msgType>
void AssertNoCrash(msgType Msg)
{
	Log(Msg);
#ifdef _DEBUG
	DebugBreak();
#endif // DEBUG
}

template <typename msgType>
void Assert(msgType Msg)
{
	Log(Msg);
	assert(false);
}

