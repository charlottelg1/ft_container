#ifndef FT_EQUAL_HPP
# define FT_EQUAL_HPP

# include <iostream>

namespace ft
{
	template< class InputIt1, class InputIt2 >
	bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 )
	{
		while (first1!=last1) {
    		if (!(*first1 == *first2)) 
      			return false;
    		++first1; ++first2; 
 	 	}
  		return true;
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate p )
	{
		while (first1!=last1) {
			if (!p(*first1,*first2))
				return false;
			++first1; ++first2;
		}
	return true;
	}
}

#endif

/*Test whether the elements in two ranges are equal
Compares the elements in the range [first1,last1) with those in the range beginning at first2, 
and returns true if all of the elements in both ranges match.

The elements are compared using operator== (or pred, in version (2)).*/