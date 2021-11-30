#ifndef BIDIRECTIONAL_HPP
#define BIDIRECTIONAL_HPP

#include "iterator.hpp"
#include "../utils.hpp"

namespace ft
{
	template <typename T>
	class bidirectional : ft::iterator<bidirectional_iterator_tag, T>
	{
		public:

		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category		iterator_category;

		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type			value_type;

		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type		difference_type;

		typedef T*																				pointer;

		typedef T&																				reference;

		bidirectional()
		{}

		bidirectional(bst<T>* node) : _node(node)
		{}

		bidirectional(const bidirectional& src)
		{
			*this = src;
		}

		virtual ~bidirectional()
		{}

		bidirectional& operator=(const bidirectional& rhs)
		{
			if (this != &rhs)
				this->_node = rhs._node;
			return *this;
		}

		reference operator*() const
		{
			return this->_node->value;
		}

		pointer operator->() const
		{
			return &(this->_node->value);
		}

		bool operator==(const bidirectional& other)
		{
			return (*this == other);
		}

		bool operator!=(const bidirectional& other)
		{
			return (*this != other);
		}

		bidirectional& operator++()
		{
			this->_node = succesor_node(this->_node);
			return *this;
		}
		bidirectional operator++(int)
		{
			bidirectional tmp = *this;
			*this = this->operator++();
			return tmp;
		}
		bidirectional& operator--()
		{
			this->_node = predecessor_node(this->_node);
			return *this;
		}
		bidirectional operator--(int)
		{
			bidirectional tmp = *this;
			*this = this->operator--();
			return tmp;
		}

		private:

		bst<T>* _node;

	};
}

#endif