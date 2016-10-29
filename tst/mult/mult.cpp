/*
/ * sum.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
 */

#include <gtest/gtest.h>
#include "matrix.hpp"

using namespace mlib;


TEST(MatrixTest, multiply)
{
  const Matrix<int, 2, 3> A =
  { 1, 2, -1,
    4, 0, 6 };

  const Matrix<int, 3, 2> B =
  { 1,  3,
    0, -1,
    4,  5 };

  const Matrix<int, 2, 2> res =
  {
   -3, -4,
   28, 42
  };

  auto prod = A*B;

  ASSERT_EQ(prod, res);

  const Matrix<float, 2, 3> Af =
  { 1.34,   2.0914, -1.43014,
    4.0001, 0.0001, 6.000034 };

  const Matrix<float, 3, 2> Bf =
  { 1.3423,  3.09431,
    0.6542, -1.04391,
    4.0353,  5.091341 };

  const Matrix<float, 2, 2> resf =
  {
    -2.60417, -5.31819,
    29.5813,  42.9257
  };

  auto prodf = Af*Bf;

  ASSERT_TRUE(compare(prodf, resf, 0.0001f));
}


TEST(MatrixTest, multiply_strassen)
{
  const Matrix<int, 2, 2> A
  {
   3, -4,
   28, 42,
  };

  const Matrix<int, 2, 2> B
  {
    1, -4,
    0,  4,
  };

  ASSERT_EQ(strassen(A, B), (A * B));
}


TEST(MatrixTest, multiply_scalar)
{
  const Matrix<float, 2, 2> A =
  {  6, 1,
    -1, 0 };

  auto prod = A * 2.0f;

  const Matrix<float, 2, 2> res =
  { 12, 2,
    -2, 0 };

  ASSERT_EQ(prod, res);

  prod = 2.0f * A;

  ASSERT_EQ(prod, res);

  auto res1 = zeros<float, 2, 2>();
  prod = A * 0.0f;

  ASSERT_EQ(prod, res1);

}


int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
