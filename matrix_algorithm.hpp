#ifndef MATRIX_ALGORITHM_HPP_
#define MATRIX_ALGORITHM_HPP_

#include "matrix_basic_math.hpp"

/**
 * @brief LU decomposition
 * 
 * Usage: The result of function is pair of matrices where L matrix is first 
 *        element of pair, the second element is U matrix
 * @param [in] Square Matrix A
 * 
 * @return Two matrices L and U
 */
template<typename T, std::size_t n>
std::pair<Matrix<T,n,n>, Matrix<T,n,n>>lu(const Matrix<T,n,n>& A)
{
  auto L = eye<T, n>();
  auto U = zeros<T, n, n>();
  T sum;

  for(std::size_t j = 0; j < n; j++)
  {
    for(std::size_t i = 0; i <= j; i++)
    {
      sum = 0.0;
      for(std::size_t p = 0; p < i; p++)
      {
        sum += U[p][j] * L[i][p];
      }
      U[i][j] = A[i][j] - sum;
    }
    for(std::size_t i = j; i < n; i++)
    {
      sum = 0.0;
      for(std::size_t p = 0; p < i; p++)
      {
        sum += U[p][j] * L[i][p];
      }

      if(U[j][j] == 0)
        throw;
      else
        L[i][j] = (A[i][j] - sum) / U[j][j];
    }
  }
  return std::pair<Matrix<T,n,n>, Matrix<T,n,n>>{L, U};
}


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
T det(const Matrix<T, n, n>& A)
{
  // TODO do it using LU algorithm (faster)
  // auto LU = lu(A);
  // auto&& L = LU.first;
  // auto&& U = LU.second;
  return -1;
}


/**
 * @brief Minor of A - A with crossed-out i-th column and j-th row
 *
 * @param [in] Square Matrix A with nxn size
 * 
 * @return Minor of A matrix
 */
template<typename T, std::size_t n>
Matrix<T, (n-1), (n-1)> getminor(const Matrix<T, n, n>& A, std::size_t i, std::size_t j)
{
  Matrix<T, (n-1), (n-1)> minor{};
  std::size_t colCount = 0,rowCount=0;
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
  auto detA = det(A);
  if (detA == 0)
  {
    throw;
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
  auto detA = det(A);
  if (detA == 0)
  {
    throw;
  }

  auto&& a = A[0][0]; auto&& b = A[0][1]; auto&& c = A[0][2];
  auto&& d = A[1][0]; auto&& e = A[1][1]; auto&& f = A[1][2];
  auto&& g = A[2][0]; auto&& h = A[2][1]; auto&& i = A[2][2];

  Matrix<T, 3, 3> invA 
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
  const auto detA = det(A);
  for(std::size_t i = 0; i < n; i++)
  {
    for(std::size_t j = 0; j < n; j++)
    {
      invA[i][j] = (((i+j) % 2) ? -1 : 1) * det(getminor(A,i,j));
    }
  }
  return trans(invA)/ detA;
}


/**
 * @brief Power of A matrix to p
 *
 * @param [in] Matrix A with nxn size
 * @param [in] Power number
 * 
 * @return Matrix A power by p
 */
template<typename T, typename P, std::size_t n>
Matrix<T, n, n> pow(Matrix<T, n, n>A, P p)
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

    auto powA = ones<T, n, n>();

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


/**
 * @brief Check if the matrix A is identity
 *
 * @param [in] Matrix A with nxn size
 * 
 * @return true - if A matrix is identity
 *         false - if A matrix is not identity
 */
template<typename T, std::size_t n>
bool isIdentity(const Matrix<T, n, n>& A)
{
  auto identity = eye<unsigned int, n>();
  auto uiA = static_cast<Matrix<unsigned int, n, n>>(A);
  return (uiA == identity);
}


/**
 * @brief
 *
 * @param [in] Matrix A ixj
 * @param [in] Matrix V ixj
 *
 * @return 
 */
template<typename T, std::size_t i, std::size_t j>
Matrix<T, i, j> conv2(const Matrix<T, i, j>& A, const Matrix<T, 3, 3>& kernel)
{
  Matrix<T, i, j> result{};

  for(std::size_t it = 1; it < i-1; it++)
  {
    for(std::size_t jt = 1; jt < j-1; jt++)
    {
      result[it][jt] = kernel[0][0] * A[it-1][jt-1] +
      kernel[0][1] * A[it-1][jt] +
      kernel[0][2] * A[it-1][jt+1] +
      kernel[1][0] * A[it][jt-1] +
      kernel[1][1] * A[it][jt] +
      kernel[1][2] * A[it][jt+1] +
      kernel[2][0] * A[it+1][jt-1] +
      kernel[2][1] * A[it+1][jt] +
      kernel[2][2] * A[it+1][jt+1];
    }
  }

  return result;
}

#endif // MATRIX_ALGORITHM_HPP_
