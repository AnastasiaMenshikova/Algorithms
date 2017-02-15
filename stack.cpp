#include "stack.h"
#include <iostream>

using namespace std;

void menu()
{
	int a, mn;
	Stack::iterater iter;


	setlocale(LC_ALL, "Russian");
	do
	{
		cout << "Выберите пункт из меню:" << endl;

		cout << "1)Добавить элемент в стек" << endl;
		cout << "2)Удалить элемент из стека" << endl;
		cout << "3)Печать стека" << endl << endl;
		cout << "Нажмите 0 для выхода из программы" << endl;
		cin >> mn;
		switch (mn)
		{
		case 1:
		{
			cout << "Введите число в стек:" << endl;
			cin >> a;
			if (isEmpty(top) == 0)
			{
				top = first(a);
				system("cls");
			}
			else
			{
				push(&top, a);
				system("cls");
			}
			break;
		}
		case 2:
		{
			if (isEmpty(top) == NULL)
			{
				system("cls");
				cout << "Элементов в стеке нет" << endl;
				cout << endl;
				cout << endl;
				cout << endl;
			}
			else
			{
				pop(&top);
				system("cls");
				cout << endl;
				cout << endl;
				cout << endl;
			}
			break;


		}


		case 3:
		{
			if (isEmpty(top) == 0)
			{
				system("cls");
				cout << "Элементов в стеке нет" << endl;
				cout << endl;
				cout << endl;
				cout << endl;
			}
			else
			{
				system("cls");
				print(&top);
				cout << endl;
				cout << endl;
				cout << endl;
			}
			break;
		}
		}
		if (mn<0 || mn>3)
			system("cls");
	} while (mn != 0);
}

Stack::Stack()
{
	top = NULL; 
	value = 0;
}

Stack::~Stack(){}

int Stack::push(int)
{
	node *pv = new node;//выделяем место в ячейке памяти 
	pv->value = value;  //записываем значение в информационное поле
	pv->next = *top;    //меняем указатель на предыдущий элемент
	*top = pv;
}

int Stack::pop()
{
	node *pv = *top; //выделяем место в ячейке памяти 
	*top = (*top)->next; // определение новой вершины
	delete pv; //освобождение памяти 
}

bool Stack::Search(int key)
{
	node *pv = *top; //выделяем место в ячейке памяти и присваиваем ему указатель на начало списка
	while (pv)
	{
		if (pv->value == value) //если значение в стеке совпало с введённым, прерываем цикл
		{
			return true;
		}
		pv = pv->next;
	}
	return false;
}

void Stack::Del()
{
	node *pv = *top; //выделяем место в ячейке памяти 
	*top = (*top)->next; // определение новой вершины
	delete pv; //освобождение памяти 
}

void Stack::Clear()
{
	node *pv = *top; //выделяем место в ячейке памяти и присваиваем ему указатель на начало списка
	while (pv)
	{
		pv = pv->next;
		delete pv;
	}
}

void Stack::RandPush(int kol, int range)
{


}


Stack::iterater Stack::getTop() //Получение вершины 
{
	return Top;
}

int Stack::getInf(iterater a)
{
	if (Stack::IsEmpty())
	{
		return false;
	}
	return a->info;
}

Stack::iterater Stack::getNext(iterater a)	//Получение следующего элемента 
{
	if (Stack::Isempty()){
		a->next = NULL;
		return a->next;
	}
	return a->next;
}

bool isEmpty(node *top) //возращает false, если стек пуст и true, если стек заполнен хотя бы одним элементом
{
	if (top == NULL)
		return false;
	else
		return true;
}


