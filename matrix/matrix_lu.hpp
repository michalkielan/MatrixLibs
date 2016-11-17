#ifndef MATRIX_MATRIX_LU_HPP_
#define MATRIX_MATRIX_LU_HPP_

#include "matrix_eye.hpp"
#include "matrix_zeros.hpp"
#include "matrix_swap.hpp"

namespace mlib
{


/**
 * @brief LU decomposition
 *
 * Usage: The result of function is pair of matrices where L matrix is first
 *        element of pair, the second element is U matrix
 * @param [in] Square Matrix data
 *
 * @return Two matrices L and U
 */
template<typename T, std::size_t n>
std::pair<Matrix<T,n,n>, Matrix<T,n,n>>lu(const Matrix<T,n,n>& data)
{
  auto A{data};
  auto L { eye<T, n>() };
  auto U { zeros<T, n, n>() };
  bool inputMatrixSwapped = false;
  T sum {};
  std::size_t nr1{1}, nr2{1};
begin:
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
      {
      //  uncomment line below in order to throw exception 
      //  without trying to swap rows.
      //  TODO: make flag which can be passed as argument for en-/disabling
      //  throw std::overflow_error("Divide by zero exception");
        goto try_swap;
      }
      else
      {
        L[i][j] = (A[i][j] - sum) / U[j][j];
      }
    }
  }
  if (inputMatrixSwapped)
  {
    swap_rows(L,1,2);
  }
  return std::make_pair(L, U);

// The following lines are changing rows procedure. 
// It will try to swap all possible rows.
// i. e. for matrix 3x3: 12, 13, 23 eventually throws exception 
try_swap:
  ++nr2;
  if (nr2 > n)
  {
    ++nr1;
    nr2 = nr1 + 1;
    if (nr1 > n)
    {
      throw std::overflow_error("Divide by zero exception");
    }
  }    
  A = data;
  swap_rows(A, nr1, nr2);
  inputMatrixSwapped = true;
  goto begin;
// END of changing rows procedure

  // this line should never be reached
  throw std::overflow_error("Divide by zero exception");
}

} /* namespace mlib */


#endif /* MATRIX_MATRIX_LU_HPP_ */
