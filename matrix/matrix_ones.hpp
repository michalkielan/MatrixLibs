/**
 * @file matrix_ones.hpp
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

#ifndef MATRIX_MATRIX_ONES_HPP_
#define MATRIX_MATRIX_ONES_HPP_

namespace mlib
{

/**
 * @brief Create i,j matrix filling with one
 *
 * Usage: <type, row , col>(data)
 *
 * @return matrix with i, j size
 */
template<unsigned int, std::size_t i, std::size_t j = i>
Matrix<unsigned int, i, j> ones()
{
  return fill<unsigned int, i, j>(1);
}

template<typename T, std::size_t i, std::size_t j = i>
Matrix<T, i, i> ones()
{
  return fill<T, i, j>(1);
}

} /* namespace mlib */


#endif /* MATRIX_MATRIX_ONES_HPP_ */
