#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:

		typedef typename Container::value_type	value_type;

		typedef Container						container_type;

		typedef typename Container::size_type	size_type;



		explicit stack (const container_type& ctnr = container_type()): _c(ctnr)
		{}
		virtual ~stack() {}

		bool empty() const
		{
			return (_c.empty());
		}

		size_type size() const
		{
			return (_c.size());
		}

		value_type& top()
		{
			return (_c.back());
		}

		const value_type& top() const
		{
			return (_c.back());
		}

		void push (const value_type& val)
		{
			_c.push_back(val);
		}

		void pop()
		{
			_c.pop_back();
		}


		friend bool operator==(const stack& lhs, const stack& rhs)
		{
			return (lhs._c == rhs._c);
		}
	

		friend bool operator!=(const stack& lhs, const stack& rhs)
		{
			return (lhs._c != rhs._c);
		}

		friend bool operator<(const stack& lhs, const stack& rhs)
		{
			return (lhs._c < rhs._c);
		}

		friend bool operator<=(const stack& lhs, const stack& rhs)
		{
			return (lhs._c <= rhs._c);
		}

		friend bool operator>(const stack& lhs, const stack& rhs)
		{
			return (lhs._c > rhs._c);
		}

		friend bool operator>=(const stack& lhs, const stack& rhs)
		{
			return (lhs._c >= rhs._c);
		}

		private:

		Container _c;
	};


}

#endif