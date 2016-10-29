/*
 * eye.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
 */


#include <iostream>
#include <gtest/gtest.h>

#include "matrix.hpp"

using namespace mlib;

TEST(MatrixTest, eye)
{
  const auto A = eye<float, 4>();

  const Matrix<float, 4, 4> resA =
  { 1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1 };

  ASSERT_EQ(A, resA);

  const auto B = eye<float, 3>(7);

  const Matrix<float, 3, 3> resB =
  { 7, 0, 0,
    0, 7, 0,
    0, 0, 7 };

  ASSERT_EQ(B, resB);
}

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
