/*
 * ones.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
 */

#include <gtest/gtest.h>
#include "matrix.hpp"

using namespace mlib;

TEST(MatrixTest, one)
{
  const auto A = ones<4, 4>();

  const Matrix<unsigned int, 4, 4> res =
  { 1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1 };

  ASSERT_EQ(A, res);
}


TEST(MatrixTest, one_1)
{
  const auto A = ones<1, 1>();

  const Matrix<unsigned int, 1, 1> res =
  { 1 };

  ASSERT_EQ(A, res);
}


int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
