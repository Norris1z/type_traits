#ifndef JANOR_TYPE_TRAITS_HPP
#define JANOR_TYPE_TRAITS_HPP

namespace janor{

	struct true_type{ static constexpr bool value = true;};

	struct false_type{ static constexpr bool value = false;};
	
template <typename T, typename U>
	struct is_same : std::false_type{};
template <typename T>
	struct is_same<T,T> : std::true_type{};

template<typename T>
	struct is_string:
	 is_same<std::string, typename std::remove_cv<T>::type>{};

template <typename T>
	struct is_int{static const bool value = false;};
	template<>
	struct is_int<int>{static const bool value = true;};
	template<>
	struct is_int<std::size_t>{static const bool value = true;};
template <typename T>
	struct is_32bit_int{static const bool value = false;};
	template<>
	struct is_32bit_int<int>{static const bool value = true;};

template<typename T>
	struct is_64bit_int{static const bool value = false;};
	template<>
	struct is_64bit_int<std::size_t>{static const bool value = true;};
	template<>
	struct is_64bit_int<std::int64_t>{static const bool value = true;};

template<typename T>
	struct is_void{ static const bool value = false;};
	template<>
	struct is_void<void>{static const bool value =true;};

template<typename T>
	struct is_vector{static const bool value = false;};
	template <typename T>
	struct is_vector<std::vector<T>>{static const bool value = true;};

template<typename T>
	struct is_pointer :std::false_type{};
	template<typename T>
	struct is_pointer<T*> :std::true_type{};

template<typename T>
	struct is_reference : std::false_type{};
	template<typename T>
	struct is_reference<T&> : std::true_type{};

template<typename T>
	struct is_rvalue_reference :std::false_type{};
	template<typename T>
	struct is_rvalue_reference<T&&>: std::true_type{};

template<typename T>
	struct is_nullptr : is_same<T, std::nullptr_t>{};

}

#endif //JANOR_TYPE_TRAITS_HPP