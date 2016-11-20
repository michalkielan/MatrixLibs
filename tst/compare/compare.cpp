/**
 * @file compare.cpp
 *
 * @date Oct 27, 2016
 *
 * @author Michal Kielan
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include <gtest/gtest.h>

#include "matrix.hpp"

using namespace mlib;

TEST(MatrixTest, compare_failed)
{
  Matrix<float, 2, 2> A =
  { 1, 2,
    0, 1 };

  const Matrix<float, 2, 2> B =
  {  6, 1,
    -1, 0 };

  ASSERT_FALSE(compare(A, B, 0.0001f));
}

TEST(MatrixTest, compare_failed_float)
{
  const Matrix<float, 2, 2> C =
  { 1.0,    2.000005,
    1.0001, 1.01 };

  const Matrix<float, 2, 2> D =
  { 1.1,    2.000009,
    1.0005, 1.05 };

  ASSERT_FALSE(compare(C, D, 0.00001f));
}

TEST(MatrixTest, compare_2_2)
{

  const Matrix<float, 2, 2> E =
  { -1.1,    -2.00000,
    -1.0001, -1.01 };

  const Matrix<float, 2, 2> F =
  { -1.1,    -2.00000,
    -1.0001, -1.01 };

  ASSERT_TRUE(compare(E, F, 0.01f));
}

TEST(MatrixTest, compare_failed_epsilon)
{

  const Matrix<float, 2, 2> G =
  { 1.1,    2.00000,
    1.0001, 1.01 };

  const Matrix<float, 2, 2> H =
  { -1.1,    -2.00000,
    -1.0001, -1.01 };

  ASSERT_FALSE(compare(G, H, 0.01f));
}


int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

