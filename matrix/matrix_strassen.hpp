/**
 * @file matrix_strassen.hpp
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

#ifndef MATRIX_STRASSEN_HPP_
#define MATRIX_STRASSEN_HPP_

#include "matrix_type.hpp"

namespace mlib
{


 /**
 * @brief Multiplication two matrixec using Strassen algorithm,
 * faster for matrix 2x2, but full recursivery algorithm for
 * every matrix is much slower, TODO: do something with it
 *
 * @param [in] Matrix A 2x2
 * @param [in] Matrix B 2x2
 *
 * @return Result of multiplication matrix A and B
 */
template<typename T>
Matrix<T, 2, 2> strassen(const Matrix<T, 2, 2>& A, const Matrix<T, 2, 2>& B)
{
  Matrix<T, 2, 2> prod{};

  T M1 =  A[0][0] * (B[0][1] - B[1][1]);
  T M2 = (A[0][0] + A[0][1]) * B[1][1];
  T M3 = (A[1][0] + A[1][1]) * B[0][0];
  T M4 =  A[1][1] * (B[1][0] - B[0][0]);
  T M5 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
  T M6 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
  T M7 = (A[0][0] - A[1][0]) * (B[0][0] + B[0][1]);

  prod[0][0] = M5 + M4 - M2 + M6;
  prod[0][1] = M1 + M2;
  prod[1][0] = M3 + M4;
  prod[1][1] = ((M1 + M5) - (M3 + M7));

  return prod;
}



} /* namespace mlib */


#endif /* MATRIX_STRASSEN_HPP_ */
