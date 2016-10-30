/*
/ * sub.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
 */

#include <gtest/gtest.h>
#include "matrix.hpp"

using namespace mlib;


TEST(MatrixTest, sub)
{

}

TEST(MatrixTest, sub_scalar)
{
  const Matrix<float, 2, 2> A =
  {  6, 1,
    -1, 0 };

  auto sub = A - 1.0f;

  const Matrix<float, 2, 2> res =
  {  5,  0,
    -2, -1 };

  ASSERT_EQ(sub, res);

  auto sub2 = A--;

  constexpr Matrix<float, 2, 2> expected2 =
  {  5,  0,
    -2, -1 };
  ASSERT_TRUE(compare(sub2,expected2,0.0001f));
}


int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
