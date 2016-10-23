#ifndef MATRIX_BASIC_MATH_HPP_
#define MATRIX_BASIC_MATH_HPP_


#include "matrix_type.hpp"

/**
 * @brief Sum of two matrices
 * 
 * @param [in] Matrix A with i, j size
 * @param [in] Matrix B with i, j size
 * 
 * @return Result of sum matrix A and B
 */
template<typename T,  std::size_t i, std::size_t j>
static Matrix<T, i, j> sum(const Matrix<T, i, j>& A, const Matrix<T, i, j>& B)
{
  Matrix<T, i, j> sum{};

  for(std::size_t it = 0; it < i; it++)
  {
    for(std::size_t jt = 0; jt < j; jt++)
    {
      sum[it][jt] = A[it][jt] + B[it][jt];
    }
  }
  return sum;
}


/**
 * @brief Sum matrix and scalar
 * 
 * @param [in] Matrix A with i, j size
 * @param [in] Scalar data with the same type as matrix A
 * 
 * @return Result of sum each element of A matrix and scalar data
 */
template<typename T, std::size_t i, std::size_t j>
static Matrix<T, i, j> sum(const Matrix<T, i, j>& A, const T scalar)
{
  Matrix<T, i, j> sum{};

  for(std::size_t it = 0; it < i; it++)
  {
    for(std::size_t jt = 0; jt < j; jt++)
    {
      sum[it][jt] = A[it][jt] + scalar;
    }
  }
  return sum;
}


/**
 * @brief Substraction of two matrices
 * 
 * @param [in] Matrix A with i, j size
 * @param [in] Matrix B with i, j size
 * 
 * @return Result of substraction matrix A and B
 */
template<typename T,  std::size_t i, std::size_t j>
static Matrix<T, i, j> sub(const Matrix<T, i, j>& A, const Matrix<T, i, j>& B)
{
  Matrix<T, i, j> sub{};

  for(std::size_t it = 0; it < i; it++)
  {
    for(std::size_t jt = 0; jt < j; jt++)
    {
      sub[it][jt] = A[it][jt] - B[it][jt];
    }
  }
  return sub;
}


/**
 * @brief Substraction matrix and scalar
 * 
 * @param [in] Matrix A with i, j size
 * @param [in] Scalar data with the same type as matrix A
 * 
 * @return Result of substraction each element of A matrix and scalar data
 */
template<typename T, std::size_t i, std::size_t j>
static Matrix<T, i, j> sub(const Matrix<T, i, j>& A, const T scalar)
{
  Matrix<T, i, j> sub{};

  for(std::size_t it = 0; it < i; it++)
  {
    for(std::size_t jt = 0; jt < j; jt++)
    {
      sub[it][jt] = A[it][jt] - scalar;
    }
  }
  return sub;
}


/**
 * @brief  Multiplication of two matrices
 *
 * Usage: If sizes of matrix A and B are illegal to multiply,
 *        the function will not compile
 * @param [in] Matrix A with n, m size
 * @param [in] Matrix B with m, p size
 * 
 * @return Result of multiplication matrix A and B
 */
template<typename T,  std::size_t n, std::size_t m, std::size_t p>
static Matrix<T, n, p> mult(const Matrix<T, n, m>& A, const Matrix<T, m, p>& B)
{
  auto prod = zeros<T, n, p>();

  for(std::size_t i = 0; i < n; ++i)
  {
    for(std::size_t j = 0; j < p; ++j)
    {
      for(std::size_t k = 0; k < m; ++k)
      {
        prod[i][j] += (A[i][k] * B[k][j]);
      }
    }
  }
  return prod;
}


 /**
 * @brief  Multiplication matrix and scalar
 * 
 * @param [in] Matrix A with i, j size
 * @param [in] Scalar data with the same type as matrix A
 * 
 * @return Result of multiplication each element of A matrix and scalar data
 */
template<typename T, std::size_t i, std::size_t j>
static Matrix<T, i, j> mult(const Matrix<T, i, j>& A, const T scalar)
{
  Matrix<T, i, j> prod{};

  for(std::size_t it = 0; it < i; it++)
  {
    for(std::size_t jt = 0; jt < j; jt++)
    {
      prod[it][jt] = A[it][jt] * scalar;
    }
  }
  return prod;
}


 /**
 * @brief Divide matrix and scalar
 * 
 * @param [in] Matrix A with i, j size
 * @param [in] Scalar data with the same type as matrix A
 * 
 * @return Result of divide each element of A matrix and scalar data
 */
template<typename T, std::size_t n, std::size_t m>
static Matrix<T, n, m> div(const Matrix<T, n, m>& A, const T scalar)
{
  if(scalar == 0)
    throw;

  Matrix<T, n, m> prod{};

  for(std::size_t i = 0; i < n; i++)
  {
    for(std::size_t j = 0; j < m; j++)
    {
      prod[i][j] = A[i][j] / scalar;
    }
  }
  return prod;
}


/**
 * @brief Overloaded '+' operator of sum two matrices
 *
 * @param [in] Matrix A ixj
 * @param [in] Matrix B ixj
 * 
 * @return Result of sum matrix A and B
 */
template<typename T, std::size_t i, std::size_t j>
Matrix<T, i, j> operator+(const Matrix<T, i, j>& A, const Matrix<T, i, j>& B)
{
	return sum(A, B);
}


/**
 * @brief Overloaded '+' operator for add matrix and scalar
 *
 * @param [in] Matrix A ixj
 * @param [in] Scalar data
 * 
 * @return Result of sum matrix A and scalar
 */
template<typename T,  std::size_t i, std::size_t j>
Matrix<T, i, j> operator+(const Matrix<T, i, j>& A, const T scalar)
{
  return sum(A, scalar);
}


/**
 * @brief Overloaded '+' operator for add scalar and matrix
 *
 * @param [in] Scalar data
 * @param [in] Matrix A ixj
 * 
 * @return Result of sum scalar and matrix A
 */
template<typename T,  std::size_t i, std::size_t j>
Matrix<T, i, j> operator+(const T scalar, const Matrix<T, i, j>& A)
{
  return sum(A, scalar);
}


/**
 * @brief Overloaded '-' operator for substraction two matrices
 *
 * @param [in] Matrix A ixj
 * @param [in] Matrix B ixj
 * 
 * @return Result of substraction matrix A and B
 */
template<typename T, std::size_t i, std::size_t j>
Matrix<T, i, j> operator-(const Matrix<T, i, j>& A, const Matrix<T, i, j>& B)
{
	return sub(A, B);
}


/**
 * @brief Overloaded '-' operator for substraction matrix and scalar
 *
 * @param [in] Matrix A ixj
 * @param [in] Scalar data
 * 
 * @return Result of substraction matrix A and scalar data
 */
template<typename T,  std::size_t i, std::size_t j>
Matrix<T, i, j> operator-(const Matrix<T, i, j>& A, const T scalar)
{
  return sub(A, scalar);
}


/**
 * @brief Overloaded '*' operator for multiply two matrices
 *
 * @param [in] Matrix A
 * @param [in] Matrix B
 * 
 * @return Result of multiplication matrix A and B
 */
template<typename T,  std::size_t n, std::size_t m, std::size_t p>
Matrix<T, n, p> operator*(const Matrix<T, n, m>& A, const Matrix<T, m, p>& B)
{
	return mult(A, B);
}


/**
 * @brief Overloaded '*' operator for multiply matrix and scalar
 *
 * @param [in] Matrix A ixj
 * @param [in] Scalar data
 * 
 * @return Result of substraction matrix A and scalar
 */
template<typename T,  std::size_t i, std::size_t j>
Matrix<T, i, j> operator*(const Matrix<T, i, j>& A, const T scalar)
{
  return mult(A, scalar);
}


/**
 * @brief Overloaded '*' operator for multiply scalar and matrix
 *
 * @param [in] Scalar data
 * @param [in] Matrix A ixj
 * 
 * @return Result of substraction scalar and matrix A
 */
template<typename T,  std::size_t i, std::size_t j>
Matrix<T, i, j> operator*(const T scalar, const Matrix<T, i, j>& A)
{
  return mult(A, scalar);
}


/**
 * @brief Overloaded '/' operator for divide matrix and scalar
 *
 * @param [in] Matrix A ixj
 * @param [in] Scalar data
 *
 * @retirn Result of divide matrix A and scalar
 */
template<typename T,  std::size_t i, std::size_t j>
Matrix<T, i, j> operator/(const Matrix<T, i, j>& A, T scalar)
{
  return div(A, scalar);
}


/**
 * @brief Absolut value of matrix
 *
 * @param [in] Matrix A with ixj size
 * 
 * @return Matrix A which is result of absolut each element of matrix
 */
template<typename T, std::size_t i, std::size_t j>
Matrix<T, i, j> abs(const Matrix<T, i, j>& A)
{
  Matrix<T, i, j> absA;
  for (std::size_t it = 0; it < i; it++)
  {
    for (std::size_t jt = 0; jt < j; jt++)
    {
      absA[it][jt] = std::abs(A[it][jt]);
    }
  }
  return absA;
}


/**
 * @ Compare two matrices with the same size, specific error
 * @param [in] Matrix A ixj
 * @param [in] Matrix B ixj
 * @param [in] error
 *
 * return true if compare, otherwise false
 */
template<typename T, std::size_t i, std::size_t j>
bool compare(const Matrix<T, i, j>& A, const Matrix<T, i, j>& B, T epsilon)
{
  auto Err = fill<T, i, j>(epsilon);
  return abs(A - B) < Err;
}


 /**
 * @brief Multiplication two matrixec using Strassen algorithm
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

#endif // MATRIX_BASIC_MATH_HPP_
