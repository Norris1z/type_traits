#ifndef J_TYPES_HPP
#define J_TYPES_HPP

namespace janor{

template<typename T>
	struct is_string{static const bool value = false;};
	template<>
	struct is_string<std::string>{static const bool value = true;};

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
	struct is_pointer{ static const bool value = false;};
	template<typename T>
	struct is_pointer<T*>{static const bool value = true;};

template<typename T>
	struct is_reference{static const bool value = false;};
	template<typename T>
	struct is_reference<T&>{static const bool value = true;};

template<typename T>
	struct is_rvalue_reference{static const bool value = false;};
	template<typename T>
	struct is_rvalue_reference<T&&>{static const bool value = true;};

}

#endif