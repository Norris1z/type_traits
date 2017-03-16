# type_traits

[![Build Status](https://travis-ci.org/Norris1z/type_traits.svg?branch=master)](https://travis-ci.org/Norris1z/type_traits)
[![Build Status](https://ci.appveyor.com/api/projects/status/j5g0wqvliknevqcl)]( https://ci.appveyor.com/project/Norris1z/type_traits )

an implementation of C++ type_traits for  learning purposes .... Please note that it is not standard. 

Kindly visit http://en.cppreference.com/w/cpp/header/type_traits for the standardized version 

`janor type_traits` is a header only file which helps you detect the type of objects

## Usage

include the header file `janor/type_traits.hpp` in your project. 
all the type check structs are under the namespace `janor`

## Example

```C++
#include <iostream>
#include <vector>
#include <janor/type_traits.hpp>

void foo(){ }

std::vector<int> bar()
{
  return std::vector<int>{1,2,3,4,5};
}
int main()
{
  
  int number = 99;
  std::cout<<(janor::is_void<decltype(foo())>::value ? "True":"False")<<'\n'; // true
  std::cout<<(janor::is_vector<decltype(bar())>::value ? "True" : "False")<<'\n'; //true
  std::cout<<(janor::is_rvalue_reference<decltype(std::move(number))>::value ? "True" : "False")<<'\n'; //true
  std::cout<<(janor::is_rvalue_reference<decltype(static_cast<int&&>(999))>::value ? "True" : "False")<<'\n'; //true
  
}
```
## Tests 

All tests are found in the Tests directory. 
Tests were written using `Gtest`.
Note that you can change the Variables in the Tests Makefile to the path of your `Gtest` includes and `src` files

