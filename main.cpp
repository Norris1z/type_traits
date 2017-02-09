#include <iostream>
#include <vector>
#include <janor/type_traits.hpp>

void funct(){

}
int main()
{
	std::string name = "Norris";
	std::vector<int> numbers;
	std::size_t norris = 89;
	auto num = 184467440737095516;
	int numm = 55;
	int* p_num = &numm;
	int& r_num = numm;
	int&& rr_num = 999;
	
	std::cout<<"is_string --- "<<(janor::is_string<decltype(name)>::value ? "True":"False")<<'\n';
	std::cout<<"is_void --- "<<(janor::is_void<decltype(funct())>::value ? "True":"False")<<'\n';
	std::cout<<"is_vector --- "<<(janor::is_vector<decltype(numbers)>::value ? "True":"False")<<'\n';
	std::cout<<"is_int --- "<<(janor::is_int<decltype(norris)>::value ? "True":"False")<<'\n';
	std::cout<<"is_32bit_int --- "<<(janor::is_32bit_int<decltype(norris)>::value ? "True":"False")<<'\n';
	std::cout<<"is_64bit_int --- "<<(janor::is_64bit_int<decltype(norris)>::value ? "True":"False")<<'\n';
	std::cout<<"is_64bit_int --- "<<(janor::is_64bit_int<decltype(num)>::value ? "True":"False")<<'\n';
	std::cout<<"is_pointer --- "<<(janor::is_pointer<decltype(p_num)>::value ? "True":"False")<<'\n';
	std::cout<<"is_reference --- "<<(janor::is_reference<decltype(r_num)>::value ? "True":"False")<<'\n';
	std::cout<<"is_rvalue_reference --- "<<(janor::is_rvalue_reference<decltype(static_cast<int&&>(999))>::value ? "True":"False")<<'\n';
	std::cout<<"is_rvalue_reference --- "<<(janor::is_rvalue_reference<decltype(rr_num)>::value ? "True":"False")<<'\n';
	std::cout<<"is_rvalue_reference --- "<<(janor::is_rvalue_reference<decltype(std::move(numm))>::value ? "True":"False")<<'\n';
}