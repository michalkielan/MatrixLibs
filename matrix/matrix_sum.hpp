/*
 * matrix_sum.hpp
 *
 *  Created on: Oct 27, 2016
 *      Author: michal
 */

#ifndef MATRIX_MATRIX_SUM_HPP_
#define MATRIX_MATRIX_SUM_HPP_

#include "matrix_type.hpp"

namespace mlib
{


/**
 * @brief Sum of two matrices
 *
 * @param [in] Matrix A with i, j size
 * @param [in] Matrix B with i, j size
 *
 * @return Result of sum matrix A and B
 */
template<typename T,  std::size_t i, std::size_t j>
static Matrix<T, i, j> sum(const Matrix<T, i, j>& A, const Matrix<T, i, j>& B)
{
  Matrix<T, i, j> sum{};

  for(std::size_t it = 0; it < i; it++)
  {
    for(std::size_t jt = 0; jt < j; jt++)
    {
      sum[it][jt] = A[it][jt] + B[it][jt];
    }
  }
  return sum;
}


/**
 * @brief Sum matrix and scalar
 *
 * @param [in] Matrix A with i, j size
 * @param [in] Scalar data with the same type as matrix A
 *
 * @return Result of sum each element of A matrix and scalar data
 */
template<typename T, std::size_t i, std::size_t j>
static Matrix<T, i, j> sum(const Matrix<T, i, j>& A, const T scalar)
{
  Matrix<T, i, j> sum{};

  for(std::size_t it = 0; it < i; it++)
  {
    for(std::size_t jt = 0; jt < j; jt++)
    {
      sum[it][jt] = A[it][jt] + scalar;
    }
  }
  return sum;
}


/**
 * @brief Overloaded '+' operator of sum two matrices
 *
 * @param [in] Matrix A ixj
 * @param [in] Matrix B ixj
 *
 * @return Result of sum matrix A and B
 */
template<typename T, std::size_t i, std::size_t j>
Matrix<T, i, j> operator+(const Matrix<T, i, j>& A, const Matrix<T, i, j>& B)
{
  return sum(A, B);
}


/**
 * @brief Overloaded '+' operator for add matrix and scalar
 *
 * @param [in] Matrix A ixj
 * @param [in] Scalar data
 *
 * @return Result of sum matrix A and scalar
 */
template<typename T,  std::size_t i, std::size_t j>
Matrix<T, i, j> operator+(const Matrix<T, i, j>& A, const T scalar)
{
  return sum(A, scalar);
}


/**
 * @brief Overloaded '+' operator for add scalar and matrix
 *
 * @param [in] Scalar data
 * @param [in] Matrix A ixj
 *
 * @return Result of sum scalar and matrix A
 */
template<typename T,  std::size_t i, std::size_t j>
Matrix<T, i, j> operator+(const T scalar, const Matrix<T, i, j>& A)
{
  return sum(A, scalar);
}


/* EXPERIMENTAL
 * TODO Doxygen comments
 */
template<typename T, std::size_t i, std::size_t j>
Matrix<T, i, j> operator++(const Matrix<T, i, j>& A, int)
{
  return (A + static_cast<T>(1));
}


} /* namespace mlib */

#endif /* MATRIX_MATRIX_SUM_HPP_ */
