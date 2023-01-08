#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		public : 
			typedef T1 first_type;
			typedef T2 second_type;

			T1 first;
			T2 second;

			pair(): first(first_type()), second(second_type()) {};
			pair(const T1 &a, const T2 &b): first(a), second(b) {};
			template< class U1, class U2 >
			pair( const pair<U1, U2>& p ): first(p.first), second(p.second) {};
			pair& operator=( const pair& other )
			{
				if (*this != other)
				{
					first = other.first;
					second = other.second;
				}
				return (*this);
			}
	};
	template<class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 t, T2 u)
	{
		return (pair<T1, T2>(t, u));
	}
	
	template< class T1, class T2 >
	bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
		{ return (lhs.first == rhs.first && lhs.second == rhs.second); }
	
	template< class T1, class T2 >
	bool operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
		{ return (!(lhs == rhs)); }
	
	template< class T1, class T2 >
	bool operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
		{ return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second<rhs.second); }
	
	template <class T1, class T2>
  	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(rhs < lhs); }
	
	template <class T1, class T2>
  	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return rhs < lhs; }
	
	template <class T1, class T2>
  	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(lhs < rhs); }
}

#endif

/*Pair of values
This class couples together a pair of values, which may be of different types (T1 and T2). 
The individual values can be accessed through its public members first and second.

Pairs are a particular case of tuple.*/