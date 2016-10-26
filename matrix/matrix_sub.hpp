/*
 * matrix_sub.hpp
 *
 *  Created on: Oct 27, 2016
 *      Author: michal
 */

#ifndef MATRIX_MATRIX_SUB_HPP_
#define MATRIX_MATRIX_SUB_HPP_

#include "matrix_type.hpp"

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


#endif /* MATRIX_MATRIX_SUB_HPP_ */
