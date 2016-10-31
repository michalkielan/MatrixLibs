/*
/ * sum.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
 */

#include <gtest/gtest.h>
#include "matrix.hpp"

using namespace mlib;


TEST(MatrixTest, LU_3x3)
{
  const Matrix<float, 3, 3> A =
  { 5, 3, 2,
    1, 2, 0,
    3, 0, 4};

  auto LU = lu(A);
  auto L = LU.first;
  auto U = LU.second;

  const Matrix<float, 3, 3> expected_L =
  {     1,      0, 0,
    1/5.0,      1, 0,
    3/5.0, -9/7.0, 1};

  ASSERT_TRUE(compare(expected_L, L, 0.0001f));

  const Matrix<float, 3, 3> expected_U =
  { 5,     3,      2,
    0, 7/5.0, -2/5.0,
    0,     0, 16/7.0};

  ASSERT_TRUE(compare(expected_U, U, 0.0001f));
  ASSERT_TRUE(compare(A, L*U, 0.0001f));
}


TEST(MatrixTest, LU_2x2)
{
  const Matrix<float, 2, 2> A =
  { 4, 3,
    6, 3};

  auto LU = lu(A);
  auto L = LU.first;
  auto U = LU.second;

  const Matrix<float, 2, 2> expected_L =
  { 1, 0,
  1.5, 1};

  ASSERT_TRUE(compare(expected_L, L, 0.0001f));

  const Matrix<float, 2, 2> expected_U =
  { 4,    3,
    0, -1.5};

  ASSERT_TRUE(compare(expected_U, U, 0.0001f));
  ASSERT_TRUE(compare(A, L*U, 0.0001f));

}


TEST(MatrixTest, LU_4_4_bad_matrix)
{
  const Matrix<float, 4, 4> A =
  {  1,     2,     3,     4,
     5,     6,     7,     8,
     10,    11,    12,    13,
     14,    15,    16,    17 };
  auto LU = lu(A);
  auto L = LU.first;
  auto U = LU.second;
  ASSERT_TRUE(compare(A, L*U, 0.0001f));
/*
  try
  {
    auto LU = lu(A);
  }

  catch(std::exception& e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
    ASSERT_TRUE(true);
  }
*/
}


TEST(MatrixTest, LU_3_3_LU_workaround)
{
  Matrix<float, 3, 3> A =
  { 1, 2, 3,
    2, 4, 5,
    1, 3, 4 };

  try
  {
    swap_rows(A, 1, 2);

    auto LU = lu(A);
    auto L = LU.first;
    auto U = LU.second;

    ASSERT_TRUE(compare(A, L*U, 0.0001f));
  }

  catch(std::exception& e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
    ASSERT_TRUE(false);
  }

}




int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
