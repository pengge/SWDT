#include "stdafx.h"
#include <iostream>

#ifdef _DEBUG
#define IL_DEBUG
#endif  // _DEBUG

#define ILUT_USE_OPENGL
#include <IL/config.h>
#include <IL/il.h>
#include <IL/ilu.h>
#include <IL/ilut.h>


void handleDevILErrors()
{
	ILenum error = ilGetError();
	
	if (IL_NO_ERROR != error)
	{
		do
		{
#if defined(UNICODE) || defined(_UNICODE)
			std::wcout << L'\t' << iluErrorString(error) << std::endl;
#else
			std::cout << '\t' << iluErrorString(error) << std::endl;
#endif
		} while (error = ilGetError());

		//exit(1);
	}
}


int wmain()
{
	void basic_operation();

	try
	{
		basic_operation();

		handleDevILErrors();
	}
	catch (const std::exception &e)
	{
		std::cout << "std::exception occurred: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "unknown exception occurred: " << std::endl;
	}

	std::cout << "press any key to exit ..." << std::endl;
	std::cin.get();
	return 0;
}
