/*
 * matrix_abs.hpp
 *
 *  Created on: Oct 27, 2016
 *      Author: michal
 */

#ifndef MATRIX_MATRIX_ABS_HPP_
#define MATRIX_MATRIX_ABS_HPP_

#include "matrix_type.hpp"

/**
 * @brief Absolut value of matrix
 *
 * @param [in] Matrix A with ixj size
 *
 * @return Matrix A which is result of absolut each element of matrix
 */
template<typename T, std::size_t i, std::size_t j>
Matrix<T, i, j> abs(const Matrix<T, i, j>& A)
{
  Matrix<T, i, j> absA;
  for (std::size_t it = 0; it < i; it++)
  {
    for (std::size_t jt = 0; jt < j; jt++)
    {
      absA[it][jt] = std::abs(A[it][jt]);
    }
  }
  return absA;
}



#endif /* MATRIX_MATRIX_ABS_HPP_ */
