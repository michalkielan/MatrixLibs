/*
 * getminor.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
 */
#include <gtest/gtest.h>
#include "matrix.hpp"

using namespace mlib;

TEST(MatrixTest, getminor_3_3)
{
  const Matrix<float, 3, 3> A =
  { 1, 2, 3,
    4, 5, 6,
    7, 8, 9 };

  const Matrix<float, 2, 2> Aminor2x2 =
  { 1, 2,
    4, 5 };

  ASSERT_TRUE(compare(getminor(A,2,2), Aminor2x2, 0.01f));

}

TEST(MatrixTest, getminor_4_4)
{

  const Matrix<float, 4, 4> A =
  { 1,  2,  3,  4,
    2,  3,  1,  2,
    1,  1,  1, -1,
    1,  0, -2, -6};

  const Matrix<float, 3, 3> minor0x0 =
  { 3,  1,  2,
    1,  1, -1,
    0, -2, -6};

  ASSERT_TRUE(compare(getminor(A,0,0), minor0x0, 0.01f));

  const Matrix<float, 3, 3> minor1x1 =
  { 1,  3,  4,
    1,  1, -1,
    1, -2, -6};

  ASSERT_TRUE(compare(getminor(A,1,1), minor1x1, 0.01f));
}


int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
