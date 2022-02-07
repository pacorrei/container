//#include "include/vector.hpp"
#include <iostream>

#ifndef SPACE
#define SPACE ft

#endif

#include "include/vector.hpp"
#include <vector>
#include "include/map.hpp"
#include <map>
#include "include/stack.hpp"
#include <stack>


void	test_vector(void)
{
	SPACE::vector<int> one (5, 5);
	SPACE::vector<int> two;
	SPACE::vector<int> three (one);
	SPACE::vector<int>::iterator it = one.begin();
	SPACE::vector<int>::iterator it2 = one.end();
	SPACE::vector<int> four (it, it2);
	
	std::cout << "All vector are constructs!" << std::endl;

	std::cout << "                     |BASIC TEST|" << std::endl;

	std::cout << "------SIZE TEST------" << std::endl;

	std::cout << "Size of vector one : " << one.size() << std::endl;
	std::cout << "Size of vector two : " << two.size() << std::endl;
	std::cout << "Size of vector three : " << three.size() << std::endl;
	std::cout << "Size of vector four: " << four.size() << std::endl;

	std::cout << "------MAX SIZE TEST------" << std::endl;

	std::cout << "Max size of vector one : " << one.max_size() << std::endl;
	std::cout << "Max size of vector two : " << two.max_size() << std::endl;
	std::cout << "Max size of vector three : " << three.max_size() << std::endl;
	std::cout << "Max size of vector four : " << four.max_size() << std::endl;

	std::cout << "------EMPTY TEST------" << std::endl;

	std::cout << "Is vector one empty: " << one.empty() << std::endl;
	std::cout << "Is vector two empty: " << two.empty() << std::endl;
	std::cout << "Is vector three empty : " << three.empty() << std::endl;
	std::cout << "Is vector four empty : " << four.empty() << std::endl;

	std::cout << "------RESIZE TEST------" << std::endl;

	std::cout << "Resize of vector one, 5 -> 7 "  << std::endl;
	 one.resize(7, 8);
	std::cout << "Resize of vector two, 0 -> 10 " << std::endl;
	two.resize(10, 10);
	std::cout << "Resize of vector three, 5 -> 3 " << std::endl;
	three.resize(3);
	std::cout << "Resize of vector four, 5 -> 1 " << std::endl;
	four.resize(1);
	std::cout << std::endl;
	std::cout << "Size of vector one : " << one.size() << std::endl;
	std::cout << "Size of vector two : " << two.size() << std::endl;
	std::cout << "Size of vector three : " << three.size() << std::endl;
	std::cout << "Size of vector four: " << four.size() << std::endl;

	std::cout << "------CAPACITY TEST------" << std::endl;

	std::cout << "Capacity of vector one : " << one.capacity() << std::endl;
	std::cout << "Capacity of vector two : " << two.capacity() << std::endl;
	std::cout << "Capacity of vector three : " << three.capacity() << std::endl;
	std::cout << "Capacity of vector four : " << four.capacity() << std::endl;

	std::cout << "                     |ELEMENT ACCESS TEST|" << std::endl;
	std::cout << "------ACCESS [] TEST------" << std::endl;

	std::cout << " vector one element access with []" << std::endl;
	for (size_t i = 0; i < one.size(); i++)
		std::cout << one[i] << std::endl;
	
	std::cout << " vector two element access with []" << std::endl;
	for (size_t i = 0; i < two.size(); i++)
		std::cout << two[i] << std::endl;
	
	std::cout << " vector three element access with []" << std::endl;
	for (size_t i = 0; i < three.size(); i++)
		std::cout << three[i] << std::endl;
	
	std::cout << " vector four element access with []" << std::endl;
	for (size_t i = 0; i < four.size(); i++)
		std::cout << four[i] << std::endl;

	std::cout << "------ACCESS AT TEST------" << std::endl;

	std::cout << "Try access at element 2 in vector one : " << one.at(1) << std::endl;
	std::cout << "Try access at element 6 in vector one : " << one.at(5) << std::endl;
	try 
	{
		std::cout << "Try access at element 15 in vector one : " << one.at(14) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Try access at element 2 in vector two : " << two.at(3) << std::endl;
	std::cout << "Try access at element 6 in vector two : " << two.at(7) << std::endl;
	std::cout << "Try access at element 1 in vector three : " << three.at(0) << std::endl;
	try 
	{
		std::cout << "Try access at element 10 in vector three : " << three.at(9) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Try access at element 1 in vector four : " << four.at(0) << std::endl;

	std::cout << "------ACCESS FRONT BACK TEST------" << std::endl;

	std::cout << "Front of vector one : " << one.front() << ", back of vector one : " << one.back() << std::endl;
	std::cout << "Front of vector two : " << two.front() << ", back of vector two : " << two.back() << std::endl;
	std::cout << "Front of vector three : " << three.front() << ", back of vector three : " << three.back() << std::endl;
	std::cout << "Front of vector four : " << four.front() << ", back of vector four : " << four.back() << std::endl;

	std::cout << "                     |MODIFIERS TEST|" << std::endl;

	std::cout << "------PUSH/POP BACK TEST------" << std::endl;

	std::cout << "Push back the value 15 on vector one." << std::endl;
	one.push_back(15);
	std::cout << "Push back the value 16 on vector one." << std::endl;
	one.push_back(16);
	std::cout << " vector one element access with []" << std::endl;
	for (size_t i = 0; i < one.size(); i++)
		std::cout << one[i] << std::endl;
	std::cout << "Pop back the last value on vector one." << std::endl;
	one.pop_back();
	std::cout << "Pop back the last value on vector one." << std::endl;
	one.pop_back();
	std::cout << " vector one element access with []" << std::endl;
	for (size_t i = 0; i < one.size(); i++)
		std::cout << one[i] << std::endl;

	
	std::cout << "Pop back the last value on vector two." << std::endl;
	two.pop_back();
	std::cout << "Pop back the last value on vector two." << std::endl;
	two.pop_back();
	std::cout << " vector two element access with []" << std::endl;
	for (size_t i = 0; i < two.size(); i++)
		std::cout << two[i] << std::endl;
	std::cout << "Push back the value 15 on vector two." << std::endl;
	two.push_back(15);
	std::cout << "Push back the value 16 on vector two." << std::endl;
	two.push_back(16);
	std::cout << " vector two element access with []" << std::endl;
	for (size_t i = 0; i < two.size(); i++)
		std::cout << two[i] << std::endl;
	
	std::cout << "Push back the value 15 on vector three." << std::endl;
	three.push_back(15);
	std::cout << "Push back the value 16 on vector three." << std::endl;
	three.push_back(16);
	std::cout << "Push back the value 17 on vector three." << std::endl;
	three.push_back(17);
	std::cout << " vector three element access with []" << std::endl;
	for (size_t i = 0; i < three.size(); i++)
		std::cout << three[i] << std::endl;

	std::cout << "Pop back the last value on vector four." << std::endl;
	four.pop_back();

	std::cout << "Size of vector one : " << one.size() << std::endl;
	std::cout << "Size of vector two : " << two.size() << std::endl;
	std::cout << "Size of vector three : " << three.size() << std::endl;
	std::cout << "Size of vector four: " << four.size() << std::endl;

	std::cout << "Push back the value 1 on vector four." << std::endl;
	four.push_back(1);
	std::cout << "Push back the value 2 on vector four." << std::endl;
	four.push_back(2);
	std::cout << "Push back the value 3 on vector four." << std::endl;
	four.push_back(3);

	std::cout << "------ASSIGN TEST------" << std::endl;

	std::cout << "Assign the vector one with a size of 5 and fill with the 42 value." << std::endl;
	one.assign(5, 42);
	std::cout << " vector one element access with []" << std::endl;
	for (size_t i = 0; i < one.size(); i++)
		std::cout << one[i] << std::endl;

	std::cout << "Assign the vector two with a size of 8 and fill with the 21 value." << std::endl;
	two.assign(8, 21);
	std::cout << " vector two element access with []" << std::endl;
	for (size_t i = 0; i < two.size(); i++)
		std::cout << two[i] << std::endl;

	std::cout << "Assign the vector three with the iterator of vector four." << std::endl;
	three.assign(four.begin(), four.end());
	std::cout << " vector three element access with []" << std::endl;
	for (size_t i = 0; i < three.size(); i++)
		std::cout << three[i] << std::endl;
	
	std::cout << "Assign the vector four with the iterator of vector one." << std::endl;
	four.assign(one.begin(), one.end());
	std::cout << " vector four element access with []" << std::endl;
	for (size_t i = 0; i < four.size(); i++)
		std::cout << four[i] << std::endl;

	std::cout << "Size of vector one : " << one.size() << std::endl;
	std::cout << "Size of vector two : " << two.size() << std::endl;
	std::cout << "Size of vector three : " << three.size() << std::endl;
	std::cout << "Size of vector four: " << four.size() << std::endl;

	std::cout << "------INSERT/ERASE TEST------" << std::endl;

	std::cout << "Insert one element at the end of vector one" << std::endl;
	one.insert(one.end(), 82);
	std::cout << " vector one element access with []" << std::endl;
	for (size_t i = 0; i < one.size(); i++)
		std::cout << one[i] << std::endl;

	std::cout << "Insert five element at the beginning of vector two" << std::endl;
	two.insert(two.begin(), 5, 11);
	std::cout << " vector two element access with []" << std::endl;
	for (size_t i = 0; i < two.size(); i++)
		std::cout << two[i] << std::endl;
		std::cout << " vector three element access with []" << std::endl;
	for (size_t i = 0; i < three.size(); i++)
		std::cout << three[i] << std::endl;

	std::cout << "Insert all element of vector one at the end of vector three" << std::endl;
	three.insert(three.end(), one.begin(), one.end());
	std::cout << " vector three element access with []" << std::endl;
	for (size_t i = 0; i < three.size(); i++)
		std::cout << three[i] << std::endl;

	std::cout << "Insert all element of vector two at the beginning of vector four" << std::endl;
	four.insert(four.begin(), two.begin(), two.end());
	std::cout << " vector four element access with []" << std::endl;
	for (size_t i = 0; i < four.size(); i++)
		std::cout << four[i] << std::endl;
	

	std::cout << std::endl;
	std::cout << "Erase test" << std::endl;

	std::cout << "Size of vector one : " << one.size() << std::endl;
	std::cout << " vector one element access with []" << std::endl;
	for (size_t i = 0; i < one.size(); i++)
		std::cout << one[i] << std::endl;
	std::cout << "Erase first element of vector one." << std::endl;
	one.erase(one.begin());
	std::cout << "Size of vector one : " << one.size() << std::endl;
	std::cout << " vector one element access with []" << std::endl;
	for (size_t i = 0; i < one.size(); i++)
		std::cout << one[i] << std::endl;

	std::cout << std::endl;	
	std::cout << "Size of vector two : " << two.size() << std::endl;
	std::cout << " vector two element access with []" << std::endl;
	for (size_t i = 0; i < two.size(); i++)
		std::cout << two[i] << std::endl;
	std::cout << "Erase last element of vector two." << std::endl;
	SPACE::vector<int>::iterator two_end = two.end();
	two_end--;
	two.erase(two_end);
	std::cout << "Size of vector two : " << two.size() << std::endl;
	std::cout << " vector two element access with []" << std::endl;
	for (size_t i = 0; i < two.size(); i++)
		std::cout << two[i] << std::endl;

	std::cout << std::endl;	
	std::cout << "Size of vector three : " << three.size() << std::endl;
	std::cout << " vector three element access with []" << std::endl;
	for (size_t i = 0; i < three.size(); i++)
		std::cout << three[i] << std::endl;
	std::cout << "Erase all elements of vector three." << std::endl;
	three.erase(three.begin(), three.end());
	std::cout << "Size of vector three : " << three.size() << std::endl;
	std::cout << " vector three element access with []" << std::endl;
	for (size_t i = 0; i < three.size(); i++)
		std::cout << three[i] << std::endl;

	std::cout << std::endl;	
	std::cout << "Size of vector four : " << four.size() << std::endl;
	std::cout << " vector four element access with []" << std::endl;
	for (size_t i = 0; i < four.size(); i++)
		std::cout << four[i] << std::endl;
	std::cout << "Erase first three elements of vector four." << std::endl;
	SPACE::vector<int>::iterator four_begin = four.begin();
	SPACE::vector<int>::iterator four_begin2 = four_begin;
	four_begin2++;
	four_begin2++;
	four_begin2++;
	four.erase(four_begin, four_begin2);
	std::cout << "Size of vector four : " << four.size() << std::endl;
	std::cout << " vector four element access with []" << std::endl;
	for (size_t i = 0; i < four.size(); i++)
		std::cout << four[i] << std::endl;

	std::cout << std::endl;
	std::cout << "------SWAP TEST------" << std::endl;

	std::cout << " vector one element access with []" << std::endl;
	for (size_t i = 0; i < one.size(); i++)
		std::cout << one[i] << std::endl;
	std::cout << " vector two element access with []" << std::endl;
	for (size_t i = 0; i < two.size(); i++)
		std::cout << two[i] << std::endl;
	std::cout << "Swap vector one and two" << std::endl;
	one.swap(two);
	std::cout << " vector one element access with []" << std::endl;
	for (size_t i = 0; i < one.size(); i++)
		std::cout << one[i] << std::endl;
	std::cout << " vector two element access with []" << std::endl;
	for (size_t i = 0; i < two.size(); i++)
		std::cout << two[i] << std::endl;

	std::cout << std::endl;
	std::cout << "------CLEAN TEST------" << std::endl;

	std::cout << "clear vector one" << std::endl;
	one.clear();
	std::cout << "Size of vector one : " << one.size() << std::endl;


}

void	test_stack(void)
{
	SPACE::stack<int> one;
	SPACE::stack<int, SPACE::vector<int>> two;
	SPACE::vector<int> tmp(2, 42);
	SPACE::stack<int, SPACE::vector<int>> three (tmp);

	std::cout << "------SIZE TEST------" << std::endl;

	std::cout << "Size of stack one : " << one.size() << std::endl;
	std::cout << "Size of stack two : " << two.size() << std::endl;
	std::cout << "Size of stack three : " << three.size() << std::endl;
	std::cout << std::endl;

	std::cout << "------EMPTY TEST------" << std::endl;

	std::cout << "Is stack one empty : " << one.empty() << std::endl;
	std::cout << "Is stack two empty : " << two.empty() << std::endl;
	std::cout << "Is stack three empty : " << three.empty() << std::endl;
	std::cout << std::endl;

	std::cout << "------PUSH/POP AND TOP TEST------" << std::endl;

	std::cout << "Push back the value 1 on stack one" << std::endl;
	one.push(1);
	std::cout << "The last value in stack one is : " << one.top() << std::endl;
	std::cout << "Push back the value 2 on stack one" << std::endl;
	one.push(2);
	std::cout << "The last value in stack one is : " << one.top() << std::endl;
	std::cout << "Pop the last value of stack one" << std::endl;
	one.pop();
	std::cout << "The last value in stack one is : " << one.top() << std::endl;

	std::cout << std::endl;
	std::cout << "Push back the value 21 on stack two" << std::endl;
	two.push(21);
	std::cout << "Push back the value 42 on stack two" << std::endl;
	two.push(42);
	std::cout << "Push back the value 84 on stack two" << std::endl;
	two.push(84);
	std::cout << "The last value in stack two is : " << two.top() << std::endl;
	std::cout << "Pop the last value of stack two" << std::endl;
	two.pop();
	std::cout << "The last value in stack two is : " << two.top() << std::endl;
	std::cout << "Pop the last value of stack two" << std::endl;
	two.pop();
	std::cout << "The last value in stack two is : " << two.top() << std::endl;

	std::cout << std::endl;
	std::cout << "The last value in stack three is : " << three.top() << std::endl;

	std::cout << std::endl;
	std::cout << "Size of stack one : " << one.size() << std::endl;
	std::cout << "Size of stack two : " << two.size() << std::endl;
	std::cout << "Size of stack three : " << three.size() << std::endl;
	
}

void	test_map(void)
{
	SPACE::map<char, int> one;

	one['a']=10;
	one['b']=30;
	one['c']=50;
	one['d']=70;

	SPACE::map<char, int> two (one.begin(),one.end());
	SPACE::map<char, int> three (two);

	std::cout << "All map are constructs!" << std::endl;

	std::cout << "------SIZE TEST------" << std::endl;
	std::cout << "Size of map one : " << one.size() << std::endl;
	std::cout << "Size of map two : " << two.size() << std::endl;
	std::cout << "Size of map three : " << three.size() << std::endl;

	std::cout << std::endl;

	std::cout << "------EMPTY TEST------" << std::endl;

	std::cout << "Is map one empty : " << one.empty() << std::endl;
	std::cout << "Is map two empty : " << two.empty() << std::endl;
	std::cout << "Is map three empty : " << three.empty() << std::endl;

	std::cout << "Clear map number three" << std::endl;
	three.clear();
	std::cout << "Is map one empty : " << one.empty() << std::endl;
	std::cout << "Is map two empty : " << two.empty() << std::endl;
	std::cout << "Is map three empty : " << three.empty() << std::endl;

	std::cout << std::endl;

	std::cout << "------MAX SIZE TEST------" << std::endl;
	std::cout << "Max size of map one : " << one.max_size() << std::endl;
	std::cout << "Max size of map two : " << two.max_size() << std::endl;
	std::cout << "Max size of map three : " << three.max_size() << std::endl;

	std::cout << std::endl;

	std::cout << "------OPERATOR [] TEST------" << std::endl;
	std::cout << "Value for map one ['a'] = " << one['a'] << std::endl;
	std::cout << "Value for map one ['b'] = " << one['b'] << std::endl;
	std::cout << "Value for map one ['c'] = " << one['c'] << std::endl;
	std::cout << "Value for map one ['d'] = " << one['d'] << std::endl;

	std::cout << std::endl;

	std::cout << "Value for map two ['a'] = " << two['a'] << std::endl;
	std::cout << "Value for map two ['b'] = " << two['b'] << std::endl;
	std::cout << "Value for map two ['c'] = " << two['c'] << std::endl;
	std::cout << "Value for map two ['d'] = " << two['d'] << std::endl;

	std::cout << std::endl;

	std::cout << "------INSERT TEST------" << std::endl;

	std::cout << "Insert value in map one" << std::endl;
	SPACE::pair<SPACE::map<char, int>::iterator, bool> ret;
	std::cout << "Try insert element 'e'" << std::endl;
	ret = one.insert(SPACE::pair<char, int>('e', 80));
	if (ret.second == false)
		std::cout << "The element 'e' already exist with the value : " << ret.first->second << std::endl;
	else
		std::cout << "The element 'e' is successfully inserted" << std::endl;

	std::cout << "Try insert element 'e'" << std::endl;
	ret = one.insert(SPACE::pair<char, int>('e', 100));
	if (ret.second == false)
		std::cout << "The element 'e' already exist with the value : " << ret.first->second << std::endl;
	else
		std::cout << "The element 'e' is successfully inserted" << std::endl;
	std::cout << "Try insert element 'f'" << std::endl;
	ret = one.insert(SPACE::pair<char, int>('f', 80));
	if (ret.second == false)
		std::cout << "The element 'f' already exist with the value : " << ret.first->second << std::endl;
	else
		std::cout << "The element 'f' is successfully inserted" << std::endl;
	SPACE::map<char, int>::iterator it;
	std::cout << "The map one contains:" << std::endl;
  	for (it = one.begin(); it != one.end(); ++it)
    std::cout << it->first << " => " << it->second << std::endl;

	std::cout << std::endl;

	std::cout << "Insert value in map two" << std::endl;

	it = two.begin();
	two.insert(it, SPACE::pair<char, int>('A', 1));
	two.insert(it, SPACE::pair<char, int>('f', 100));
	std::cout << "The map two contains:" << std::endl;
  	for (it = two.begin(); it != two.end(); ++it)
    std::cout << it->first << " => " << it->second << std::endl;

	std::cout << "Insert value in map three" << std::endl;
	std::cout << "Insert with iterator, from the beginning of map one, to the 'd' element" << std::endl;
	three.insert(one.begin(), one.find('d'));
	std::cout << "The map three contains:" << std::endl;
  	for (it = three.begin(); it != three.end(); ++it)
    std::cout << it->first << " => " << it->second << std::endl;


	std::cout << std::endl;

	std::cout << "------ERASE TEST------" << std::endl;

	std::cout << "Erase value in map one" << std::endl;

	std::cout << "The map one contains:" << std::endl;
  	for (it = one.begin(); it != one.end(); ++it)
    std::cout << it->first << " => " << it->second << std::endl;
	std::cout << "Size of map one : " << one.size() << std::endl;

	std::cout << std::endl;

	std::cout << "Erase element 'a' in map one with iterator" << std::endl;
	one.erase(one.find('a'));
	std::cout << "Erase element 'c' in map one with iterator" << std::endl;
	one.erase(one.find('c'));
	std::cout << "Erase element 'f' in map one with iterator" << std::endl;
	one.erase(one.find('f'));

	std::cout << std::endl;

	std::cout << "The map one contains:" << std::endl;
  	for (it = one.begin(); it != one.end(); ++it)
    	std::cout << it->first << " => " << it->second << std::endl;
	std::cout << "Size of map one : " << one.size() << std::endl;

	std::cout << std::endl;

	std::cout << "Erase value in map two" << std::endl;

	std::cout << "The map two contains:" << std::endl;
  	for (it = two.begin(); it != two.end(); ++it)
    std::cout << it->first << " => " << it->second << std::endl;
	std::cout << "Size of map two : " << two.size() << std::endl;

	std::cout << std::endl;

	std::cout << "Erase element 'a' in map two with element" << std::endl;
	two.erase('a');
	std::cout << "Erase element 'd' in map two with element" << std::endl;
	two.erase('d');

	for (it = two.begin(); it != two.end(); ++it)
    std::cout << it->first << " => " << it->second << std::endl;
	std::cout << "Size of map two : " << two.size() << std::endl;

	std::cout << std::endl;

	std::cout << "Erase value in map three" << std::endl;

	std::cout << "The map three contains:" << std::endl;
  	for (it = three.begin(); it != three.end(); ++it)
    std::cout << it->first << " => " << it->second << std::endl;
	std::cout << "Size of map three : " << three.size() << std::endl;

	std::cout << "Erase all value in map three with range of iterator" << std::endl;
	three.erase(three.begin(), three.end());std::cout << "------ERASE TEST------" << std::endl;

	for (it = three.begin(); it != three.end(); ++it)
    std::cout << it->first << " => " << it->second << std::endl;
	std::cout << "Size of map three : " << three.size() << std::endl;

	std::cout << std::endl;

	std::cout << "------SWAP TEST------" << std::endl;

	std::cout << "The map one contains:" << std::endl;
  	for (it = one.begin(); it != one.end(); ++it)
    	std::cout << it->first << " => " << it->second << std::endl;

	std::cout << "The map two contains:" << std::endl;
  	for (it = two.begin(); it != two.end(); ++it)
   		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << "Swap the map one and the map two" << std::endl;

	one.swap(two);

	std::cout << "The map one contains:" << std::endl;
  	for (it = one.begin(); it != one.end(); ++it)
    	std::cout << it->first << " => " << it->second << std::endl;

	std::cout << "The map two contains:" << std::endl;
  	for (it = two.begin(); it != two.end(); ++it)
   		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << "------CLEAR TEST------" << std::endl;

	std::cout << "Clear map one and two" << std::endl;

	one.clear();
	two.clear();

	std::cout << "The map one contains:" << std::endl;
  	for (it = one.begin(); it != one.end(); ++it)
    	std::cout << it->first << " => " << it->second << std::endl;
		std::cout << "Size of map one : " << one.size() << std::endl;

	std::cout << "The map two contains:" << std::endl;
  	for (it = two.begin(); it != two.end(); ++it)
   		std::cout << it->first << " => " << it->second << std::endl;
		   std::cout << "Size of map two : " << two.size() << std::endl;

		
}

int 	main(void)
{
	//test_vector();
	//test_stack();
	//test_map();
	return 0;
}