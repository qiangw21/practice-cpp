#include "linked_list.h"
#include <iostream>
#include <assert.h>

using namespace wq;
using namespace std;

int main()
{
	linkedlists lists;
	lists.push_back(2);
	lists.print();
	cout << "testing push ... " << endl;
	lists.push_front(5);
	assert(lists.front() == 5);
	lists.push_back(6);
	assert(lists.back() == 6);
	lists.push_back(8);
	lists.push_back(12);
	std::cout << "lists value should be: 5, 2, 6, 8, 12" << std::endl;
	lists.print();

	cout << "testing pop ..." << endl;
	assert(lists.pop_front() == 5);
	assert(lists.pop_back() == 12);
	std::cout << "lists value should be: 2, 6, 8" << std::endl;
	lists.print();
	
	cout << "testing insert ..." << endl;
	lists.insert(2, 3);
	lists.print();
	assert(lists.value_at(2) == 3);
	lists.insert(0, 3);
	lists.print();

	cout << "testing erase ..." << endl;
	lists.erase(3);
	lists.print();
	lists.erase(0);
	std::cout << "lists value should be: 2, 6, 8" << std::endl;
	lists.print();

	cout << "value_n_from_end ..." << endl;
	lists.push_front(2);
	assert(lists.value_n_from_end(1) == 8);

	cout << "testing reverse ..." << endl;
	lists.reverse();
	lists.print();
	lists.pop_back();
	lists.reverse();
	lists.print();
	lists.pop_back();
	lists.reverse();
	lists.print();

	cout << "testing remove ..." << endl;
	lists.push_back(18);
	lists.remove_value(6);
	lists.print();
	lists.remove_value(18);
	lists.print();
	lists.remove_value(3);
	lists.print();

	return 0;

}