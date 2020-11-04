#pragma once
#include <fstream>
#include <Helper/PathOfExe.h>

class Logging
{
public:
	~Logging();

	template <typename MsgType>
	void Log(MsgType Msg)
	{
		if (Logging::myfile.is_open() == false)
			OpenStream();

		if (Logging::myfile.is_open())
		{
			Logging::myfile << Msg << std::endl;
		}
	}
	static Logging& GetInstance();
private:
	std::ofstream myfile;
	void OpenStream();
};

template <typename MsgType>
void Log(MsgType Msg)
{
	Logging::GetInstance().Log(Msg);
}

