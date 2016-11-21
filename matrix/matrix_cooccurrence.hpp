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

#ifndef MATRIX_MATRIX_COOCCURENCE_HPP_
#define MATRIX_MATRIX_COOCCURENCE_HPP_


namespace mlib
{

/****
 * \brief Co-occurence matrix
 *
 * \param Input matrix
 *
 * \return Co-occurence matrix - corelation between two pixel. 
 * First is the refference. Second is the neighbour on the right side.
 * Using one pixel offset.
 */
template<typename T,  std::size_t I, std::size_t J>
Matrix<T, 4, 4> cooccurrence(const Matrix<T, I, J>& A)
{
  Matrix<T, 4, 4> result{};
  for (std::size_t i = 0; i < I; i++)
  {
    for (std::size_t j = 0; j < J-1; j++)
    {
      for (std::size_t a = 0; a < 4; a++)
      {
        for (std::size_t b = 0; b < 4; b++)
        {
          if (A[i][j] == a && A[i][j+1] == b)
          {
            result[a][b]++;
          }
	}
      }
    }
  }
  return result;
}



} /* namespace mlib */


#endif /* MATRIX_MATRIX_COOCCURRENCE_HPP_ */
