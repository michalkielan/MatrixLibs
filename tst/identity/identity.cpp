/*
 * identity.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
 */


#include <gtest/gtest.h>

#include "matrix.hpp"

using namespace mlib;


TEST(MatrixTest, identity_3_3)
{
  const Matrix<unsigned int, 3, 3> A =
  { 1, 0, 0,
    0, 1, 0,
    0, 0, 1 };

  ASSERT_TRUE(isIdentity(A));
}

TEST(MatrixTest, identity_eye)
{
  auto A = eye<unsigned int, 100>();
  ASSERT_TRUE(isIdentity(A));
}


TEST(MatrixTest, identity_fill_one)
{
  auto A = fill<unsigned int, 50, 50>(1);
  ASSERT_FALSE(isIdentity(A));
}


TEST(MatrixTest, identity_ones)
{
  auto A = ones<4, 4>();
  ASSERT_FALSE(isIdentity(A));
}



int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
