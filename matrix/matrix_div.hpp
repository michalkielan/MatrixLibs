/**
 * @file matrix_div.hpp
 *
 * @date Oct 27, 2016
 *
 * @author Michal Kielan
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#ifndef MATRIX_MATRIX_DIV_HPP_
#define MATRIX_MATRIX_DIV_HPP_

#include "matrix_inv.hpp"


namespace mlib
{


/**
 * @brief Division matrix and matrix
 *
 * Usage: If sizes of matrix A and B are illegal to division,
 *        the function will not compile
 * @param [in] Matrix A with n, m size
 * @param [in] Matrix B with m, p size
 *
 * @return Result of sum each element of A matrix and scalar data
 */
template<typename T,  std::size_t n, std::size_t m, std::size_t p>
static Matrix<T, n, p> div(const Matrix<T, n, m>& A, const Matrix<T, m, p>& B)
{
  return A * inv(B);
}


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
 * @brief Overloaded '/' operator for divide matrix and matrix
 *
 * Usage: If sizes of matrix A and B are illegal to division,
 *        the function will not compile
 * @param [in] Matrix A with n, m size
 * @param [in] Matrix B with m, p size
 *
 * @return Result of sum each element of A matrix and scalar data
 */
template<typename T,  std::size_t n, std::size_t m, std::size_t p>
Matrix<T, n, p> operator/(const Matrix<T, n, m>& A, const Matrix<T, m, p>& B)
{
  return div(A, B);
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
