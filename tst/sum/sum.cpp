/**
 * @file sum.cpp
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

TEST(MatrixTest, sum)
{
  const Matrix<float, 2, 2> A =
  { 1, 2,
    0, 1 };

  const Matrix<float, 2, 2> B =
  {  6, 1,
    -1, 0 };

  auto sum = A + B;

  Matrix<float, 2, 2> res =
  {  7, 3,
    -1, 1 };

  ASSERT_EQ(sum, res);

  auto sum2 = A++;
  
  constexpr Matrix<float, 2, 2> expected2 =
  { 2, 3,
    1, 2 };
  ASSERT_TRUE(compare(sum2,expected2,0.0001f));
}

TEST(MatrixTest, sum_scalar)
{
  const Matrix<float, 2, 2> A =
  {  6, 1,
    -1, 0 };

  auto sum = A + 1.0f;

  const Matrix<float, 2, 2> res =
  { 7, 2,
    0, 1 };

  ASSERT_EQ(sum, res);

  sum = 1.0f + A;

  ASSERT_EQ(sum, res);
}

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
