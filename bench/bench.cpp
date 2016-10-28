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



template<std::size_t i, std::size_t j>
static void multiply(benchmark::State& state) 
{
  Matrix<int, i, j> A;
  Matrix<int, i, j> B;

  setRand(A);
  setRand(B);

  while (state.KeepRunning())
  {
    mult(A, B);
  }
}

BENCHMARK_TEMPLATE(multiply, 100, 100);
BENCHMARK_TEMPLATE(multiply, 200, 200);
BENCHMARK_TEMPLATE(multiply, 300, 300);
BENCHMARK_TEMPLATE(multiply, 400, 400);
BENCHMARK_TEMPLATE(multiply, 500, 500);
BENCHMARK_TEMPLATE(multiply, 600, 600);
BENCHMARK_TEMPLATE(multiply, 700, 700);

BENCHMARK_MAIN();

