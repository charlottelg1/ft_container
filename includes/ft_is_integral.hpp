#ifndef FT_IS_INTEGRAL_HPP
# define FT_IS_INTEGRAL_HPP

# include <iostream>

namespace ft
{
	template <typename T>
	struct is_integral
	{
		static const bool value = false;
	};

	template <>
    struct is_integral<bool>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<char>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<signed char>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned char>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<wchar_t>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<short>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned short>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<int>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned int>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<long>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned long>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<long long>
    {
        static const bool value = true;
    };

    template <>
    struct is_integral<unsigned long long>
    {
        static const bool value = true;
    };
}

#endif

/*Trait class that identifies whether T is an integral type.

It inherits from integral_constant as being either true_type or false_type, 
depending on whether T is an integral type:

fundamental integral types
	bool
	char
	char16_t (since 11)
	char32_t (since 11)
	wchar_t
	signed char
	short int
	int
	long int
	long long int
	unsigned char
	unsigned short int
	unsigned int
	unsigned long int
	unsigned long long int
*/