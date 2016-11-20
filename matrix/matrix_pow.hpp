/**
 * @file matrix_pow.hpp
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

#ifndef MATRIX_MATRIX_POW_HPP_
#define MATRIX_MATRIX_POW_HPP_

#include "matrix_inv.hpp"

namespace mlib
{


/**
 * @brief Power of A matrix to p
 *
 * @param [in] Matrix A with nxn size
 * @param [in] Power number
 *
 * @return Matrix A power by p
 */
template<typename T, typename P, std::size_t n>
Matrix<T, n, n> pow(Matrix<T, n, n> A, P p)
{
  if(p == 0)
  {
    return eye<T, n>();
  }

  else if(p == 1)
  {
    return A;
  }

  else
  {
    if(p < 0)
    {
      A = inv(A);
      p = std::abs(p);
    }

    auto powA { ones<T, n, n>() };

    powA = pow(A, p/2);
    if ((p % 2) == 0)
    {
      return powA * powA;
    }
    else
    {
      return powA * powA * A;
    }
  }
}

} /* namespace mlib */

#endif /* MATRIX_MATRIX_POW_HPP_ */
