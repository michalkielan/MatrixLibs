/**
 * @file matrix_print.hpp
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

#ifndef MATRIX_PRINT_HPP_
#define MATRIX_PRINT_HPP_

#include "matrix_type.hpp"

/**
 * @brief Print matrix using output stream
 * @param [in] Matrix
 *
 * @usage Enable only if PRINT_MODE_ON is defined,
 * otherwise the iostream library has not been include,
 * add your own output mode if needed
 */
#ifdef PRINT_IOSTREAM_ENABLE

#include <iostream>

namespace mlib
{


template<typename T>
static inline void print_num(T&& num)
{
  std::cout << num << " ";
}

static inline void print_endl()
{
  std::cout << std::endl;
}


#else

namespace mlib
{


template<typename T>
static inline void print_num(T t)
{
  // custom print implementation
}

static inline void print_endl()
{
  // cunstom print implementation
}


#endif


template<typename T, std::size_t I, std::size_t J>
void print(const Matrix<T, I, J>& A)
{
  for (std::size_t i = 0; i < I; i++)
  {
    for (std::size_t j = 0; j < J; j++)
    {
      const T tmp { A[i][j] };
      print_num(tmp);
    }
    print_endl();
  }
}

} /* namespace mlib */


#endif /* MATRIX_PRINT_HPP_ */
