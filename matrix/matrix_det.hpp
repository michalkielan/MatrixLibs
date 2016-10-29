#ifndef MATRIX_MATRIX_DET_HPP_
#define MATRIX_MATRIX_DET_HPP_

#include "matrix_swap.hpp"


namespace mlib
{


/**
 * @brief Determinant of matrix 1x1
 *
 * @param [in] Square Matrix A with 1x1 size
 *
 * @return Determinant of matrix A
 */
template<typename T>
T det(const Matrix<T, 1, 1>& A)
{
  return A[0][0];
}


/**
 * @brief Determinant of matrix 2x2
 *
 * @param [in] Square Matrix A with 2x2 size
 *
 * @return Determinant of matrix A
 */
template<typename T>
T det(const Matrix<T, 2, 2>& A)
{
  auto&& a = A[0][0]; auto&& b = A[0][1];
  auto&& c = A[1][0]; auto&& d = A[1][1];

  return a*d - b*c;
}


/**
 * @brief Determinant of matrix 3x3
 *
 * @param [in] Square Matrix A with 3x3 size
 *
 * @return Determinant of matrix A
 */
template<typename T>
T det(const Matrix<T, 3, 3>& A)
{
  auto&& a = A[0][0]; auto&& b = A[0][1]; auto&& c = A[0][2];
  auto&& d = A[1][0]; auto&& e = A[1][1]; auto&& f = A[1][2];
  auto&& g = A[2][0]; auto&& h = A[2][1]; auto&& i = A[2][2];

  return a*e*i + b*f*g + c*d*h - c*e*g - b*d*i - a*f*h;
}


/**
 * @brief Determinant of matrix nxn
 *
 * @param [in] Square Matrix A with nxn size
 *
 * @return Determinant of matrix A
 */
template<typename T, std::size_t n>
T det(Matrix<T, n, n> A)
{
  T factor{1};
  std::size_t pivot{0};

  auto prod = [&]()
  {
    float prod{1};

    for (std::size_t i = 0; i < n; ++i)
    {
      prod *= A[i][i];
    }
    return prod / factor;
  };

  for (std::size_t r = 0; r < n; ++r)
  {
    if (n <= pivot)
    {
      return prod();
    }

    std::size_t i = r;

    while (A[i][pivot] == 0)
    {
      ++i;
      if (n == i)
      {
        i = r;
        ++pivot;
        if (n == pivot)
        {
          return prod();
        }
      }
    }

    if (i != r)
    {
      swap_rows(A, i, r);
      factor *= -1;
    }

    for (std::size_t i = pivot + 1; i < n; ++i)
    {
      if (i != r)
      {
        T val = A[i][pivot];
        for (std::size_t j = pivot; j < n; ++j)
        {
          A[i][j] -= val * A[r][j] / A[r][pivot];
        }

      }
    }
    pivot++;
  }
  return prod();
}

} /* namespace mlib */

#endif /* MATRIX_MATRIX_DET_HPP_ */
