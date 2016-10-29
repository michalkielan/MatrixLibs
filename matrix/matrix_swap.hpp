/*
 * matrix_swap.hpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
 */

#ifndef MATRIX_SWAP_HPP_
#define MATRIX_SWAP_HPP_


namespace mlib
{


/**
 * @brief Swap rows
 *
 * @param [in] Matrix A
 * @param [in] this rows has to be swapped into
 * @param [in] that rows
 *
 * @return Inverse of matrix A
 */
template<typename T, std::size_t row, std::size_t col>
void swap_rows(Matrix<T, row, col>& A, std::size_t row1, std::size_t row2)
{
  if (row1 != row2)
  {
    for (std::size_t i = 0; i < col; ++i)
    {
      std::swap(A[row1][i], A[row2][i]);
    }
  }
}


/**
 * @brief Swap colums
 *
 * @param [in] Matrix A
 * @param [in] this column has to be swapped into
 * @param [in] that column
 *
 * @return Inverse of matrix A
 */
template<typename T, std::size_t row, std::size_t col>
void swap_cols(Matrix<T, row, col>& A, std::size_t col1, std::size_t col2)
{
  if (col1 != col2)
  {
    for(auto& a: A)
    {
      std::swap(a[col1], a[col2]);
    }
  }
}


} /* namespace mlib */


#endif /* MATRIX_SWAP_HPP_ */
