/**
 * @file matrix_cholesky.hpp
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

#ifndef MATRIX_MATRIX_CHOLESKY_HPP_
#define MATRIX_MATRIX_CHOLESKY_HPP_


namespace mlib
{

/****
 * \brief Check if is symetric
 *
 * \param [in] Matrix A nxn
 *
 * \return true when symetric, false if not
 */
template<typename T,  std::size_t n>
bool isSymetric(
  const Matrix<T, n, n>& A)
{
  bool isSymetric = true;
  for (std::size_t i = 1; i < n; i++)
  {
    for (std::size_t j = 0; j < i; j++)
    {
      if (A[i][j] != A[j][i])
      {
        return false;
      }
    }
  }
  return isSymetric;
}

/****
 * \brief Cholesky decomposition
 *
 * \param [in] Matrix A nxn
 *
 * \return matrix L (A=L*trans(L))
 */
template<typename T,  std::size_t n>
Matrix<T, n, n> chol(
  const Matrix<T, n, n>& A)
{
  //TODO: enable only if isSymetric(A)
  Matrix<T, n, n> L{};
  T sum{};
  for (std::size_t i = 0; i < n; i++)
  {
    for (std::size_t j = 0; j <= i; j++)
    {
      if (j == i)
      {
        sum = 0;
        for (std::size_t k = 0; k < i; k++)
        {
          sum = sum + L[i][k] * L[i][k];
        }
        L[i][i] = sqrt( A[i][i] - sum);
      }
      else
      {
        sum = 0;
        for (std::size_t k = 0; k < i; k++)
        {
          sum += L[i][k] * L[j][k];
        }
        L[i][j] = ( A[i][j] - sum ) / L[j][j];
      }
    }
  }
  return L;
}


} /* namespace mlib */


#endif /* MATRIX_MATRIX_CHOLESKY_HPP_ */
