#pragma once

//класс для узла односвязного списка
class Node {
friend class My_list;
private:
	int value;
	Node* next;
public:
	//конструктор с параметром
	Node(int val);
};
 
// класс односвязного списка 
class My_list {
private:
	Node* head;
	Node* tail;
public:
	//конструктор по умолчанию
	My_list();
	//конструктор с параметром
	My_list(int val);
	//функция проверки наличия узлов
	bool is_empty();
	//функция добавления элемента в конец списка
	void append(int val);
	//функция печати списка 
	void print();
	//функция поиска узла по значению 
	Node* find(int val);
	// функция удаления первого узла
	void remove_head();
	//функция удаления последнего узла
	void remove_tail();


};