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

  const Matrix<float, 3, 3> B =
  { 1,   2,  3,
    5,   6,  8,
    10, 11, 12};

  LU = lu(B);
  L = LU.first;
  U = LU.second;

  ASSERT_TRUE(compare(B, L*U, 0.0001f));

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
/*  print(A);
  std::cout << "\n";
  print(L);
  std::cout << "\n";
  print(U);
  std::cout << "\n";
  print(L*U);
  std::cout << "\n";
*/
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

TEST(MatrixTest, LU_4_4_bad_matrix_after_swap)
{
  const Matrix<float, 4, 4> B =
  {  5,     6,     7,     8,
     1,     2,     3,     4,
     10,    11,    12,    13,
     14,    15,    16,    17 };
  auto LU = lu(B);
  auto L = LU.first;
  auto U = LU.second;
/*  print(B);
  std::cout << "\n";
  print(L);
  std::cout << "\n";
  print(U);
  std::cout << "\n";
  print(L*U);
  std::cout << "\n";
*/
  ASSERT_TRUE(compare(B, L*U, 0.0001f));

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

TEST(MatrixTest, LU_9x9)
{
  const Matrix<float, 9, 9> B =
  {  5,     6,     7,     8,   32,   11,   32,   44,   12,
     1,     2,     3,     4,   41,   14,   19,   34,   88,
     1,     3,     4,     4,   41,   14,   17,   40,   88,
     1,     5,     5,     4,   41,   23,   10,   29,   88,
     1,     3,     6,     4,   41,   14,   15,   28,   88,
     1,     2,     6,     2,   53,   22,   16,   19,   88,
     1,     9,     3,     4,   41,   14,   25,   21,   88,
     10,    11,    12,    13,  11,   93,   83,   66,   45,
     14,    15,    16,    17,  12,   32,   56,   55,   56 };
  auto LU = lu(B);
  auto L = LU.first;
  auto U = LU.second;
/*  print(B);
  std::cout << "\n";
  print(L);
  std::cout << "\n";
  print(U);
  std::cout << "\n";
  print(L*U);
  std::cout << "\n";
*/
  ASSERT_EQ(B[5][7] , (L*U)[5][7]);
  ASSERT_TRUE(compare(B, L*U, 0.0001f));

}





int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
