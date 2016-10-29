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
  {0.11111111, 0.11111111, 0.11111111,
   0.11111111, 0.11111111, 0.11111111,
   0.11111111, 0.11111111, 0.11111111 };

  const Matrix<float, 7, 7> conv_full =
 { 1, 2,  3,  3,  3,  2, 1,
   3, 6,  9, 10, 11,  8, 4,
   4, 8, 12, 13, 14, 10, 5,
   4, 8, 12, 13, 14, 10, 5,
   3, 6,  9,  9,  9,  6, 3,
   2, 4,  6,  6,  6,  4, 2, 
   1, 2,  3,  3,  3,  2, 1 };

  const Matrix<float, 5, 5> conv_same =
 { 6,  9, 10, 11,  8,
   8, 12, 13, 14, 10,
   8, 12, 13, 14, 10,
   6,  9,  9,  9,  6,
   4,  6,  6,  6,  4 };

  const Matrix<float, 3, 3> conv_valid =
 { 12, 13, 14,
   12, 13, 14,
    9,  9,  9, }; 

  ASSERT_TRUE(compare(conv_same, conv2(A,kernel), 0.1f));
  ASSERT_TRUE(compare(conv_full, conv2_full(A,kernel), 0.0001f));
  ASSERT_TRUE(compare(conv_valid, conv2_valid(A,kernel), 0.0001f));
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
  { 30, 20, 20, 20, 30,
    20,  5,  1,  1, 16,
    20,  5,  1, 41, 16,
    20,  5,  1,  1, 16,
    30, 20, 20, 20, 30};

  auto after = conv2(A, kernel);

  ASSERT_TRUE(compare(expected_after, after, 0.0001f));
}


int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}




