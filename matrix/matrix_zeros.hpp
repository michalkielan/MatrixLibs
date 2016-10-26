/*
 * matrix_zeros.hpp
 *
 *  Created on: Oct 26, 2016
 *      Author: michal
 */

#ifndef MATRIX_MATRIX_ZEROS_HPP_
#define MATRIX_MATRIX_ZEROS_HPP_


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


#endif /* MATRIX_MATRIX_ZEROS_HPP_ */
