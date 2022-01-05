#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include "pair.hpp"
#include "utils.hpp"
#include "iterator/bidirectional.hpp"
#include "iterator/reverse_iterator.hpp"

namespace ft
{
	template <class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		typedef Key 											key_type;
		typedef T												mapped_type;
		typedef ft::pair<const key_type, mapped_type>			value_type;
		typedef Compare											key_compare;
		typedef Alloc											allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef ft::bidirectional<value_type>					iterator;
		typedef ft::bidirectional<const value_type>				const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef std::ptrdiff_t									difference_type;
		typedef std::size_t										size_type;




		class value_compare
		{
			public:
			explicit value_compare(Compare c) : comp(c) {}

			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;

			bool operator()( const value_type& x, const value_type& y ) const
			{
				return comp(x.first, y.first);
			}

			protected:
			Compare comp;
		};

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _compare(comp)
		{
			_size = 0;
			_root = _create_node(ft::make_pair(key_type(), mapped_type()));
			_end = _root;
		}

		template <class InputIterator>
  		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _compare(comp)
		{
			_size = 0;
			_root = _create_node(ft::make_pair(key_type(), mapped_type()));
			_end = _root;
			for (InputIterator tmp = first; tmp != last; tmp++)
				this->insert(*tmp);
			
		}

		map (const map& other)
		{
			_size = 0;
			_root = _create_node(ft::make_pair(key_type(), mapped_type()));
			_end = _root;
			_alloc = other._alloc;
			_alloc_node = other._alloc_node;
			_compare = other._compare;
			for (iterator tmp = other.begin(); tmp != other.end(); tmp++)
				this->insert(*tmp);
			
		}

		~map()
		{

		}

		map& operator= (const map& other)
		{
			if (*this != other)
			{
				this->clear();
				_alloc = other._alloc;
				_alloc_node = other._alloc_node;
				_compare = other._compare;
				for (iterator tmp = other.begin(); tmp != other.end(); tmp++)
					this->insert(*tmp);
			}
			return (*this);
		}

		iterator begin()
		{
			return (iterator(ft::min_value<value_type>(_root)));
		}

		const_iterator begin() const
		{
			return (const_iterator(ft::min_value<value_type>(_root)));
		}

		iterator end()
		{
			return (iterator(_end));
		}

		const_iterator end() const
		{
			return (const_iterator(_end));
		}

		reverse_iterator rbegin()
		{
			return (end());
		}

		const_reverse_iterator rbegin() const
		{
			return (end());
		}

		reverse_iterator rend()
		{
			return (begin());
		}

		const_reverse_iterator rend() const
		{
			return (begin());
		}

		bool empty() const
		{
			if (_size == 0)
				return (true);
			return (false);
		}

		size_type size() const
		{
			return (this->_size);
		}

		size_type max_size() const
		{
			return (_alloc_node.max_size());
		}

		allocator_type get_allocator() const
		{
			return (_alloc);
		}

		mapped_type& operator[] (const key_type& k)
		{
			iterator tmp = this->find(k);
			if (tmp == _end)
				return this->insert(ft::make_pair(k, T())).first->second;
			else
				return tmp->second;
		}

		pair<iterator,bool> insert (const value_type& val)
		{
			size_type old_size = _size;
			bst<value_type>* ret;
			ret = _insert(val, _root);
			if (_root == _end  && _size != old_size)
			{
				_root = ret;
				_root->right = _end;
				_end->parent = _root;
			}
			return (ft::make_pair(iterator(ret), _size != old_size));
		}

		iterator insert (iterator position, const value_type& val)
		{
			size_type old_size = _size;
			bst<value_type>* ret;
			static_cast<void>(position);
			ret = _insert(val, _root);
			if (_root == _end && _size != old_size)
			{
				_root = ret;
				_root->right = _end;
				_end->parent = _root;
			}
			return (iterator(ret));
		}

		template <class InputIterator>
 		void insert (InputIterator first, InputIterator last)
		{
			for (InputIterator tmp = first; tmp != last; tmp++)
			{
				this->insert(*tmp);
			}
			
		}

		void erase (iterator position)
		{
			erase(position._node->value.first);
		}

		size_type erase (const key_type& key)
		{
			size_type tmp_size = _size;
			this->_delete_node(key, _root);
			return (tmp_size != _size);
		}

		void erase (iterator first, iterator last)
		{
			for (iterator tmp = first; tmp != last; tmp++)
				erase(tmp._node->value.first);
		}

		void swap (map& other)
		{
			Alloc tmp_alloc = _alloc;
			typename Alloc::template rebind<bst<value_type> >::other tmp_alloc_node = _alloc_node;
			Compare tmp_compare = _compare;
			bst<value_type>* tmp_root = _root;
			bst<value_type>* tmp_end = _end;
			size_type tmp_size = _size;

			_alloc = other._alloc;
			_alloc_node = other._alloc_node;
			_compare = other._compare;
			_root = other._root;
			_end = other._end;
			_size = other._size;

			other._alloc = tmp_alloc;
			other._alloc_node = tmp_alloc_node;
			other._compare = tmp_compare;
			other._root = tmp_root;
			other._end = tmp_end;
			other._size = tmp_size;

		}

		void clear()
		{
			if (!empty())
			{
				this->_clear_bst(_root);
				_root = _end;
				_end->parent = NULL;
				_size = 0;
			}
		}

		key_compare key_comp() const
		{
			return (_compare);
		}

		value_compare value_comp() const
		{
			return (value_compare(_compare));
		}

		iterator find (const key_type& key)
		{
			bst<value_type>* ret = _search_node(key, _root);
			if (ret == NULL || ret == _root)
				return (end());
			else
				return (iterator(ret));
		}

		const_iterator find (const key_type& key) const
		{
			bst<value_type>* ret = _search_node(key, _root);
			if (ret == NULL || ret == _root)
				return (end());
			else
				return (const_iterator(ret));
		}

		size_type count (const key_type& key) const
		{
			return (find(key) != end());
		}

		iterator lower_bound (const key_type& key)
		{
			iterator ret = begin();
			while(ret != end())
			{
				if (ret->_node.value.first == key || !_compare(ret->_node.value.first, key))
					return (ret);
				ret++;
			}
		}

		const_iterator lower_bound (const key_type& key) const
		{
			const_iterator ret = begin();
			while(ret != end())
			{
				if (ret->_node.value.first == key || !_compare(ret->_node.value.first, key))
					return (ret);
				ret++;
			}
		}

		iterator upper_bound (const key_type& key)
		{
			iterator ret = begin();
			while(ret != end())
			{
				if (ret->_node.value.first != key && !_compare(ret->_node.value.first, key))
					return (ret);
				ret++;
			}
		}

		const_iterator upper_bound (const key_type& key) const
		{
			const_iterator ret = begin();
			while(ret != end())
			{
				if (ret->_node.value.first != key && !_compare(ret->_node.value.first, key))
					return (ret);
				ret++;
			}
		}

		pair<const_iterator,const_iterator> equal_range (const key_type& key) const
		{
			return (ft::make_pair(lower_bound(key), upper_bound(key)));
		}

		pair<iterator,iterator>	equal_range (const key_type& key)
		{
			return (ft::make_pair(lower_bound(key), upper_bound(key)));
		}

		private:

		Alloc														_alloc;
		typename Alloc::template rebind<bst<value_type> >::other 	_alloc_node;
		Compare														_compare;
		bst<value_type>*											_root;
		bst<value_type>*											_end;
		size_type 													_size;

		bst<value_type>*	_create_node(const value_type& value)
		{
			bst<value_type>* ret = _alloc_node.allocate(1);
			_alloc.construct(&ret->value, value);
			ret->left = NULL;
			ret->right = NULL;
			ret->parent = NULL;
			return (ret);
		}

		void	_clear_bst(bst<value_type>* node)
		{
			if (node->left)
				_clear_bst(node->left);
			if (node->right && node->right != _end)
				_clear_bst(node->right);
			_alloc.destroy(&node->value);
			_alloc_node.deallocate(node, 1);
		}

		bst<value_type>*	_search_node(const key_type& key, bst<value_type>* node)
		{
			if (!node || node == _end || key == node->value.first)
				return (node);
			if (_compare(key, node->value.first))
				return (_search_node(key, node->right));
			else
				return (_search_node(key, node->left));
		}

		
		void	_free_node(bst<value_type>*	node)
		{
			_alloc.destroy(&node->value);
			_alloc_node.deallocate(node, 1);
		}

		void	_delete_node(const key_type& key, bst<value_type>* node)
		{
			if (node == NULL || node == _end)
				return ;
			if (key < node->value.first)
			{
				_delete_node(key, node->left);
				return ;
			}

			if (key > node->value.first)
			{
				_delete_node(key, node->right);
				return ;
			}

			_size--;
			if (!node->right && !node->left)
			{
				if (node == _root)
					_root = _end;
				_free_node(node);
			}
			else if (!node->right || !node->left)
			{
				bst<value_type>* tmp;
				if (!node->right)
					tmp = node->left;
				else
					tmp = node->right;
				tmp->parent = node->parent;
				if (node == _root)
					_root = tmp;
				_free_node(node);
			}
			else
			{
				bst<value_type>* successor_parent = node;
				bst<value_type>* successor = node->right;
				//find successor
				while (successor->left != NULL)
				{
					successor_parent = successor;
					successor = successor->left;
				}

				//reattach right successor branch to parent
				if (successor_parent != node)
					successor_parent->left = successor->right;
				else
					successor_parent->right = successor->right;

				if (successor->right)
					successor->right->parent = successor_parent;

				//give succesor the left right parent of successor parent
				successor->right = node->right;
				if (successor->right)
					successor->right->parent = successor;

				successor->left = node->left;
				if (successor->left)
					successor->left->parent = successor;

				successor->parent = node->parent;

				if (node == _root)
					_root = successor;
				_free_node(node);
			}
		}

		bst<value_type>* _insert(const value_type& val, bst<value_type>* node)
		{
			bst<value_type>* tmp;
			while (node != NULL && node != _end)
			{
				if (val.first == node->value.first)
					return (node);
				else if (val.first < node->value.first)
				{
					tmp = node;
					node = node->left;
				}
				else
				{
					tmp = node;
					node = node->right;
				}
			}
			_size++;
			bst<value_type>* ret = _create_node(val);
			if (ret == _end)
			{
				_end->parent = ret;
				ret->right = _end;
			}
			ret->parent = tmp;
			if (tmp->value.first < ret->value.first)
				tmp->right = ret;
			else
				tmp->left = ret;
			return (ret);
		}



		
	};
}

#endif