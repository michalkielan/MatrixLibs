#include <benchmark/benchmark.h>
#include <random>
#include <algorithm>

#include "matrix.hpp"


template<typename T, std::size_t i, std::size_t j>
void setRand(Matrix<T, i, j>& A)    
{           
  std::default_random_engine dre{std::random_device{}()};
  std::uniform_int_distribution<T> ud;
                        
  for(auto& a : A)                               
  {                                      
    a.fill(ud(dre));                                                 
  }
}

static void Multiply_500_500(benchmark::State& state) 
{
  Matrix<int, 500, 500> A;
  Matrix<int, 500, 500> B;

  setRand(A);
  setRand(B);

  while (state.KeepRunning())
  {
    mult(A, B);
  }
}

static void Multiply_400_400(benchmark::State& state) 
{
  Matrix<int, 400, 400> A;
  Matrix<int, 400, 400> B;

  setRand(A);
  setRand(B);

  while (state.KeepRunning())
  {
    mult(A, B);
  }
}

BENCHMARK(Multiply_400_400);
BENCHMARK(Multiply_500_500);

BENCHMARK_MAIN();

