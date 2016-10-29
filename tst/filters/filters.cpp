/*
/ * filters.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
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
