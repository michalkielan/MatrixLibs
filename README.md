## Overwiew
MatrixLibs is C++11 meta-programming, header-only, no-dynamic memory allocations library for matrix computation, similar to matlab, microcontroller friendly if you use C++ on embedded platform without using exceptions


## Algorithm already implemented:
* Sum
* Substraction
* Multiply
* Division
* Absolut
* Power
* Transpose
* Inverse
* Strassen
* Determinant
* LU
* Concatenate
* Histogram
* Filters: mean, meadina, variance, standard deviation


## Usage
* include matrix.hpp
* enable C++11 or higher
* have fun

Matrix object uses `std::array` from C++11, so the explicity type and the size of matrix is always necessary
```C++
constexpr std::size_t n = 2;
Matrix<float, n, n> A
{ 1, 2, 
  3, 4 };
  
auto B = <float, n, n>eye();
  
auto C = A * B:
```

