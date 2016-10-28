/*
 * matrix_conv2.hpp
 *
 *  Created on: Oct 26, 2016
 *      Author: michal
 */

#ifndef MATRIX_MATRIX_CONV2_HPP_
#define MATRIX_MATRIX_CONV2_HPP_

#include "matrix_type.hpp"

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
  auto isOutOfRange = [](int a, int b)
  {
    std::size_t result = 0;
    if (a-1 < 0)
    {
      result++;
    }
    if (b-1 < 0)
    {
      result++;
    }
    if (static_cast<unsigned int>(a+1) >= i)
    {
      result++;
    }
    if (static_cast<unsigned int>(b+1) >= j)
    {
      result++;
    }
    return result;
  };

  for(std::size_t it = 0; it < i; it++)
  {
    for(std::size_t jt = 0; jt < j; jt++)
    {
      result[it][jt] = kernel[0][0] * ((isOutOfRange(it-1,jt-1)) ? 0 : A[it-1][jt-1]);   
      result[it][jt] += kernel[0][1] * ((isOutOfRange(it-1,jt))   ? 0 : A[it-1][jt]);
      result[it][jt] += kernel[0][2] * ((isOutOfRange(it-1,jt+1)) ? 0 : A[it-1][jt+1]);
      result[it][jt] += kernel[1][0] * ((isOutOfRange(it,jt-1))   ? 0 : A[it][jt-1]);   
      result[it][jt] += kernel[1][1] * ((isOutOfRange(it,jt))     ? 0 : A[it][jt]);   
      result[it][jt] += kernel[1][2] * ((isOutOfRange(it,jt+1))   ? 0 : A[it][jt+1]);   
      result[it][jt] += kernel[2][0] * ((isOutOfRange(it+1,jt-1)) ? 0 : A[it+1][jt-1]);  
      result[it][jt] += kernel[2][1] * ((isOutOfRange(it+1,jt))   ? 0 : A[it+1][jt]);
      result[it][jt] += kernel[2][2] * ((isOutOfRange(it+1,jt+1)) ? 0 : A[it+1][jt+1]); 
    }
  }

  return result;
}

//experimental conv2 with 'full' option
//returns i+1 x j+1 because kernel is 3x3
//basic rule is i+(n-1)/2 x j+(n-1)/2
template<typename T, std::size_t i, std::size_t j>
Matrix<T, i+1, j+1> conv2_full(const Matrix<T, i, j>& A, const Matrix<T, 3, 3>& kernel)
{
  Matrix<T, i+1, j+1> result{};

  return result;
}

//experimental conv2 with 'valid' option
//returns i-1 x j-1 because kernel is 3x3
//basic rule is i-(n-1)/2 x j-(n-1)/2
template<typename T, std::size_t i, std::size_t j>
Matrix<T, i-1, j-1> conv2_valid(const Matrix<T, i, j>& A, const Matrix<T, 3, 3>& kernel)
{
  Matrix<T, i-1, j-1> result{};

  return result;
}



#endif /* MATRIX_MATRIX_CONV2_HPP_ */
