/**
 * @file matrix_sub.hpp
 *
 * @date Oct 26, 2016
 *
 * @author Michal Kielan
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#ifndef MATRIX_SUB_HPP_
#define MATRIX_SUB_HPP_

#include "matrix_type.hpp"

namespace mlib
{


/**
 * @brief Substraction of two matrices
 *
 * @param [in] Matrix A with i, j size
 * @param [in] Matrix B with i, j size
 *
 * @return Result of substraction matrix A and B
 */
template<typename T,  std::size_t i, std::size_t j>
static Matrix<T, i, j> sub(const Matrix<T, i, j>& A, const Matrix<T, i, j>& B)
{
  Matrix<T, i, j> sub{};

  for(std::size_t it = 0; it < i; it++)
  {
    for(std::size_t jt = 0; jt < j; jt++)
    {
      sub[it][jt] = A[it][jt] - B[it][jt];
    }
  }
  return sub;
}


/**
 * @brief Substraction matrix and scalar
 *
 * @param [in] Matrix A with i, j size
 * @param [in] Scalar data with the same type as matrix A
 *
 * @return Result of substraction each element of A matrix and scalar data
 */
template<typename T, std::size_t i, std::size_t j>
static Matrix<T, i, j> sub(const Matrix<T, i, j>& A, const T scalar)
{
  Matrix<T, i, j> sub{};

  for(std::size_t it = 0; it < i; it++)
  {
    for(std::size_t jt = 0; jt < j; jt++)
    {
      sub[it][jt] = A[it][jt] - scalar;
    }
  }
  return sub;
}


/**
 * @brief Overloaded '-' operator for substraction two matrices
 *
 * @param [in] Matrix A ixj
 * @param [in] Matrix B ixj
 *
 * @return Result of substraction matrix A and B
 */
template<typename T, std::size_t i, std::size_t j>
Matrix<T, i, j> operator-(const Matrix<T, i, j>& A, const Matrix<T, i, j>& B)
{
  return sub(A, B);
}


/**
 * @brief Overloaded '-' operator for substraction matrix and scalar
 *
 * @param [in] Matrix A ixj
 * @param [in] Scalar data
 *
 * @return Result of substraction matrix A and scalar data
 */
template<typename T,  std::size_t i, std::size_t j>
Matrix<T, i, j> operator-(const Matrix<T, i, j>& A, const T scalar)
{
  return sub(A, scalar);
}


/* 
 * @brief Overloaded '--' operator for substraction of 
 * matrix and scalar value of '1'
 *
 * @param [in] Matrix A ixj
 *
 * @return Result of substraction matrix A and scalar of value 1
 */
template<typename T, std::size_t i, std::size_t j>
Matrix<T, i, j> operator--(const Matrix<T, i, j>& A, int)
{
  return (A - static_cast<T>(1));
}


} /* namespace mlib */

#endif /* MATRIX_SUB_HPP_ */
