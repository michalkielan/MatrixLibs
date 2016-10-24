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
    0, 1};

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

  Matrix<float, 2, 2> res =
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
  const Matrix<float, 2, 2> A2 =
  { 1, 2,
    0, 1 };

  ASSERT_EQ(det(A2), 1);

  const Matrix<float, 3, 3> A3 =
  { 1, 2,  1,
    0, 1, -3,
    3, 5,  1 };

  ASSERT_EQ(det(A3), -5);


  const Matrix<float, 4, 4> A4 =
  { 1, 2,  3,  4,
    5, 6,  7,  8,
    9, 10, 2,  2,
    2, 1,  -4, 0 };

  ASSERT_EQ(det(A4), 196);

  const Matrix<float, 4, 4> B4 =
  { 1,  0,  4, -2,
    0, -5,  3,  1,
   -4,  5,  1,  0,
    1,  0, -1,  2};

  ASSERT_EQ(det(B4), -225);

  const Matrix<float, 5, 5> C5 =
  {  1,    0,    2,    3,    5,
     7,    6,  - 4,    0,    1,
   - 1,  - 4,    0,    5,    1,
     2,  - 4,    3,  - 5,    0,
     1,    2,    5,  - 3,    0 };

  ASSERT_EQ(static_cast<int>(det(C5)), -6040);

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
  const Matrix<float, 2, 2> A =
  { 1, 2,
    0, 1 };

  const Matrix<float, 2, 2> invA =
  { 1, -2,
    0, 1 };

  ASSERT_EQ(inv(A), invA);

  const Matrix<float, 3, 3> B =
  { -2, 5, 1,
     3, 0, 1,
     1, 1, 2 };

  const Matrix<float, 3, 3> invB =
  {  0.05,  0.45, -0.25,
     0.25,  0.25, -0.25,
    -0.15, -0.35,  0.55 };

  ASSERT_TRUE(compare(inv(B), invB, 0.01f));

  const Matrix<float, 4, 4> C =
  { 1,  2,  3,  4,
    2,  3,  1,  2,
    1,  1,  1, -1,
    1,  0, -2, -6};

  const Matrix<float, 4, 4> invC =
  { 22, -6, -26,  17,
   -17,  5,  20, -13,
    -1,  0,   2,  -1,
     4, -1,  -5,   3};

  ASSERT_TRUE(compare(inv(C), invC, 0.01f));
}

TEST_F(MatrixTest, trans_square_matrix)
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

TEST_F(MatrixTest, trans_not_square_matrix)
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
  Matrix<float, 2, 2> A =
  { 1, 2,
    0, 1 };

  const Matrix<float, 2, 2> B =
  {  6, 1,
    -1, 0 };

  ASSERT_FALSE(compare(A, B, 0.0001f));

  const Matrix<float, 2, 2> C =
  { 1.0,    2.000005,
    1.0001, 1.01 };

  const Matrix<float, 2, 2> D =
  { 1.1,    2.000009,
    1.0005, 1.05 };

  ASSERT_FALSE(compare(C, D, 0.00001f));

  const Matrix<float, 2, 2> E =
  { -1.1,    -2.00000,
    -1.0001, -1.01 };

  const Matrix<float, 2, 2> F =
  { -1.1,    -2.00000,
    -1.0001, -1.01 };

  ASSERT_TRUE(compare(E, F, 0.01f));

  const Matrix<float, 2, 2> G =
  { 1.1,    2.00000,
    1.0001, 1.01 };

  const Matrix<float, 2, 2> H =
  { -1.1,    -2.00000,
    -1.0001, -1.01 };

  ASSERT_FALSE(compare(G, H, 0.01f));
}

TEST_F(MatrixTest, pow)
{
  const Matrix<float, 2, 2> A
  {
    1, 2,
    3, 4
  };

   ASSERT_EQ((eye<float, 2>()), pow(A,0));

   ASSERT_EQ( (A),         pow(A,1) );
   ASSERT_EQ( (A*A),       pow(A,2) );
   ASSERT_EQ( (A*A*A),     pow(A,3) );
   ASSERT_EQ( (A*A*A*A),   pow(A,4) );
   ASSERT_EQ( (A*A*A*A*A), pow(A,5) );
   
   auto invA = inv(A);
   ASSERT_EQ( (invA),                     pow(A,-1));
   ASSERT_EQ( (invA*invA),                pow(A,-2));
   ASSERT_EQ( (invA*invA*invA),           pow(A,-3));
   ASSERT_EQ( (invA*invA*invA*invA),      pow(A,-4));
   ASSERT_EQ( (invA*invA*invA*invA*invA), pow(A,-5));
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

  ASSERT_TRUE(compare(expected_L, L, 0.0001f));

  const Matrix<float, 3, 3> expected_U =
  { 5,     3,      2,
    0, 7/5.0, -2/5.0,
    0,     0, 16/7.0};

  ASSERT_TRUE(compare(expected_U, U, 0.0001f));

  const Matrix<float, 3, 3> random =
  { 1,     1,  -1000,
    1, 7/5.0, -2/5.0,
    1,     1,      1};

  ASSERT_FALSE(compare(random, U, 0.0001f));
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
  ASSERT_TRUE(compare(expected_L, L, 0.0001f));

  const Matrix<float, 2, 2> expected_U =
  { 4,    3,
    0, -1.5};

  ASSERT_TRUE(compare(expected_U, U, 0.0001f));

  // const Matrix<float, 2, 2> random =
  // { 4.0f, 12.0f,
  //   9.0f, 12.0f};

//TODO fix compare bug
 // auto areNotEqualsU = compare(random, U, 0.0001f);
 // ASSERT_FALSE(areNotEqualsU);
}

TEST_F(MatrixTest, convolution)
{
  const Matrix<float, 5, 5> A =
  { 9,  9,  9,  9,  9,
   18, 18, 18, 27, 27,
    9,  9,  9,  9,  9,
    9,  9,  9,  9,  9,
    9,  9,  9,  9,  9};

  Matrix<float, 3, 3> kernel =
  {1/9, 1/9, 1/9,
   1/9, 1/9, 1/9,
   1/9, 1/9, 1/9 };

  const Matrix<float, 5, 5> expected_after_conv =
 { 0,  0,  0,  0, 0,
   0, 12, 13, 14, 0,
   0, 12, 13, 14, 0,
   0,  9,  9,  9, 0,
   0,  0,  0,  0, 0};

  auto after_conv = conv2(A,kernel);

  ASSERT_TRUE(compare(expected_after_conv, after_conv, 0.0001f));

  const Matrix<float, 5, 5> B =
 { 5, 5, 5, 5, 5,
   5, 5, 5, 5, 5,
   5, 5, 5, 9, 5,
   5, 5, 5, 5, 5,
   5, 5, 5, 5, 5 };

  Matrix<float, 3, 3> kernel_highpass =
  {-1, -1, -1,
   -1,  9, -1,
   -1, -1, -1 };

  const Matrix<float, 5, 5> expected_after_highpass =
  { 0, 0, 0,  0, 0,
    0, 5, 1,  1, 0,
    0, 5, 1, 41, 0,
    0, 5, 1,  1, 0,
    0, 0, 0,  0, 0};

  auto after_highpass = conv2(B,kernel_highpass);

  ASSERT_TRUE(compare(expected_after_highpass, after_highpass, 0.0001f));
}

TEST_F(MatrixTest, concatenate)
{
  const Matrix<float, 2, 2> A =
  { 4, 3,
    6, 3};
  const Matrix<float, 3, 2> B =
  { 10, 12,
    15, 13,
    17, 11};
  const Matrix<float, 5, 2> expected_AB =
  { 4, 3,
    6, 3,
    10, 12,
    15, 13,
    17, 11};

  auto AB = concatenate(A,B);
  ASSERT_TRUE(compare(expected_AB, AB, 0.0001f));

  const Matrix<float, 2, 3> C =
  { 4, 3, 1,
    6, 3, 1};
  const Matrix<float, 2, 2> D =
  { 10, 12,
    15, 13};
  const Matrix<float, 2, 5> expected_CD =
  { 4, 3, 1, 10, 12,
    6, 3, 1, 15, 13};

  auto CD = concatenate(C,D);

  ASSERT_TRUE(compare(expected_CD, CD, 0.0001f));

  const Matrix<float, 2, 2> E =
  { 4, 3,
    6, 3};

  const Matrix<float, 2, 2> F =
  { 10, 12,
    15, 13};

  const Matrix<float, 4, 2> expected_EF =
  { 4, 3,
    6, 3,
   10, 12,
   15, 13};

  auto EF = concatenateV(E,F);
  ASSERT_TRUE(compare(expected_EF, EF, 0.0001f));

  const Matrix<float, 2, 2> G =
  { 4, 3,
    6, 3};

  const Matrix<float, 2, 2> H =
  { 10, 12,
    15, 13};

  const Matrix<float, 2, 4> expected_GH =
  { 4, 3, 10, 12,
    6, 3, 15, 13};

  auto GH = concatenateH(G,H);
  ASSERT_TRUE(compare(expected_GH, GH, 0.0001f));

  const Matrix<float, 2, 2> I =
  { 4, 3,
    6, 3};

  const Matrix<float, 2, 2> J =
  { 10, 12,
    15, 13};

  const Matrix<float, 4, 2> expected_IJ =
  { 4, 3,
    6, 3,
   10, 12,
   15, 13};

  Matrix<float, 4, 2> IJ = concatenate(I,J).first;
  ASSERT_TRUE(compare(expected_IJ, IJ, 0.0001f));
}

TEST_F(MatrixTest, getminor)
{
  const Matrix<float, 3, 3> A =
  { 1, 2, 3,
    4, 5, 6,
    7, 8, 9 };

  const Matrix<float, 2, 2> Aminor2x2 =
  { 1, 2,
    4, 5 };

  ASSERT_TRUE(compare(getminor(A,2,2), Aminor2x2, 0.01f));

  const Matrix<float, 4, 4> C =
  { 1,  2,  3,  4,
    2,  3,  1,  2,
    1,  1,  1, -1,
    1,  0, -2, -6};

  const Matrix<float, 3, 3> minor0x0 =
  { 3,  1,  2,
    1,  1, -1,
    0, -2, -6};

  ASSERT_TRUE(compare(getminor(C,0,0), minor0x0, 0.01f));

  const Matrix<float, 3, 3> minor1x1 =
  { 1,  3,  4,
    1,  1, -1,
    1, -2, -6};

  ASSERT_TRUE(compare(getminor(C,1,1), minor1x1, 0.01f));
}

TEST_F(MatrixTest, stats)
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

TEST_F(MatrixTest, histogram)
{
  const Matrix<float, 3, 3> A =
  { 1, 2, 2,
    4, 4, 2,
    7, 8, 4 };
  auto histA = histogram(A);

  #if HISTOGRAM_DEBUG
    for (const auto &p : histA) {
      std::cout << p.first << " " << p.second << std::endl;
    }
  #endif // HISTOGRAM_DEBUG

  ASSERT_EQ(histA[1],1);
  ASSERT_EQ(histA[2],3);
  ASSERT_EQ(histA[4],3);
  ASSERT_EQ(histA[7],1);
  ASSERT_EQ(histA[8],1);
}

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
