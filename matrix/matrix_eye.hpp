/**
 * @file matrix_eye.hpp
 *
 * @date Oct 26, 2016
 *
 * @author Michal Kielan
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#ifndef MATRIX_MATRIX_EYE_HPP_
#define MATRIX_MATRIX_EYE_HPP_

#include "matrix_fill.hpp"

namespace mlib
{


/**
 * @brief Create a matrix with one number at the diagonal
 *
 * Usage: <type, row , col>(data) or <type, row , col>()
 * @param [in] data to fill the matrix if empty, the default is 1
 *
 * @return matrix with i, j size
 */
template<typename T, std::size_t n>
Matrix<T, n, n> eye(T data = 1)
{
  auto eye = fill<T, n, n>(0);

  for (std::size_t i = 0; i < n; i++)
  {
    eye[i][i] = data;
  }
  return eye;
}

} /* namespace mlib */

#endif /* MATRIX_MATRIX_EYE_HPP_ */
