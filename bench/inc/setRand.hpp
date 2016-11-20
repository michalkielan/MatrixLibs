/**
 * @file setRand.cpp
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

#ifndef BENCH_SETRAND_HPP_
#define BENCH_SETRAND_HPP_

#include <random>
#include "matrix.hpp"

template<std::size_t i, std::size_t j>
void setRand(mlib::Matrix<float, i, j>& A)
{
  std::default_random_engine dre{std::random_device{}()};
  std::uniform_real_distribution<float> ud;

  for(std::size_t it = 0; it < i; it++)
  {
    for(std::size_t jt = 0; jt < j; jt++)
    {
      A[it][jt] = ud(dre);
    }
  }
}


template<std::size_t i, std::size_t j>
void setRand(mlib::Matrix<int, i, j>& A)
{
  std::default_random_engine dre{std::random_device{}()};
  std::uniform_int_distribution<int> ud;

  for(std::size_t it = 0; it < i; it++)
  {
    for(std::size_t jt = 0; jt < j; jt++)
    {
      A[it][jt] = ud(dre);
    }
  }
}


#endif /* BENCH_SETRAND_HPP_ */
