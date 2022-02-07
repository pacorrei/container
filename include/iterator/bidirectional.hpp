#ifndef BIDIRECTIONAL_HPP
#define BIDIRECTIONAL_HPP

#include "iterator.hpp"
#include "../utils.hpp"

namespace ft
{

	template <typename T>
	class bidirectional;

	template <typename T>
	class Constbidirectional;



	template <typename T>
	class bidirectional : public ft::iterator<bidirectional_iterator_tag, T, std::ptrdiff_t, T*, T&>
	{
		public:

		typedef ft::bidirectional_iterator_tag 	iterator_category;

		typedef T 								value_type;

		typedef std::ptrdiff_t 					difference_type;

		typedef T*								pointer;

		typedef T&								reference;

		bidirectional() : _node(NULL)
		{}

		bidirectional(bst<value_type>* node) : _node(node)
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

		friend bool operator==(const bidirectional& lhs, const bidirectional& rhs)
		{
			return (lhs._node == rhs._node);
		}

		friend bool operator!=(const bidirectional& lhs, const bidirectional& rhs)
		{
			return (lhs._node != rhs._node);
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

		bst<T>* _node;

	};


	template <typename T>
	class Constbidirectional : public ft::iterator<bidirectional_iterator_tag, T, std::ptrdiff_t, T*, T&>
	{
		public:

		typedef ft::bidirectional_iterator_tag 			iterator_category;

		typedef const T 								value_type;

		typedef std::ptrdiff_t 							difference_type;

		typedef const T*								pointer;

		typedef const T&								reference;

		Constbidirectional() : _node(NULL)
		{}

		Constbidirectional(bst<value_type>* node) : _node(node)
		{}

		Constbidirectional(Constbidirectional const & src)
		{
			*this = src;
		}

		Constbidirectional(const bidirectional<T> & src) : _node(src._node) {}

		virtual ~Constbidirectional() {}

		Constbidirectional& operator=(Constbidirectional const & rhs)
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

		friend bool operator==(const Constbidirectional& lhs, const Constbidirectional& rhs)
		{
			return (lhs._node == rhs._node);
		}

		friend bool operator!=(const Constbidirectional& lhs, const Constbidirectional& rhs)
		{
			return (lhs._node != rhs._node);
		}

		Constbidirectional& operator++()
		{
			this->_node = succesor_node(this->_node);
			return *this;
		}
		Constbidirectional operator++(int)
		{
			Constbidirectional tmp = *this;
			*this = this->operator++();
			return tmp;
		}
		Constbidirectional& operator--()
		{
			this->_node = predecessor_node(this->_node);
			return *this;
		}
		Constbidirectional operator--(int)
		{
			Constbidirectional tmp = *this;
			*this = this->operator--();
			return tmp;
		}

		bst<T>* _node;

	};
}

#endif