/**
 * @file lu.cpp
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


TEST(MatrixTest, LU_3x3)
{
  const Matrix<float, 3, 3> A =
  { 5, 3, 2,
    1, 2, 0,
    3, 0, 4};

  auto LU = lu(A);
  auto&& L = LU.first;
  auto&& U = LU.second;

  const Matrix<float, 3, 3> expected_L =
  {     1,      0, 0,
    1/5.0,      1, 0,
    3/5.0, -9/7.0, 1};

  ASSERT_TRUE(compare(expected_L, L, 0.0001f));

  const Matrix<float, 3, 3> expected_U =
  { 5,     3,      2,
    0, 7/5.0, -2/5.0,
    0,     0, 16/7.0};

  ASSERT_TRUE(compare(expected_U, U, 0.0001f));

  const Matrix<float, 3, 3> random =
  { 1,     1,  -1000,
    1, 7/5.0, -2/5.0,
    1,     1,      1};

  ASSERT_FALSE(compare(random, U, 0.0001f));
}


TEST(MatrixTest, LU_2x2)
{
  const Matrix<float, 2, 2> A =
  { 4, 3,
    6, 3};

  auto LU = lu(A);
  auto L = LU.first;
  auto U = LU.second;

  const Matrix<float, 2, 2> expected_L =
  { 1, 0,
  1.5, 1};

  ASSERT_TRUE(compare(expected_L, L, 0.0001f));

  const Matrix<float, 2, 2> expected_U =
  { 4,    3,
    0, -1.5};

  ASSERT_TRUE(compare(expected_U, U, 0.0001f));

  const Matrix<float, 2, 2> random =
   { 4.0f, 12.0f,
     9.0f, 12.0f};

  ASSERT_FALSE(compare(random, U, 0.0001f));
}



int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
