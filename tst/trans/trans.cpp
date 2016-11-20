/**
 * @file trans.cpp
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



TEST(MatrixTest, trans_square_matrix)
{
  const Matrix<float, 3, 3> A =
  { 1, 2,  1,
    0, 1, -3,
    3, 5,  1 };

  const Matrix<float, 3, 3> res =
  { 1,  0, 3,
    2,  1, 5,
    1, -3, 1 };

  ASSERT_EQ(trans(A), res);
}

TEST(MatrixTest, trans_not_square_matrix)
{
  const Matrix<float, 2, 3> A =
  { 1, 2, 3,
    4, 5, 6 };

  const Matrix<float, 3, 2> res =
  { 1, 4,
    2, 5,
    3, 6 };

  ASSERT_EQ(trans(A), res);
}



int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
