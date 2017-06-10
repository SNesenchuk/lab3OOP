#include <exception>

using namespace std;

class input_char_exception : public exception
{
public:
	input_char_exception(char *s) : exception(s){}
};
class input_int_exception : public exception
{
public:
	input_int_exception(char *s) : exception(s){}
};
class blank_name_exception : public input_char_exception
{
public: blank_name_exception(char *s) : input_char_exception(s){}
};
class name_length_exception : public input_char_exception
{
public:
	name_length_exception(char *s) : input_char_exception(s){}
};

class sorting_exception : public exception
{
public:
	sorting_exception(char *s) : exception(s){}
};