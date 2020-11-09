#include "linked_list.h"
#include <iostream>

namespace wq {
	node::node(int value) :m_value(value), m_next_ptr(nullptr) {};
	node::~node() 
	{
	}

	/*linkedlists::linkedlists(int value) {
		m_header = nullptr;
		m_header = new node(value);
		m_size = 1;
	}*/

	linkedlists::~linkedlists()
	{
		
		node* next_node = nullptr;
		node* current_node = m_header;

		while (current_node) {
			next_node = current_node->m_next_ptr;
			delete current_node;
			current_node = next_node;
		}
		
	}

	int linkedlists::size()
	{
		int size_ = 0;
		node* current_node = m_header;
		while (current_node)
		{
			current_node = current_node->m_next_ptr;
			++size_;
		}
		return size_;
	}

	int linkedlists::value_at(int index)
	{
		/*if (index < 0 || index >= m_size) {
			std::cerr << "Index out of bounds: size = " << m_size
				<< ", index = " << index << "." << std::endl;
			exit(EXIT_FAILURE);
		}*/
		node* temp_node = m_header;
		int i = 0;
		for (; i < index && temp_node != nullptr; ++i) {
			temp_node = temp_node->m_next_ptr;
		}

		if (i != index || temp_node == nullptr) {
			std::cerr << "Index out of bounds!" << std::endl;
			exit(EXIT_FAILURE);
		}

		return temp_node->m_value;
	}

	void linkedlists::push_front(int value)
	{
		node* temp_node = new node(value);
		
		temp_node->m_next_ptr = m_header;
		m_header = temp_node;
		
	}

	int linkedlists::pop_front()
	{
		if (m_header == nullptr) {
			std::cerr << "Lists is empty!" << std::endl;
			exit(EXIT_FAILURE);
		}
		int temp_value = m_header->m_value;
		node* temp_node = m_header;
		m_header = m_header->m_next_ptr;
		delete temp_node;
		
		return temp_value;
	}

	void linkedlists::push_back(int value)
	{
		if (m_header == nullptr) {
			m_header = new node(value);
			return;
		}
			
		node* temp_node = m_header;
		while (temp_node->m_next_ptr) {
			temp_node = temp_node->m_next_ptr;
		}
		
		temp_node->m_next_ptr = new node(value);
	}

	int linkedlists::pop_back()
	{
		if (m_header == nullptr) {
			std::cerr << "Lists is empty!" << std::endl;
			exit(EXIT_FAILURE);
		}
		node* current_node = m_header;
		node* prev_node = nullptr;
		while (current_node->m_next_ptr){
			prev_node = current_node;
			current_node = current_node->m_next_ptr;
		}
		int value = current_node->m_value;

		if (prev_node == nullptr) {
			m_header = nullptr;
		}
		else{
			prev_node->m_next_ptr = nullptr;
		}
		delete current_node;
		return value;
	}

	int linkedlists::front()
	{
		if (m_header == nullptr) {
			std::cerr << "Lists is empty!" << std::endl;
			exit(EXIT_FAILURE);
		}
		return m_header->m_value;
	}

	int linkedlists::back()
	{
		if (m_header == nullptr) {
			std::cerr << "Lists is empty!" << std::endl;
			exit(EXIT_FAILURE);
		}
		node* temp_node = m_header;
		while (temp_node->m_next_ptr) {
			temp_node = temp_node->m_next_ptr;
		}
		
		return temp_node->m_value;
	}

	void linkedlists::insert(int index, int value)
	{
		/*if (index < 0 || index >= m_size) {
			std::cerr << "Index out of bounds: size = " << m_size
				<< ", index = " << index << "." << std::endl;
				exit(EXIT_FAILURE);
		}*/
		node* current_node = m_header;
		node* prev_node = nullptr;
		int i;
		for (i = 0; i < index && current_node != nullptr; ++i) {
			prev_node = current_node;
			current_node = current_node->m_next_ptr;
		}
		if (i != index) {
			std::cerr << "Index out of bounds." << std::endl;
			exit(EXIT_FAILURE);
		}
		node* new_node = new node(value);
		if (prev_node == nullptr) {
			new_node->m_next_ptr = m_header;
			m_header = new_node;
		}
		else
		{
			new_node->m_next_ptr = prev_node->m_next_ptr;
			prev_node->m_next_ptr = new_node;
		}	
	}

	void linkedlists::erase(int index)
	{
		if (m_header == nullptr) {
			std::cerr << "List is empty." << std::endl;
			exit(EXIT_FAILURE);
		}
		node* current_node = m_header;
		node* prev_node = nullptr;
		int i;
		for (i = 0; i < index && current_node; ++i) {
			prev_node = current_node;
			current_node = current_node->m_next_ptr;
		}
		
		if (i != index || current_node == nullptr) {
			std::cerr << "Index out of bounds!" << std::endl;
			exit(EXIT_FAILURE);
		}
		if (prev_node == nullptr) {
			m_header = m_header->m_next_ptr;
		}
		else
		{
			prev_node->m_next_ptr = current_node->m_next_ptr;
		}
		delete current_node;
	}

	int linkedlists::value_n_from_end(int n)
	{
		if (n < 1 || m_header == nullptr) {
			std::cerr << "List is empty." << std::endl;
			exit(EXIT_FAILURE);
		}

		auto* current = m_header;
		auto* match = m_header;

		int i;
		for (i = 0; i < n && current; ++i) {
			current = current->m_next_ptr;
		}

		if (i != n) {
			std::cerr << "Index out of bounds." << std::endl;
			exit(EXIT_FAILURE);
		}

		while (current) {
			match = match->m_next_ptr;
			current = current->m_next_ptr;
		}

		return match->m_value;

	}

	void linkedlists::reverse()
	{
		if (m_header == nullptr) {
			return;
		}
		node* front_node = nullptr;
		node* current_node = m_header;
		node* next_node = current_node->m_next_ptr;
		while (current_node)
		{
			next_node = current_node->m_next_ptr;
			current_node->m_next_ptr = front_node;
			front_node = current_node;
			current_node = next_node;
		}
		m_header = front_node;
	}

	void linkedlists::remove_value(int value)
	{
		node* front_node = nullptr;
		node* current_node = m_header;

		while (current_node) {
			if (current_node->m_value == value) {
				if (front_node == nullptr)
					m_header = m_header->m_next_ptr;
				else
					front_node->m_next_ptr = current_node->m_next_ptr;
				delete current_node;
				return;
			}
			front_node = current_node;
			current_node = current_node->m_next_ptr;
		}	
	}

	void linkedlists::print()
	{
		std::cout << "lists size: " << size() << " ,value: ";
		if (m_header == nullptr) {
			std::cout << "None!" << std::endl;
			return;
		}
		node* temp_node = m_header;
		while (temp_node)
		{
			std::cout << temp_node->m_value << " ";
			temp_node = temp_node->m_next_ptr;
		}
		std::cout << std::endl;
	}


}//namespace wq