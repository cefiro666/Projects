#include "Interface.h"

int main(int argc, char* argv[])
{
	try 
	{
		Interface interface(argc, argv);
		return interface.argProcessing();
	}

	catch (Excep excep)
	{
		std::cout << excep.error << std::endl;
	}
}