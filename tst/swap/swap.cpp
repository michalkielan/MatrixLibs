/*
 * swap.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
 */


#include <gtest/gtest.h>
#include "matrix.hpp"

using namespace mlib;


TEST(MatrixTest, swap_rows_4_4)
{
  Matrix<float, 4, 4> A =
  { 1, 2,  3,  4,
    5, 6,  7,  8,
    9, 10, 2,  2,
    2, 1,  -4, 0 };

  Matrix<float, 4, 4> swappedA =
  { 9, 10, 2,  2,
    5, 6,  7,  8,
    1, 2,  3,  4,
    2, 1,  -4, 0 };

  swap_rows(A, 0, 2);


  ASSERT_EQ(A, swappedA);
}


TEST(MatrixTest, swap_rows_2_4)
{
  Matrix<float, 2, 4> A =
  { 1, 2,  3,  4,
    5, 6,  7,  8 };

  Matrix<float, 2, 4> swappedA =
  { 5, 6,  7,  8,
    1, 2,  3,  4 };

  swap_rows(A, 0, 1);

  ASSERT_EQ(A, swappedA);
}


TEST(MatrixTest, swap_rows_4_3)
{
  Matrix<float, 4, 3> A =
  { 1, 2,  3,
    5, 6,  7,
    9, 10, 2,
    2, 1,  -4 };

  Matrix<float, 4, 3> swappedA =
  { 9, 10, 2,
    5, 6,  7,
    1, 2,  3,
    2, 1,  -4 };

  swap_rows(A, 0, 2);


  ASSERT_EQ(A, swappedA);
}



TEST(MatrixTest, swap_cols_4_4)
{
  Matrix<float, 4, 4> A =
  { 1, 2,  3,  4,
    5, 6,  7,  8,
    9, 10, 2,  2,
    2, 1,  -4, 0 };

  Matrix<float, 4, 4> swappedA =
  { 4, 2,  3, 1,
    8, 6,  7, 5,
    2, 10, 2, 9,
    0, 1, -4, 2 };

  swap_cols(A, 0, 3);

  ASSERT_EQ(A, swappedA);
}

TEST(MatrixTest, swap_cols_4_3)
{
  Matrix<float, 4, 4> A =
  { 1, 2,  3,  4,
    5, 6,  7,  8,
    9, 10, 2,  2,
    2, 1,  -4, 0 };

  Matrix<float, 4, 4> swappedA =
  { 4, 2,  3, 1,
    8, 6,  7, 5,
    2, 10, 2, 9,
    0, 1, -4, 2 };

  swap_cols(A, 0, 3);

  ASSERT_EQ(A, swappedA);
}

TEST(MatrixTest, swap_cols_4_2)
{
  Matrix<float, 4, 2> A =
  { 1, 2,
    5, 6,
    9, 10,
    2, 1, };

  Matrix<float, 4, 2> swappedA =
  { 2,   1,
    6,   5,
    10,  9,
    1,   2 };

  swap_cols(A, 1, 0);

  ASSERT_EQ(A, swappedA);
}


TEST(MatrixTest, swap_equal)
{
  Matrix<float, 4, 4> A =
  { 1, 2,  3,  4,
    5, 6,  7,  8,
    9, 10, 2,  2,
    2, 1,  -4, 0 };

  swap_cols(A, 0, 0);
  ASSERT_EQ(A, A);

  swap_rows(A, 2, 2);
  ASSERT_EQ(A, A);
}

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
