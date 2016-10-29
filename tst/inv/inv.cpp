/*
/ * sum.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
 */

#include <gtest/gtest.h>
#include "matrix.hpp"

using namespace mlib;


TEST(MatrixTest, inv_2_2)
{
  const Matrix<float, 2, 2> A =
  { 1, 2,
    0, 1 };

  const Matrix<float, 2, 2> invA =
  { 1, -2,
    0, 1 };

  ASSERT_EQ(inv(A), invA);

}

TEST(MatrixTest, inv_3_3)
{

  const Matrix<float, 3, 3> A =
  { -2, 5, 1,
     3, 0, 1,
     1, 1, 2 };

  const Matrix<float, 3, 3> invA =
  {  0.05,  0.45, -0.25,
     0.25,  0.25, -0.25,
    -0.15, -0.35,  0.55 };

  ASSERT_TRUE(compare(inv(A), invA, 0.01f));

}

TEST(MatrixTest, inv_4_4)
{

  const Matrix<float, 4, 4> A =
  { 1,  2,  3,  4,
    2,  3,  1,  2,
    1,  1,  1, -1,
    1,  0, -2, -6};

  const Matrix<float, 4, 4> invA =
  { 22, -6, -26,  17,
   -17,  5,  20, -13,
    -1,  0,   2,  -1,
     4, -1,  -5,   3};

  ASSERT_TRUE(compare(inv(A), invA, 0.01f));
}



int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
