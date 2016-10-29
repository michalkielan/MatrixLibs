/*
 * histogram.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: michal
 */
#include <gtest/gtest.h>
#include "matrix.hpp"

using namespace mlib;


TEST(MatrixTest, histogram)
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
