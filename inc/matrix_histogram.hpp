#ifndef MATRIX_HISTOGRAM_HPP_
#define MATRIX_HISTOGRAM_HPP_

#include "matrix_type.hpp"

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

#endif // MATRIX_HISTOGRAM_HPP_