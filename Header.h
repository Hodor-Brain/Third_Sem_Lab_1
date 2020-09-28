#pragma once
#include <iostream>
#include <conio.h>
#include <sstream>
#include <string>
#include <vector>

void flush()
{
	std::cin.clear(); 
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int menu()
{
	int key = 0;
	int code;

	do
	{
		system("cls");

		key = (key + 5) % 5;

		std::cout << "Choose the type of value to work with : " << std::endl << std::endl;

		if (key == 0) std::cout << "-> Int" << std::endl;
		else  std::cout << "   Int" << std::endl;

		if (key == 1) std::cout << "-> Double" << std::endl;
		else  std::cout << "   Double" << std::endl;

		if (key == 2) std::cout << "-> String" << std::endl;
		else  std::cout << "   String" << std::endl;

		if (key == 3) std::cout << "-> My class" << std::endl << std::endl;
		else  std::cout << "   My class" << std::endl << std::endl;

		if (key == 4) std::cout << "-> Exit" << std::endl;
		else  std::cout << "   Exit" << std::endl;

		code = _getch();

		if (code == 224)
		{
			code = _getch();

			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

int menu1()
{
	int key = 0;
	int code;

	do
	{
		system("cls");

		key = (key + 2) % 2;

		std::cout << "Fill the list by : " << std::endl << std::endl;

		if (key == 0) std::cout << "-> Random function" << std::endl;
		else  std::cout << "   Random function" << std::endl;

		if (key == 1) std::cout << "-> Insertion by keyboard" << std::endl;
		else  std::cout << "   Insertion by keyboard" << std::endl;

		code = _getch();

		if (code == 224)
		{
			code = _getch();

			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

int sort_menu()
{
	int key = 0;
	int code;

	do
	{
		system("cls");

		key = (key + 4) % 4;

		std::cout << "Choose any type of sort : " << std::endl << std::endl;

		if (key == 0) std::cout << "-> Insert sort" << std::endl;
		else  std::cout << "   Insert sort" << std::endl;

		if (key == 1) std::cout << "-> Quick sort" << std::endl;
		else  std::cout << "   Quick sort" << std::endl;

		if (key == 2) std::cout << "-> Merge sort" << std::endl;
		else  std::cout << "   Merge sort" << std::endl;

		if (key == 3) std::cout << "-> Bubble sort" << std::endl;
		else  std::cout << "   Bubble sort" << std::endl;

		code = _getch();

		if (code == 224)
		{
			code = _getch();

			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

int decr_incr_menu()
{
	int key = 0;
	int code;

	do
	{
		system("cls");

		key = (key + 2) % 2;

		if (key == 0) std::cout << "-> Increasing sort" << std::endl;
		else  std::cout << "   Increasing sort" << std::endl;

		if (key == 1) std::cout << "-> Decressive sort" << std::endl;
		else  std::cout << "   Decressive sort" << std::endl;

		code = _getch();

		if (code == 224)
		{
			code = _getch();

			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

template <typename T>
struct Node 
{
	T value;

	Node<T>* prev;
	Node<T>* next;

	int key;

	Node(T value, Node<T>* prev = nullptr, Node<T>* next = nullptr, int key = -1)
	{
		this->value = value;
		this->prev = prev;
		this->next = next;
		this->key = key;
	}

	Node() {}
	~Node() {}
};

template <typename T>
class Doubly_Linked_List 
{
private:

	Node<T>* begin;
	Node<T>* end;

	std::size_t count;

public:

	Doubly_Linked_List()
	{
		this->begin = nullptr;
		this->end = nullptr;
		this->count = 0;
	}

	~Doubly_Linked_List() 
	{
		this->clear();
	}

	Node<T>* get_end() 
	{
		return this->end;
	}

	Node<T>* get_beg() 
	{
		return this->begin;
	}

	void addLast(T value) 
	{
		Node<T>* new_node = new Node<T>{ value };

		if (begin == nullptr) 
		{
			end = new_node;
			begin = new_node;
			new_node->key = 0;
		}
		else 
		{
			new_node->prev = end;
			new_node->key = new_node->prev->key + 1;

			end->next = new_node;
			end = new_node;
		}
		count++;
	}

	void clear() 
	{
		Node<T>* current = begin;

		while (current) 
		{
			Node<T>* to_delete = current;
			current = current->next;
			delete to_delete;
		}

		begin = end = nullptr;
		count = 0;
	}

	std::size_t size() 
	{
		return count;
	}

	/*int operator[](std::size_t index) 
	{
		Node<T>* current = begin;
		std::size_t i = 0;
		while (current) 
		{
			if (i == index) 
			{
				return current->value;
			}

			current = current->next;
			i++;
		throw std::out_of_range{ "Ind " + std::to_string(index) + " larger than list size = " + std::to_string(size) };
		}
	}*/

	friend std::ostream& operator<<(std::ostream& out, const Doubly_Linked_List<T>& list) 
	{
		Node<T>* current = list.begin;
		out << "[";
		while (current) 
		{
			if (current != list.begin)
				out << " ";
			out << current->value;
			current = current->next;
		}
		out << "]";
		return out;
	}

	Node<T>* find_by_iter(int iter) 
	{
		Node<T>* cur = begin;
		while (cur) 
		{
			if (cur->key == iter)
				break;
			cur = cur->next;
		}
		return cur;
	}

	Node<T>* find_by_value(T val) 
	{
		Node<T>* cur = begin;
		while (cur) 
		{
			if (cur->value == val)
				break;
			cur = cur->next;
		}
		return cur;
	}

	bool RemoveLast() 
	{
		if (begin == nullptr) 
		{
			std::cout << "There are no elements!" << std::endl << std::endl;
			return false;
		}
		else 
		{
			Node<T>* cur = end;
			end = (end)->prev;
			(end)->next = nullptr;
			delete cur;
			std::cout << "Successful!" << std::endl;
			return true;
		}

	}

	void Insert_from_kb()
	{
		while (true)
		{
			T val;

			std::string a;

			std::cout << "Current type of value: " << typeid(val).name() << std::endl << std::endl;
			std::cout << "Enter the value (to stop adding type 'end'): ";

			std::stringstream ss;

			std::getline(std::cin, a);

			ss.str(a.c_str());

			if (ss.str() == "end")
			{
				system("cls");
				break;
			}

			ss >> val;

			if (ss.fail())
			{
				ss.clear();

				system("cls");
				std::cout << "You can't enter different types of values!" << std::endl;
				system("pause");
				system("cls");
				continue;
			}

			system("cls");

			this->addLast(val);
		}
	}
};

template<typename T>
void QuickSort(Doubly_Linked_List<T>* a, int length, int L, int R, bool isDecr) 
{
	int i = L, j = R;
	int mid = (R + L) / 2;

	T first = a->find_by_iter(mid)->value;
	T sec;

	if (isDecr) 
	{
		do 
		{
			while (a->find_by_iter(i)->value > first)
				i++;

			while (first > a->find_by_iter(j)->value)
				j--;

			if (i <= j) 
			{
				sec = a->find_by_iter(i)->value;
				a->find_by_iter(i)->value = a->find_by_iter(j)->value;
				a->find_by_iter(j)->value = sec;

				i++;
				j--;
			}
		} while (i < j);
	}
	else 
	{
		do 
		{
			while (a->find_by_iter(i)->value < first)
				i++;

			while (first < a->find_by_iter(j)->value)
				j--;

			if (i <= j) 
			{
				sec = a->find_by_iter(i)->value;
				a->find_by_iter(i)->value = a->find_by_iter(j)->value;
				a->find_by_iter(j)->value = sec;

				i++;
				j--;
			}
		} while (i < j);
	}

	if (L < j)
		QuickSort(a, length, L, j, isDecr);

	if (i < R)
		QuickSort(a, length, i, R, isDecr);
}

template<typename T>
void BubbleSort(Doubly_Linked_List<T>* a, int size, bool isDecr) 
{
	T x;
	int i, j;
	if (isDecr) 
	{
		for (i = 0; i < size; i++) 
		{
			for (j = size - 1; j > i; j--) 
			{
				if (a->find_by_iter(j - 1)->value < a->find_by_iter(j)->value) 
				{
					x = a->find_by_iter(j - 1)->value;
					a->find_by_iter(j - 1)->value = a->find_by_iter(j)->value;
					a->find_by_iter(j)->value = x;
				}
			}
		}
	}
	else 
	{
		for (i = 0; i < size; i++) 
		{
			for (j = size - 1; j > i; j--) 
			{
				if (a->find_by_iter(j - 1)->value > a->find_by_iter(j)->value) 
				{
					x = a->find_by_iter(j - 1)->value;
					a->find_by_iter(j - 1)->value = a->find_by_iter(j)->value;
					a->find_by_iter(j)->value = x;
				}
			}
		}
	}
}

template<typename T>
void InsertSort(Doubly_Linked_List<T>* a, int size, bool isDecr) 
{
	T x;
	int i, j;
	if (isDecr) 
	{
		for (i = 0; i < size; ++i) 
		{
			x = a->find_by_iter(i)->value;
			for (j = i - 1; j >= 0 && a->find_by_iter(j)->value < x; j--)
				a->find_by_iter(j + 1)->value = a->find_by_iter(j)->value;
			a->find_by_iter(j + 1)->value = x;
		}
	}
	else 
	{
		for (i = 0; i < size; ++i) 
		{
			x = a->find_by_iter(i)->value;
			for (j = i - 1; j >= 0 && a->find_by_iter(j)->value > x; j--)
				a->find_by_iter(j + 1)->value = a->find_by_iter(j)->value;
			a->find_by_iter(j + 1)->value = x;
		}
	}
}

template<typename T>
void MergeSort(int l, int r, int length, Doubly_Linked_List<T>* a, bool isDecr)
{
	if (r == l)
		return;

	if (r - l == 1) 
	{
		if (isDecr)
		{
			if (a->find_by_iter(r)->value > a->find_by_iter(l)->value)
			{
				T temp = a->find_by_iter(r)->value;
				a->find_by_iter(r)->value = a->find_by_iter(l)->value;
				a->find_by_iter(l)->value = temp;
			}
		}
		else
		{
			if (a->find_by_iter(r)->value < a->find_by_iter(l)->value)
			{
				T temp = a->find_by_iter(r)->value;
				a->find_by_iter(r)->value = a->find_by_iter(l)->value;
				a->find_by_iter(l)->value = temp;
			}
		}
		return;
	}

	int m = (r + l) / 2;


	MergeSort(l, m, length, a, isDecr);

	MergeSort(m + 1, r, length, a, isDecr);

	Doubly_Linked_List<T>* buf = new Doubly_Linked_List<T>;
	while (buf->size() < length) 
	{
		buf->addLast(0);
	}

	int xl = l;
	int xr = m + 1;
	int cur = 0;

	while (r - l + 1 != cur)
	{
		if (isDecr)
		{
			if (xl > m)
				buf->find_by_iter(cur++)->value = a->find_by_iter(xr++)->value;

			else if (xr > r)
				buf->find_by_iter(cur++)->value = a->find_by_iter(xl++)->value;

			else if (a->find_by_iter(xl)->value < a->find_by_iter(xr)->value)
				buf->find_by_iter(cur++)->value = a->find_by_iter(xr++)->value;

			else
				buf->find_by_iter(cur++)->value = a->find_by_iter(xl++)->value;
		}
		else
		{
			if (xl > m)
				buf->find_by_iter(cur++)->value = a->find_by_iter(xr++)->value;

			else if (xr > r)
				buf->find_by_iter(cur++)->value = a->find_by_iter(xl++)->value;

			else if (a->find_by_iter(xl)->value > a->find_by_iter(xr)->value)
				buf->find_by_iter(cur++)->value = a->find_by_iter(xr++)->value;

			else
				buf->find_by_iter(cur++)->value = a->find_by_iter(xl++)->value;
		}
	}
	for (int i = 0; i < cur; i++)
		a->find_by_iter(i + l)->value = buf->find_by_iter(i)->value;

}

template<typename T>
void ShellSort(Doubly_Linked_List<T>* a, int length, bool isDecr)
{
	for (int d = length / 2; d >= 1; d /= 2)
	{
		for (int i = d; i < length; i++)
		{
			if (isDecr)
			{
				for (int j = i; j >= d && a->find_by_iter(j - d)->value < a->find_by_iter(j)->value; j -= d)
				{
					swap(a->find_by_iter(j)->value, a->find_by_iter(j - d)->value);
				}
			}
			else
			{
				for (int j = i; j >= d && a->find_by_iter(j - d)->value > a->find_by_iter(j)->value; j -= d)
				{
					swap(a->find_by_iter(j)->value, a->find_by_iter(j - d)->value);
				}
			}
		}
	}
}

template<typename T>
void ChooseSort(Doubly_Linked_List<T>* a)
{
	int ans = -1;

	while (ans != 0 && ans != 1 && ans != 2 && ans != 3)
	{
		ans = sort_menu();

		switch (ans)
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default: 
			break;
		}
	}
}

void IntMain()
{
	auto DLL = new Doubly_Linked_List <int>;

	int ans = -1;

	while (/*ans != 0 &&*/ ans != 1)
	{
		ans = menu1();

		switch (ans)
		{
		case 0:
			break;
		case 1:

			DLL->Insert_from_kb();
			std::cout << *DLL << std::endl;

			break;
		default:
			break;
		}
	}

	system("pause");

	ans = -1;
	int temp = -1;

	while (ans != 0 && ans != 1 && ans != 2 && ans != 3)
	{
		ans = sort_menu();
		temp = decr_incr_menu();

		switch (ans)
		{
		case 0:

			if (temp == 0)
			{
				InsertSort<int>(DLL, DLL->size(), 0);
			}
			else
			{
				InsertSort<int>(DLL, DLL->size(), 1);
			}

			break;
		case 1:

			if (temp == 0)
			{
				QuickSort<int>(DLL, DLL->size(), 0, DLL->size() - 1, 0);
			}
			else
			{
				QuickSort<int>(DLL, DLL->size(), 0, DLL->size() - 1, 1);
			}

			break;
		case 2:

			if (temp == 0)
			{
				MergeSort<int>(0, DLL->size() - 1, DLL->size(), DLL, 0);
			}
			else
			{
				MergeSort<int>(0, DLL->size() - 1, DLL->size(), DLL, 1);
			}

			break;
		case 3:

			if (temp == 0)
			{
				BubbleSort<int>(DLL, DLL->size(), 0);
			}
			else
			{
				BubbleSort<int>(DLL, DLL->size(), 1);
			}

			break;
		default:
			break;
		}
	}

	std::cout << *DLL << std::endl;

	system("pause");

	delete DLL;
}