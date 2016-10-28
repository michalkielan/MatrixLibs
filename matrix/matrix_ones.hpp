/*
 * matrix_ones.hpp
 *
 *  Created on: Oct 26, 2016
 *      Author: michal
 */

#ifndef MATRIX_MATRIX_ONES_HPP_
#define MATRIX_MATRIX_ONES_HPP_

namespace mlib
{

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

} /* namespace mlib */


#endif /* MATRIX_MATRIX_ONES_HPP_ */
