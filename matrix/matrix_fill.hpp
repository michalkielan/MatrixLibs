/**
 * @file matrix_fill.hpp
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

#ifndef MATRIX_MATRIX_FILL_HPP_
#define MATRIX_MATRIX_FILL_HPP_

namespace mlib
{


/**
 * @brief Create i,j matrix filling with some data
 *
 * Usage: <type, row , col>(data)
 * @param [in] data to fill the matrix
 *
 * @return matrix with i, j size
 */
template<typename T, std::size_t i, std::size_t j>
Matrix<T, i, j> fill(T data)
{
  Matrix<T, i, j> A{};
  for(auto& a : A)
  {
    a.fill(data);
  }

  return A;
}

} /* namespace mlib */

#endif /* MATRIX_MATRIX_FILL_HPP_ */
