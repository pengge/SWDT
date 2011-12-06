#include "stdafx.h"
#include <Eigen/Core>
#include <Eigen/Array>


USING_PART_OF_NAMESPACE_EIGEN

// define a custom template unary functor
template<typename Scalar>
struct CwiseClampOp
{
	CwiseClampOp(const Scalar &inf, const Scalar &sup)
	: m_inf(inf), m_sup(sup)
	{}

	const Scalar operator()(const Scalar &x) const { return x < m_inf ? m_inf : (x > m_sup ? m_sup : x); }

	Scalar m_inf, m_sup;
};

int coefficient_wise_unary_operator(int, char **)
{
	Matrix4d m1 = Matrix4d::Random();
	std::cout << m1 << std::endl << "becomes: " << std::endl << m1.unaryExpr(CwiseClampOp<double>(-0.5, 0.5)) << std::endl;

	return 0;
}
