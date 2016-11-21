/**
 * @file cooccurrence.cpp
 *
 * @date Nov 21, 2016
 *
 * @author JaroslawWiosna
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

TEST(MatrixTest, glcm)
{
  const Matrix<float, 4, 4> A =
  { 0,  0,  1,  1,
    0,  0,  1,  1,
    0,  2,  2,  2,
    2,  2,  3,  3 };

  const Matrix<float, 4, 4> cooccurrenceA =
  { 2,  2,  1,  0,
    0,  2,  0,  0,
    0,  0,  3,  1,
    0,  0,  0,  1 };

  ASSERT_TRUE(compare(cooccurrence(A), cooccurrenceA, 0.01f));
}

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

