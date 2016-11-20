/**
 * @file matrix_abs.hpp
 *
 * @date Oct 27, 2016
 *
 * @author Michal Kielan
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */


#ifndef MATRIX_ABS_HPP_
#define MATRIX_ABS_HPP_

#include "matrix_type.hpp"

namespace mlib
{

/**
 * @brief Absolut value of matrix
 *
 * @param [in] Matrix A with ixj size
 *
 * @return Matrix A which is result of absolut each element of matrix
 */
template<typename T, std::size_t i, std::size_t j>
Matrix<T, i, j> abs(const Matrix<T, i, j>& A)
{
  Matrix<T, i, j> absA;
  for (std::size_t it = 0; it < i; it++)
  {
    for (std::size_t jt = 0; jt < j; jt++)
    {
      absA[it][jt] = std::abs(A[it][jt]);
    }
  }
  return absA;
}

} /* namespace mlib */

#endif /* MATRIX_ABS_HPP_ */
