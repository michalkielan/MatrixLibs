#ifndef MATRIX_MATRIX_LU_HPP_
#define MATRIX_MATRIX_LU_HPP_

#include "matrix_eye.hpp"
#include "matrix_zeros.hpp"

namespace mlib
{


/**
 * @brief LU decomposition
 *
 * Usage: The result of function is pair of matrices where L matrix is first
 *        element of pair, the second element is U matrix
 * @param [in] Square Matrix A
 *
 * @return Two matrices L and U
 */
template<typename T, std::size_t n>
std::pair<Matrix<T,n,n>, Matrix<T,n,n>>lu(const Matrix<T,n,n>& A)
{
  auto L { eye<T, n>() };
  auto U { zeros<T, n, n>() };
  T sum {};

  for(std::size_t j = 0; j < n; j++)
  {
    for(std::size_t i = 0; i <= j; i++)
    {
      sum = 0.0;
      for(std::size_t p = 0; p < i; p++)
      {
        sum += U[p][j] * L[i][p];
      }
      U[i][j] = A[i][j] - sum;
    }
    for(std::size_t i = j; i < n; i++)
    {
      sum = 0.0;
      for(std::size_t p = 0; p < i; p++)
      {
        sum += U[p][j] * L[i][p];
      }

      if(U[j][j] == 0)
        throw std::overflow_error("Divide by zero exception");
      else
        L[i][j] = (A[i][j] - sum) / U[j][j];
    }
  }
  return std::pair<Matrix<T,n,n>, Matrix<T,n,n>>{L, U};
}

} /* namespace mlib */


#endif /* MATRIX_MATRIX_LU_HPP_ */
