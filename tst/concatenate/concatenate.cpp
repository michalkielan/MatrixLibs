/*
 * concatenate.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
 */
#include <gtest/gtest.h>

#include "matrix.hpp"

using namespace mlib;


TEST(MatrixTest, concatenate)
{
  const Matrix<float, 2, 2> A =
  { 4, 3,
    6, 3};
  const Matrix<float, 3, 2> B =
  { 10, 12,
    15, 13,
    17, 11};
  const Matrix<float, 5, 2> expected_AB =
  { 4, 3,
    6, 3,
    10, 12,
    15, 13,
    17, 11};

  auto AB = concatenate(A,B);
  ASSERT_TRUE(compare(expected_AB, AB, 0.0001f));

  const Matrix<float, 2, 3> C =
  { 4, 3, 1,
    6, 3, 1};
  const Matrix<float, 2, 2> D =
  { 10, 12,
    15, 13};
  const Matrix<float, 2, 5> expected_CD =
  { 4, 3, 1, 10, 12,
    6, 3, 1, 15, 13};

  auto CD = concatenate(C,D);
  ASSERT_TRUE(compare(expected_CD, CD, 0.0001f));

  const Matrix<float, 2, 2> E =
  { 4, 3,
    6, 3};

  const Matrix<float, 2, 2> F =
  { 10, 12,
    15, 13};

  const Matrix<float, 4, 2> expected_EF =
  { 4, 3,
    6, 3,
   10, 12,
   15, 13};

  auto EF = concatenateV(E,F);
  ASSERT_TRUE(compare(expected_EF, EF, 0.0001f));

  const Matrix<float, 2, 2> G =
  { 4, 3,
    6, 3};

  const Matrix<float, 2, 2> H =
  { 10, 12,
    15, 13};

  const Matrix<float, 2, 4> expected_GH =
  { 4, 3, 10, 12,
    6, 3, 15, 13};

  auto GH = concatenateH(G,H);
  ASSERT_TRUE(compare(expected_GH, GH, 0.0001f));

  const Matrix<float, 2, 2> I =
  { 4, 3,
    6, 3};

  const Matrix<float, 2, 2> J =
  { 10, 12,
    15, 13};

  const Matrix<float, 4, 2> expected_IJ =
  { 4, 3,
    6, 3,
   10, 12,
   15, 13};

  Matrix<float, 4, 2> IJ = concatenate(I,J).first;
  ASSERT_TRUE(compare(expected_IJ, IJ, 0.0001f));
}


int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
