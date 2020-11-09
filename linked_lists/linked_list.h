#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

namespace wq {

	class node {
	public:
		node(int value);
		~node();
		int m_value;
		node* m_next_ptr;
	};

	class linkedlists {
	public:
		explicit linkedlists() :m_header(nullptr) {}
		linkedlists(const linkedlists& other) = delete;
		linkedlists& operator =(const linkedlists&) = delete;
		~linkedlists();

		//return number of data elements in list
		int size();
		//returns true if empty
		bool empty() { return m_header == nullptr; };
		//returns the value of the nth item(starting at 0 for first)
		int value_at(int index);
		//adds an item to the front of the list
		void push_front(int value);
		//remove front item and return its value
		int pop_front();
		//adds an item at the end
		void push_back(int value);
		//removes end item and returns its value
		int pop_back();
		// get value of front item
		int front();
		//get value of end item
		int back();
		// insert value at index, so current item at that index is pointed to by new item at index
		void insert(int index, int value);
		// removes node at given index
		void erase(int index);
		//returns the value of the node at nth position from the end of the list
		int value_n_from_end(int n);
		//reverses the list
		void reverse();
		//removes the first item in the list with this value
		void remove_value(int value);
		//prient value
		void print();


	private:
		//int m_size;
		node* m_header;

	};
}//namespace wq

#endif // !_LINKED_LIST_H

