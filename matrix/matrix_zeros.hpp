/**
 * @file matrix_zeros.hpp
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


#ifndef MATRIX_MATRIX_ZEROS_HPP_
#define MATRIX_MATRIX_ZEROS_HPP_

namespace mlib
{


/**
 * @brief Create i,j matrix filling with zeros
 *
 * Usage: <type, row , col>(data)
 *
 * @return matrix with i, j size
 */
template<typename T, std::size_t i, std::size_t j>
Matrix<T, i, j> zeros()
{
  return fill<T, i, j>(static_cast<T>(0));
}


} /* namespace mlib */

#endif /* MATRIX_MATRIX_ZEROS_HPP_ */
