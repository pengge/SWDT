//#include "stdafx.h"
#include <iostream>


namespace {
namespace local {

}  // namespace local
}  // unnamed namespace

namespace my_clustering {

void k_medoids();
void kmeanspp();

void spectral_clustering();

}  // namespace my_clustering

int clustering_main(int argc, char *argv[])
{
	// k-means & k-means++
	my_clustering::kmeanspp();

	//my_clustering::k_medoids();  // not yet implemented

	my_clustering::spectral_clustering();

	return 0;
}
