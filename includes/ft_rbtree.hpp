#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <iostream>

namespace ft
{
	enum Treecolor{red, black};
	template <class T>
	struct Node
	{
		typedef T	value_type;
		T			data;
		Node		*parent;
		Node		*left;
		Node		*right;
		Treecolor	color;
		Node (value_type data, Node *parent, Node *left, Node *right, Treecolor color)
		: data(data), parent(parent), left(left), right(right), color(color) {}
	};

	template <class Key, class T, class KeyOfValue, class Compare, class Alloc>
	class rbtree
	{
		public:
			typedef	T					value_type;
			typedef	Key					key_type;
			typedef	Compare				key_compare;
			typedef Alloc				allocator_type;
			typedef	Node<value_type>	node_type;
			typedef Node<value_type>*	node_ptr;
			typedef std::size_t 		size_type;
			typedef typename allocator_type::template rebind<Node<T> >::other pair_alloc_type;

		protected :
			node_ptr		_root;
			node_ptr		_end;
			key_compare		_comp;
			pair_alloc_type	_alloc;
			size_type		_size;
		
		public : 
		// CONSTRUCTOR
		rbtree(const key_compare &comp = key_compare(), const pair_alloc_type &alloc = pair_alloc_type())
		: _comp(comp), _alloc(alloc), _size(0)
		{
			_end = _alloc.allocate(1);
			_alloc.construct(_end, node_type(value_type(), NULL, NULL, NULL, black));
			_root = _end;
		}

		// DESTRUCTOR
		virtual ~rbtree()
		{
			clear_tree(_root);
			_alloc.destroy(_end);
			_alloc.deallocate(_end, 1);
		}

		// GETTER
		node_ptr	get_root() const
		{ return (_root);}

		node_ptr	get_end() const
		{ return (_end);}

		key_compare	get_comp() const
		{return (_comp);}

		pair_alloc_type	get_alloc() const
		{return (_alloc);}

		size_type	get_size() const
		{return (_size);}

		size_type	max_size() const
		{ return _alloc.max_size();}

		// CLEAR
		void	clear_tree(node_ptr node)
		{
			clear_all(node);
			_root = _end;
		}

		void	clear_all(node_ptr node)
		{
			if (node == _end)
				return ;
			clear_tree(node->left);
			clear_tree(node->right);
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
			_size--;
		}
		
		// SWAP
		void	swap(rbtree &other)
		{
			std::swap(_root, other._root);
			std::swap(_end, other._end);
			std::swap(_size, other._size);
		}

		// ROTATION
		void	left_rotate(node_ptr x)
		{
			node_ptr	y = x->right;
			x->right = y->left;
			if (y->left != _end)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				_root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else 
				x->parent->right = y;
			x->parent = y;
			y->left = x;
		}

		void	right_rotate(node_ptr x)
		{
			node_ptr	y = x->left;
			x->left = y->right;
			if (y->right != _end)
				y->right->parent = x;
			y->parent = x ->parent;
			if (x->parent == NULL)
				_root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			x->parent = y;
			y->right = x;
		}

		// SEARCH
		node_ptr	search_tree(node_ptr node, key_type key) const
		{
			if (node == _end || key == KeyOfValue()(node->data) )
				return (node);
			if (node != _end)
			{
				if (_comp(key, KeyOfValue()(node->data)))
					return (search_tree(node->left, key));
				return (search_tree(node->right, key));
			}
			return (_end);
		}

		node_ptr	min_node(node_ptr node) const
		{
			if (node == _end)
				return (_root);
			while (node->left != _end)
				node = node->left;
			return (node);
		}

		// INSERT
		void insertFix(node_ptr k) 
		{
			node_ptr u;
			while (k->parent->color == red) 
			{
				if (k->parent == k->parent->parent->right) 
				{
					u = k->parent->parent->left;
					if (u->color == red) 
					{
						u->color = black;
						k->parent->color = black;
						k->parent->parent->color = red;
						k = k->parent->parent;
					} 
					else 
					{
						if (k == k->parent->left) 
						{
							k = k->parent;
							right_rotate(k);
						}
						k->parent->color = black;
						k->parent->parent->color = red;
						left_rotate(k->parent->parent);
					}
				}
				else 
				{
					u = k->parent->parent->right;
					if (u->color == red) 
					{
						u->color = black;
						k->parent->color = black;
						k->parent->parent->color = red;
						k = k->parent->parent;
					} 
					else 
					{
						if (k == k->parent->right) 
						{
							k = k->parent;
							left_rotate(k);
						}
						k->parent->color = black;
						k->parent->parent->color = red;
						right_rotate(k->parent->parent);
					}
				}
				if (k == _root)
					break;
				}
    		_root->color = black;
  		}

		node_ptr insert(const value_type &data) 
		{
			node_ptr node;
			node = _alloc.allocate(1);
			_alloc.construct(node, node_type(data, NULL, _end, _end, red));
			node_ptr 	y = NULL;
			node_ptr	x = _root;

			while (x != _end) 
			{
				y = x;
				if (_comp(KeyOfValue()(node->data), KeyOfValue()(x->data)))
					x = x->left;
				else if (_comp(KeyOfValue()(x->data), KeyOfValue()(node->data)))
					x = x->right;
				else 
				{
					_alloc.destroy(node);
					_alloc.deallocate(node, 1);
					return (_end);
				}
			}
			node->parent = y;
			if (y == NULL)
			{
				_size++;
				_root = node;
				node->color = black;
				return (_root);
			}
			else if (_comp(KeyOfValue()(node->data), KeyOfValue()(y->data)))
				y->left = node;
			else
				y->right = node;
			_size++;
			if (node->parent->parent == _end)
				return (node);
			insertFix(node);
			return (node);
		}

		// DELETE
		void rbTransplant(node_ptr u, node_ptr v) 
		{
			if (u->parent == NULL)
				_root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}

		void deleteFix(node_ptr x) 
		{
			node_ptr s;
			while (x != _root && x->color == black) 
			{
				if (x == x->parent->left) 
				{
					s = x->parent->right;
					if (s->color == red) 
					{
						s->color = black;
						x->parent->color = red;
						left_rotate(x->parent);
						s = x->parent->right;
					}
					if (s->left->color == black && s->right->color == black) 
					{
						s->color = red;
						x = x->parent;
					} 
					else 
					{
						if (s->right->color == black)
						{ 
							s->left->color = black;
							s->color = red;
							right_rotate(s);
							s = x->parent->right;
						}
						s->color = x->parent->color;
						x->parent->color = black;
						s->right->color = black;
						left_rotate(x->parent);
						x = _root;
					}
				} 
				else 
				{
					s = x->parent->left;
					if (s->color == red) 
					{
						s->color = black;
						x->parent->color = red;
						right_rotate(x->parent);
						s = x->parent->left;
					}
					if (s->right->color == black && s->right->color == black) 
					{
						s->color = red;
						x = x->parent;
					} 
					else 
					{
						if (s->left->color == black) 
						{
							s->right->color = black;
							s->color = red;
							left_rotate(s);
							s = x->parent->left;
						}
						s->color = x->parent->color;
						x->parent->color = black;
						s->left->color = black;
						right_rotate(x->parent);
						x = _root;
					}
				}
			}
			x->color = black;
		}

		bool deleteNode(key_type key)
		{
			node_ptr z, x, y;
			z = search_tree(_root, key);
			if (z == _end)
				return (false);
			y = z;
			Treecolor yog_color = y->color;  
			if (z->left == _end) 
			{
				x = z->right;
				rbTransplant(z, z->right);
			} 
			else if (z->right == _end) 
			{
				x = z->left;
				rbTransplant(z, z->left);
			} 
			else 
			{
				y = min_node(z->right); 
				yog_color = y->color;
				x = y->right;
				if (y->parent == z)
					x->parent = y;
				else 
				{
					rbTransplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				rbTransplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			_alloc.destroy(z);
			_alloc.deallocate(z, 1);
			_size--;
			if (yog_color == black)
				deleteFix(x);
			return true;
		}			

		// PRINT
		 void printHelper(node_ptr root, std::string indent, bool last) {
			if (root != _end) {
			std::cout << indent;
			if (last) {
				std::cout << "R----";
				indent += "   ";
			} else {
				std::cout << "L----";
				indent += "|  ";
			}

			std::string sColor = root->color ? "BLACK" : "RED";
			std::cout << root->data << "(" << sColor << ")" << std::endl;
			printHelper(root->left, indent, false);
			printHelper(root->right, indent, true);
			}
		}

		void printTree() {
			if (_root) {
			printHelper(this->_root, "", true);
			}
		}
	};
}

#endif

/* 
A rdbtree staisfies the follozing properties : 
- every node is colored, either red or black
- the root is black
- every leaf (NIL) is black
- if a red node has children, they are always black
- for each node, any simple path from this node to any f its descendant leaf has the same black_depth

Every node has the following attributes :
- color
- key
- left child
- right child
- parent (except root)

Various operation can bw pweformed on a rbtree : 
- Rotating the subtrees in a rbtree
- Inserting an element into a rbtree 
	new nodes are always red but if violation : recolor and rotation
- Deleting an element from a fbtree
*/