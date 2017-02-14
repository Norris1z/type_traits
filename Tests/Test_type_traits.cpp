#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <janor/type_traits.hpp>
#include <functions.hpp>

TEST(TYPE_TRAITS, test_is_string)
{
	std::string name_true ="Norris";
	bool value_true = janor::is_string<decltype(name_true)>::value;

	auto name_false = 99;
	bool value_false = janor::is_string<decltype(name_false)>::value;
	
	const std::string const_name = "Janor";
	bool value_const = janor::is_string<decltype(const_name)>::value;

	volatile std::string volatile_name = "Github";
	bool value_volatile = janor::is_string<decltype(volatile_name)>::value;
	
	EXPECT_EQ(false,value_false);
	EXPECT_EQ(true,value_true);
	EXPECT_EQ(true,value_const);
	EXPECT_EQ(true,value_volatile);
}


TEST(TYPE_TRAITS, test_is_int)
{
	auto number_true = 999;
	bool value_true = janor::is_int<decltype(number_true)>::value;

	auto number_false = "Helloo";
	bool value_false = janor::is_int<decltype(number_false)>::value;

	EXPECT_EQ(false,value_false);
	EXPECT_EQ(true,value_true);
}


TEST(TYPE_TRAITS, test_is_32bit_int)
{
	auto number_true = 999;
	bool value_true = janor::is_32bit_int<decltype(number_true)>::value;

	auto number_false = 9826463734734837;
	bool value_false = janor::is_32bit_int<decltype(number_false)>::value;
	
	EXPECT_EQ(false,value_false);
	EXPECT_EQ(true,value_true);
}


TEST(TYPE_TRAITS, test_is_64bit_int)
{
	auto number_true = 9826463734734837;
	bool value_true = janor::is_64bit_int<decltype(number_true)>::value;

	auto number_false = 999;
	bool value_false = janor::is_64bit_int<decltype(number_false)>::value;

	EXPECT_EQ(false,value_false);
	EXPECT_EQ(true,value_true);
}


TEST(TYPE_TRAITS, test_is_void)
{
	bool value_true = janor::is_void<decltype(function())>::value;

	bool value_false = janor::is_void<decltype(func())>::value;

	EXPECT_EQ(false,value_false);
	EXPECT_EQ(true,value_true);
}


TEST(TYPE_TRAITS, test_is_vector)
{
	bool value_true = janor::is_vector<decltype(vector_function())>::value;
	bool value_false = janor::is_vector<decltype(func())>::value;

	EXPECT_EQ(false,value_false);
	EXPECT_EQ(true,value_true);
}


TEST(TYPE_TRAITS, test_is_pointer)
{
	int number = 999;
	int* p_num = &number;
	bool value_true = janor::is_pointer<decltype(p_num)>::value;
	bool value_false = janor::is_pointer<decltype(number)>::value;
	
	EXPECT_EQ(false,value_false);
	EXPECT_EQ(true,value_true);
}


TEST(TYPE_TRAITS, test_is_reference)
{
	int number = 999;
	int& ref_num = number;
	bool value_true = janor::is_reference<decltype(ref_num)>::value;
	bool value_false = janor::is_reference<decltype(number)>::value;
	EXPECT_EQ(false,value_false);
	EXPECT_EQ(true,value_true);
}


TEST(TYPE_TRAITS, test_is_rvalue_reference)
{
	int number = 999;
	int&& ref_num = 999;
	bool value_true = janor::is_rvalue_reference<decltype(ref_num)>::value;
	bool value_true_cast = janor::is_rvalue_reference<decltype(static_cast<int&&>(999))>::value;
	bool value_true_move = janor::is_rvalue_reference<decltype(std::move(number))>::value;
	bool value_false = janor::is_rvalue_reference<decltype(number)>::value;
	EXPECT_EQ(false,value_false);
	EXPECT_EQ(true,value_true);
	EXPECT_EQ(true,value_true_cast);
	EXPECT_EQ(true,value_true_move);
}

TEST(TYPE_TRAITS, test_is_same)
{
	int number = 44;
	int number2 = 99;
	bool true_value = janor::is_same<decltype(number),decltype(number2)>::value;
	
	auto num = nullptr;
	auto numm = "C++ is awesome";
	bool false_value = janor::is_same<decltype(num),decltype(numm)>::value;
	
	EXPECT_EQ(true,true_value);
	EXPECT_EQ(false,false_value);
}

TEST(TYPE_TRAITS, test_is_nullptr)
{
	int number = 99;
	auto pointer = nullptr;
	auto* point = &number;
	
	bool true_value = janor::is_nullptr<decltype(pointer)>::value;
	bool false_value = janor::is_nullptr<decltype(point)>::value;

	EXPECT_EQ(true,true_value); 
	EXPECT_EQ(false,false_value); 
}

TEST(TYPE_TRAITS, test_true_type)
{
	bool value = is_true<int>::value;
	EXPECT_EQ(true,value);
}

TEST(TYPE_TRAITS, test_false_type)
{
	bool value = is_false<int>::value;
	EXPECT_EQ(false,value);	
}