/*
/ * sum.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
 */

#include <gtest/gtest.h>
#include "matrix.hpp"

using namespace mlib;



TEST(MatrixTest, trans_square_matrix)
{
  const Matrix<float, 3, 3> A =
  { 1, 2,  1,
    0, 1, -3,
    3, 5,  1 };

  const Matrix<float, 3, 3> res =
  { 1,  0, 3,
    2,  1, 5,
    1, -3, 1 };

  ASSERT_EQ(trans(A), res);
}

TEST(MatrixTest, trans_not_square_matrix)
{
  const Matrix<float, 2, 3> A =
  { 1, 2, 3,
    4, 5, 6 };

  const Matrix<float, 3, 2> res =
  { 1, 4,
    2, 5,
    3, 6 };

  ASSERT_EQ(trans(A), res);
}



int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
