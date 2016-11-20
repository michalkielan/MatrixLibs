/**
 * @file matrix_eye.hpp
 *
 * @date Oct 26, 2016
 *
 * @author Jaroslaw Wiosna
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#ifndef MATRIX_MATRIX_MULT_HPP_
#define MATRIX_MATRIX_MULT_HPP_

namespace mlib
{


/**
 * @brief  Multiplication of two matrices
 *
 * Usage: If sizes of matrix A and B are illegal to multiply,
 *        the function will not compile
 * @param [in] Matrix A with n, m size
 * @param [in] Matrix B with m, p size
 *
 * @return Result of multiplication matrix A and B
 */
template<typename T,  std::size_t n, std::size_t m, std::size_t p>
static Matrix<T, n, p> mult(const Matrix<T, n, m>& A, const Matrix<T, m, p>& B)
{
  auto prod = zeros<T, n, p>();

  for(std::size_t i = 0; i < n; ++i)
  {
    for(std::size_t j = 0; j < p; ++j)
    {
      for(std::size_t k = 0; k < m; ++k)
      {
        prod[i][j] += (A[i][k] * B[k][j]);
      }
    }
  }
  return prod;
}


 /**
 * @brief  Multiplication matrix and scalar
 *
 * @param [in] Matrix A with i, j size
 * @param [in] Scalar data with the same type as matrix A
 *
 * @return Result of multiplication each element of A matrix and scalar data
 */
template<typename T, std::size_t i, std::size_t j>
static Matrix<T, i, j> mult(const Matrix<T, i, j>& A, const T scalar)
{
  Matrix<T, i, j> prod{};

  for(std::size_t it = 0; it < i; it++)
  {
    for(std::size_t jt = 0; jt < j; jt++)
    {
      prod[it][jt] = A[it][jt] * scalar;
    }
  }
  return prod;
}


/**
 * @brief Overloaded '*' operator for multiply two matrices
 *
 * @param [in] Matrix A
 * @param [in] Matrix B
 *
 * @return Result of multiplication matrix A and B
 */
template<typename T,  std::size_t n, std::size_t m, std::size_t p>
Matrix<T, n, p> operator*(const Matrix<T, n, m>& A, const Matrix<T, m, p>& B)
{
  return mult(A, B);
}


/**
 * @brief Overloaded '*' operator for multiply matrix and scalar
 *
 * @param [in] Matrix A ixj
 * @param [in] Scalar data
 *
 * @return Result of substraction matrix A and scalar
 */
template<typename T,  std::size_t i, std::size_t j>
Matrix<T, i, j> operator*(const Matrix<T, i, j>& A, const T scalar)
{
  return mult(A, scalar);
}


/**
 * @brief Overloaded '*' operator for multiply scalar and matrix
 *
 * @param [in] Scalar data
 * @param [in] Matrix A ixj
 *
 * @return Result of substraction scalar and matrix A
 */
template<typename T,  std::size_t i, std::size_t j>
Matrix<T, i, j> operator*(const T scalar, const Matrix<T, i, j>& A)
{
  return mult(A, scalar);
}


} /* namespace mlib */


#endif /* MATRIX_MATRIX_MULT_HPP_ */
