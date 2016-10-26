#ifndef MATRIX_TYPE_HPP_
#define MATRIX_TYPE_HPP_

#include <array>
#include <utility>
#include <cmath>
#include <algorithm>
#include <map>


/**
 * @bref Matrix type definition
 *
 * @Usage: Matrix<type, row, col>
 */
template <typename T, std::size_t i, std::size_t j>//,
//typename Arithmetic = std::enable_if<std::is_arithmetic<T>::value>>
using Matrix = std::array<std::array<T, j>, i>;

#endif // MATRIX_TYPE_HPP_
