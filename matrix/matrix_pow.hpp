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
