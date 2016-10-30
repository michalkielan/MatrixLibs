/*
/ * cholesky.cpp
 *
 *  Created on: Oct 30, 2016
 *      Author: JaroslawWiosna
 */

#include <gtest/gtest.h>
#include "matrix.hpp"

using namespace mlib;

TEST(MatrixTest, cholesky)
{
  const Matrix<float, 3, 3> A =
  {   4,  12, -16,
     12,  37, -43,
    -16, -43,  98 };
  const Matrix<float, 3, 3> LA =
  { 2, 0, 0,
    6, 1, 0,
   -8, 5, 3 };

  ASSERT_TRUE(isSymetric(A));
  ASSERT_FALSE(isSymetric(LA));
  ASSERT_TRUE(compare(chol(A)*trans(chol(A)), LA*trans(LA), 0.01f));

  const Matrix<float, 4, 4> B =
  { 1,  2,  4,   4,
    2,  5,  9,  15,
    4,  9, 42,  53,
    4, 15, 53, 102 };
  const Matrix<float, 4, 4> LB =
  { 1, 0, 0, 0,
    2, 1, 0, 0,
    4, 1, 5, 0,
    4, 7, 6, 1 };
  ASSERT_TRUE(compare(chol(B)*trans(chol(B)), LB*trans(LB), 0.01f));
}


int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
