/*
 * matrix_conv2.hpp
 *
 *  Created on: Oct 26, 2016
 *      Author: michal
 */

#ifndef MATRIX_MATRIX_CONV2_HPP_
#define MATRIX_MATRIX_CONV2_HPP_

#include "matrix_type.hpp"

namespace mlib
{


/**
 * @brief Convolution in two dimensions using kernel of size 3x3
 *         It works as conv2 in Octave with 'same' parameter
 *
 * @param [in] Matrix A ixj
 * @param [in] Matrix kenel 3x3
 *
 * @todo TODO Allow kernel to be square matrix of any siza
 *       TODO Implement 'full' = full convolution that returns larger than ixj
 *       TODO Implement 'valid' = returns smaller than ixj
 *
 * @return Returns the central part of the convolution (of size ixj like A)
 */
template<typename T, std::size_t i, std::size_t j>
Matrix<T, i, j> conv2(const Matrix<T, i, j>& A, const Matrix<T, 3, 3>& kernel)
{
  Matrix<T, i, j> result{};

  for(std::size_t it = 1; it < i-1; it++)
  {
    for(std::size_t jt = 1; jt < j-1; jt++)
    {
      result[it][jt] = kernel[0][0] * A[it-1][jt-1] +
      kernel[0][1] * A[it-1][jt] +
      kernel[0][2] * A[it-1][jt+1] +
      kernel[1][0] * A[it][jt-1] +
      kernel[1][1] * A[it][jt] +
      kernel[1][2] * A[it][jt+1] +
      kernel[2][0] * A[it+1][jt-1] +
      kernel[2][1] * A[it+1][jt] +
      kernel[2][2] * A[it+1][jt+1];
    }
  }

  return result;
}

} /* namespace mlib */


#endif /* MATRIX_MATRIX_CONV2_HPP_ */
