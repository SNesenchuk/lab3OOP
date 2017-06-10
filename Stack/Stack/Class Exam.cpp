#include <iostream>
#include "Class Exam.h"
#include "Exceptions.h"

using namespace std;



Exam::Exam()
{
	mark = 0;
}

Exam::Exam(string name, string surname, string name_publishing_house, int pages)
{
	name = name;
	surname = surname;
	name_of_exam = name_publishing_house;
	mark = pages;
}

Exam::Exam(const Exam &ob)
{
	name = ob.name;
	surname = ob.surname;
	name_of_exam = ob.name_of_exam;
	mark = ob.mark;
}

void Exam::data_Checking(string data)
{
	data.c_str();
	for (int i = 0; data[i]; i++)
	{
		if ((data[i] >= 'A' && data[i] <= 'ÿ') || (data[i] >= '0' && data[i] <= '9'))
		{
			if (data[i] != '-')
			{
				throw input_char_exception(LIMITATION_SYMBOL_ENTRY);
			}
		}
		if (i>30) throw name_length_exception(LONG_NAME);
	}
	if (data == " " || data == "") throw blank_name_exception(EMPTY_FIELD_IS_NOT_ALLOWED);
}

istream &operator >> (istream &is, Exam &ob)
{
	cout << ENTER_NAME_STUDENT;
	try{
		getline(is, ob.name);
		ob.data_Checking(ob.name);
	}
	catch (name_length_exception e)
	{
		cout << e.what() << endl;
		cout << ENTER_NAME_STUDENT;
		getline(is, ob.name);
	}
	catch (blank_name_exception e)
	{
		cout << e.what() << endl;
		cout << ENTER_NAME_STUDENT;
		getline(is, ob.name);
	}
	catch (input_char_exception e)
	{
		cout << e.what() << endl;
		cout << ENTER_NAME_STUDENT;
		getline(is, ob.name);
	}
	catch (...)
	{
		cout << UNKNOWN_ERROR << endl;
	}
	cout << ENTER_SURNAME_STUDENT;
	try{
		getline(is, ob.surname);
		ob.data_Checking(ob.surname);
		fflush(stdin);
	}
	catch (name_length_exception e)
	{
		cout << e.what() << endl;
		cout << ENTER_SURNAME_STUDENT;
		getline(is, ob.surname);
	}
	catch (blank_name_exception e)
	{
		cout << e.what() << endl;
		cout << ENTER_SURNAME_STUDENT;
		is >> ob.surname;
	}
	catch (input_char_exception e)
	{
		cout << e.what() << endl;
		cout << ENTER_SURNAME_STUDENT;
		is >> ob.surname;
	}
	catch (...)
	{
		cout << UNKNOWN_ERROR << endl;
	}
	cout << ENTER_NAME_EXAM;
	try{
		fflush(stdin);
		getline(is, ob.name_of_exam);
		ob.data_Checking(ob.name_of_exam);
		fflush(stdin);
	}
	catch (name_length_exception e)
	{
		cout << e.what() << endl;
		cout << ENTER_NAME_EXAM;
		getline(is, ob.name_of_exam);
	}
	catch (blank_name_exception e)
	{
		cout << e.what() << endl;
		cout << ENTER_NAME_EXAM;
		getline(is, ob.name_of_exam);
	}
	catch (input_char_exception e)
	{
		cout << e.what() << endl;
		cout << ENTER_NAME_EXAM;
		getline(is, ob.name_of_exam);
	}
	catch (...)
	{
		cout << UNKNOWN_ERROR << endl;
	}
	char c;
	cout << ENTER_MARK;
	while (1){
		try{
			is >> ob.mark;
			int flags = cin.rdstate();
			if (flags & ios::failbit)
				throw input_int_exception("Incorect input, you need to enter only numbers here");
			break;
		}
		catch (input_int_exception e)
		{
			cout << e.what() << endl;
			is.clear(0);
			is >> c;
		}
		catch (...)
		{
			cout << UNKNOWN_ERROR << endl;
		}
	}
	is.ignore();
	return is;
}

ostream &operator << (ostream &os, Exam &ob)
{
	os << setw(20) << ob.name << " " << setw(20) << ob.surname << setw(20) << ob.name_of_exam << setw(20) << ob.mark;
	return os;
}

string Exam::get_name()
{
	return this->name;
}

Exam Exam::operator = (Exam ob)
{
	if (this != &ob)
	{
		name = ob.name;
		surname = ob.surname;
		name_of_exam = ob.name_of_exam;
		mark = ob.mark;
	}
	return *this;
}

void Exam::show()
{
	cout << "______________________________________________________________________________________" << endl;
	cout << setw(20) << "Student's name" << setw(23) << "Surname" << setw(23) << "Exam" << setw(20) << "Mark" << endl;
	cout << "______________________________________________________________________________________" << endl;
}

Exam Exam::editing()
{
	int ch = 0;
	cout << "Make your choise:\n 1) Student's name\n 2) Surname\n 3) Name of the exam\n 4) Mark\n " << endl;
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
			  cout << ENTER_NAME_STUDENT;
			  try{
				  getline(cin, name);
				  data_Checking(name);
			  }
			  catch (name_length_exception e)
			  {
				  cout << e.what() << endl;
				  cout << ENTER_NAME_STUDENT;
				  getline(cin, name);
			  }
			  catch (blank_name_exception e)
			  {
				  cout << e.what() << endl;
				  cout << ENTER_NAME_STUDENT;
				  getline(cin, name);
			  }
			  catch (input_char_exception e)
			  {
				  cout << e.what() << endl;
				  cout << ENTER_NAME_STUDENT;
				  getline(cin, name);
			  }
			  catch (...)
			  {
				  cout << UNKNOWN_ERROR << endl;
			  }
			  return *this;
			  break;
	}
	case 2:
	{
			  cout << ENTER_SURNAME_STUDENT;
			  try{
				  getline(cin, surname);
				  data_Checking(surname);
				  fflush(stdin);
			  }
			  catch (name_length_exception e)
			  {
				  cout << e.what() << endl;
				  cout << ENTER_SURNAME_STUDENT;
				  getline(cin, surname);
			  }
			  catch (blank_name_exception e)
			  {
				  cout << e.what() << endl;
				  cout << ENTER_SURNAME_STUDENT;
				  cin >> surname;
			  }
			  catch (input_char_exception e)
			  {
				  cout << e.what() << endl;
				  cout << ENTER_SURNAME_STUDENT;
				  cin >> surname;
			  }
			  catch (...)
			  {
				  cout << UNKNOWN_ERROR << endl;
			  }
			  return *this;
			  break;
	}
	case 3:
	{
			  cout << ENTER_NAME_EXAM;
			  try{
				  fflush(stdin);
				  getline(cin, name_of_exam);
				  data_Checking(name_of_exam);
				  fflush(stdin);
			  }
			  catch (name_length_exception e)
			  {
				  cout << e.what() << endl;
				  cout << ENTER_NAME_EXAM;
				  getline(cin, name_of_exam);
			  }
			  catch (blank_name_exception e)
			  {
				  cout << e.what() << endl;
				  cout << ENTER_NAME_EXAM;
				  getline(cin, name_of_exam);
			  }
			  catch (input_char_exception e)
			  {
				  cout << e.what() << endl;
				  cout << ENTER_NAME_EXAM;
				  getline(cin, name_of_exam);
			  }
			  catch (...)
			  {
				  cout << UNKNOWN_ERROR << endl;
			  }
			  return *this;
			  break;
	}
	case 4:
	{
			  cout << "Enter a mark: " << endl;
			  while (!(cin >> mark))
			  {
				  cin.clear();
				  while (cin.get() != '\n');
				  cout << "Incorrect input. Repeat once again" << endl;
				  cout << "Enter a mark: ";
			  }
			  return *this;
			  break;
	}
	default:
	{
			   cout << "Enter the right menu item:" << endl;
			   break;
	}
	}
}

Exam::~Exam()
{};


Stack::Stack()
{
	first_ = NULL;
}

void Stack::push(Exam ob)
{
	Element *p = new Element;
	p->data_ = ob;
	p->next_ = first_;
	first_ = p;
}

void Stack::pop()
{
	Element *p = first_;
	first_ = first_->next_;
	delete p;
	cout << "Element was succesfully deleted!" << endl;
	return;
}

void Stack::dellAllStack()
{
	Element *p;
	while (first_ != NULL)
	{
		p = first_;
		first_ = first_->next_;
		delete p;
	}
	cout << "See you later!" << endl;
}

int Stack::find(string value)
{
	Element *p = first_;
	if (first_ == NULL)
	{
		cout << STACK_EMPTY << endl;
		return 0;
	}
	else
	{
		while (p != NULL)
		{
			if (p->data_.get_name() == value)
			{
				cout << p->data_ << endl;
			}
			p = p->next_;
		}
		return 1;
	}
}

void Stack::print()
{
	Element *p = first_;
	if (first_ == NULL)
	{
		cout << STACK_EMPTY << endl;
		return;
	}
	while (p != NULL)
	{
		cout << p->data_ << endl;
		p = p->next_;
	}
	cout << endl;
}

int Stack::sorting()
{
	Element *p = first_;
	try{
		if (p == NULL)
			throw sorting_exception("Stack is empty. Please, add some information!");
		else
		{
			while (p->next_)
			{
				if (p->data_.get_name() > p->next_->data_.get_name())
				{
					swap(p->data_, p->next_->data_);
					p = p->next_;
					sorting();
				}
				else p = p->next_;
			}
		}
	}
	catch (sorting_exception e)
	{
		cout << e.what() << endl;
		return NULL;
	}
	catch (...)
	{
		cout << "Unknown Error!" << endl;
	}
}

Exam Stack::top()
{
	return first_->data_;
}

Stack::~Stack()
{
	system("cls");
	dellAllStack();
}

