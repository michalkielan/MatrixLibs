/*
 * sum.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
 */

#include <gtest/gtest.h>
#include "matrix.hpp"

using namespace mlib;

TEST(MatrixTest, sum)
{
  const Matrix<float, 2, 2> A =
  { 1, 2,
    0, 1 };

  const Matrix<float, 2, 2> B =
  {  6, 1,
    -1, 0 };

  auto sum = A + B;

  Matrix<float, 2, 2> res =
  {  7, 3,
    -1, 1 };

  ASSERT_EQ(sum, res);

}

TEST(MatrixTest, sum_scalar)
{
  const Matrix<float, 2, 2> A =
  {  6, 1,
    -1, 0 };

  auto sum = A + 1.0f;

  const Matrix<float, 2, 2> res =
  { 7, 2,
    0, 1 };

  ASSERT_EQ(sum, res);

  sum = 1.0f + A;

  ASSERT_EQ(sum, res);
}

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
