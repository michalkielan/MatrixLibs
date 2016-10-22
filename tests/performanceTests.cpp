/*
 * performanceTests.cpp
 *
 *  Created on: Sep 16, 2016
 *      Author: mkielanx
 */

#include <iostream>
#include <random>
#include <algorithm>
#include <functional>
#include <memory>
#include <chrono>
#include <fstream>
#include <gtest/gtest.h>

#include "matrix.hpp"


/**
 * \brief File mode flag,
 *
 * Usage: if true each data is writing to his own test file,
 * otherwise, data is plotting on standard output stream - std::cout
 *
 */
const bool fileMode = true;
const std::string ext {"data"};
const auto mode = std::ostream::out | std::ofstream::trunc;


inline std::string getFileName(const std::string& dir, const std::string& name, const std::string& ext)
{
  return std::string {dir + "/" + name + "." + ext};
}

/**
 * \brief Plots path
 */
const std::string plotpath {"plots"};


using MatrixDataType = int;

static constexpr std::size_t i[] =
{
  100, 200, 300, 400, 500, 600, 700, 800, 1000, 1100, 1200, 1300, 1400, 1500, 1600
};

constexpr std::size_t doublei[] =
{
  2*i[0], 2*i[1], 2*i[2],  2*i[3],  2*i[4],  2*i[5],  2*i[6], 2*i[7],
  2*i[8], 2*i[9], 2*i[10], 2*i[11], 2*i[12], 2*i[13], 2*i[14]
};

static Matrix<MatrixDataType, i[0],  doublei[0]>  A0, B0;
static Matrix<MatrixDataType, i[1],  doublei[1]>  A1, B1;
static Matrix<MatrixDataType, i[2],  doublei[2]>  A2, B2;
static Matrix<MatrixDataType, i[3],  doublei[3]>  A3, B3;
static Matrix<MatrixDataType, i[4],  doublei[4]>  A4, B4;
static Matrix<MatrixDataType, i[5],  doublei[5]>  A5, B5;
static Matrix<MatrixDataType, i[6],  doublei[6]>  A6, B6;
static Matrix<MatrixDataType, i[7],  doublei[7]>  A7, B7;
static Matrix<MatrixDataType, i[8],  doublei[8]>  A8, B8;
static Matrix<MatrixDataType, i[9],  doublei[9]>  A9, B9;
static Matrix<MatrixDataType, i[10], doublei[10]> A10, B10;
static Matrix<MatrixDataType, i[11], doublei[11]> A11, B11;
static Matrix<MatrixDataType, i[12], doublei[12]> A12, B12;
static Matrix<MatrixDataType, i[13], doublei[13]> A13, B13;
static Matrix<MatrixDataType, i[14], doublei[14]> A14, B14;

static Matrix<MatrixDataType, i[0],  i[0]>  sqrA0, sqrB0;
static Matrix<MatrixDataType, i[1],  i[1]>  sqrA1, sqrB1;
static Matrix<MatrixDataType, i[2],  i[2]>  sqrA2, sqrB2;
static Matrix<MatrixDataType, i[3],  i[3]>  sqrA3, sqrB3;
static Matrix<MatrixDataType, i[4],  i[4]>  sqrA4, sqrB4;
static Matrix<MatrixDataType, i[5],  i[5]>  sqrA5, sqrB5;
static Matrix<MatrixDataType, i[6],  i[6]>  sqrA6, sqrB6;
static Matrix<MatrixDataType, i[7],  i[7]>  sqrA7, sqrB7;
static Matrix<MatrixDataType, i[8],  i[8]>  sqrA8, sqrB8;
static Matrix<MatrixDataType, i[9],  i[9]>  sqrA9, sqrB9;
static Matrix<MatrixDataType, i[10], i[10]> sqrA10, sqrB10;
static Matrix<MatrixDataType, i[11], i[11]> sqrA11, sqrB11;
static Matrix<MatrixDataType, i[12], i[12]> sqrA12, sqrB12;
static Matrix<MatrixDataType, i[13], i[13]> sqrA13, sqrB13;
static Matrix<MatrixDataType, i[14], i[14]> sqrA14, sqrB14;

class MatrixPerformanceTest : public ::testing::Test
{
  protected:

    void SetUp() override
    {
      fillRand(A0);  fillRand(B0);
      fillRand(A1);  fillRand(B1);
      fillRand(A2);  fillRand(B2);
      fillRand(A3);  fillRand(B3);
      fillRand(A4);  fillRand(B4);
      fillRand(A5);  fillRand(B5);
      fillRand(A6);  fillRand(B6);
      fillRand(A7);  fillRand(B7);
      fillRand(A8);  fillRand(B8);
      fillRand(A9);  fillRand(B9);
      fillRand(A10);  fillRand(B10);
      fillRand(A11);  fillRand(B11);
      fillRand(A12);  fillRand(B12);
      fillRand(A13);  fillRand(B13);
      fillRand(A14);  fillRand(B14);

      fillRand(sqrA0);  fillRand(sqrB0);
      fillRand(sqrA1);  fillRand(sqrB1);
      fillRand(sqrA2);  fillRand(sqrB2);
      fillRand(sqrA3);  fillRand(sqrB3);
      fillRand(sqrA4);  fillRand(sqrB4);
      fillRand(sqrA5);  fillRand(sqrB5);
      fillRand(sqrA6);  fillRand(sqrB6);
      fillRand(sqrA7);  fillRand(sqrB7);
      fillRand(sqrA8);  fillRand(sqrB8);
      fillRand(sqrA9);  fillRand(sqrB9);
      fillRand(sqrA10);  fillRand(sqrB10);
      fillRand(sqrA11);  fillRand(sqrB11);
      fillRand(sqrA12);  fillRand(sqrB12);
      fillRand(sqrA13);  fillRand(sqrB13);
      fillRand(sqrA14);  fillRand(sqrB14);
    }

    void TearDown() override {}

    template<typename T, std::size_t I, std::size_t J>
    void print(const Matrix<T, I, J>& A)
    {
      for (std::size_t i = 0; i < I; i++)
      {
        for (std::size_t j = 0; j < J; j++)
        {
          std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
      }
    }

    template<typename T, std::size_t i, std::size_t j>
    void fillRand(Matrix<T, i, j>& A)
    {
      std::default_random_engine dre{std::random_device{}()};
      std::uniform_int_distribution<T> ud;

      for(auto& a : A)
      {
        a.fill(ud(dre));
      }
    }

    template<typename T1, typename T2>
    void printPlot(T1&& colLeft, T2&& colRight, std::ostream& stream)
    {
      stream << colLeft << '\t' << colRight << std::endl;
    }

    template< typename TimeType, typename MatrixA, typename MatrixB, typename Functor>
    void measureTime(const MatrixA& A, const MatrixB& B, std::size_t i,  std::size_t j, Functor fun, std::size_t times = 10, std::ostream& ostream = std::cout)
    {
      std::vector<decltype(times)> timeSamples;
      timeSamples.reserve(times);

      while(times--)
      {
        auto begin = std::chrono::steady_clock::now();
        fun(std::move(A), std::move(B), i, j);
        auto end = std::chrono::steady_clock::now();
        timeSamples.push_back( std::chrono::duration_cast<TimeType>(end - begin).count() );
      }

      auto result =  std::min_element( std::begin(timeSamples), std::end(timeSamples) );

      printPlot(i, *result, ostream);
    };

};

TEST_F(MatrixPerformanceTest, histogram)
{
  const std::string filenameHistogram { "histogram" };
  const std::string filenameCumulativeHistogram { "histogram_cumul" };
  std::ofstream file;
  auto* ostream = fileMode ? &file : &std::cout;

  if(fileMode)
  {
    file.open(getFileName(plotpath, filenameHistogram, ext) , mode);
  }

  const Matrix<float, 5, 5> A =
  { 1, 2, 2, 3, 3,
    4, 4, 2, 3, 3,
    7, 8, 4, 3, 6,
    6, 5, 5, 5, 9,
    3, 3, 5, 6, 6 };

  auto histA = histogram(A);

  ASSERT_EQ(histA[1],1);
  ASSERT_EQ(histA[2],3);
  ASSERT_EQ(histA[4],3);
  ASSERT_EQ(histA[7],1);
  ASSERT_EQ(histA[8],1);

  printPlot("value", "quantity", *ostream);
  for (const auto &p : histA) {
    printPlot(p.first, p.second, *ostream);
  }

  if(fileMode)
  {
    file.close();
  }

  if(fileMode)
  {
    file.open(getFileName(plotpath, filenameCumulativeHistogram, ext) , mode);
  }

  auto cumul_histA = cumulative_histogram(A);

  ASSERT_EQ(cumul_histA[1],1);
  ASSERT_EQ(cumul_histA[2],4);
  ASSERT_EQ(cumul_histA[3],11);
  ASSERT_EQ(cumul_histA[4],14);
  ASSERT_EQ(cumul_histA[5],18);
  ASSERT_EQ(cumul_histA[6],22);
  ASSERT_EQ(cumul_histA[7],23);
  ASSERT_EQ(cumul_histA[8],24);
  ASSERT_EQ(cumul_histA[9],25);

  printPlot("value", "quantity", *ostream);
  for (const auto &p : cumul_histA) {
    printPlot(p.first, p.second, *ostream);
  }

  if(fileMode)
  {
    file.close();
  }
}

/**
 * \brief Measure the difference time between filling matrices starting from row or col loop
 *
 * for(i...row)     or    for(i...col)
 *   for(j...col)           for(j...row)
 *
 */
TEST_F(MatrixPerformanceTest, fill_matrices)
{
  using TimeFormat = std::chrono::microseconds;
  const std::string format   { "us" };
  const std::size_t samples  { 50 };
  const std::string filenameRowMajor { "fill_matrices_row_major" };
  const std::string filenameColMajor { "fill_matrices_col_major" };
  std::ofstream file;
  auto* ostream = fileMode ? &file : &std::cout;

  if(fileMode)
  {
    file.open(getFileName(plotpath, filenameRowMajor, ext) , mode);
  }


  /**
   * \brief Functions do random stuff to read each element of matrix (in example sum all element in matrix)
   */
  auto rowf = [](auto&& A, auto&& B, std::size_t row,  std::size_t col)
  {
	MatrixDataType sum = 0;
    for(std::size_t i = 0; i< row; i++)
    {
      for(std::size_t j = 0; j< col; j++)
      {
        sum += A[i][j];
      }
    }
  };

  auto colf = [](auto&& A, auto&& B, std::size_t row,  std::size_t col)
  {
    MatrixDataType sum = 0;
    for(std::size_t i = 0; i< col; i++)
    {
      for(std::size_t j = 0; j< row; j++)
      {
        sum += A[i][j];
      }
    }
  };

  printPlot("size", "time["+format+"]", *ostream);
  measureTime<TimeFormat>(A0,  B0,  i[0],  i[0],  rowf, samples, *ostream);
  measureTime<TimeFormat>(A1,  B1,  i[1],  i[1],  rowf, samples, *ostream);
  measureTime<TimeFormat>(A2,  B2,  i[2],  i[2],  rowf, samples, *ostream);
  measureTime<TimeFormat>(A3,  B3,  i[3],  i[3],  rowf, samples, *ostream);
  measureTime<TimeFormat>(A4,  B4,  i[4],  i[4],  rowf, samples, *ostream);
  measureTime<TimeFormat>(A5,  B5,  i[5],  i[5],  rowf, samples, *ostream);
  measureTime<TimeFormat>(A6,  B6,  i[6],  i[6],  rowf, samples, *ostream);
  measureTime<TimeFormat>(A7,  B7,  i[7],  i[7],  rowf, samples, *ostream);
  measureTime<TimeFormat>(A8,  B8,  i[8],  i[8],  rowf, samples, *ostream);
  measureTime<TimeFormat>(A9,  B9,  i[9],  i[9],  rowf, samples, *ostream);
  measureTime<TimeFormat>(A10, B10, i[10], i[10], rowf, samples, *ostream);
  measureTime<TimeFormat>(A11, B11, i[11], i[11], rowf, samples, *ostream);
  measureTime<TimeFormat>(A12, B12, i[12], i[12], rowf, samples, *ostream);
  measureTime<TimeFormat>(A13, B13, i[13], i[13], rowf, samples, *ostream);
  measureTime<TimeFormat>(A14, B14, i[14], i[14], rowf, samples, *ostream);

  if(fileMode)  
  {
    file.close();
    file.open(getFileName(plotpath, filenameColMajor, ext), mode);
    ostream = &file;
  }

  printPlot("size", "time["+format+"]", *ostream);
  measureTime<TimeFormat>(A0,  B0,  i[0],  i[0],  colf, samples, *ostream);
  measureTime<TimeFormat>(A1,  B1,  i[1],  i[1],  colf, samples, *ostream);
  measureTime<TimeFormat>(A2,  B2,  i[2],  i[2],  colf, samples, *ostream);
  measureTime<TimeFormat>(A3,  B3,  i[3],  i[3],  colf, samples, *ostream);
  measureTime<TimeFormat>(A4,  B4,  i[4],  i[4],  colf, samples, *ostream);
  measureTime<TimeFormat>(A5,  B5,  i[5],  i[5],  colf, samples, *ostream);
  measureTime<TimeFormat>(A6,  B6,  i[6],  i[6],  colf, samples, *ostream);
  measureTime<TimeFormat>(A7,  B7,  i[7],  i[7],  colf, samples, *ostream);
  measureTime<TimeFormat>(A8,  B8,  i[8],  i[8],  colf, samples, *ostream);
  measureTime<TimeFormat>(A9,  B9,  i[9],  i[9],  colf, samples, *ostream);
  measureTime<TimeFormat>(A10, B10, i[10], i[10], colf, samples, *ostream);
  measureTime<TimeFormat>(A11, B11, i[11], i[11], colf, samples, *ostream);
  measureTime<TimeFormat>(A12, B12, i[12], i[12], colf, samples, *ostream);
  measureTime<TimeFormat>(A13, B13, i[13], i[13], colf, samples, *ostream);
  measureTime<TimeFormat>(A14, B14, i[14], i[14], colf, samples, *ostream);

}



/**
 * \brief Measure time of multiplying square matrices
 *
 */
TEST_F(MatrixPerformanceTest, multiply_square)
{
  using TimeFormat = std::chrono::milliseconds;
  const std::string format   { "ms" };
  const std::size_t samples  { 5 };
  const std::string filename { "multiply_square" };
  std::ofstream file;
  auto* ostream = fileMode ? &file : &std::cout;

  if(fileMode)
  {
    file.open(getFileName(plotpath, filename, ext), mode);
  }

  /**
   * \brief Functions multiplying matrices
   */
  auto mulf = [](auto&& A, auto&& B, std::size_t row,  std::size_t col)
  {
    auto C = A * B;
    (void)C;
  };

  printPlot("size", "time["+format+"]", *ostream);
  measureTime<TimeFormat>(sqrA0,  sqrB0,  i[0],  i[0],  mulf, samples, *ostream);
  measureTime<TimeFormat>(sqrA1,  sqrB1,  i[1],  i[1],  mulf, samples, *ostream);
  measureTime<TimeFormat>(sqrA2,  sqrB2,  i[2],  i[2],  mulf, samples, *ostream);
  measureTime<TimeFormat>(sqrA3,  sqrB3,  i[3],  i[3],  mulf, samples, *ostream);
  measureTime<TimeFormat>(sqrA4,  sqrB4,  i[4],  i[4],  mulf, samples, *ostream);
  measureTime<TimeFormat>(sqrA5,  sqrB5,  i[5],  i[5],  mulf, samples, *ostream);
  measureTime<TimeFormat>(sqrA6,  sqrB6,  i[6],  i[6],  mulf, samples, *ostream);
  measureTime<TimeFormat>(sqrA7,  sqrB7,  i[7],  i[7],  mulf, samples, *ostream);
  measureTime<TimeFormat>(sqrA8,  sqrB8,  i[8],  i[8],  mulf, samples, *ostream);
  measureTime<TimeFormat>(sqrA9,  sqrB9,  i[9],  i[9],  mulf, samples, *ostream);
  measureTime<TimeFormat>(sqrA10, sqrB10, i[10], i[10], mulf, samples, *ostream);
  measureTime<TimeFormat>(sqrA11, sqrB11, i[11], i[11], mulf, samples, *ostream);
  measureTime<TimeFormat>(sqrA12, sqrB12, i[12], i[12], mulf, samples, *ostream);
  measureTime<TimeFormat>(sqrA13, sqrB13, i[13], i[13], mulf, samples, *ostream);
  measureTime<TimeFormat>(sqrA14, sqrB14, i[14], i[14], mulf, samples, *ostream);
}


int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
