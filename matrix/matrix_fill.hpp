/*
 * matrix_fill.hpp
 *
 *  Created on: Oct 26, 2016
 *      Author: michal
 */

#ifndef MATRIX_MATRIX_FILL_HPP_
#define MATRIX_MATRIX_FILL_HPP_

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



#endif /* MATRIX_MATRIX_FILL_HPP_ */
