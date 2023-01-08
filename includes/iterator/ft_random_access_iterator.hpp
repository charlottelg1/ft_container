#ifndef FT_RANDOM_ACCESS_ITERATOR_HPP
# define FT_RANDOM_ACCESS_ITERATOR_HPP

# include <iostream>

# include "ft_iterator_traits.hpp"
# include "ft_reverse_iterator.hpp"

namespace ft
{
	template< class T >
	class random_access_iterator
	{
		public : 

			typedef  std::random_access_iterator_tag 	iterator_category;
			typedef  T 									value_type;
			typedef  std::ptrdiff_t 					difference_type;
			typedef  T* 								pointer;
			typedef  T&									reference;
			typedef  const T* 							const_pointer;
			typedef  const T&							const_reference;
		
		protected :
			pointer _current;
		
		public : 
		// MEMBER FUNCTIONS 
			//CONSTRUCTORS
		random_access_iterator() : _current(NULL) {}
		
		random_access_iterator( pointer x ) : _current(x) {}
		
		template< class U >
		random_access_iterator( const random_access_iterator<U>& other ) : _current(other.base()) {}

		// Overload called when trying to copy construct a const_iterator
		// based on an iterator
		operator random_access_iterator<value_type const>() const
		{ return random_access_iterator<value_type const>(_current);}

			//OPERATOR =
		template< class U >
		random_access_iterator& operator=( const random_access_iterator<U>& other )
		{
			if (this != &other)
				_current = other.base();
			return (*this);
		}

			//DESTRUCTOR
		virtual ~random_access_iterator() {}

			//BASE
		pointer base() const
		{return (_current);}

			//OPERATOR * ->
		reference operator*() 
		{return (*_current);}

		const_reference operator*() const
		{return (*_current);}

		pointer operator->() 
		{return (_current);}

		const_pointer operator->() const
		{return (_current);}

			//OPERATOR []
		reference operator[]( difference_type n ) const
		{return (*(_current + n));}

			//OPERATOR ++,+,+=,--,-,-=
		random_access_iterator& operator++()
		{
			_current++;
			return (*this);
		}

		random_access_iterator operator++( int )
		{
			random_access_iterator<T> tmp(*this);
			_current++;
			return(tmp);
		}

		random_access_iterator& operator--()
		{
			_current--;
			return (*this);
		}

		random_access_iterator operator--( int )
		{
			random_access_iterator<T> tmp(*this);
			_current--;
			return(tmp);
		}

		random_access_iterator operator+( difference_type n ) const
		{ return (random_access_iterator<T>(_current + n));}

		random_access_iterator operator-( difference_type n ) const
		{ return (random_access_iterator<T>(_current - n));}

		difference_type operator-( random_access_iterator const &lhs ) const
		{ return (_current - lhs._current);}

		random_access_iterator& operator+=( difference_type n )
		{
			_current += n;
			return (*this);
		}

		random_access_iterator& operator-=( difference_type n )
		{
			_current -= n;
			return (*this);
		}

		template< class Iterator1, class Iterator2 >
		friend bool operator==( const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs );

		template< class Iterator1, class Iterator2 >
		friend bool operator!=( const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs );

		template< class Iterator1, class Iterator2 >
		friend bool operator<( const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs );

		template< class Iterator1, class Iterator2 >
		friend bool operator<=( const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs );

		template< class Iterator1, class Iterator2 >
		friend bool operator>( const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs );

		template< class Iterator1, class Iterator2 >
		friend bool operator>=( const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs );
	};
	
	// NON-MEMBER FUNCTIONS 
		// OPERATOR ==,!=,<,<=,>,>=,<=>
	template< class Iterator1, class Iterator2 >
	bool operator==( const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs )
	{return (lhs.base() == rhs.base());}

	template< class Iterator1, class Iterator2 >
	bool operator!=( const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs )
	{return (lhs.base() != rhs.base());}

	template< class Iterator1, class Iterator2 >
	bool operator<( const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs )
	{return (lhs.base() < rhs.base());}

	template< class Iterator1, class Iterator2 >
	bool operator<=( const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs )
	{return (lhs.base() <= rhs.base());}

	template< class Iterator1, class Iterator2 >
	bool operator>( const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs )
	{return (lhs.base() > rhs.base());}

	template< class Iterator1, class Iterator2 >
	bool operator>=( const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs )
	{return (lhs.base() >= rhs.base());}

	template<class Iterator>
	ft::random_access_iterator<Iterator> operator+(typename ft::random_access_iterator<Iterator>::difference_type n, ft::random_access_iterator<Iterator> const &lhs)
	{
		return (lhs + n);
	}
}

#endif