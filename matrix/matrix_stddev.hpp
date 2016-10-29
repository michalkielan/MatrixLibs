#ifndef MATRIX_STDDEV_HPP_
#define MATRIX_STDDEV_HPP_

#include "matrix_var.hpp"

namespace mlib
{


/**
 * @brief Standatrd deviation
 *
 * @param [in] Matrix A nxn
 *
 * @return Standard deviation
 */
template<typename T,  std::size_t i, std::size_t j>
T stddev(const Matrix<T, i, j>& A)
{
  return sqrt(var(A));
}


} /* namespace mlib */

#endif // MATRIX_STDDEV_HPP_
