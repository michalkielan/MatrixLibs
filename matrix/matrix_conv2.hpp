/*
 * matrix_conv2.hpp
 *
 *  Created on: Oct 26, 2016
 *      Author: michal
 */

#ifndef MATRIX_MATRIX_CONV2_HPP_
#define MATRIX_MATRIX_CONV2_HPP_

#include "matrix_type.hpp"
#include "matrix_inv.hpp"  //getminor needed TODO move getminor to i.e. utils?

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
    if (a < 0)
    {
      result++;
    }
    if (b < 0)
    {
      result++;
    }
    if (static_cast<unsigned int>(a) >= i)
    {
      result++;
    }
    if (static_cast<unsigned int>(b) >= j)
    {
      result++;
    }
    return result;
  };

  for(std::size_t it = 0; it < i; it++)
  {
    for(std::size_t jt = 0; jt < j; jt++)
    {
      result[it][jt] = 0;
      result[it][jt] += ((isOutOfRange(it-1,jt-1)) ? 0 : kernel[0][0] * A[it-1][jt-1]);   
      result[it][jt] += ((isOutOfRange(it-1,jt))   ? 0 : kernel[0][1] * A[it-1][jt]);
      result[it][jt] += ((isOutOfRange(it-1,jt+1)) ? 0 : kernel[0][2] * A[it-1][jt+1]);
      result[it][jt] += ((isOutOfRange(it,jt-1))   ? 0 : kernel[1][0] * A[it][jt-1]);   
      result[it][jt] += ((isOutOfRange(it,jt))     ? 0 : kernel[1][1] * A[it][jt]);   
      result[it][jt] += ((isOutOfRange(it,jt+1))   ? 0 : kernel[1][2] * A[it][jt+1]);   
      result[it][jt] += ((isOutOfRange(it+1,jt-1)) ? 0 : kernel[2][0] * A[it+1][jt-1]);  
      result[it][jt] += ((isOutOfRange(it+1,jt))   ? 0 : kernel[2][1] * A[it+1][jt]);
      result[it][jt] += ((isOutOfRange(it+1,jt+1)) ? 0 : kernel[2][2] * A[it+1][jt+1]); 
    }
  }
  return result;
}

//experimental conv2 with 'full' option
//returns i+2 x j+2 because kernel is 3x3
//basic rule is i+(n-1) x j+(n-1)
// TODO move in inside conv2() (add parameter 'valid' as option)
// TODO refactor it so it will look more friendly
template<typename T, std::size_t i, std::size_t j>
Matrix<T, i+2, j+2> conv2_full(const Matrix<T, i, j>& A, const Matrix<T, 3, 3>& kernel)
{
  Matrix<T, i+2, j+2> result{};
  // equals 1 because kernel is 3x3, if kernel is 5x5 offset would be 2 
  constexpr std::size_t offset{1};
  auto isOutOfRange = [](int a, int b)
  {
    std::size_t result = 0;
    if (a < 0)
    {
      result++;
    }
    if (b < 0)
    {
      result++;
    }
    if (static_cast<unsigned int>(a) >= i+2)
    {
      result++;
    }
    if (static_cast<unsigned int>(b) >= j+2)
    {
      result++;
    }
    return result;
  };

  for(std::size_t it = 0; it < i+2; it++)
  {
    for(std::size_t jt = 0; jt < j+2; jt++)
    {
      result[it][jt] = 0;
      result[it][jt] += ((isOutOfRange(it-1 - offset,jt-1 - offset)) ? 0 : kernel[0][0] * A[it-1 - offset][jt-1 - offset]);   
      result[it][jt] += ((isOutOfRange(it-1 - offset,jt - offset))   ? 0 : kernel[0][1] * A[it-1 - offset][jt - offset]);
      result[it][jt] += ((isOutOfRange(it-1 - offset,jt+1 - offset)) ? 0 : kernel[0][2] * A[it-1 - offset][jt+1 - offset]);
      result[it][jt] += ((isOutOfRange(it - offset,jt-1 - offset))   ? 0 : kernel[1][0] * A[it - offset][jt-1 - offset]);   
      result[it][jt] += ((isOutOfRange(it - offset,jt - offset))     ? 0 : kernel[1][1] * A[it - offset][jt - offset]);   
      result[it][jt] += ((isOutOfRange(it - offset,jt+1 - offset))   ? 0 : kernel[1][2] * A[it - offset][jt+1 - offset]);   
      result[it][jt] += ((isOutOfRange(it+1 - offset,jt-1 - offset)) ? 0 : kernel[2][0] * A[it+1 - offset][jt-1 - offset]);  
      result[it][jt] += ((isOutOfRange(it+1 - offset,jt - offset))   ? 0 : kernel[2][1] * A[it+1 - offset][jt - offset]);
      result[it][jt] += ((isOutOfRange(it+1 - offset,jt+1 - offset)) ? 0 : kernel[2][2] * A[it+1 - offset][jt+1 - offset]); 
    }
  }
  return result;
}

//experimental conv2 with 'valid' option
//returns i-2 x j-2 because kernel is 3x3
//basic rule is i-(n-1) x j-(n-1)
// TODO move in inside conv2() (add parameter 'valid' as option)
template<typename T, std::size_t i, std::size_t j>
Matrix<T, i-2, j-2> conv2_valid(const Matrix<T, i, j>& A, const Matrix<T, 3, 3>& kernel)
{
  auto tmp1 = getminor(conv2(A,kernel),i,j); // conv2 means conv2 with -same option
  return getminor(tmp1,0,0);
}



#endif /* MATRIX_MATRIX_CONV2_HPP_ */
