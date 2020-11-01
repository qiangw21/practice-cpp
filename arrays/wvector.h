#ifndef _WVECTOR_H_
#define _WVECTOR_H_

#include <memory>
const int kMinCapacity = 16;
const int kGrowthFactor = 2;
const int kShrinkFactor = 4;

namespace wq {

	class wvector {
	public:
		wvector();
		wvector(const wvector& other) = default;
		~wvector();

		// number of items
		int size() { return m_size; }
		// number of items it can hold
		int capacity() { return m_capacity; }

		bool is_empty() { return m_size == 0; }

		//returns item at given index, blows up if index out of bounds
		int at(int index);

		void push(int item);

		// inserts item at index, shifts that index's value and trailing elements to the right
		void insert(int index, int item);

		// can use insert above at index 0
		void prepend(int item);

		//remove from end, return value
		int pop();

		//delete item at index, shifting all trailing elements left
		void delet(int index);

		// looks for value and removes index holding it (even if in multiple places)
		void remove(int item);

		//looks for value and returns first index with that value, -1 if not found
		int find(int item);

	private:
		//when you reach capacity, resize to double the size
		//when popping an item, if size is 1 / 4 of capacity, resize to half
		void resize(int new_capacity);
		// Increases the capacity of the vector.
		//void increaseSize();
		// Decreases the capacity of the vector.
		//void decreaseSize();

		std::unique_ptr<int[]> m_data;
		int* m_new_ptr;
		int* m_old_ptr;
		int m_size;
		int m_capacity;

	};

}// namespace wq

#endif // !_WVECTOR_H_