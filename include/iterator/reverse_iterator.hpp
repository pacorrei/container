#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "random_access_iterator.hpp"

namespace ft

{

	template <class Iterator>

	class reverse_iterator
	{
		public:

		typedef  Iterator													iterator_type;

		typedef typename  iterator_traits<Iterator>::iterator_category	iterator_category;

		typedef typename iterator_traits<Iterator>::value_type			value_type;

		typedef typename iterator_traits<Iterator>::difference_type		difference_type;

		typedef typename iterator_traits<Iterator>::pointer				pointer;

		typedef typename iterator_traits<Iterator>::reference			reference;

		reverse_iterator(void) : _it()
		{}

		explicit reverse_iterator(iterator_type it): _it(it)
		{}
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter>& other): _it(other.base())
		{}

		virtual ~reverse_iterator()
		{}

		template <class Iter>
		reverse_iterator& operator=(const reverse_iterator<Iter>& other)
		{
			_it = other.base();
			return (*this);
		}

		iterator_type base() const
		{
			return (_it);
		}

		reference operator*() const
		{
			Iterator tmp = _it;
			return *--tmp;
		}

		reverse_iterator operator+(difference_type n) const
		{
			return reverse_iterator(base() - n);
		}

		reverse_iterator& operator++()
		{
			_it--;
			return (*this);
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator tmp(*this);
			_it--;
			return (tmp);
		}

		reverse_iterator& operator+=(difference_type n)
		{
			_it = _it - n;
			return (*this);
		}

		reverse_iterator operator-(difference_type n) const
		{
			return reverse_iterator(base() + n);
		}

		reverse_iterator& operator--()
		{
			_it++;
			return (*this);
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator tmp(*this);
			_it++;
			return (tmp);
		}

		reverse_iterator& operator-=(difference_type n)
		{
			_it = _it + n;
			return (*this);
		}

		pointer operator->() const
		{
			return &(this->operator*());
		}

		reference operator[] (difference_type n) const
		{
			return base()[- n -1];
		}

  		friend reverse_iterator operator+(difference_type n, const reverse_iterator& rhs)
		{
			return rhs.operator+(n);
		}

		template <class Iter>
  		difference_type operator-(const reverse_iterator<Iter>& lhs)
		{
			return (lhs.base().operator-(this->_it));
		}


		Iterator _it;
	};

	template <class Iterator, class Iterator2>
	bool operator== (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		if (lhs.base() == rhs.base())
			return (true);
		return (false);
	}

	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		if (lhs.base() == rhs.base())
			return (true);
		return (false);
	}

	template <class Iterator, class Iterator2>
	bool operator!= (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		if (lhs.base() != rhs.base())
			return (true);
		return (false);
	}

	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		if (lhs.base() != rhs.base())
			return (true);
		return (false);
	}
	
	template <class Iterator, class Iterator2>
	bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		if (lhs.base() > rhs.base())
			return (true);
		return (false);
	}

	template <class Iterator, class Iterator2>
	bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		if (lhs.base() < rhs.base())
			return (true);
		return (false);
	}

	template <class Iterator, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		if (lhs.base() >= rhs.base())
			return (true);
		return (false);
	}

	template <class Iterator, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		if (lhs.base() <= rhs.base())
			return (true);
		return (false);
	}

}

#endif