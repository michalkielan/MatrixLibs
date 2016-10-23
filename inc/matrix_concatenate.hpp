#ifndef MATRIX_CONCATENATE_HPP_
#define MATRIX_CONCATENATE_HPP_

template<typename T,  std::size_t n>
Matrix<T, n,(n+n)> concatenateH(const Matrix<T, n, n>& A, const Matrix<T, n, n>& B);


/**
 * @brief Concatenate two squared matrices
 * 
 * @param [in] Matrix A nxn
 * @param [in] Matrix B nxn
 *
 * @return first of pair is matrix joined vertically, second horizontally 
 */
template<typename T,  std::size_t n>
std::pair<Matrix<T, (n+n), n>,Matrix<T, n, (n+n)>> concatenate(const Matrix<T, n, n>& A, const Matrix<T, n, n>& B)
{
  std::pair<Matrix<T, (n+n), n>, Matrix<T, n, (n+n)>> result{};
  for (std::size_t i = 0; i < n; i++)
  {
    for (std::size_t j = 0; j < n; j++)
    {
      result.first[i][j] = A[i][j];
    }
  }

  for (std::size_t i = n; i < n+n; i++)
  {
    for (std::size_t j = 0; j < n; j++)
    {
      result.first[i][j] = B[i-n][j];
    }
  }

  for (std::size_t i = 0; i < n; i++)
  {
    for (std::size_t j = 0; j < n; j++)
    {
      result.second[i][j] = A[i][j];
    }
    for (std::size_t j = n; j < n+n; j++)
    {
      result.second[i][j] = A[i][j-n];
    }
  }

  return result;
}


/**
 * @brief Concatenate two matrices vertically
 * 
 * @param [in] Matrix A i1xj
 * @param [in] Matrix B i2xj
 *
 * @return matrix joined vertically - size: (i1+i2)xj
 */
template<typename T,  std::size_t i1, std::size_t i2, std::size_t j>
Matrix<T, (i1+i2), j> concatenate(const Matrix<T, i1, j>& A, const Matrix<T, i2, j>& B)
{
  Matrix<T, (i1+i2), j> result{};
  for (std::size_t it = 0; it < i1; it++)
  {
    for (std::size_t jt = 0; jt < j; jt++)
    {
      result[it][jt] = A[it][jt];
    }
  }
  for (std::size_t it = i1; it < i2; it++)
  {
    for (std::size_t jt = 0; jt < j; jt++)
    {
      result[it][jt] = B[it-i1][jt];
    }
  }
  return result;
}


/**
 * @brief Concatenate two matrices horizontally
 * 
 * @param [in] Matrix A ixj1
 * @param [in] Matrix B ixj2
 *
 * @return matrix joined horizontally - size: ix(j1+j2)
 */
template<typename T,  std::size_t i, std::size_t j1, std::size_t j2>
Matrix<T, i, (j1+j2)> concatenate(const Matrix<T, i, j1>& A, const Matrix<T, i, j2>& B)
{
  Matrix<T, i, (j1+j2)> result{};
  for (std::size_t it = 0; it < i; it++)
  {
    for (std::size_t jt = 0; jt < j1; jt++)
    {
      result[it][jt] = A[it][jt];
    }
    for (std::size_t jt = j1; jt < j2; jt++)
    {
      result[it][jt] = A[it][jt-j2];
    }
  }
  return result;
}


/**
 * @brief Concatenate two square matrices vertically
 * 
 * @param [in] Matrix A nxn
 * @param [in] Matrix B nxn
 *
 * @return matrix joined vertically - size: (2n)xn
 */
template<typename T,  std::size_t n>
Matrix<T, (n+n), n> concatenateV(const Matrix<T, n, n>& A, const Matrix<T, n, n>& B)
{
  Matrix<T, (n+n), n> result{};
  for (std::size_t it = 0; it < n; it++)
  {
    for (std::size_t jt = 0; jt < n; jt++)
    {
      result[it][jt] = A[it][jt];
    }
  }
  for (std::size_t it = n; it < n+n; it++)
  {
    for (std::size_t jt = 0; jt < n; jt++)
    {
      result[it][jt] = B[it-n][jt];
    }
  }
  return result;
}


/**
 * @brief Concatenate two square matrices horizontally
 * 
 * @param [in] Matrix A nxn
 * @param [in] Matrix B nxn
 *
 * @return matrix joined horizontally - size: nx(2n)
 */
template<typename T,  std::size_t n>
Matrix<T, n,(n+n)> concatenateH(const Matrix<T, n, n>& A, const Matrix<T, n, n>& B)
{
  Matrix<T, n, (n+n)> result{};
  for (std::size_t i = 0; i < n; i++)
  {
    for (std::size_t j = 0; j < n; j++)
    {
      result[i][j] = A[i][j];
    }
    for (std::size_t j = n; j < n+n; j++)
    {
      result[i][j] = A[i][j-n];
    }
  }
  return result;
}

#endif // MATRIX_CONCATENATE_HPP_