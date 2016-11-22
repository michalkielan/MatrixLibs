/**
 * @file matrix_inv.hpp
 *
 * @date Oct 26, 2016
 *
 * @author Jaroslaw Wiosna
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#ifndef MATRIX_MATRIX_INV_HPP_
#define MATRIX_MATRIX_INV_HPP_

#include "matrix_div.hpp"
#include "matrix_det.hpp"
#include "matrix_trans.hpp"

namespace mlib
{


/**
 * @brief Minor of A - A with crossed-out i-th column and j-th row
 *
 * @param [in] Square Matrix A with nxn size
 *
 * @return Minor of A matrix
 */
template<typename T, std::size_t n>
static Matrix<T, (n-1), (n-1)> getminor(const Matrix<T, n, n>& A, std::size_t i, std::size_t j)
{
  Matrix<T, (n-1), (n-1)> minor{};
  std::size_t colCount {0},rowCount {0};
  for(std::size_t k = 0; k < n; k++)
  {
    if (k != i)
    {
      colCount = 0;
      for(std::size_t l = 0; l < n; l++)
      {
        if (l != j)
        {
          minor[rowCount][colCount] = A[k][l];
          colCount++;
        }
      }
      rowCount++;
    }
  }
  return minor;
}


/**
 * @brief Inverse of matrix 1x1
 *
 * @param [in] Square Matrix A with 1x1 size
 *
 * @return Inverse of matrix A
 */
template<typename T>
Matrix<T, 1, 1> inv(const Matrix<T, 1, 1>& A)
{
  return Matrix<T, 1, 1>{ 1/det(A) };
}


/**
 * @brief Inverse of matrix 2x2
 *
 * @param [in] Square Matrix A with 2x2 size
 *
 * @return Inverse of matrix A
 *         error with the A is zero
 */
template<typename T>
Matrix<T, 2, 2> inv(const Matrix<T, 2, 2>& A)
{
  Matrix<T, 2, 2> invA{};
  const auto detA { det(A) };
  if (detA == 0)
  {
    throw std::overflow_error("Divide by zero exception");
  }
  invA = {A[1][1], -A[0][1],
         -A[1][0],  A[0][0]};
  invA = invA / detA;
  return invA;
}


/**
 * @brief Inverse of matrix 3x3
 *
 * @param [in] Square Matrix A with 3x3 size
 *
 * @return Inverse of matrix A
 *         error with the A is zero
 */
template<typename T>
Matrix<T, 3, 3> inv(const Matrix<T, 3, 3>& A)
{
  const auto detA { det(A) };
  if (detA == 0)
  {
    throw std::overflow_error("Divide by zero exception");
  }

  auto&& a = A[0][0]; auto&& b = A[0][1]; auto&& c = A[0][2];
  auto&& d = A[1][0]; auto&& e = A[1][1]; auto&& f = A[1][2];
  auto&& g = A[2][0]; auto&& h = A[2][1]; auto&& i = A[2][2];

  const Matrix<T, 3, 3> invA
  { e*i - f*h, c*h - b*i, b*f - c*e,
    f*g - d*i, a*i - c*g, c*d - a*f,
    d*h - e*g, b*g - a*h, a*e - b*d };

  return invA / detA;
}

/**
 * @brief Inverse of matrix nxn
 *
 * @param [in] Square Matrix A with nxn size
 *
 * @return Inverse of matrix A
 */
template<typename T, std::size_t n>
Matrix<T, n, n> inv(const Matrix<T, n, n>& A)
{
  Matrix<T, n, n> invA{};
  const auto detA { det(A) };
  for(std::size_t i = 0; i < n; i++)
  {
    for(std::size_t j = 0; j < n; j++)
    {
      invA[i][j] = (((i+j) % 2) ? -1 : 1) * det(getminor(A, i, j));
    }
  }
  return trans(invA)/ detA;
}


} /* namespace mlib */

#endif /* MATRIX_MATRIX_INV_HPP_ */
