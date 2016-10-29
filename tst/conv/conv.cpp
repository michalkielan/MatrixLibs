/*
 * conv.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
 */


#include <gtest/gtest.h>

#include "matrix.hpp"

using namespace mlib;

TEST(MatrixTest, conv_1)
{
  const Matrix<float, 5, 5> A =
  { 9,  9,  9,  9,  9,
   18, 18, 18, 27, 27,
    9,  9,  9,  9,  9,
    9,  9,  9,  9,  9,
    9,  9,  9,  9,  9};

  Matrix<float, 3, 3> kernel =
  {1/9, 1/9, 1/9,
   1/9, 1/9, 1/9,
   1/9, 1/9, 1/9 };

  const Matrix<float, 5, 5> expected_after_conv =
 { 0,  0,  0,  0, 0,
   0, 12, 13, 14, 0,
   0, 12, 13, 14, 0,
   0,  9,  9,  9, 0,
   0,  0,  0,  0, 0};

  auto after_conv = conv2(A,kernel);

  ASSERT_TRUE(compare(expected_after_conv, after_conv, 0.0001f));

}

TEST(MatrixTest, conv_highpass)
{

  const Matrix<float, 5, 5> A =
 { 5, 5, 5, 5, 5,
   5, 5, 5, 5, 5,
   5, 5, 5, 9, 5,
   5, 5, 5, 5, 5,
   5, 5, 5, 5, 5 };

  Matrix<float, 3, 3> kernel =
  {-1, -1, -1,
   -1,  9, -1,
   -1, -1, -1 };

  const Matrix<float, 5, 5> expected_after =
  { 0, 0, 0,  0, 0,
    0, 5, 1,  1, 0,
    0, 5, 1, 41, 0,
    0, 5, 1,  1, 0,
    0, 0, 0,  0, 0};

  auto after = conv2(A, kernel);

  ASSERT_TRUE(compare(expected_after, after, 0.0001f));
}


int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}




