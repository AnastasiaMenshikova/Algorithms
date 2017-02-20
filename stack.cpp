#include "stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
	top = NULL;
}

Stack::~Stack()
{
	Clear();
}

void Stack::push(int a)		// Функция добавления элемента в вершину стека
{ 
	node* pv = new node();	//выделяем место в ячейке памяти 
	pv->value = a;			//записываем значение в информационное поле
	pv->next = top;			//меняем указатель вершины
	top = pv;				//определение новой вершины
}

int Stack::pop()			// Функция удаления элемента из вершины стека, возвращает целочисленное значение
{ 
	node* pv = new node();	//выделяем место в ячейке памяти 
	pv = top;				//присваиваем pv указатель на вершину стека
	if (Stack::IsEmpty())	//Если стек пуст
	{
		return NULL;		//возвращаем 0, т.к. нечего удалять
	}
	else
	{
		int a;				//в переменную запишем значение удаленного элемента из вершины стека
		a = pv->value;
		pv = top; // возможно лишняя строчка
		top = pv->next;		//меняем указатель на вершину стека
		delete pv;			//удаляем элемент из стека
		return a;			//возвращаем значение удалённого элемента стека
	}
}

bool Stack::Search(int key)	//Функция поиска элемента из стека по ключу
{
	node *pv = new node();	//выделяем место в ячейке памяти 
	pv = top;				//присваиваем pv указатель на вершину стека
	while (pv)				// проходим по стеку пока вершина не ноль
	{
		if (pv->value == key)//если значение совпадает с ключом, возвращаем true, иначе false
		{
			return true;
		}
		pv = pv->next;		//меняем указатель, тем самым проходим по стеку
	}
	return false;
}

void Stack::Del() 
{ 
	node* pv = new node();	//выделяем место в ячейке памяти 
	pv = top;				//присваиваем pv указатель на вершину стека
	top = pv->next;			//меняем указатель вершины
	delete pv;				//удаляем элемент
}

void Stack::RandPush(int kol, int range) 
{
	int random, i = 0;
	node* elem = new node();
	srand(time(NULL));
	while (i != kol)
	{
		random = rand() % range;
		push(random);
		i++;
	}
}

void Stack::Clear()	//Функция очистки стека
{
	while (top)		// пока указатель на вершину не ноль 
	{
		Del();		//удаляем элементы из стека
	}
}

Stack::iterater Stack::getTop()	//Возвращает указатель на вершину стека
{ 
	return top;
}

Stack::iterater Stack::getNext(iterater a)	//Возвращает указатель на следующий элемент
{ 
	if (Stack::IsEmpty()) 
	{
		return NULL;
	}
	return a->next;
}

int Stack::getInf(iterater a)	//Возвращает значение элемента стека или 0, если стек пуст
{
	if (Stack::IsEmpty()) 
	{
		return NULL;
	}
	return a->value;
}

bool Stack::IsEmpty() //Возращает false, если стек пуст и true, если стек заполнен хотя бы одним элементом
{ 
	if (top)
		return false;
	else true;
}

void menu()
{
	int mn, data, range, kol, error; // data - информационное поле
	Stack a;
	Stack::iterater iter;

	setlocale(LC_ALL, "Russian");
	do
	{
		cout << "Выберите пункт меню:" << endl;
		cout << "1)Добавить элемент в стек" << endl;
		cout << "2)Добавить рандомный(ые) элемент(ы)" << endl << endl;
		cout << "3)Удалить элемент из стека" << endl;
		cout << "4)Очистить стек" << endl << endl;
		cout << "5)Поиск элемента в стеке" << endl << endl;
		cout << "6)Просмотр элементов стека" << endl << endl;
		cout << "7)Уничтожить стек" << endl << endl;
		cout << "Нажмите 0 для выхода из программы" << endl;
		cin >> mn;
		switch (mn)
		{
		case 1:
		{
			system("cls");
			cout << "Введите число в стек:" << endl;
			cin >> data;
			if (isEmpty() == 0)
			{
				top = first(data);
				system("cls");
			}
			else
			{
				push(&top, data);
				system("cls");
			}
			break;
		}
		case 2:
		{

		}


		case 3:
		{
			system("cls");
			if (isEmpty(top) == NULL)
			{
				system("cls");
				cout << "Элементов в стеке нет" << endl;

			}
			else
			{
				pop(&top);
				system("cls");
				cout << "Элемент был успешно удалён" << endl;

			}
			break;


		}
		case 4:
		{
		}

		case 5
		{
		}

		case 6
		{
			system("cls");
			if (isEmpty(top) == 0)
			{
				system("cls");
				cout << "Элементов в стеке нет" << endl;

			}
			else
			{
				cout << "Элемент был успешно удалён" << endl;
			}
			system("cls");
			break;
		}

		case 7
		{
		}

		}
		if (mn<0 || mn>7)
			system("cls");
	} while (mn != 0);
}
