#include "My_list.h"
#include <iostream>
using namespace std;

Node::Node(int val) {

	value = val;
	next = nullptr;
}

My_list::My_list() {
	head = nullptr;
	tail = nullptr;
}

My_list::My_list(int val) {
	head = new Node(val);
	tail = new Node(val);
}

//проверка наличия узлов
bool My_list::is_empty() {
	return head == nullptr;
}

//добавление в конец списка
void My_list::append(int val) {
	Node* temp = new Node(val);

	//если список пустой
	if (this->is_empty()) {
		head = temp;
		tail = temp;
	}
	//иначе расширить
	else {
		tail->next = temp;
		tail = temp;
	}
}

//печать списка
void My_list::print() {
	//если список пустой
	if (this->is_empty())
		return;
	//пока элемент существует, выводить
	Node* curr = this->head;
	while (curr != nullptr) {
		cout << curr->value << " ";
		curr = curr->next;
	}
	cout << '\n';
}

//поиск узла по значению
Node* My_list::find(int val) {
	Node* curr = this->head;
	while (true) {
		//если ничего не нашли
		if (curr == nullptr) {
			return nullptr;
		}
		//если нашли узел
		else if (curr->value == val) {
			return curr;
		}
		//продолжаем идти дальше
		else
			curr = curr->next;
	}
}

//удалить первый узел
void My_list::remove_head() {
	//если пуст - ошибка
	if (this->is_empty())
		throw "error";
	//иначе следующий узел - новая голова, предыдущий удалить
	else {
		Node* new_h = this->head->next;
		this->head = nullptr;
		this->head = new_h;
	}
}

//удалить последний узел
void My_list::remove_tail() {
	//если пуст - ошибка
	if (this->is_empty())
		throw "error";
	//если состоит из 1 узла - удалить его 
	else if (this->head == this->tail)
		this->remove_head(); 
	// иначе, идя от головы, найти предпоследний хвост - новый хвост, последний удалить 
	else {
		Node* new_t = this->head;
		while (new_t->next != this->tail) {
			new_t = new_t->next;
		}
		this->tail = nullptr;
		new_t->next = nullptr;
		this->tail = new_t;
	}
}



