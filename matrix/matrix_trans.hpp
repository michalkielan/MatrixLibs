/**
 * @file matrix_trans.hpp
 *
 * @date Oct 26, 2016
 *
 * @author Michal Kielan
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#ifndef MATRIX_TRANS_HPP_
#define MATRIX_TRANS_HPP_

#include "matrix_type.hpp"

namespace mlib
{


/**
 * @brief Transpose of matrix nxm
 *
 * @param [in] Matrix A with nxm size
 *
 * @return Transpose of matrix A
 */
template<typename T, std::size_t n, std::size_t m>
Matrix<T, m, n> trans(const Matrix<T, n, m>& A)
{
  Matrix<T, m, n> transA{};

  for (std::size_t i = 0; i < n; i++)
  {
    for (std::size_t j = 0; j < m; j++)
    {
      transA[j][i] = A[i][j];
    }
  }
  return transA;
}


} /* namespace mlib */


#endif /* MATRIX_TRANS_HPP_ */
