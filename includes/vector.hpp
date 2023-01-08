#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>

# include "iterator/ft_iterator_traits.hpp"
# include "iterator/ft_random_access_iterator.hpp"
# include "iterator/ft_reverse_iterator.hpp"
# include "ft_is_integral.hpp"
# include "ft_equal.hpp"
# include "ft_enable_if.hpp"
# include "ft_lexicographical_compare.hpp"

namespace ft
{
	template<class T,class Allocator = std::allocator<T> >
	class vector
	{		
		public : 
			typedef 	T 			value_type;
			typedef 	Allocator 	allocator_type;

			typedef typename Allocator::size_type 							size_type;
			typedef typename Allocator::difference_type 					difference_type;
			typedef typename Allocator::reference 							reference;
			typedef typename Allocator::const_reference 					const_reference;
			typedef typename Allocator::pointer 							pointer;
			typedef typename Allocator::const_pointer 						const_pointer;

			typedef typename ft::random_access_iterator<value_type>			iterator;
			typedef typename ft::random_access_iterator<const value_type> 	const_iterator;

			typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> 			const_reverse_iterator;
		
		protected :
			pointer 		_ptr;
			size_type 		_size;
			size_type		_capacity;
			allocator_type	_alloc;
		
		private :
			template< class InputIt >
			difference_type ft_diff(InputIt first, InputIt last)
			{
				difference_type diff = 0;
				for (InputIt tmp = first; tmp != last; tmp++)
					diff++;
				return (diff);
			}

		public :
			void	display_vect()
			{
				for (size_type i = 0; i < _size; i++)
					std::cout << _ptr[i];
				std::cout << std::endl;
			}

			//ELEMENT ACCESS
			reference at( size_type pos )
			{
				if (!(pos < _size))
					throw std::out_of_range("ft_vector::at");
				return (_ptr[pos]);
			}
			const_reference at( size_type pos ) const
			{
				if (!(pos < _size))
					throw std::out_of_range("ft_vector::at");
				return (_ptr[pos]);
			}

			reference operator[]( size_type pos )
			{return (_ptr[pos]);}
			const_reference operator[]( size_type pos ) const
			{return (_ptr[pos]);}

			reference front()
			{return (_ptr[0]);}
			const_reference front() const
			{return (_ptr[0]);}

			reference back()
			{return (_ptr[_size - 1]);}
			const_reference back() const
			{return (_ptr[_size - 1]);}

			T* data()
			{return (_ptr);}
			const T* data() const
			{return (_ptr);}

			// ITERATORS
			iterator begin()
			{return (iterator(_ptr));}
			
			const_iterator begin() const
			{return (const_iterator(_ptr));}

			iterator end()
			{return (iterator(_ptr + _size));}
			
			const_iterator end() const
			{return (const_iterator(_ptr + _size));}

			reverse_iterator rbegin()
			{return (reverse_iterator(_ptr + _size));}
			
			const_reverse_iterator rbegin() const
			{return (const_reverse_iterator(_ptr + _size));}

			reverse_iterator rend()
			{return (reverse_iterator(_ptr));}
			
			const_reverse_iterator rend() const
			{return (const_reverse_iterator(_ptr));}
			
				// CONSTRUCTORS 
			vector():_ptr(NULL), _size(0), _capacity(0), _alloc(allocator_type()){}

			explicit vector( const Allocator& alloc ):_ptr(NULL), _size(0), _capacity(0), _alloc(alloc){}

			explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator())\
			:_ptr(NULL), _size(count), _capacity(count), _alloc(alloc)
			{
				_ptr = _alloc.allocate(count);
				for(size_type i = 0; i < count;i++)
					_alloc.construct(_ptr + i, value);

			}

			template< class InputIt >
			vector( InputIt first, InputIt last, const Allocator& alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL ):_ptr(NULL), _size(0), \
			_capacity(0), _alloc(alloc)
			{
				difference_type diff = 0;
				for (InputIt tmp = first; tmp != last; tmp++)
					diff++;
				_ptr = _alloc.allocate(diff);
				_capacity = diff;
				for (;first != last;first++)
					push_back(*first);
				_size = diff;
			} 
			
			vector( const vector& other ):_ptr(NULL), _size(0), _capacity(0), _alloc(other._alloc)
			{
				insert(begin(), other.begin(), other.end());}

				// DESTRUCTOR
			~vector() 
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_ptr[i]);
				_alloc.deallocate(_ptr, _capacity);
			}

				// OPERATOR = 
			vector& operator=( const vector& other )
			{
				if (*this != other)
				{
					clear();
					insert(end(), other.begin(), other.end());
				}
				return (*this);
			}

				// ASSIGN
			void assign( size_type count, const T& value )
			{
				clear();
				reserve(count);
				for (size_type i = 0; i < count; i++)
					push_back(value);
			}
			
			template< class InputIt >
			void assign( InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL )
			{
				clear();
				difference_type diff = ft_diff(first, last);
				reserve (diff);
				for (; first != last; first++)
					push_back(*first);
			}

				// GET ALLOCATOR 
			allocator_type get_allocator() const
			{return (_alloc);}

			// CAPACITY
			bool empty() const {return (begin()== end());}
			size_type size() const {return (_size);}
			size_type max_size() const {return (_alloc.max_size());}
			
			void reserve( size_type new_cap )
			{
				if (new_cap > max_size())
					throw (std::length_error("vector::reserve"));
				if (new_cap > _capacity && new_cap != 0)
				{
					value_type *tmp = _alloc.allocate(new_cap);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&tmp[i], _ptr[i]);
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(&_ptr[i]);
					_alloc.deallocate(_ptr, new_cap);
					_capacity = new_cap;
					_ptr = tmp;
				}
			}
			size_type capacity() const {return (_capacity);}

			// MODIFIERS
			void clear()
			{
				if (_ptr)
					while (_size > 0)
						pop_back();
			}

			iterator insert( iterator pos, const T& value ) 
			{
				difference_type index = pos - begin();
				insert(pos, 1, value);
				return (begin() + index);
			}

			iterator insert( iterator pos, size_type count, const T& value )
			{
				size_type index = pos - begin();
				if (count == 0)
					return (pos);
				if (count + _size > _capacity)
				{
					size_t new_cap = 0;
					if (_capacity == 0)
						new_cap = 1;
					else 
						new_cap = _size * 2;
					if (new_cap < _size + count)
						new_cap = _size + count;
					reserve(new_cap);
				}
				for (size_type i = _size; i > index ; i--)
				{
					_alloc.construct(_ptr + i - 1 + count, *(_ptr + i - 1));
					_alloc.destroy(_ptr + i - 1);
				}
				for (size_type i = 0; i < count; i ++)
				{
					_alloc.construct(&_ptr[index + i], value);
				}
				_size += count;
				return (pos);
			}

			template< class InputIt > 
			iterator insert( iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value>::type* = 0)
			{
				size_type index = pos - begin();
				size_type count = 0;
				for (InputIt tmp = first; tmp != last; tmp++)
					count++;
				if (_size + count > max_size())
					throw (std::length_error("ft_vector::insert"));
				if (_capacity < _size + count)
				{	
					size_t new_cap = 0;
					if (_capacity == 0)
						new_cap = 1;
					else
						new_cap = _size * 2;
					if (new_cap < _size + count)
						new_cap = _size + count;
					reserve(new_cap);
				}
				for (size_type i = _size; i > index ; i--)
				{
					_alloc.construct(_ptr + i - 1 + count, *(_ptr + i - 1));
					_alloc.destroy(_ptr + i - 1);
				}
				for (InputIt ite = first; ite != last; ++ite)
				{
					_alloc.construct(&_ptr[index++], *ite);
				}
				_size += count;
				return (pos);
			}

			iterator erase( iterator pos )
			{
				_alloc.destroy(&*pos);
				for (iterator tmp = pos; tmp + 1 != end(); tmp++)
				{
					_alloc.construct(&*tmp, *(tmp + 1));
					_alloc.destroy(&*(tmp + 1));
				}
				_size -= 1;
				return (pos);
			}

			iterator erase( iterator first, iterator last )
			{
				size_t count = 0;
				for (iterator tmp = first; tmp != last; tmp ++)
				{
					count ++;
					_alloc.destroy(&*tmp);
				}
				for (iterator tmp = first; tmp + count != end(); tmp++)
				{
					_alloc.construct(&*tmp, *(tmp + count));
					_alloc.destroy(&*tmp + count);
				}
				_size -= count;
				return (first);
			}

			void push_back( const T& value )
			{
				if (_size + 1 > _capacity)
				{
					if (empty())
						reserve(1);
					else
						reserve(_size * 2);
				}
				_alloc.construct(_ptr + _size, value);
				_size += 1;
			}

			void pop_back()
			{
				if (empty())
					return ;
				_alloc.destroy(_ptr + _size - 1);
				_size--;
			}

			void resize( size_type count, T value = T() )
			{
				if (count == _size)
					return;
				if (count > max_size())
					throw (std::length_error("vector::resize)"));
				if (_size > count)
				{
					for (size_type i = count; i < _size; i++)
						_alloc.destroy(_ptr + i);
				}
				else
				{
					size_t new_cap = 0;
					if (_capacity == 0)
						new_cap = 1;
					else 
						new_cap = _size * 2;
					if (new_cap < count)
						new_cap = count;
					reserve(new_cap);
					for (size_type i = _size; i < count; i ++)
						push_back(value);
				}
				_size = count;
			}

			void swap( vector& other )
			{
				std::swap(_ptr, other._ptr);
				std::swap(_size, other._size);
				std::swap(_capacity, other._capacity);
				std::swap(_alloc, other._alloc);
			}
	};
	template <class T, class Alloc>
  	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{ x.swap(y);}

	// NON-MEMBER FUNCTIONS
	template< class T, class Alloc >
	bool operator==( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template< class T, class Alloc >
	bool operator!=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return (!(lhs==rhs));
	}

	template< class T, class Alloc >
	bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class T, class Alloc >
	bool operator<=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return (!(rhs < lhs));
	}

	template< class T, class Alloc >
	bool operator>( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return (rhs < lhs);
	}

	template< class T, class Alloc >
	bool operator>=( const ft::vector<T,Alloc>& lhs,const ft::vector<T,Alloc>& rhs )
	{
		return (!(lhs < rhs));
	}
}

#endif