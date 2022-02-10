#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "utils.hpp"
#include "iterator/reverse_iterator.hpp"
#include "iterator/random_access_iterator.hpp"
#include "is_integral.hpp"
#include "compare.hpp"

namespace ft

{

template<class T, class Alloc = std::allocator<T> >

class vector 
{

	public:


	//first param of the template

	typedef T value_type;


	//second param of the template

	typedef Alloc allocator_type;


	//reference of value_type

	typedef typename allocator_type::reference reference;


	//const reference of value_type

	typedef typename allocator_type::const_reference const_reference;


	//pointer of value_type

	typedef typename allocator_type::pointer pointer;


	//const pointer of value_type

	typedef typename allocator_type::const_pointer const_pointer;


	//type that can be used to obtain distance between two iterators

	typedef typename allocator_type::difference_type difference_type;


	//type that represent non negative value of difference_type

	typedef typename allocator_type::size_type size_type;

	//random_access_iterator

	typedef  ft::random_access_iterator<T> iterator;

	//const random_access_iterator

	typedef  ft::const_random_access_iterator<T> const_iterator;

	typedef  ft::reverse_iterator<iterator> reverse_iterator;

	typedef  ft::reverse_iterator<const_iterator> const_reverse_iterator;


 //Constructor:

	//Default constructors

	explicit vector (const allocator_type& alloc = allocator_type()) :
	 _alloc(alloc), _begin(NULL), _end(NULL), _capacity(0)
	{}


	//Fill constructors

	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
	_alloc(alloc), _begin(NULL), _end(NULL), _capacity(0)
	{
		_begin = _alloc.allocate(n);
		_end = _begin;
		_capacity =  n;

		while (n)
		{
			_alloc.construct(_end, val);
			_end++;
			n--;
		}
	}

	template <class InputIterator>
    vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!is_integral<InputIterator>::value>::type* = NULL)
	{
		size_type i = 0;
		InputIterator tmp = first;
		while (tmp != last)
		{
			i++;
			tmp++;
		}
		_alloc = alloc;
		tmp = first;
		_begin = _alloc.allocate(i);
		_end = _begin;
		_capacity = i;
		while (tmp != last)
		{
			_alloc.construct(_end, *tmp);
			_end++;
			tmp++;
		}
	}

	vector (const vector &x) : _alloc(x._alloc) 
	{
		this->_begin = NULL;
		this->_capacity = x.size();
		if (_capacity)
			_begin = _alloc.allocate(_capacity);
		_end = _begin;
		size_type i = 0; 
		for(const_iterator it = x.begin(); it != x.end(); it++)
		{
				_alloc.construct(_begin + i++, *it);
				_end++;
		}
	}

	vector& operator= (const vector& x)
	{
		if (this == &x)
			return (*this);
		
		this->clear();
		_alloc.deallocate(_begin, this->capacity());
		this->_alloc = x._alloc;
		this->_begin = NULL;
		if (this->_capacity < x._capacity)
			this->_capacity = x._capacity;
		if (_capacity)
			_begin = _alloc.allocate(_capacity);
		_end = _begin;
		size_type i = 0;
		for(const_iterator it = x.begin(); it != x.end(); it++)
		{
				_alloc.construct(_begin + i++, *it);
				_end++;
		}
		return (*this);
	}

	virtual ~vector(void)
	{
		this->clear();
		_alloc.deallocate(_begin, this->capacity());

	}

	iterator begin(void)
	{
		return (iterator(_begin));
	}

	const_iterator begin(void) const
	{
		return (const_iterator(_begin));
	}

	reverse_iterator rbegin()
	{
		return (reverse_iterator(end()));
	}

	const_reverse_iterator rbegin() const
	{
		return (const_reverse_iterator(end()));
	}

	iterator end(void)
	{
		if (this->empty())
			return (iterator(_begin));
		return (iterator(_end));
	}

	const_iterator end(void) const
	{
		if (this->empty())
			return (const_iterator(_begin));
		return (const_iterator(_end));
	}

	reverse_iterator rend()
	{
		return (reverse_iterator(begin()));
	}

	const_reverse_iterator rend() const
	{
		return (const_reverse_iterator(begin()));
	}

	size_type size(void) const
	{
		return (_end - _begin);
	}

	size_type max_size() const
	{
		return (_alloc.max_size());
	}

	size_type capacity(void) const
	{
		return (_capacity);
	}

	void reserve(size_type n)
	{
		if (this->max_size() < n)
			throw (std::length_error("vector::reserve"));
		if (this->capacity() < n)
		{
			pointer old_begin = _begin;
			pointer tmp = _begin;
			size_type size = this->size();
			if (_begin == NULL)
				size = 0;
			size_type i = 0;
			size_type capacity = this->capacity();
			_begin = _alloc.allocate(n);
			_end = _begin;
			_capacity = n;
			while (i < size)
			{
				_alloc.construct(_end, *old_begin);
				_alloc.destroy(old_begin);
				_end++;
				old_begin++;
				i++;
			}
			if (capacity != 0)
				_alloc.deallocate(tmp, capacity);
		}
	}

	void resize(size_type n, value_type val = value_type())
	{
		if (this->max_size() < n)
			throw (std::length_error("vector::_M_fill_insert"));
		if (this->size() > n)
		{
			while (this->size() > n)
			{
				_end--;
				_alloc.destroy(_end);
			}
			
		}
		else
		{
			if (n > _capacity && n < (_capacity * 2))
			{
				this->reserve(_capacity * 2);
			}
			else if (n > _capacity && n >= (_capacity * 2))
			{
				this->reserve(n);
			}
			size_type size = this->size();
			for (size_type i = 0; i < n - size; i++)
			{
				_alloc.construct(_begin + size + i, val);
				_end++;
			}
		}
	}

	bool empty(void) const
	{
		if (this->size() == 0)
			return true;
		return false;
	}

	reference operator[](size_type n)
	{
		return (*(_begin + n));
	}

	const_reference operator[](size_type n) const
	{
		return (*(_begin + n));
	}

	reference front(void)
	{
		return (*_begin);
	}

	const_reference front(void) const
	{
		return (*_begin);
	}

	reference back(void)
	{
		return (*(_end - 1));
	}

	const_reference back(void) const
	{
		return (*(_end - 1));
	}

	reference at(size_type n)
	{
		if (this->size() <= n || n < 0)
		{
			std::stringstream error;
			error << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->size() << ")";
			throw (std::out_of_range(error.str()));
		}
		return (*(_begin + n));
	}

	const_reference at(size_type n) const
	{
		if (this->size() <= n || n < 0)
		{
			std::stringstream error;
			error << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->size() << ")";
			throw (std::out_of_range(error.str()));
		}
		return (*(_begin + n));
	}

	void push_back(const value_type & val)
	{
		if (this->size() >= _capacity)
		{
			if (_capacity == 0)
				this->reserve(1);
			else
				this->reserve(_capacity * 2);
		}
		_alloc.construct(_end, val);
		_end++;
	}

	void pop_back(void)
	{
		_end--;
		_alloc.destroy(_end);
	}

	void assign (size_type n, const value_type& val)
	{
		this->clear();
		this->reserve(n);
		size_type i = 0;
		_end = _begin;
		while (i != n)
		{
			_alloc.construct(_begin + i, val);
			i++;
			_end++;
		}
	}

	template <class InputIterator>
  	void assign (InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value>::type* = NULL)
	{
		this->clear();
		size_type i = 0;
		InputIterator tmp = first;
		_end = _begin;
		while (tmp != last)
		{
			i++;
			tmp++;
		}
		this->reserve(i);
		i = 0;
		while (first != last)
		{
			_alloc.construct(_begin + i, *first);
			i++;
			first++;
			_end++;
		}
	}

	iterator erase (iterator position)
	{
		if (this->empty() || position == this->end())
			return _end;
		size_type tmp = position._it - _begin;
		_alloc.destroy(position._it);
		for (size_type i = tmp; i < this->size() - 1; i++)
		{
			_alloc.construct(_begin + i, _begin[i + 1]);
			_alloc.destroy(_begin + i + 1);
		}
		_end -= 1;
		return (iterator(_begin + tmp));
	}

	iterator erase (iterator first, iterator last)
	{
		if (this->empty() || first == this->end())
			return _end;
		size_type i = 0;
		iterator tmp = first;
		while (tmp != last)
		{
			tmp++;
			i++;
		}
		if (i > this->size())
			return _end;
		if (i == 0)
			return last;
		size_type n = 0;
		size_type index = first._it - _begin;
		size_type after_erase = last._it - _begin;
		size_type nb_cp = this->size() - i;
		_end -= last._it - first._it;
		while (n != i)
		{
			_alloc.destroy(first._it + n);
			n++;
		}
		for (size_type j = index; j < nb_cp; j++)
		{
			_alloc.construct(_begin + j, _begin[after_erase]);
			_alloc.destroy(_begin + after_erase);
			after_erase++;
		}
		return (iterator(_begin + index));
	}

	iterator insert (iterator position, const value_type& val)
	{
		size_type index = position._it - _begin;
		this->insert(position, 1, val);
		return (iterator(_begin + index));
	}

	void insert (iterator position, size_type n, const value_type& val)
	{
		if (n == 0)
			return ;
		size_type index = position._it - _begin;
		if (_capacity == 0)
				this->reserve(1);
		if (this->size() + n > _capacity)
		{
			if (this->size() * 2 > _capacity + n)
				this->reserve(this->size() * 2);
			else
				this->reserve(_capacity + n);
		}
		if (!(this->empty()))
		{
			for (size_type i = this->size(); i > index; i--)
			{
				_alloc.construct(_begin + i + n - 1, _begin[i - 1]);
				_alloc.destroy(_begin + i - 1);
			}
		}
		for (size_type i = index; i < n + index; i++)
		{
			_alloc.construct(_begin + i, val);
		}
		_end += n;
	}

	template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!is_integral<InputIterator>::value>::type* = NULL)
	{
		/*size_type n = 0;
		size_type index = position._it - _begin;
		InputIterator tmp = first;
		while (tmp != last)
		{
			tmp++;
			n++;
		}
		while (this->size() + n >= _capacity)
		{
			if (_capacity == 0)
				this->reserve(1);
			this->reserve(_capacity * 2);
		}
		n = 0;
		position = iterator(_begin + index);
		for (tmp = first; tmp != last; tmp++)
		{
			this->insert(position + n, 1, *tmp);
			n++;
		}*/

		size_type n = 0;
		size_type index = position._it - _begin;
		InputIterator tmp = first;
		while (tmp != last)
		{
			tmp++;
			n++;
		}
		if (_capacity == 0)
				this->reserve(1);
		if (this->size() + n > _capacity)
		{
			if (this->size() * 2 > _capacity + n)
				this->reserve(this->size() * 2);
			else
				this->reserve(_capacity + n);
		}
		if (!(this->empty()))
		{
			for (size_type i = this->size(); i > index; i--)
			{
				_alloc.construct(_begin + i + n - 1, _begin[i - 1]);
				_alloc.destroy(_begin + i - 1);
			}
		}
		tmp = first;
		for (size_type i = index; i < n + index; i++)
		{
			_alloc.construct(_begin + i, *tmp);
			tmp++;
		}
		_end += n;
	}

	void swap(vector & x)
	{
		pointer tmp_begin = _begin;
		pointer tmp_end = _end;
		size_type tmp_capacity = _capacity;
		allocator_type tmp_alloc = _alloc;

		this->_begin = x._begin;
		this->_end = x._end;
		this->_capacity = x._capacity;
		this->_alloc = x._alloc;

		x._begin = tmp_begin;
		x._end = tmp_end;
		x._capacity = tmp_capacity;
		x._alloc = tmp_alloc;
	}

	void clear(void)
	{
		size_type i = 0;
		for (size_type size = this->size(); i < size; i++)
		{

			_end--;
			_alloc.destroy(_end);
		}
	}

	allocator_type get_allocator(void) const
	{
		return (_alloc);
	}



	private:

	allocator_type	_alloc;
	pointer			_begin;
	pointer			_end;
	size_type		_capacity;

};

	template <class T, class Alloc>
  	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
  	{
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
  	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}

}
#endif