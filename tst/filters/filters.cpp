/**
 * @file filters.cpp
 *
 * @date Oct 29, 2016
 *
 * @author Jaroslaw Wiosna
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


TEST(MatrixTest, stats)
{
  constexpr float eps = 0.01f;

  const Matrix<float, 3, 3> A =
  { 1, 2, 3,
    4, 5, 6,
    7, 8, 9 };
  ASSERT_TRUE((mean(A)   - 5)             < eps);
  ASSERT_TRUE((median(A) - 5)             < eps);
  ASSERT_TRUE((var(A)    - 6.66667)       < eps);
  ASSERT_TRUE((stddev(A) - sqrt(6.66667)) < eps);

  const Matrix<float, 3, 3> B =
  { 2, 2, 2,
    5, 5, 5,
    8, 8, 8 };

  ASSERT_TRUE((mean(B)   - 5)       < eps);
  ASSERT_TRUE((median(B) - 5)       < eps);
  ASSERT_TRUE((var(B)    - 6)       < eps);
  ASSERT_TRUE((stddev(B) - sqrt(6)) < eps);
}



int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
