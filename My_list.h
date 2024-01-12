#pragma once

//����� ��� ���� ������������ ������
class Node {
friend class My_list;
private:
	int value;
	Node* next;
public:
	//����������� � ����������
	Node(int val);
};
 
// ����� ������������ ������ 
class My_list {
private:
	Node* head;
	Node* tail;
public:
	//����������� �� ���������
	My_list();
	//����������� � ����������
	My_list(int val);
	//������� �������� ������� �����
	bool is_empty();
	//������� ���������� �������� � ����� ������
	void append(int val);
	//������� ������ ������ 
	void print();
	//������� ������ ���� �� �������� 
	Node* find(int val);
	// ������� �������� ������� ����
	void remove_head();
	//������� �������� ���������� ����
	void remove_tail();


};