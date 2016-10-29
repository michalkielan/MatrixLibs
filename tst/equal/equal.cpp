/*
/ * sum.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
 */

#include <gtest/gtest.h>
#include "matrix.hpp"

using namespace mlib;


TEST(MatrixTest, equal)
{
  const Matrix<float, 2, 2> A =
  { 1, 2,
    0, 1};

  const Matrix<float, 2, 2> B =
  { 1, 2,
    0, 1 };

  ASSERT_EQ(A, B);
}

TEST(MatrixTest, not_equal)
{
  const Matrix<float, 2, 2> A =
  { 1, 2,
    0, 1 };

  const Matrix<float, 2, 2> B =
  { 1, 2,
    0, 0 };

  ASSERT_FALSE((A == B));
}




int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

