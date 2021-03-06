//#include "stdafx.h"
#include <yaml-cpp/yaml.h>
#include <iostream>


namespace {
namespace local {

}  // namespace local
}  // unnamed namespace

namespace my_yaml_cpp {

#if 0
// for the old APIs
void basic_parsing();
void basic_emitting();
#else
void configuration_example();
void example_0_5();
#endif

}  // namespace my_yaml_cpp

int yaml_cpp_main(int argc, char *argv[])
{
	try
	{
#if 0
		// for the old APIs
		my_yaml_cpp::basic_parsing();
		my_yaml_cpp::basic_emitting();
#else
		my_yaml_cpp::configuration_example();
		my_yaml_cpp::example_0_5();
#endif
	}
	catch (const YAML::RepresentationException &e)
	{
		std::cout << "YAML::RepresentationException caught: " << e.what() << std::endl;
		return 1;
	}
	catch (const YAML::ParserException &e)
	{
		std::cout << "YAML::ParserException caught: " << e.what() << std::endl;
		return 1;
	}
	catch (const YAML::EmitterException &e)
	{
		std::cout << "YAML::EmitterException caught: " << e.what() << std::endl;
		return 1;
	}
	catch (const YAML::Exception &e)
	{
		std::cout << "YAML::Exception caught: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
