#include "Interface.h"

Interface::Interface(int argc, char* argv[]) : mode(0)
{
	argList.insert(std::pair<Arg, std::string>(PROGNAME, argv[0]));
	
	if (argc < 2) throw Excep("\n Too few arguments!");

	std::string arg;
	for (int i = 1; i < argc; i++)
	{
		arg = argv[i];
		if (arg == "-h")
		{
			argList.insert(std::pair<Arg, std::string>(HELP, "true"));
			continue;
		}

		if (arg == "-f")
		{
			argList.insert(std::pair<Arg, std::string>(NAMEFILE, argv[++i]));
			continue;
		}

		if (arg == "-m")
		{
			argList.insert(std::pair<Arg, std::string>(MODE, argv[++i]));
			continue;
		}

		if (arg == "-w")
		{
			argList.insert(std::pair<Arg, std::string>(WORD, argv[++i]));
			continue;
		}
	}
}

int Interface::argProcessing()
{
	if (argList[HELP] == "true")
	{
		help();
		return 0;

	} else if (argList[MODE] == "count") {

		mode = new Mode(argList[NAMEFILE]);
		std::cout << "\n Number of occurrences of the word \"" << argList[WORD]
			<< "\" - " << mode->count(argList[WORD]) << std::endl;
		delete mode;
		return 0;

	} else if (argList[MODE] == "checksum") {

		mode = new Mode(argList[NAMEFILE]);
		std::cout << "\n File checksum - " << mode->checksum() << std::endl;
		delete mode;
		return 0;

	} else {

		throw Excep("\n Unrecognized command!");
	}
}

void Interface::help()
{
	std::cout << 
		"\n The console program \"apptest\" has the following parameters:\n"
		"\t-f <text file name>;\n"
		"\t-m <application mode>;\n"
		"\t-w <word>;\n"
		"\t-h - call help;\n\n"

		" There are two modes:\n"
		"\t-count - counts the number of occurrences of the word in the file;\n"
		"\t-checksum - considers the checksum of the file;\n\n"

		" Example of using the program:\n"
		"\tapptest.exe -h\n"
		"\tapptest.exe -f file.txt -m count -w append\n"
		"\tapptest.exe -f file.txt -m checksum\n";
}