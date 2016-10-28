/*
 * matrix_utils.hpp
 *
 *  Created on: Oct 26, 2016
 *      Author: michal
 */

#ifndef MATRIX_MATRIX_UTILS_HPP_
#define MATRIX_MATRIX_UTILS_HPP_

#include "matrix_eye.hpp"

namespace mlib
{


/**
 * @brief Check if the matrix A is identity
 *
 * @param [in] Matrix A with nxn size
 *
 * @return true - if A matrix is identity
 *         false - if A matrix is not identity
 */
template<typename T, std::size_t n>
bool isIdentity(const Matrix<T, n, n>& A)
{
  const auto identity{ eye<unsigned int, n>() };
  const auto uiA { static_cast<Matrix<unsigned int, n, n>>(A) };
  return (uiA == identity);
}


/**
 * @ Compare two matrices with the same size, specific error
 * @param [in] Matrix A ixj
 * @param [in] Matrix B ixj
 * @param [in] error
 *
 * return true if compare, otherwise false
 */
template<typename T, std::size_t i, std::size_t j>
bool compare(const Matrix<T, i, j>& A, const Matrix<T, i, j>& B, T epsilon)
{
  auto Err = fill<T, i, j>(epsilon);
  return abs(A - B) < Err;
}


} /* namespace mlib */


#endif /* MATRIX_MATRIX_UTILS_HPP_ */
