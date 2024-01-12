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

//�������� ������� �����
bool My_list::is_empty() {
	return head == nullptr;
}

//���������� � ����� ������
void My_list::append(int val) {
	Node* temp = new Node(val);

	//���� ������ ������
	if (this->is_empty()) {
		head = temp;
		tail = temp;
	}
	//����� ���������
	else {
		tail->next = temp;
		tail = temp;
	}
}

//������ ������
void My_list::print() {
	//���� ������ ������
	if (this->is_empty())
		return;
	//���� ������� ����������, ��������
	Node* curr = this->head;
	while (curr != nullptr) {
		cout << curr->value << " ";
		curr = curr->next;
	}
	cout << '\n';
}

//����� ���� �� ��������
Node* My_list::find(int val) {
	Node* curr = this->head;
	while (true) {
		//���� ������ �� �����
		if (curr == nullptr) {
			return nullptr;
		}
		//���� ����� ����
		else if (curr->value == val) {
			return curr;
		}
		//���������� ���� ������
		else
			curr = curr->next;
	}
}

//������� ������ ����
void My_list::remove_head() {
	//���� ���� - ������
	if (this->is_empty())
		throw "error";
	//����� ��������� ���� - ����� ������, ���������� �������
	else {
		Node* new_h = this->head->next;
		this->head = nullptr;
		this->head = new_h;
	}
}

//������� ��������� ����
void My_list::remove_tail() {
	//���� ���� - ������
	if (this->is_empty())
		throw "error";
	//���� ������� �� 1 ���� - ������� ��� 
	else if (this->head == this->tail)
		this->remove_head(); 
	// �����, ��� �� ������, ����� ������������� ����� - ����� �����, ��������� ������� 
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



