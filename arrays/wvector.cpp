#include "wvector.h"
#include <iostream>


namespace wq {

	wvector::wvector():m_size(0), m_capacity(kMinCapacity),
		m_old_ptr(nullptr), m_new_ptr(nullptr) {
		resize(m_capacity);
	}

	wvector::~wvector() {}

	int wvector::at(int index) 
	{
		if (index < 0 || index >= m_size) {
			std::cerr << "Index out of bounds: size = " << m_size
				<< ", index = " << index << "." << std::endl;
			exit(EXIT_FAILURE);
		}

		return m_data[index];

	}

	void wvector::push(int item)
	{
		increaseSize();

		m_data[m_size] = item;
		++m_size;
	}

	void wvector::insert(int index, int item)
	{
		if (index < 0 || index >= m_size) {
			std::cerr << "Index out of bounds: size = " << m_size
				<< ", index = " << index << "." << std::endl;
			exit(EXIT_FAILURE);
		}
		increaseSize();

		for (int i = m_size; i > index; --i) {
			m_data[i] = m_data[i - 1];
		}
		m_data[index] = item;
		++m_size;

	}

	void wvector::prepend(int item)
	{
		insert(0, item);
	}

	int wvector::pop()
	{
		int ret = m_data[m_size - 1];
		--m_size;
		decreaseSize();
		return ret;
	}

	void wvector::delet(int index)
	{
		if (index < 0 || index >= m_size) {
			std::cerr << "index out of bounds: size = " << m_size
				<< ", index = " << index << "." << std::endl;
			exit(EXIT_FAILURE);
		}

		for (int i = index; i < m_size - 1; ++i) {
			m_data[i] = m_data[i + 1];
		}
		--m_size;

		decreaseSize();
	}

	void wvector::remove(int item)
	{
		for (int i = m_size - 1; i >= 0; --i) {
			if (m_data[i] == item) {
				delet(i);
			}
		}
	}

	int wvector::find(int item)
	{
		for (int i = 0; i < m_size; ++i)
		{
			if (m_data[i] == item)
				return i;
		}
		return -1;
	}
	
	void wvector::resize(int new_capacity)
	{
		if (m_old_ptr == nullptr) {
			m_old_ptr = new int[new_capacity];
			memcpy(m_old_ptr, m_new_ptr, sizeof(int) * m_size);
			m_data.reset(m_old_ptr);
			m_new_ptr = nullptr;
		}
		else{
			m_new_ptr = new int[new_capacity];
			memcpy(m_new_ptr, m_old_ptr, sizeof(int) * m_size);
			m_data.reset(m_new_ptr);
			m_old_ptr = nullptr;
		}
	}

	void wvector::increaseSize()
	{
		if (m_size + 1 == m_capacity) {
			m_capacity *= kGrowthFactor;
			resize(m_capacity);
		}
	}

	void wvector::decreaseSize()
	{
		if (m_size <= m_capacity / kShrinkFactor) {
			m_capacity /= 2;
			resize(m_capacity);
		}
	}

}// namespace wq