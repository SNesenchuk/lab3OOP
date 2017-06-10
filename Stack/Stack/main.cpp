#include <iostream>
#include "Class Exam.h"
#include "Exceptions.h"

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void SetColor(ConsoleColor text, ConsoleColor background)
{
	SetConsoleTextAttribute(hConsole, (WORD)((background << 4) | text));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

void menu_items()
{

	cout << " \t\t\t\t Menu:" << endl;
	cout << "1) Add information" << endl;
	cout << "2) Show information" << endl;
	cout << "3) Delete information" << endl;
	cout << "4) Searching" << endl;
	cout << "5) Sorting" << endl;
	cout << "6) Getting the top of the stack" << endl;
	cout << "7) Exit" << endl;
}

void menu()
{
	Stack stack;
	char choice = NULL;
	while (choice != '7')
	{
		system("cls");
		menu_items();
		choice = _getch();
		switch (choice)
		{
		case '1':
		{
					system("cls");
					Exam object;
					cin >> object;
					stack.push(object);
					break;
		}
		case '2':
		{
					system("cls");
					Exam object;
					object.show();
					stack.print();
					_getch();
					break;
		}
		case '3':
		{
					system("cls");
					stack.pop();
					_getch();
					break;
		}
		case '4':
		{
					system("cls");
					string surname;
					cout << "Enter a surname of the student to find an information about him: ";
					cin >> surname;
					Exam object;
					object.show();
					stack.find(surname);
					_getch();
					break;
		}
		case '5':
		{
					system("cls");
					Exam object;
					if (stack.sorting() != NULL)
					{
						object.show();
						stack.print();
					}
					cout << endl << endl;
					_getch();
					break;
		}
		case '6':
		{
					system("cls");
					cout << "Top of the stack:" << endl;
					Exam object = stack.top();
					cout << object;
					_getch();
					break;
		}
		case '7':
		{
					break;
		}
		}
	}
}

void main()
{
	setlocale(LC_CTYPE, "Rus");
	SetColor(White, Magenta);
	menu();
	_getch();
}