#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"


namespace ft
{
	template <typename T>
	class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
	{
		public:

		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;

		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type			value_type;

		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;

		typedef T*																			pointer;

		typedef T&																			reference;


		random_access_iterator(void): _it(NULL)
		{}

		random_access_iterator(pointer ptr): _it(ptr)
		{}

		random_access_iterator(const random_access_iterator& other): _it(other._it)
		{}

		virtual ~random_access_iterator()
		{}

		random_access_iterator &operator=(const random_access_iterator& other)
		{
			if (this == &other)
				return (*this);
			this->_it = other._it;
			return (*this);
		}

		bool operator==(const random_access_iterator& other)
		{
			return (this->_it == other._it);
		}

		bool operator!=(const random_access_iterator& other)
		{
			return (this->_it != other._it);
		}

		reference operator*(void)
		{
			return (*_it);
		}

		pointer operator->(void)
		{
			return (_it);
		}

		random_access_iterator &operator++(void)
		{
			_it++;
			return (*this);
		}

		random_access_iterator operator++(int)
		{
			random_access_iterator tmp(_it);
			_it++;
			return (tmp);
		}


		random_access_iterator &operator--(void)
		{
			_it--;
			return (*this);
		}

		random_access_iterator operator--(int)
		{
			random_access_iterator tmp(_it);
			_it--;
			return (tmp);
		}


		random_access_iterator operator+(difference_type n) const
		{
			return random_access_iterator(this->_it + n);
		}

		random_access_iterator operator-(difference_type n) const
		{
			return random_access_iterator(this->_it - n);
		}


		random_access_iterator &operator+=(difference_type n)
		{
			_it = _it + n;
			return (*this);
		}

		random_access_iterator &operator-=(difference_type n)
		{
			_it = _it - n;
			return (*this);
		}

		reference &operator[](difference_type n) const
		{
			return (*(_it + n));
		}

		pointer _it;

	};

}

#endif
