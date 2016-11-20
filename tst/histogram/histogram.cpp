/**
 * @file histogram.cpp
 *
 * @date Oct 27, 2016
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


TEST(MatrixTest, histogram)
{
  const Matrix<float, 3, 3> A =
  { 1, 2, 2,
    4, 4, 2,
    7, 8, 4 };
  auto histA = histogram(A);

#if HISTOGRAM_DEBUG
  for (const auto &p : histA)
  {
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
