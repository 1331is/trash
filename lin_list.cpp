#include "linked_list.h"

class list
{
public:
	list();
	~list();
	void push_front(int element) {
		insert(0, element);
	}
	// 6-> 1-> 2-> 3-> 4-> 5 
	void push_back(int element) {
		insert(size, element);
	}
	// 1-> 2-> 3-> 4-> 5-> 6
	bool find(int element) {
		Node* current = head;
		while (current != nullptr) {
			if ((current->data) == element) {
				return true;
			}
			current = current->pNext;
		}
		return false;

	}
	int get_index(int element) { //TODO Поиск элемента по индексу Get_by_index
		int a = 0;
		Node* current = head;
		while (current != nullptr) {
			if ((current->data) == element) {
				return a;
			}
			++a;
			current = current->pNext;
		}
		return -1;

	}
	void insert(unsigned int index, int element) {
		if (index > size) {
			return;
		}
		++size;
		if (index == 0) {
			Node* old_head = head;
			head = new Node{ element, old_head };
			return;
		}
		Node* current = head;
		for (int a = 0; a < index - 1; a++) {
			current = current->pNext;
		}

		Node* oldcurrent = current->pNext;
		current->pNext = new Node{ element, oldcurrent };
	}
	void erase(unsigned int index) {
		if (index >= size) {
			return;
		}
		Node* current = head;
		for (int a = 0; a < index - 1; a++) {
			current = current->pNext;
		}
		Node* prev = current;
		current = current->pNext;
		Node* next = prev->pNext->pNext;
		prev->pNext = next;
		delete(current);
		--size;
	}
	void print_all() {
		Node* current = head;
		while (current != nullptr) {
			cout << (*current).data << "->"; // current->data
			current = current->pNext;
		}
		cout << "\n";
	}


private:


	class Node
	{
	public:
		Node* pNext;
		int data;

		Node(int data, Node* pNext)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	Node* head = nullptr;
	unsigned int size = 0;
};

list::list()
{
}

list::~list()
{
}

