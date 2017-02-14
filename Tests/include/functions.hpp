#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

void function(){}

std::string func(){return "Hello World";}

std::vector<int> vector_function(){return std::vector<int>{1,2,3,4};};

template<typename T>
struct is_true:janor::true_type{};

template<typename T>
struct is_false:janor::false_type{};

#endif
