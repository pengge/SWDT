//#include "stdafx.h"
#if defined(WIN32)
#include <vld/vld.h>
#endif
#include <iostream>
#include <stdexcept>
#include <cstdlib>


int main(int argc, char *argv[])
{
	int assimp_main(int argc, char *argv[]);
	int hdf_main(int argc, char *argv[]);
	int csv_parser_main(int argc, char *argv[]);
	
	int retval = EXIT_SUCCESS;
	try
	{
		std::cout << "ASSIMP library-- ----------------------------------------------------" << std::endl;
		//retval = assimp_main(argc, argv);  // not yet implemented.

		std::cout << "\nHDF library ---------------------------------------------------------" << std::endl;
		//retval = hdf_main(argc, argv);  // not yet implemented.

		std::cout << "\nCSV Parser library --------------------------------------------------" << std::endl;
		retval = csv_parser_main(argc, argv);
	}
    catch (const std::bad_alloc &e)
	{
		std::cout << "std::bad_alloc caught: " << e.what() << std::endl;
		retval = EXIT_FAILURE;
	}
	catch (const std::exception &e)
	{
		std::cout << "std::exception caught: " << e.what() << std::endl;
		retval = EXIT_FAILURE;
	}
	catch (...)
	{
		std::cout << "unknown exception caught" << std::endl;
		retval = EXIT_FAILURE;
	}

	std::cout << "press any key to exit ..." << std::endl;
	std::cin.get();

	return retval;
}
