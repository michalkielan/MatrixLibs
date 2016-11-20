/**
 * @file zeros.cpp
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


TEST(MatrixTest, zeros_sqr)
{
  const auto A = zeros<unsigned int, 4, 4>();

  const Matrix<unsigned int, 4, 4> res =
  { 0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0 };

  ASSERT_EQ(A, res);
}


TEST(MatrixTest, zeros_2_4)
{
  const auto A = zeros<unsigned int, 2, 4>();

  const Matrix<unsigned int, 2, 4> res =
  { 0, 0, 0, 0,
    0, 0, 0, 0 };

  ASSERT_EQ(A, res);
}

TEST(MatrixTest, zeros_4_2)
{
  const auto A = zeros<unsigned int, 4, 2>();

  const Matrix<unsigned int, 4, 2> res =
  { 0, 0,
    0, 0,
    0, 0,
    0, 0 };

  ASSERT_EQ(A, res);
}



TEST(MatrixTest, zeros_1_1)
{
  const auto A = zeros<unsigned int, 1, 1>();

  const Matrix<unsigned int, 1,1> res =
  { 0 };

  ASSERT_EQ(A, res);
}




int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

