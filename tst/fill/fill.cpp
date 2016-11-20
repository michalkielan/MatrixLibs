/**
 * @file fill.cpp
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


TEST(MatrixTest, fill)
{
  const auto A = fill<float, 5, 4>(5.4);

  const Matrix<float, 5, 4> res =
  { 5.4, 5.4, 5.4, 5.4,
    5.4, 5.4, 5.4, 5.4,
    5.4, 5.4, 5.4, 5.4,
    5.4, 5.4, 5.4, 5.4,
    5.4, 5.4, 5.4, 5.4 };

  ASSERT_EQ(A, res);
}

TEST(MatrixTest, fill_wrong)
{
  const auto A = fill<float, 5, 4>(5.4);

  const Matrix<float, 5, 4> res =
  { 5.4, 5.4, 5.4, 5,
    5.4, 5.4, 5.4, 5,
    5.4, 5.4, 5.4, 5,
    5.4, 5.4, 5.4, 5,
    5.4, 5.4, 5.4, 5 };

  ASSERT_NE(A, res);
}


int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
