//#include "include/vector.hpp"
#include <iostream>


#include "include/vector.hpp"
#include <vector>
#include "include/map.hpp"

int main(void)
{
	std::vector<int> test (10,10);
	std::vector<int>::iterator it = test.end();
	std::cout << *(test.end()) << std::endl;
	it--;
	std::cout << *it << std::endl;

	ft::vector<int> test1 (10,10);
	ft::vector<int>::iterator it1 = test1.end();
	std::cout << *(test1.end()) << std::endl;
	--it1;
	std::cout << *it1 << std::endl;

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