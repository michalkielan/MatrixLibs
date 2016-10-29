/*
 * cache.hpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
 */

#ifndef BENCH_CACHE_CACHE_HPP_
#define BENCH_CACHE_CACHE_HPP_

#include <benchmark/benchmark.h>
#include "setRand.hpp"


template<typename T, std::size_t row, std::size_t col>
static void row_major(benchmark::State& state)
{
  mlib::Matrix<T, row, col> A;
  T sum = 0;

  while (state.KeepRunning())
  {
    for(std::size_t i = 0; i < row; i++)
    {
      for(std::size_t j = 0; j < col; j++)
      {
        sum += A[i][j];
      }
    }
  }
}

template<typename T, std::size_t row, std::size_t col>
static void col_major(benchmark::State& state)
{
  mlib::Matrix<T, row, col> A;
  T sum = 0;

  while (state.KeepRunning())
  {
    for(std::size_t i = 0; i < col; i++)
    {
      for(std::size_t j = 0; j < row; j++)
      {
        sum += A[i][j];
      }
    }
  }
}

template<typename T, std::size_t row, std::size_t col>
static void rand_major(benchmark::State& state)
{
  mlib::Matrix<T, row, col> A;
  T sum = 0;

  const std::size_t min = 0;
  const std::size_t max = col;

  std::default_random_engine dre {std::random_device{}()};
  std::uniform_int_distribution<std::size_t> ud {min, max};

  while (state.KeepRunning())
  {
    for(std::size_t i = 0; i < col; i++)
    {
      for(std::size_t j = 0; j < row; j++)
      {
        sum += A[i][ud(dre)];
      }
    }
  }
}

using MatrixType = float;

BENCHMARK_TEMPLATE(row_major, MatrixType, 1*10, 1*10);
BENCHMARK_TEMPLATE(row_major, MatrixType, 2*10, 2*10);
BENCHMARK_TEMPLATE(row_major, MatrixType, 3*10, 3*10);
BENCHMARK_TEMPLATE(row_major, MatrixType, 4*10, 4*10);
BENCHMARK_TEMPLATE(row_major, MatrixType, 5*10, 5*10);
BENCHMARK_TEMPLATE(row_major, MatrixType, 6*10, 6*10);
BENCHMARK_TEMPLATE(row_major, MatrixType, 7*10, 7*10);
BENCHMARK_TEMPLATE(row_major, MatrixType, 8*10, 8*10);
BENCHMARK_TEMPLATE(row_major, MatrixType, 9*10, 9*10);
BENCHMARK_TEMPLATE(row_major, MatrixType, 1*100, 1*100);
BENCHMARK_TEMPLATE(row_major, MatrixType, 2*100, 2*100);
BENCHMARK_TEMPLATE(row_major, MatrixType, 3*100, 3*100);
BENCHMARK_TEMPLATE(row_major, MatrixType, 4*100, 4*100);
BENCHMARK_TEMPLATE(row_major, MatrixType, 5*100, 5*100);
BENCHMARK_TEMPLATE(row_major, MatrixType, 6*100, 6*100);
BENCHMARK_TEMPLATE(row_major, MatrixType, 7*100, 7*100);
BENCHMARK_TEMPLATE(row_major, MatrixType, 8*100, 8*100);
BENCHMARK_TEMPLATE(row_major, MatrixType, 9*100, 9*100);

BENCHMARK_TEMPLATE(col_major, MatrixType, 1*10, 1*10);
BENCHMARK_TEMPLATE(col_major, MatrixType, 2*10, 2*10);
BENCHMARK_TEMPLATE(col_major, MatrixType, 3*10, 3*10);
BENCHMARK_TEMPLATE(col_major, MatrixType, 4*10, 4*10);
BENCHMARK_TEMPLATE(col_major, MatrixType, 5*10, 5*10);
BENCHMARK_TEMPLATE(col_major, MatrixType, 6*10, 6*10);
BENCHMARK_TEMPLATE(col_major, MatrixType, 7*10, 7*10);
BENCHMARK_TEMPLATE(col_major, MatrixType, 8*10, 8*10);
BENCHMARK_TEMPLATE(col_major, MatrixType, 9*10, 9*10);
BENCHMARK_TEMPLATE(col_major, MatrixType, 1*100, 1*100);
BENCHMARK_TEMPLATE(col_major, MatrixType, 2*100, 2*100);
BENCHMARK_TEMPLATE(col_major, MatrixType, 3*100, 3*100);
BENCHMARK_TEMPLATE(col_major, MatrixType, 4*100, 4*100);
BENCHMARK_TEMPLATE(col_major, MatrixType, 5*100, 5*100);
BENCHMARK_TEMPLATE(col_major, MatrixType, 6*100, 6*100);
BENCHMARK_TEMPLATE(col_major, MatrixType, 7*100, 7*100);
BENCHMARK_TEMPLATE(col_major, MatrixType, 8*100, 8*100);
BENCHMARK_TEMPLATE(col_major, MatrixType, 9*100, 9*100);

BENCHMARK_TEMPLATE(rand_major, MatrixType, 1*10, 1*10);
BENCHMARK_TEMPLATE(rand_major, MatrixType, 2*10, 2*10);
BENCHMARK_TEMPLATE(rand_major, MatrixType, 3*10, 3*10);
BENCHMARK_TEMPLATE(rand_major, MatrixType, 4*10, 4*10);
BENCHMARK_TEMPLATE(rand_major, MatrixType, 5*10, 5*10);
BENCHMARK_TEMPLATE(rand_major, MatrixType, 6*10, 6*10);
BENCHMARK_TEMPLATE(rand_major, MatrixType, 7*10, 7*10);
BENCHMARK_TEMPLATE(rand_major, MatrixType, 8*10, 8*10);
BENCHMARK_TEMPLATE(rand_major, MatrixType, 9*10, 9*10);
BENCHMARK_TEMPLATE(rand_major, MatrixType, 1*100, 1*100);
BENCHMARK_TEMPLATE(rand_major, MatrixType, 2*100, 2*100);
BENCHMARK_TEMPLATE(rand_major, MatrixType, 3*100, 3*100);
BENCHMARK_TEMPLATE(rand_major, MatrixType, 4*100, 4*100);
BENCHMARK_TEMPLATE(rand_major, MatrixType, 5*100, 5*100);
BENCHMARK_TEMPLATE(rand_major, MatrixType, 6*100, 6*100);
BENCHMARK_TEMPLATE(rand_major, MatrixType, 7*100, 7*100);
BENCHMARK_TEMPLATE(rand_major, MatrixType, 8*100, 8*100);
BENCHMARK_TEMPLATE(rand_major, MatrixType, 9*100, 9*100);


#endif /* BENCH_CACHE_CACHE_HPP_ */
