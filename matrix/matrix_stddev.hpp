/**
 * @file matrix_stddev.hpp
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
