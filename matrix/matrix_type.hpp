/**
 * @file matrix_type.hpp
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


#ifndef MATRIX_TYPE_HPP_
#define MATRIX_TYPE_HPP_

#include <array>
#include <utility>
#include <cmath>
#include <algorithm>
#include <map>
#include <complex>

namespace mlib
{


/**
 * @bref Matrix type definition
 *
 * @Usage: Matrix<type, row, col>
 */
template <typename T, std::size_t i, std::size_t j>
using Matrix = std::array<std::array<T, j>, i>;



} /* namespace mlib */

#endif // MATRIX_TYPE_HPP_
