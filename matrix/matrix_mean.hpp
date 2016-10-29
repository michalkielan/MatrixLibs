#ifndef MATRIX_MEAN_HPP_
#define MATRIX_MEAN_HPP_

#include "matrix_type.hpp"

namespace mlib
{


/**
 * @brief Mean
 *
 * @param [in] Matrix A nxn
 *
 * @return mean value of type T
 */
template<typename T,  std::size_t i, std::size_t j>
T mean(const Matrix<T, i, j>& A)
{
  T result{};
  for (std::size_t it = 0; it < i; it++)
  {
    for (std::size_t jt = 0; jt < j; jt++)
    {
      result += A[it][jt];
    }
  }
  return (result / (i*j));
}




} /* namespace mlib */

#endif // MATRIX_MEAN_HPP_
