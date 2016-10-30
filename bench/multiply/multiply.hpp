/*
 * multiply.hpp
 *
 *  Created on: Oct 28, 2016
 *      Author: michal
 */

#ifndef BENCH_MULTIPLY_HPP_
#define BENCH_MULTIPLY_HPP_

#include <benchmark/benchmark.h>
#include "setRand.hpp"


template<typename T, std::size_t i, std::size_t j>
static void multiply(benchmark::State& state)
{
  mlib::Matrix<int, i, j> A, B;

  setRand(A);
  setRand(B);

  while (state.KeepRunning())
  {
    mlib::mult(A, B);
  }
}


static void multiply_2_2_strassen(benchmark::State& state)
{
  mlib::Matrix<int, 2, 2> A, B;

  setRand(A);
  setRand(B);

  while (state.KeepRunning())
  {
    mlib::strassen(A,B);
  }
}


static void multiply_2_2(benchmark::State& state)
{
  mlib::Matrix<int, 2, 2> A, B;

  setRand(A);
  setRand(B);

  while (state.KeepRunning())
  {
    mlib::mult(A,B);
  }
}


static const auto format = benchmark::kMillisecond;

BENCHMARK(multiply_2_2);
BENCHMARK(multiply_2_2_strassen);

BENCHMARK_TEMPLATE(multiply, int, 1*100, 1*100)->Unit(format);
BENCHMARK_TEMPLATE(multiply, int, 2*100, 2*100)->Unit(format);
BENCHMARK_TEMPLATE(multiply, int, 3*100, 3*100)->Unit(format);
BENCHMARK_TEMPLATE(multiply, int, 4*100, 4*100)->Unit(format);
BENCHMARK_TEMPLATE(multiply, int, 5*100, 5*100)->Unit(format);
BENCHMARK_TEMPLATE(multiply, int, 6*100, 6*100)->Unit(format);
BENCHMARK_TEMPLATE(multiply, int, 7*100, 7*100)->Unit(format);

BENCHMARK_TEMPLATE(multiply, float, 1*100, 1*100)->Unit(format);
BENCHMARK_TEMPLATE(multiply, float, 2*100, 2*100)->Unit(format);
BENCHMARK_TEMPLATE(multiply, float, 3*100, 3*100)->Unit(format);
BENCHMARK_TEMPLATE(multiply, float, 4*100, 4*100)->Unit(format);
BENCHMARK_TEMPLATE(multiply, float, 5*100, 5*100)->Unit(format);
BENCHMARK_TEMPLATE(multiply, float, 6*100, 6*100)->Unit(format);
BENCHMARK_TEMPLATE(multiply, float, 7*100, 7*100)->Unit(format);


#endif /* BENCH_MULTIPLY_HPP_ */
