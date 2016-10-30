## Overwiew
MatrixLibs is C++11 meta-programming, header-only, no-dynamic memory allocations library for matrix computation, similar to matlab.


## Algorithms already implemented:
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
* LU decomposition
* Cholesky decomposition
* Concatenate
* Convolution
* Histogram
* Filters: mean, meadina, variance, standard deviation
* Swap rows, cols


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

##Dependiences
The google test and google benchmark framework is used in correct and performance tests
* https://github.com/google/googletest
* https://github.com/google/benchmark


## Compiling
Compile like most of applications with cmake

```
$ mkdir build && cd build
$ cmake ..
$ make
```

If you don't want to make the tests, you can use this cmake options
```
$ cmake -DBUILD_TESTS=OFF
```

or switch off benchmark tests

```
$ cmake -DBUILD_BENCH=OFF
```


If you want to debug the memory leaks, you can set up the address sanitizer option

```
$ cmake -DSANITIZER=ON
```




