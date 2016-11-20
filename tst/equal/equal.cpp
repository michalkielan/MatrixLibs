/**
 * @file equal.cpp
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


TEST(MatrixTest, equal)
{
  const Matrix<float, 2, 2> A =
  { 1, 2,
    0, 1};

  const Matrix<float, 2, 2> B =
  { 1, 2,
    0, 1 };

  ASSERT_EQ(A, B);
}

TEST(MatrixTest, not_equal)
{
  const Matrix<float, 2, 2> A =
  { 1, 2,
    0, 1 };

  const Matrix<float, 2, 2> B =
  { 1, 2,
    0, 0 };

  ASSERT_FALSE((A == B));
}




int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

