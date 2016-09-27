//============================================================================
// Name        : MatrixEmbedded.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <gtest/gtest.h>
#include "matrix.hpp"


class MatrixTest : public ::testing::Test
{
  protected:
    void SetUp() override {}
    void TearDown() override {}

    template<typename T, std::size_t I, std::size_t J>
    void print(const Matrix<T, I, J>& A)
    {
      for (std::size_t i = 0; i < I; i++)
      {
        for (std::size_t j = 0; j < J; j++)
        {
          std::cout << A[i][j] << " ";
        }
        std::cout << std::endl;
      }
    }
};


TEST_F(MatrixTest, create_matrix)
{

}

TEST_F(MatrixTest, equal)
{
  const Matrix<float, 2, 2> A =
  { 1, 2,
    0, 1 };

  const Matrix<float, 2, 2> B =
  { 1, 2,
    0, 1 };

  ASSERT_EQ(A, B);
}

TEST_F(MatrixTest, not_equal)
{
  const Matrix<float, 2, 2> A =
  { 1, 2,
    0, 1 };

  const Matrix<float, 2, 2> B =
  { 1, 2,
    0, 0 };

  ASSERT_NE(A, B);
}

TEST_F(MatrixTest, sum)
{
  const Matrix<float, 2, 2> A =
  { 1, 2,
    0, 1 };

  const Matrix<float, 2, 2> B =
  {  6, 1,
    -1, 0 };

  auto sum = A + B;

  const Matrix<float, 2, 2> res =
  {  7, 3,
    -1, 1 };

  ASSERT_EQ(sum, res);

}

TEST_F(MatrixTest, sum_scalar)
{
  const Matrix<float, 2, 2> A =
  {  6, 1,
    -1, 0 };

  auto sum = A + 1.0f;

  const Matrix<float, 2, 2> res =
  { 7, 2,
    0, 1 };

  ASSERT_EQ(sum, res);

  sum = 1.0f + A;

  ASSERT_EQ(sum, res);

}

TEST_F(MatrixTest, multiply)
{
  const Matrix<int, 2, 3> A =
  { 1, 2, -1,
    4, 0, 6 };

  const Matrix<int, 3, 2> B =
  { 1,  3,
    0, -1,
    4,  5 };

  const Matrix<int, 2, 2> res =
  {
   -3, -4,
   28, 42
  };

  auto prod = A*B;

  ASSERT_EQ(prod, res);

  const Matrix<float, 2, 3> Af =
  { 1.34,   2.0914, -1.43014,
    4.0001, 0.0001, 6.000034 };

  const Matrix<float, 3, 2> Bf =
  { 1.3423,  3.09431,
    0.6542, -1.04391,
    4.0353,  5.091341 };

  const Matrix<float, 2, 2> resf =
  {
    -2.60417, -5.31819,
    29.5813,  42.9257
  };

  auto prodf = Af*Bf;
  auto isEqual = compare(prodf, resf, 0.0001f);

  ASSERT_TRUE(isEqual);

}


TEST_F(MatrixTest, multiply_strassen)
{
  const Matrix<int, 2, 2> A
  {
   3, -4,
   28, 42, 
  };

  const Matrix<int, 2, 2> B
  {
    1, -4,
    0,  4,
  };

  auto isEqual = (strassen(A, B) == (A * B));
  ASSERT_TRUE(isEqual);
}


TEST_F(MatrixTest, multiply_scalar)
{
  const Matrix<float, 2, 2> A =
  {  6, 1,
    -1, 0 };

  auto prod = A * 2.0f;

  const Matrix<float, 2, 2> res =
  { 12, 2,
    -2, 0 };

  ASSERT_EQ(prod, res);

  prod = 2.0f * A;

  ASSERT_EQ(prod, res);

  auto res1 = zeros<float, 2, 2>();
  prod = A * 0.0f;

  ASSERT_EQ(prod, res1);

}

TEST_F(MatrixTest, sub)
{

}

TEST_F(MatrixTest, sub_scalar)
{
  const Matrix<float, 2, 2> A =
  {  6, 1,
    -1, 0 };

  auto sub = A - 1.0f;

  const Matrix<float, 2, 2> res =
  {  5,  0,
    -2, -1 };

  ASSERT_EQ(sub, res);
}

TEST_F(MatrixTest, det)
{
  const Matrix<float, 2, 2> A =
  { 1, 2,
    0, 1 };

  auto detA = det(A);
  auto resA = 1;

  ASSERT_EQ(detA, resA);

  const Matrix<float, 3, 3> B =
  { 1, 2,  1,
    0, 1, -3,
    3, 5,  1 };

  auto detB = det(B);
  auto resB = -5;

  ASSERT_EQ(detB, resB);
}

TEST_F(MatrixTest, identity)
{
  const Matrix<unsigned int, 3, 3> A =
  { 1, 0, 0,
    0, 1, 0,
    0, 0, 1 };

  auto res = isIdentity(A);
  ASSERT_TRUE(res);

  auto B = eye<unsigned int, 100>();

  res = isIdentity(B);
  ASSERT_TRUE(res);

  auto C = fill<unsigned int, 50, 50>(4);

  res = isIdentity(C);
  ASSERT_FALSE(res);
}

TEST_F(MatrixTest, inv)
{


//  const Matrix<float, 2, 2> A =
//  { 1, 2,
//    0, 1 };
//
//  auto invA = inv(A);
//
//  print(invA);
////  auto res ;
//
////  ASSERT_EQ(detA, res);
//
//  const Matrix<float, 3, 3> B =
//  { 1, 2,  1,
//    0, 1, -3,
//    3, 5,  1 };
//
//  auto invB = inv(B);
//
//  print(invB);
 // res = -5;

//  ASSERT_EQ(detB, res);

//    const Matrix<int, 3, 3> A =
//    { 1, 2,  1,
//      0, 1, -3,
//      3, 5,  1 };

   // auto LU = lu(A);
    //auto&& L = LU.first;
   // auto&& U = LU.second;

//    print(L);

  const Matrix<float, 3, 3> B =
  { -2, 5, 1,
     3, 0, 1,
     1, 1, 2 };

  auto invB = inv(B);
  const Matrix<float, 3, 3> expected_invB =
  {  0.05,  0.45, -0.25,
     0.25,  0.25, -0.25,
    -0.15, -0.35,  0.55 };
  auto areEqualsB = compare(expected_invB, invB, 0.0001f);

  ASSERT_TRUE(areEqualsB);
}

TEST_F(MatrixTest, trans_square_matrix)
{
  const Matrix<float, 3, 3> A =
  { 1, 2,  1,
    0, 1, -3,
    3, 5,  1 };

  const auto transA = trans(A);

  const Matrix<float, 3, 3> res =
  { 1,  0, 3,
    2,  1, 5,
    1, -3, 1 };

  ASSERT_EQ(transA, res);
}

TEST_F(MatrixTest, trans_not_square_matrix)
{
  const Matrix<float, 2, 3> A =
  { 1, 2, 3,
    4, 5, 6 };

  const auto transA = trans(A);

  const Matrix<float, 3, 2> res =
  { 1, 4,
    2, 5,
    3, 6 };

  ASSERT_EQ(transA, res);
}

TEST_F(MatrixTest, eye)
{
  const auto A = eye<float, 4>();

  const Matrix<float, 4, 4> resA =
  { 1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1 };

  ASSERT_EQ(A, resA);

  const auto B = eye<float, 3>(7);

  const Matrix<float, 3, 3> resB =
  { 7, 0, 0,
    0, 7, 0,
    0, 0, 7 };

  ASSERT_EQ(B, resB);
}

TEST_F(MatrixTest, fill)
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

TEST_F(MatrixTest, one)
{
  const auto A = ones<4, 4>();

  const Matrix<unsigned int, 4, 4> res =
  { 1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1 };

  ASSERT_EQ(A, res);
}

TEST_F(MatrixTest, zeros)
{
  const auto A = zeros<unsigned int, 4, 4>();

  const Matrix<unsigned int, 4, 4> res =
  { 0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0 };

  ASSERT_EQ(A, res);
}

TEST_F(MatrixTest, compare)
{
  const Matrix<float, 2, 2> A =
  { 1, 2,
    0, 1 };

  const Matrix<float, 2, 2> B =
  {  6, 1,
    -1, 0 };

  auto areEquals = compare(A, B, 0.0001f);
  ASSERT_FALSE(areEquals);

  const Matrix<float, 2, 2> C =
  { 1.0,    2.000005,
    1.0001, 1.01 };

  const Matrix<float, 2, 2> D =
  { 1.1,    2.000009,
    1.0005, 1.05 };

  areEquals = compare(C, D, 0.00001f);
  ASSERT_FALSE(areEquals);

  const Matrix<float, 2, 2> E =
  { -1.1,    -2.00000,
    -1.0001, -1.01 };

  const Matrix<float, 2, 2> F =
  { -1.1,    -2.00000,
    -1.0001, -1.01 };

  areEquals = compare(E, F, 0.01f);
  ASSERT_TRUE(areEquals);

  const Matrix<float, 2, 2> G =
  { 1.1,    2.00000,
    1.0001, 1.01 };

  const Matrix<float, 2, 2> H =
  { -1.1,    -2.00000,
    -1.0001, -1.01 };

  areEquals = compare(G, H, 0.01f);
  ASSERT_FALSE(areEquals);
}

TEST_F(MatrixTest, pow)
{
  const Matrix<float, 2, 2> A
  {
    1, 2,
    3, 4
  };

   auto isEqual = eye<float, 2>() == pow(A,0);
   ASSERT_TRUE(isEqual);

   isEqual = (A) == pow(A,1);
   ASSERT_TRUE(isEqual);

   isEqual = (A*A) == pow(A,2);
   ASSERT_TRUE(isEqual);

   isEqual = (A*A*A) == pow(A,3);
   ASSERT_TRUE(isEqual);

   isEqual = (A*A*A*A) == pow(A,4);
   ASSERT_TRUE(isEqual);

   auto invA = inv(A);

   isEqual = (invA) == pow(A,-1);
   ASSERT_TRUE(isEqual);

   isEqual = (invA*invA) == pow(A,-2);
   ASSERT_TRUE(isEqual);

   isEqual = (invA*invA*invA) == pow(A,-3);
   ASSERT_TRUE(isEqual);

   isEqual = (invA*invA*invA*invA) == pow(A,-4);
   ASSERT_TRUE(isEqual);

}

TEST_F(MatrixTest, LU_3x3)
{
  const Matrix<float, 3, 3> A =
  { 5, 3, 2,
    1, 2, 0,
    3, 0, 4};

  auto LU = lu(A);
  auto&& L = LU.first;
  auto&& U = LU.second;

  const Matrix<float, 3, 3> expected_L =
  {     1,      0, 0,
    1/5.0,      1, 0,
    3/5.0, -9/7.0, 1};
  auto areEqualsL = compare(expected_L, L, 0.0001f);
  ASSERT_TRUE(areEqualsL);

  const Matrix<float, 3, 3> expected_U =
  { 5,     3,      2,
    0, 7/5.0, -2/5.0,
    0,     0, 16/7.0};

  auto areEqualsU = compare(expected_U, U, 0.0001f);
  ASSERT_TRUE(areEqualsU);

  const Matrix<float, 3, 3> random =
  { 1,     1,  -1000,
    1, 7/5.0, -2/5.0,
    1,     1,      1};

  auto areNotEqualsU = compare(random, U, 0.0001f);
  ASSERT_FALSE(areNotEqualsU);
}


TEST_F(MatrixTest, LU_2x2)
{
  const Matrix<float, 2, 2> A =
  { 4, 3,
    6, 3};

    auto LU = lu(A);
    auto&& L = LU.first;
    auto&& U = LU.second;

  const Matrix<float, 2, 2> expected_L =
  { 1, 0,
  1.5, 1};
  auto areEqualsL = compare(expected_L, L, 0.0001f);
  ASSERT_TRUE(areEqualsL);

  const Matrix<float, 2, 2> expected_U =
  { 4,    3,
    0, -1.5};

  auto areEqualsU = compare(expected_U, U, 0.0001f);
  ASSERT_TRUE(areEqualsU);

  // const Matrix<float, 2, 2> random =
  // { 4.0f, 12.0f,
  //   9.0f, 12.0f};

//TODO fix compare bug
 // auto areNotEqualsU = compare(random, U, 0.0001f);
 // ASSERT_FALSE(areNotEqualsU);
}

int main(int argc, char* argv[])
{
  //int i = 4;
  //auto* p = new Matrix<int, 2, i>{};

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


