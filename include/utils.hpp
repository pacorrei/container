#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <sstream>

namespace ft
{

	/*template <typename T>

	std::string convert_string(T ret)
	{
		std::ostringstream convert;
		convert << ret;
		return (convert.str());
	}*/

	template <class T> struct less
	{
		typedef T		first_argument_type;
		typedef T		second_argument_type;
		typedef bool	result_type;
		bool operator() (const T& x, const T& y) const
		{
			return (x < y);
		}

	};

	template<class T>
	struct bst
	{
		T value;
		bst* parent;
		bst* left;
		bst* right;
		int	max_size;
	};

	template<class T>
	bst<T>* min_value(bst<T>* node)
	{
		bst<T>* current = node;
		while(current->left)
			current = current->left;
		return current;
	}

	template<class T>
	bst<T>* max_value(bst<T>* node)
	{
		bst<T>* current = node;
		while(current->right)
			current = current->right;
		return current;
	}

	template<class T>
	bst<T>* succesor_node(bst<T>* node)
	{
		if (node->right)
			return min_value(node->right);
		bst<T>* tmp = node->parent;
		while (tmp && node == tmp->right)
		{
			node = tmp;
			tmp = tmp->parent;
		}
		return tmp;
	}
	template<class T>
	bst<T>* predecessor_node(bst<T>* node)
	{
		if (node->left)
			return max_value(node->left);
		bst<T>* tmp = node->parent;
		while(tmp && node == tmp->left)
		{
			node = tmp;
			tmp = tmp->parent;
		}
		return tmp;
	}


}

#endif