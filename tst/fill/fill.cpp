/*
 * fill.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
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
