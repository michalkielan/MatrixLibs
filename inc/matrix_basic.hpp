#ifndef MATRIX_BASIC_HPP_
#define MATRIX_BASIC_HPP_

#include "matrix_type.hpp"

/**
 * @brief Create i,j matrix filling with some data
 * 
 * Usage: <type, row , col>(data)
 * @param [in] data to fill the matrix
 * 
 * @return matrix with i, j size
 */
template<typename T, std::size_t i, std::size_t j>
Matrix<T, i, j> fill(T data)
{
  Matrix<T, i, j> A{};
  for(auto& a : A)
  {
    a.fill(data);
  }

  return A;
}


/**
 * @brief Create i,j matrix filling with one
 * 
 * Usage: <type, row , col>(data)
 * 
 * @return matrix with i, j size
 */
template<unsigned int, std::size_t i, std::size_t j = i>
Matrix<unsigned int, i, j> ones()
{
  return fill<unsigned int, i, j>(1);
}

template<typename T, std::size_t i, std::size_t j = i>
Matrix<T, i, i> ones()
{
  return fill<T, i, j>(1);
}


/**
 * @brief Create i,j matrix filling with zeros
 * 
 * Usage: <type, row , col>(data)
 * 
 * @return matrix with i, j size
 */
template<typename T, std::size_t i, std::size_t j>
Matrix<T, i, j> zeros()
{
  return fill<T, i, j>(static_cast<T>(0));
}


/**
 * @brief Create a matrix with one number at the diagonal
 * 
 * Usage: <type, row , col>(data) or <type, row , col>()
 * @param [in] data to fill the matrix if empty, the default is 1
 * 
 * @return matrix with i, j size
 */
template<typename T, std::size_t n>
Matrix<T, n, n> eye(T data = 1)
{
  auto eye = fill<T, n, n>(0);

  for (std::size_t i = 0; i < n; i++)
  {
    eye[i][i] = data;
  }
  return eye;
}

#endif // MATRIX_BASIC_MATH_HPP_

