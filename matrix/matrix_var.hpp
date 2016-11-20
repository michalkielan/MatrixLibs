/**
 * @file matrix_var.hpp
 *
 * @date Oct 26, 2016
 *
 * @author Jaroslaw Wiosna
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#ifndef MATRIX_VAR_HPP_
#define MATRIX_VAR_HPP_

#include "matrix_type.hpp"

namespace mlib
{


/**
 * @brief Variance
 *
 * @param [in] Matrix A nxn
 *
 * @return Variance
 */
template<typename T,  std::size_t i, std::size_t j>
T var(const Matrix<T, i, j>& A)
{
  T result{};
  T meanA = mean(A);
  for (std::size_t it = 0; it < i; it++)
  {
    for (std::size_t jt = 0; jt < j; jt++)
    {
      result += (A[it][jt] - meanA)*(A[it][jt] - meanA);
    }
  }
  return (result / (i*j));
}



} /* namespace mlib */

#endif // MATRIX_VAR_HPP_
