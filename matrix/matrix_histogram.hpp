/**
 * @file matrix_eye.hpp
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

#ifndef MATRIX_HISTOGRAM_HPP_
#define MATRIX_HISTOGRAM_HPP_

#include "matrix_type.hpp"

namespace mlib
{

/**
 * @brief Histogram
 *
 * @param [in] Matrix A ixj
 *
 * @return std::map with unique value of matrix A as key value and
 *         quantity of that unique value as mapped value.
 */
template<typename T, std::size_t i, std::size_t j>
std::map<T,std::size_t> histogram(const Matrix<T, i, j>& A)
{
  std::map<T,std::size_t> histogram{};
  for (std::size_t it = 0; it < i; it++)
  {
    for (std::size_t jt = 0; jt < j; jt++)
    {
      histogram[A[it][jt]]++;
    }
  }
  return histogram;
}


/**
 * @brief Cumulative histogram //TODO: Think about better name of this fun.
 *
 * @param [in] Matrix A ixj
 *
 * @return std::map with unique value of matrix A as key value and as mapped
 *     value quantity of values that are not greater than unique value.
 */
template<typename T, std::size_t i, std::size_t j>
std::map<T, std::size_t> cumulative_histogram(const Matrix<T, i, j>& A)
{
  std::map<T,std::size_t> result{};
  std::size_t cumul_sum{};
  const auto histA = histogram(A);
  for (const auto &p : histA) 
  {
    cumul_sum += p.second;
    result[p.first] = cumul_sum;
  }
  
  return result;
}


} /* namespace mlib */

#endif // MATRIX_HISTOGRAM_HPP_
