/*
/ * sum.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
 */

#include <gtest/gtest.h>
#include "matrix.hpp"

using namespace mlib;


TEST(MatrixTest, zeros_sqr)
{
  const auto A = zeros<unsigned int, 4, 4>();

  const Matrix<unsigned int, 4, 4> res =
  { 0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0 };

  ASSERT_EQ(A, res);
}


TEST(MatrixTest, zeros_2_4)
{
  const auto A = zeros<unsigned int, 2, 4>();

  const Matrix<unsigned int, 2, 4> res =
  { 0, 0, 0, 0,
    0, 0, 0, 0 };

  ASSERT_EQ(A, res);
}

TEST(MatrixTest, zeros_4_2)
{
  const auto A = zeros<unsigned int, 4, 2>();

  const Matrix<unsigned int, 4, 2> res =
  { 0, 0,
    0, 0,
    0, 0,
    0, 0 };

  ASSERT_EQ(A, res);
}



TEST(MatrixTest, zeros_1_1)
{
  const auto A = zeros<unsigned int, 1, 1>();

  const Matrix<unsigned int, 1,1> res =
  { 0 };

  ASSERT_EQ(A, res);
}




int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

