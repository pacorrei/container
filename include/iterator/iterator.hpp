#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>

namespace ft

{
//This base class only provides some member types, which in fact are not required to be present in any iterator type
// (iterator types have no specific member requirements), but they might be useful, since they define the members needed for the default iterator_traits 

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator
	{
		public:
		
			typedef T	value_type;

			typedef Distance	difference_type;

			typedef Pointer		pointer;

			typedef Reference	reference;

			typedef Category	iterator_category;
	};

	struct output_iterator_tag { };

	struct input_iterator_tag { };

	struct forward_iterator_tag : public input_iterator_tag{ };

	struct bidirectional_iterator_tag : public forward_iterator_tag { };

	struct random_access_iterator_tag : public bidirectional_iterator_tag{ };

}

#endif