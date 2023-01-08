#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iostream>

# include "ft_iterator_traits.hpp"

namespace ft
{
	template< class Iter >
	class reverse_iterator
	{
		public : 
		typedef Iter 													iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category 	iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type 			value_type;
		typedef typename std::ptrdiff_t  	difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer 			pointer;
		typedef typename ft::iterator_traits<Iter>::reference 			reference;

		protected : 
			iterator_type _current;
		
		public : 
		// MEMBER FUNCTIONS 
			//CONSTRUCTORS
		reverse_iterator() : _current(iterator_type()) {}
		
		explicit reverse_iterator( iterator_type x ) : _current(x) {}
		
		template< class U >
		reverse_iterator( reverse_iterator<U> const &other ) : _current(other.base()) {}
		
			//OPERATOR =
		template< class U >
		reverse_iterator& operator=( reverse_iterator<U> const &other )
		{
			if (this != & other)
				_current = other.base();
			return (*this);
		}

			//DESTRUCTOR
		virtual ~reverse_iterator() {}

			//BASE
		iterator_type base() const
		{return (_current);}

			//OPERATOR * ->
		reference operator*() const
		{	
			Iter tmp(_current);
			return (*--tmp);
		}

		pointer operator->() const
		{return (&(operator*()));}

			//OPERATOR []
		reference operator[]( difference_type n ) const
		{return (_current[-n - 1]);}

			//OPERATOR ++,+,+=,--,-,-=
		reverse_iterator& operator++()
		{
			_current--;
			return (*this);
		}

		reverse_iterator& operator--()
		{
			_current++;
			return (*this);
		}

		reverse_iterator operator++( int )
		{
			reverse_iterator<Iter> tmp(*this);
			_current--;
			return(tmp);
		}

		reverse_iterator operator--( int )
		{
			reverse_iterator<Iter> tmp(*this);
			_current++;
			return(tmp);
		}

		reverse_iterator operator+( difference_type n ) const
		{ return (reverse_iterator<Iter>(_current - n));}

		reverse_iterator operator-( difference_type n ) const
		{ return (reverse_iterator<Iter>(_current + n));}

		reverse_iterator& operator+=( difference_type n )
		{
			_current -= n;
			return (*this);
		}

		reverse_iterator& operator-=( difference_type n )
		{
			_current += n;
			return (*this);
		}
	};
	
	// NON-MEMBER FUNCTIONS 
		// OPERATOR ==,!=,<,<=,>,>=,<=>
	template< class Iterator1, class Iterator2 >
	bool operator==( const reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
	{return (lhs.base() == rhs.base());}

	template< class Iterator1, class Iterator2 >
	bool operator!=( const reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
	{return (lhs.base() != rhs.base());}

	template< class Iterator1, class Iterator2 >
	bool operator<( const reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
	{return (lhs.base() > rhs.base());}

	template< class Iterator1, class Iterator2 >
	bool operator<=( const reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
	{return (lhs.base() >= rhs.base());}

	template< class Iterator1, class Iterator2 >
	bool operator>( const reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
	{return (lhs.base() < rhs.base());}

	template< class Iterator1, class Iterator2 >
	bool operator>=( const reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
	{return (lhs.base() <= rhs.base());}

		//OPERATOR +
	template< class Iter >
	reverse_iterator<Iter> operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it )
	{return (it + n);}

	template <class Iterator, class Iter>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iter> &it)
	{
		return (it + n);
	}
		//OPERATOR -
	template< class Iterator1, class Iterator2 >
	typename reverse_iterator<Iterator1>::difference_type operator-( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
	{return (rhs.base() - lhs.base());}
}

#endif