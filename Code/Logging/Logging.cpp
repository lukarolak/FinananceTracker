#include <Logging/Logging.h>

Logging g_LoggingInstance;

Logging::~Logging()
{
	if (myfile.is_open())
	{
		myfile.close();
	}
}

Logging& Logging::GetInstance()
{
	return g_LoggingInstance;
}

void Logging::OpenStream()
{
	std::wstring logPath = GetExePathInstance().GetExePath();
	logPath.append(L"\\..\\..\\Logs\\Log.txt");
	myfile.open(logPath);
}
