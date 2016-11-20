/**
 * @file inv.hpp
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
#ifndef BENCH_MULTIPLY_HPP_
#define BENCH_MULTIPLY_HPP_

#include <benchmark/benchmark.h>
#include "setRand.hpp"
#include "matrix.hpp"

template<typename T, std::size_t i, std::size_t j>
static void inv(benchmark::State& state)
{
  mlib::Matrix<float, i, j> A;

  setRand(A);

  while (state.KeepRunning())
  {
    mlib::inv(A);
  }
}


static const auto format = benchmark::kMicrosecond;

BENCHMARK_TEMPLATE(inv, float, 1*10, 1*10)->Unit(format);
BENCHMARK_TEMPLATE(inv, float, 2*10, 2*10)->Unit(format);
BENCHMARK_TEMPLATE(inv, float, 3*10, 3*10)->Unit(format);
BENCHMARK_TEMPLATE(inv, float, 4*10, 4*10)->Unit(format);
BENCHMARK_TEMPLATE(inv, float, 5*10, 5*10)->Unit(format);
BENCHMARK_TEMPLATE(inv, float, 6*10, 6*10)->Unit(format);
BENCHMARK_TEMPLATE(inv, float, 7*10, 7*10)->Unit(format);
BENCHMARK_TEMPLATE(inv, float, 1*100, 1*100)->Unit(format);
BENCHMARK_TEMPLATE(inv, float, 2*100, 2*100)->Unit(format);
BENCHMARK_TEMPLATE(inv, float, 3*100, 3*100)->Unit(format);
BENCHMARK_TEMPLATE(inv, float, 4*100, 4*100)->Unit(format);
BENCHMARK_TEMPLATE(inv, float, 5*100, 5*100)->Unit(format);
BENCHMARK_TEMPLATE(inv, float, 6*100, 6*100)->Unit(format);
BENCHMARK_TEMPLATE(inv, float, 7*100, 7*100)->Unit(format);


#endif /* BENCH_MULTIPLY_HPP_ */
