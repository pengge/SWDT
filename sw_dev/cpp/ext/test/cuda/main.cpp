#include <cuda_runtime.h>
#include <iostream>


#if defined(__cplusplus)
extern "C" {
#endif

//__global__ void HelloWorld();
__global__ void HelloWorld()
{
	std::cout << "Hello World!" << std::endl;
}

int main(int argc, char **argv)
{
	try
	{
		HelloWorld();
	}
	catch (const std::exception &e)
	{
		std::cout << "std::exception occurred !!!: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "unknown exception occurred !!!" << std::endl;
	}

	std::cout << "press any key to exit ..." << std::endl;
	std::cin.get();

    return 0;
}

#if defined(__cplusplus)
}  // extern "C"
#endif
