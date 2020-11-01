#include "wvector.h"
#include <iostream>
#include <assert.h>

using namespace std;
using namespace wq;

void print(wvector& vec)
{
	if (!vec.is_empty()) {
		cout << "vec capacity: " << vec.capacity()
			 <<" vec size: " << vec.size() << ", value: ";
		for (int i = 0; i < vec.size(); ++i)
			cout << vec.at(i) << " ";
		cout << endl;
	}
	else
	{
		cout << "This is empty vector! ";
		cout << "vec capacity: " << vec.capacity()
			<< " vec size: " << vec.size() << "." << endl;
	}
}

int main()
{
	wvector vec;
	assert(vec.is_empty());
	print(vec);
	//testing push, at
	cout << "testing push, at ..." << endl;
	for (int i = 0; i < 10; ++i) {
		vec.push(i);
	}
	assert(vec.size() == 10);
	print(vec);
	//testing insert
	cout << "testing insert,prepend ..." << endl;
	vec.insert(1, 2);
	print(vec);
	vec.prepend(2);
	print(vec);

	cout << "testing pop, delet ..." << endl;
	int value = vec.pop();
	assert(value == 9);
	print(vec);
	vec.delet(3);
	print(vec);

	cout << "testing remove ... " << endl;
	vec.remove(2);
	print(vec);

	cout << "testing find ..." << endl;
	cout << "find 2: " << vec.find(2) << endl;
	cout << "find 5: " << vec.find(5) << endl;





}