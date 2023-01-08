#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>

# include "vector.hpp"

namespace ft
{
	template< class T, class Container = ft::vector<T> > 
	class stack
	{
		public : 
			typedef 			Container 					container_type;
			typedef  			T							value_type;
			typedef typename 	Container::size_type		size_type;
			typedef typename 	Container::reference		reference;
			typedef typename 	Container::const_reference	const_reference;

		// MEMBER FUNCTIONS
			// CONSTRUCTORS
			explicit stack( const Container& cont = Container() ):_c(cont){}
			stack( const stack& other ):_c(other._c){}

			// DESTRUCTOR
			~stack(){}

			// OPERATOR = 
			stack& operator=( const stack& other )
			{
				if (*this != other) 
					_c = other._c;
				return (*this);
			}

			// ELEMENT ACCESS
			reference top()
			{ return (_c.back());}
			const_reference top() const
			{ return (_c.back());}

			// CAPACITY 
			bool empty() const
			{ return (_c.empty());}
			size_type size() const
			{ return (_c.size());}

			// MODIFIERS
			void push( const value_type& value )
			{ _c.push_back(value);}
			void pop()
			{_c.pop_back();}

		// MEMBER OBJECTS
			container_type _c;

			friend bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
			{return (lhs._c == rhs._c);}

			friend bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
			{return (lhs._c != rhs._c);}

			friend bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
			{return (lhs._c < rhs._c);}

			friend bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
			{return (lhs._c <= rhs._c);}

			friend bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
			{return (lhs._c > rhs._c);}

			friend bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
			{return (lhs._c >= rhs._c);}
	};
}

#endif
