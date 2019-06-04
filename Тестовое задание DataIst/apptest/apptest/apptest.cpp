#include "Mode.h"

void help()
{
	std::cout << "Help\n"
		"-h - help\n -f - file name\n -m - mode\n";
}

int main(int argc, char* argv[])
{
	try 
	{
		Mode* mode = 0;

		std::string arg;
		for (int i = 1; i < argc; i++)
		{
			arg = argv[i];
			if (arg == "-h")
			{
				help();
				return 0;
			}

			if (arg == "-f")
			{
				mode = new Mode(argv[++i]);
				continue;
			}

			if (arg == "-m")
			{
				arg = argv[++i];
				if (arg == "count")
				{
					std::cout << mode->count(argv[i + 2]);
					delete mode;
					return 0;

				} else if (arg == "checksum") {

					std::cout << mode->checksum();
					delete mode;
					return 0;

				} else {

					throw Mode::Excep("No comand!");
				}
			}
		}
	}

	catch (Mode::Excep excep)
	{
		std::cout << excep.error << std::endl;
	}
}