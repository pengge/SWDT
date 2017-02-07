//#include "stdafx.h"
#include <iostream>


namespace {
namespace local {

}  // namespace local
}  // unnamed namespace

namespace my_dlib {

void svm_struct_example();
void graph_labeling_example();

}  // namespace my_dlib

int dlib_main(int argc, char *argv[])
{
	// Matrix operation example.
	// REF [file] >> ${DLIB_HOME}/examples/matrix_ex.cpp

	// Structured SVM example.
	my_dlib::svm_struct_example();

	// Graph labeling example.
	my_dlib::graph_labeling_example();

	// Deep learning example.


	return 0;
}
