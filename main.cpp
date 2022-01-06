//#include "include/vector.hpp"
#include <iostream>


#include "include/vector.hpp"
#include <vector>
#include "include/map.hpp"


void	test_vector(void)
{
		//Create vector
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

	std::cout << "Insert all element of vector four at the end of vector three" << std::endl;
	three.insert(three.end(), four.begin(), four.end());
	std::cout << " vector three element access with []" << std::endl;
	for (size_t i = 0; i < three.size(); i++)
		std::cout << three[i] << std::endl;

	//std::cout << "Insert all element of vector two at the beginning of vector four" << std::endl;
	//four.insert(four.begin() + 1, two.begin(), two.end());
	std::cout << " vector four element access with []" << std::endl;
	for (size_t i = 0; i < four.size(); i++)
		std::cout << four[i] << std::endl;
	






}

int 	main(void)
{
	test_vector();


	/*SPACE::vector<int> test (10,10);

	SPACE::vector<int>::iterator it = test.end();
	std::cout << *(test.end()) << std::endl;
	it--;
	std::cout << *it << std::endl;

	SPACE::vector<int> test1 (10,10);
	SPACE::vector<int>::iterator it1 = test1.end();
	std::cout << *(test1.end()) << std::endl;
	--it1;
	std::cout << *it1 << std::endl;*/

	//std::cout << test.max_size() << std::endl;
	/*try
	{
		test.at(10);
	//	test.resize(4611686018427387904);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}*/

	//ft::vector<int>::iterator it;

	//ft::vector<int>::reverse_iterator rit = test.rbegin();
	//ft::iterator_traits<int*> it2;

	//it = test.begin();
	//std::cout << *it << std::endl;
	//std::cout << *rit << std::endl;
	//rit++;
	//std::cout << *rit << std::endl;
	return 0;
}