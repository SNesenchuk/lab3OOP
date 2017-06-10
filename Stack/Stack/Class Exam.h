#include <iostream>
#include <locale.h>
#include <iomanip>
#include <string>
#include <sstream>
#include <conio.h>
#include <windows.h>
#include <exception>
using namespace std;


class Exam
{
	string name;
	string surname;
	string name_of_exam;
	int mark;
public:
	Exam();
	Exam(string name, string surname, string name_of_exam, int mark);
	Exam(const Exam &ob);
	friend istream &operator >>(istream &is, Exam &ob);
	friend ostream &operator <<(ostream &os, Exam &ob);
	string get_name();
	Exam operator = (Exam ob);
	void data_Checking(string data);
	void show();
	Exam editing();
	~Exam();
};

class Stack
{
	struct Element
	{
		Exam data_;
		Element *next_;
	};
	Element *first_;
public:
	Stack();
	void push(Exam ob);
	void pop();
	void dellAllStack();
	int find(string value);
	void print();
	int sorting();
	Exam top();
	~Stack();
};

string Test();

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

#define LIMITATION_SYMBOL_ENTRY "You can input only English symbols here"
#define LONG_NAME "Name is too long!"
#define EMPTY_FIELD_IS_NOT_ALLOWED "Epty field is not allowded !"
#define UNKNOWN_ERROR "Unknown Error!"
#define ENTER_NAME_STUDENT "Enter student's name : "
#define ENTER_SURNAME_STUDENT  "Enter student's surname: "
#define ENTER_NAME_EXAM "Enter name of the exam:: "
#define ENTER_MARK "Enter student's mark: "
#define STACK_EMPTY "ÑStack is enpty!"
#define UNKNOWN_ERROR "Unknown Error!"