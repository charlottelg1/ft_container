#ifndef MAP_HPP	
# define MAP_HPP

# include <iostream>

# include "ft_pair.hpp"
# include "ft_lexicographical_compare.hpp"
# include "ft_equal.hpp"
# include "ft_rbtree.hpp"
# include "iterator/ft_reverse_iterator.hpp"
# include "iterator/ft_bidirectional_iterator.hpp"

namespace ft
{
	template <class T, class Key>
	struct get_key : public std::unary_function<T, Key> 
	{
		const Key &operator()(const T &x) const
		{return (x.first);}
	};
	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > > 
	class map
	{
		// MEMBER TYPES
		public : 
			typedef	Key						key_type;
			typedef	T						mapped_type;
			typedef ft::pair<const Key, T> 	value_type;
			typedef std::size_t 			size_type;
			typedef typename std::ptrdiff_t	difference_type;
			typedef Compare 				key_compare;
			typedef Allocator 				allocator_type;
			typedef value_type& 			reference;
			typedef const value_type& 		const_reference;
			typedef	Node<value_type>		node_type;
			typedef Node<value_type>		*node_ptr;
			
			typedef ft::bidirectional_iterator<value_type, node_type> 				iterator;
			typedef ft::bidirectional_iterator<value_type const, node_type const>	const_iterator;
			
			typedef typename Allocator::pointer 					pointer;
			typedef typename Allocator::const_pointer 				const_pointer;
			typedef typename ft::reverse_iterator<iterator> 		reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> 	const_reverse_iterator;
		
		// MEMBER CLASS
			class value_compare
			{
				public:
					typedef	bool		result_type;
					typedef	value_type	first_argument_type;
					typedef	value_type	second_argument_type;
				protected :
					Compare comp;
					value_compare( Compare c): comp(c) {}
				public:
					value_compare() : comp(Compare()) {}
					bool operator()( const value_type& lhs, const value_type& rhs ) const
					{return (comp(lhs.first, rhs.first));}

			};
		
		protected :
			typedef ft::rbtree<key_type, value_type, get_key<value_type, key_type>, key_compare, Allocator>	type_tree;
			allocator_type	_alloc;
			key_compare		_key_comp;
			value_compare	_value_comp;
			type_tree		_tree;

		public : 
		// MEMBER FUNCTIONS
			// CONSTRUCTOR
			map() {}
			
			explicit map( const Compare& comp, const Allocator& alloc = Allocator() )
			: _alloc(alloc), _key_comp(comp), _tree() {}
			
			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(),const Allocator& alloc = Allocator() )
			: _alloc(alloc), _key_comp(comp), _tree()
			{ insert(first, last);}

			map( const map& other )
			: _alloc(other._alloc), _key_comp(other._key_comp), _tree()
			{ insert(other.begin(), other.end());}

			// DESTRUCTOR
			~map(){}

			// OPERATOR =
			map& operator=( const map& other )
			{
				if (this != &other)
				{
					if (_tree.get_root() != _tree.get_end())
						clear();
					_alloc = other._alloc;
					_key_comp = other._key_comp;
					_value_comp = other._value_comp;
					insert(other.begin(), other.end());
					return (*this);
				}
				return (*this);
			}

			// GET_ALLOCATOR
			allocator_type get_allocator() const
			{ return (_alloc);}
		
		// ELEMENT ACCESS
			T& at( const Key& key )
			{
				node_ptr	val = _tree.search_tree(_tree.get_root(), key);
				if (val == _tree.get_end())
					throw (std::out_of_range("map::at")); // le vrai map abort ici 
				return (val->data.second);
			}

			const T& at( const Key& key ) const
			{
				node_ptr	val = _tree.search_tree(_tree.get_root(), key);
				if (val == _tree.get_end())
					throw (std::out_of_range("map::at const"));
				return (val->data.second);
			}

			T& operator[]( const Key& key )
			{
				node_ptr val = _tree.search_tree(_tree.get_root(), key);
				if (val != _tree.get_end())
					return (val->data.second);
				else
				{
					_tree.insert(value_type(key, mapped_type()));
					val = _tree.search_tree(_tree.get_root(), key);
					return (val->data.second);
				}
			}
		
		// ITERATORS 
			iterator begin()
			{ return (iterator(_tree.get_root(), _tree.min_node(_tree.get_root()), _tree.get_end()));}

			const_iterator begin() const
			{ return (const_iterator(_tree.get_root(), _tree.min_node(_tree.get_root()), _tree.get_end()));}

			iterator end() 
			{ return (iterator(_tree.get_root(), _tree.get_end(), _tree.get_end()));}

			const_iterator end() const
			{ return (const_iterator(_tree.get_root(), _tree.get_end(), _tree.get_end()));}

			reverse_iterator rbegin()
			{ return(reverse_iterator(end()));}

			const_reverse_iterator rbegin() const
			{ return(const_reverse_iterator(end()));}

			reverse_iterator rend()
			{ return(reverse_iterator(begin()));}

			const_reverse_iterator rend() const
			{ return(const_reverse_iterator(begin()));}
		
		// CAPACITY 
			bool empty() const
			{ return (_tree.get_size() == 0);}

			size_type size() const
			{ return (_tree.get_size());}

			size_type max_size() const
			{ return (_tree.max_size());}

		// MODIFIERS
			void clear()
			{ _tree.clear_tree(_tree.get_root());}

			ft::pair<iterator, bool> insert( const value_type& value )
			{
				iterator it = find(value.first);
				if (it != end())
					return (ft::pair<iterator, bool>(it,false));
				_tree.insert(value);
				it = find(value.first);
				return (ft::pair<iterator, bool>(it, true));
			}

			iterator insert( iterator pos, const value_type& value )
			{
				(void)pos;
				return (insert(value).first);
			}

			template< class InputIt >
			void insert( InputIt first, InputIt last )
			{
				for (; first != last; first++)
					insert(*first);
			}

			void erase( iterator pos )
			{ erase(pos->first);}

			void erase( iterator first, iterator last )
			{
				while (first != last)
					erase((first++)->first);
			}

			size_type erase( const Key& key )
			{return (_tree.deleteNode(key));}

			void swap( map& other )
			{ _tree.swap(other._tree);}

		// LOOKUP
			size_type count( const Key& key ) const
			{
				if (_tree.search_tree(_tree.get_root(), key) != _tree.get_end())
					return (1);
				return (0);
			}

			iterator find( const Key& key ) 
			{
				node_ptr	tmp = _tree.search_tree(_tree.get_root(), key);
				if (tmp == _tree.get_end())
					return (end());
				return (iterator(_tree.get_root(), tmp, _tree.get_end()));
			}

			const_iterator find( const Key& key ) const
			{
				node_ptr	tmp = _tree.search_tree(_tree.get_root(), key);
				if (tmp == _tree.get_end())
					return (end());
				return (const_iterator(_tree.get_root(), tmp, _tree.get_end()));
			}

			ft::pair<iterator,iterator> equal_range( const Key& key )
			{ return (ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key)));}

			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
			{ return (ft::pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key)));}

			iterator lower_bound( const Key& key )
			{
				iterator	itb = begin();
				iterator	ite = end();
				while (itb != ite)
				{
					if (_key_comp(itb->first, key) == false)
						break;
					itb++;
				}
				return (itb);
			}

			const_iterator lower_bound( const Key& key ) const
			{
				const_iterator	itb = begin();
				const_iterator	ite = end();
				while (itb != ite)
				{
					if (_key_comp(itb->first, key) == false)
						break;
					itb++;
				}
				return (itb);
			}

			iterator upper_bound( const Key& key )
			{
				iterator	itb = begin();
				iterator	ite = end();
				while (itb != ite)
				{
					if (_key_comp(key, itb->first))
						break;
					itb++;
				}
				return (itb);
			}

			const_iterator upper_bound( const Key& key ) const
			{
				const_iterator	itb = begin();
				const_iterator	ite = end();
				while (itb != ite)
				{
					if (_key_comp(key, itb->first))
						break;
					itb++;
				}
				return (itb);
			}
		
		// OBSERVERS
			key_compare key_comp() const
			{ return (_key_comp);}

			value_compare value_comp() const
			{ return (_value_comp);}
	};
	// NON MEMBERS
	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		if (lhs.size() != rhs.size() )
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{ return (!(lhs == rhs));}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{ return ( ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{ return (!(rhs < lhs));}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{return (rhs < lhs);}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{ return (!(lhs < rhs));}

	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs )
	{ lhs.swap(rhs);}
}

#endif