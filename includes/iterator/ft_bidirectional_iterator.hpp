#ifndef FT_BIDIRECTIONAL_ITERATOR_HPP
# define FT_BIDIRECTIONAL_ITERATOR_HPP

# include <iostream>
# include "ft_iterator_traits.hpp"
# include "../ft_rbtree.hpp"
# include "../ft_enable_if.hpp"
# include "../ft_is_integral.hpp"

namespace ft
{
	template< class T, class N >
	class bidirectional_iterator
	{
		public : 
			typedef	ft::bidirectional_iterator_tag iterator_category;
			typedef T 								value_type;
			typedef std::ptrdiff_t 					difference_type;
			typedef T* 								pointer;
			typedef T&								reference;
			typedef const T* 						const_pointer;
			typedef	const T&						const_reference;
			typedef	N								node_type;
			typedef	node_type*						node_ptr;
		
		private :
			node_ptr	_ptr;
			node_ptr	_end;
			node_ptr	_root;
		
		public : 
		// MEMBER FUNCTIONS 
			//CONSTRUCTORS
			bidirectional_iterator() : _ptr(NULL), _end(NULL), _root(NULL) {}
			
			explicit bidirectional_iterator(node_ptr root, node_ptr base, node_ptr end)
			: _ptr(base), _end(end), _root(root) {}
			
			bidirectional_iterator( const bidirectional_iterator& other )
			: _ptr(other._ptr), _end(other._end), _root(other._root) {}

				//OPERATOR =
			bidirectional_iterator& operator=( const bidirectional_iterator& other )
			{
				if (this != &other)
				{
					_ptr = other._ptr;
					_end = other._end;
					_root = other._root;
				}
				return (*this);
			}

			operator bidirectional_iterator<value_type const, node_type const>() const
			{ return bidirectional_iterator<value_type const, node_type const>(_root, _ptr, _end);}

			//DESTRUCTOR
			virtual ~bidirectional_iterator() {}

			//BASE
			pointer base() const
			{return (_ptr);}

			//OPERATOR * ->
			reference operator*() 
			{return (_ptr->data);}

			const_reference operator*() const 
			{return (_ptr->data);}

			pointer operator->() 
			{return (&(operator*()));}

			const_pointer operator->() const
			{return (&(operator*()));}

			//COMP
			bool operator==(const bidirectional_iterator &lhs) const
			{ return (_ptr == lhs._ptr);}

			bool operator!=(const bidirectional_iterator &lhs) const
			{ return (_ptr != lhs._ptr);}

			//OPERATOR ++,+,+=,--,-,-=
			bidirectional_iterator& operator++()
			{
				if (_ptr != _end)
					_ptr = successor(_ptr);
				return (*this);
			}

			bidirectional_iterator operator++(int)
			{
				bidirectional_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			bidirectional_iterator& operator--()
			{
				if (_ptr == _end)
					_ptr = max(_root);
				else
					_ptr = predecessor(_ptr);
				return (*this);
			}

			bidirectional_iterator operator--( int )
			{
				bidirectional_iterator	tmp(*this);
				operator--();
				return(tmp);
			}

		protected: 
			node_ptr	_min(node_ptr node)
			{
				while (node->left != _end)
					node = node->left;
				return (node);
			}

			node_ptr	max(node_ptr node)
			{
				if (node != _end || node != NULL)
				{
					while (node->right != _end)
						node = node->right;
				}
				return (node);
			}

			node_ptr successor(node_ptr x)
			{
				if (x->right != _end)
					return _min(x->right);
				node_ptr y = x->parent;
				while (y != NULL && x == y->right)
				{
					x = y;
					y = y->parent;
				}
				if (y == NULL)
					return (_end);
				return y;
			}

			node_ptr predecessor(node_ptr x)
			{
				if (x->left != _end)
					return max(x->left);
				node_ptr y = x->parent;
				while (y != _end && x == y->left)
				{
					x = y;
					y = y->parent;
				}
				return y;
			}
		
	};
	
	// NON-MEMBER FUNCTIONS 
	template<class Iterator, class Iter>
	bool operator==(ft::bidirectional_iterator<Iterator, ft::Node<Iterator> > const &lhs, ft::bidirectional_iterator<Iter, ft::Node<Iter> > const &rhs)
	{
		return (lhs._ptr == rhs._ptr);
	}

	template<class Iterator, class Iter>
	bool operator!=(ft::bidirectional_iterator<Iterator, ft::Node<Iterator> > const &lhs, ft::bidirectional_iterator<Iter, ft::Node<Iter> > const &rhs)
	{
		return (lhs._ptr != rhs._ptr);
	}

}

#endif 