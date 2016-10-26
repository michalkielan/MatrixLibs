#ifndef MATRIX_MATRIX_TRANS_HPP_
#define MATRIX_MATRIX_TRANS_HPP_

#include "matrix_type.hpp"

/**
 * @brief Transpose of matrix nxm
 *
 * @param [in] Matrix A with nxm size
 *
 * @return Transpose of matrix A
 */
template<typename T, std::size_t n, std::size_t m>
Matrix<T, m, n> trans(const Matrix<T, n, m>& A)
{
  Matrix<T, m, n> transA{};

  for (std::size_t i = 0; i < n; i++)
  {
    for (std::size_t j = 0; j < m; j++)
    {
      transA[j][i] = A[i][j];
    }
  }
  return transA;
}


#endif /* MATRIX_MATRIX_TRANS_HPP_ */
