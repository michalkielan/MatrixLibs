/*
/ * sum.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
 */

#include <gtest/gtest.h>
#include "matrix.hpp"

using namespace mlib;

TEST(MatrixTest, det_2_2)
{
  const Matrix<float, 2, 2> A =
  { 1, 2,
    0, 1 };

  ASSERT_EQ(det(A), 1);

}

TEST(MatrixTest, det_3_3)
{
  const Matrix<float, 3, 3> A =
  { 1, 2,  1,
    0, 1, -3,
    3, 5,  1 };

  ASSERT_EQ(det(A), -5);

}

TEST(MatrixTest, det_4_4)
{
  const Matrix<float, 4, 4> A =
  { 1, 2,  3,  4,
    5, 6,  7,  8,
    9, 10, 2,  2,
    2, 1,  -4, 0 };

  ASSERT_EQ(det(A), 196);


  const Matrix<float, 4, 4> B =
  { 1,  0,  4, -2,
    0, -5,  3,  1,
   -4,  5,  1,  0,
    1,  0, -1,  2};

  ASSERT_EQ(det(B), -225);

}

TEST(MatrixTest, det_5_5)
{
  const Matrix<float, 5, 5> A =
  {  1,    0,    2,    3,    5,
     7,    6,  - 4,    0,    1,
   - 1,  - 4,    0,    5,    1,
     2,  - 4,    3,  - 5,    0,
     1,    2,    5,  - 3,    0 };

  ASSERT_EQ(static_cast<int>(det(A)), -6040);

}

TEST(MatrixTest, det_9_9)
{
  const Matrix<float, 9, 9> A =
  {  1,    0,    2,    3,    5,    4,    1,    0,    1,
     7,    6,  - 4,    0,    1,    6,    0,    0,    0,
   - 1,  - 4,    0,    5,    1,    5,    4,    6,    2,
     2,  - 4,    3,  - 5,    0,    0,    0,    0,  - 1,
     1,    2,    5,  - 3,    0,    0,    0,    3,  - 3,
     7,    6,  - 4,    0,    1,    6,    0,  - 1,    0,
   - 1,  - 7,  - 2,    5,    1,    2,    4,    5,    1,
     2,  - 4,    0,  - 5,  - 3,    0,    0,    0,    2,
     1,    5,    3,  - 3,    0,    0,    0,    3,    1 };

  ASSERT_EQ(static_cast<int>(det(A)), static_cast<int>(89931.29104));

}



int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
