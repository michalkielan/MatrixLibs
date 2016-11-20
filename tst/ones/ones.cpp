/**
 * @file ones.cpp
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

TEST(MatrixTest, one)
{
  const auto A = ones<4, 4>();

  const Matrix<unsigned int, 4, 4> res =
  { 1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1 };

  ASSERT_EQ(A, res);
}


TEST(MatrixTest, one_1)
{
  const auto A = ones<1, 1>();

  const Matrix<unsigned int, 1, 1> res =
  { 1 };

  ASSERT_EQ(A, res);
}


int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
