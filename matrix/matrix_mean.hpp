/**
 * @file matrix_mean.hpp
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
