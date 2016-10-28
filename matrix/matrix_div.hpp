/*
 * matrix_div.hpp
 *
 *  Created on: Oct 27, 2016
 *      Author: michal
 */

#ifndef MATRIX_MATRIX_DIV_HPP_
#define MATRIX_MATRIX_DIV_HPP_

#include "matrix_type.hpp"

namespace mlib
{


 /**
 * @brief Divide matrix and scalar
 *
 * @param [in] Matrix A with i, j size
 * @param [in] Scalar data with the same type as matrix A
 *
 * @return Result of divide each element of A matrix and scalar data
 */
template<typename T, std::size_t n, std::size_t m>
static Matrix<T, n, m> div(const Matrix<T, n, m>& A, const T scalar)
{
  if(scalar == 0)
    throw;

  Matrix<T, n, m> prod{};

  for(std::size_t i = 0; i < n; i++)
  {
    for(std::size_t j = 0; j < m; j++)
    {
      prod[i][j] = A[i][j] / scalar;
    }
  }
  return prod;
}


/**
 * @brief Overloaded '/' operator for divide matrix and scalar
 *
 * @param [in] Matrix A ixj
 * @param [in] Scalar data
 *
 * @retirn Result of divide matrix A and scalar
 */
template<typename T,  std::size_t i, std::size_t j>
Matrix<T, i, j> operator/(const Matrix<T, i, j>& A, T scalar)
{
  return div(A, scalar);
}


} /* namespace mlib */

#endif /* MATRIX_MATRIX_DIV_HPP_ */
