/**
 * @file pow.cpp
 *
 * @date Oct 27, 2016
 *
 * @author Michal Kielan
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


TEST(MatrixTest, pow)
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


int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
