#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"



namespace ft
{
	template <typename T>
	class const_random_access_iterator;

	template <typename T>
	class random_access_iterator;


	template <typename T>
	class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T, T*, T&>
	{
		public:

		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;

		typedef T																			value_type;

		typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;

		typedef T*																			pointer;

		typedef T&																			reference;


		random_access_iterator(void): _it(NULL)
		{}

		random_access_iterator(pointer ptr)
		{
			_it = ptr;
		}

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

		bool operator==(const random_access_iterator& other) const
		{
			return (this->_it == other._it);
		}


		bool operator==(const const_random_access_iterator<T>& other) const
		{
			return (this->_it == other._it);
		}


		bool operator!=(const random_access_iterator& other) const
		{
			return (this->_it != other._it);
		}

		bool operator!=(const const_random_access_iterator<T> & other) const
		{
			return (this->_it != other._it);
		}

		bool operator<=(const random_access_iterator& other) const
		{
			return (this->_it <= other._it);
		}

		bool operator<=(const const_random_access_iterator<T>& other) const
		{
			return (this->_it <= other._it);
		}

		bool operator>=(const random_access_iterator& other) const
		{
			return (this->_it >= other._it);
		}

		bool operator>=(const const_random_access_iterator<T>& other) const
		{
			return (this->_it >= other._it);
		}

		bool operator<(const random_access_iterator& other) const
		{
			return (this->_it < other._it);
		}

		bool operator<(const const_random_access_iterator<T>& other) const
		{
			return (this->_it < other._it);
		}

		bool operator>(const random_access_iterator& other) const
		{
			return (this->_it > other._it);
		}

		bool operator>(const const_random_access_iterator<T>& other) const
		{
			return (this->_it > other._it);
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


		random_access_iterator operator+(difference_type n)
		{
			return random_access_iterator(this->_it + n);
		}

		random_access_iterator operator-(difference_type n)
		{
			return random_access_iterator(this->_it - n);
		}

		difference_type operator-(random_access_iterator & other)
		{
			return (this->_it - other._it);
		}

		difference_type operator-(const_random_access_iterator<T> & other) const
		{
			return (this->_it - other._it);
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

	template<typename T>
	random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n,
	random_access_iterator<T>& other)
	{
		return (random_access_iterator<T>(other._it + n));
	}

	template<typename T>
	random_access_iterator<T> operator-(typename random_access_iterator<T>::difference_type n,
	random_access_iterator<T>& other)
	{
		return (random_access_iterator<T>(other._it - n));
	}




	template <typename T>
	class const_random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T, T*, T&>
	{
		public:

		typedef typename  ft::iterator<ft::random_access_iterator_tag, T>::iterator_category		iterator_category;

		typedef  const T																			value_type;

		typedef typename  ft::iterator<ft::random_access_iterator_tag, T>::difference_type			difference_type;

		typedef const T*																			pointer;

		typedef const T&																			reference;


		const_random_access_iterator(void): _it(NULL)
		{}

		const_random_access_iterator(pointer ptr)
		{
			_it = ptr;
		}

		const_random_access_iterator(const const_random_access_iterator& other): _it(other._it)
		{}

		const_random_access_iterator(const random_access_iterator<T>& other) : _it(other._it)
		{}

		virtual ~const_random_access_iterator()
		{}

		const_random_access_iterator &operator=(const const_random_access_iterator& other)
		{
			if (this == &other)
				return (*this);
			this->_it = other._it;
			return (*this);
		}

		bool operator==(const const_random_access_iterator& other) const
		{
			return (this->_it == other._it);
		}

		bool operator!=(const const_random_access_iterator& other) const
		{
			return (this->_it != other._it);
		}

		bool operator<=(const const_random_access_iterator& other) const
		{
			return (this->_it <= other._it);
		}

		bool operator>=(const const_random_access_iterator& other) const
		{
			return (this->_it >= other._it);
		}

		bool operator<(const const_random_access_iterator& other) const
		{
			return (this->_it < other._it);
		}

		bool operator>(const const_random_access_iterator& other) const
		{
			return (this->_it > other._it);
		}

		reference operator*(void) const
		{
			return (*_it);
		}

		pointer operator->(void) const
		{
			return (_it);
		}

		const_random_access_iterator &operator++(void)
		{
			_it++;
			return (*this);
		}

		const_random_access_iterator operator++(int)
		{
			const_random_access_iterator tmp(_it);
			_it++;
			return (tmp);
		}


		const_random_access_iterator &operator--(void)
		{
			_it--;
			return (*this);
		}

		const_random_access_iterator operator--(int)
		{
			const_random_access_iterator tmp(_it);
			_it--;
			return (tmp);
		}


		const_random_access_iterator operator+(difference_type n) const
		{
			return const_random_access_iterator(this->_it + n);
		}

		const_random_access_iterator operator-(difference_type n) const
		{
			return const_random_access_iterator(this->_it - n);
		}

		difference_type operator-(const_random_access_iterator & other) const
		{
			return (this->_it - other._it);
		}

		difference_type operator-(const const_random_access_iterator & other) const
		{
			return (this->_it - other._it);
		}


		const_random_access_iterator &operator+=(difference_type n)
		{
			_it = _it + n;
			return (*this);
		}

		const_random_access_iterator &operator-=(difference_type n)
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

	template<typename T>
	const_random_access_iterator<T> operator-(typename const_random_access_iterator<T>::difference_type n,
	const_random_access_iterator<T> & other)
	{
		return (random_access_iterator<T>(other._it - n));
	}

}

#endif
