#include <mtl/mtl2lapack.h>
#include <iostream>


namespace {
namespace local {

typedef double value_type;
typedef mtl::dense2D<value_type, mtl::rectangle<>, mtl::dense<>, mtl::column_major>::type matrix_type;
typedef mtl::dense1D<mtl::complex<value_type> > vector_type;

void print_matrix(const matrix_type &mat)
{
	for (matrix_type::const_iterator i = mat.begin(); i != mat.end(); ++i)
	{
		std::cout << '\t';
		for (matrix_type::OneD::const_iterator j = (*i).begin(); j != (*i).end(); ++j)
			std::cout << *j << ", ";
		std::cout << std::endl;
	}
/*
	const matrix_type::size_type nrow = mat.nrows();
	for (int i = 0; i < nrow; ++i)
	{
		std::cout << '\t';
		const mtl::rows_type<matrix_type>::type row = rows(mat);
		double ab = rows(mat)[0];
		//for (mtl::rows_type<matrix_type>::type::const_iterator it = row.begin(); it != row.end(); ++it)
		//	std::cout << *it << ", ";
		//mtl::rows_type<matrix_type>::type::size_type aa = mtl::max_index(row);
		//for (int j = 0; j < mtl::max_index(row); ++j)
		//	std::cout << row[j] << ", ";
		std::cout << std::endl;
	}
*/
}

}  // namespace local
}  // unnamed namespace

namespace my_mtl {

}  // namespace my_mtl

int mtl_main(int argc, char *argv[])
{
	const int dim = 2;
	local::matrix_type mat(dim, dim);
	mat(0, 0) = 1;
	mat(0, 1) = 4;
	mat(1, 0) = 9;
	mat(1, 1) = 1;

	std::cout << "mat:" << std::endl;
	local::print_matrix(mat);

	local::matrix_type eigvec_l(dim, dim), eigvec_r(dim, dim);
	local::vector_type eigval(dim);
	const int ret = mtl2lapack::geev(mtl2lapack::GEEV_CALC_BOTH, mat, eigval, eigvec_l, eigvec_r);

	std::cout << "right eigenvector:" << std::endl;
	local::print_matrix(eigvec_r);
	std::cout << "left eigenvector:" << std::endl;
	local::print_matrix(eigvec_l);

	return 0;
}
