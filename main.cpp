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
	
	std::cout << "All vector are constructs" << std::endl;

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