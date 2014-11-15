#ifndef __STRING_H__
#define __STRING_H__

#include <string.h>
#include <iostream>
using namespace std;

class String
{
	friend ostream &operator << (ostream&, const String&);
	friend istream &operator >> (istream&, String&);
public:
	String ();
	String (const char *);
	String (const String &);
	~String ();

	String& operator= (const String &);
	String& operator= (const char*);
	String& operator= (const char);
	char operator[] (unsigned int) const;
	char& operator[] (unsigned int);
	//const char at (unsigned int) const;
	String& operator+= (const String &);
	//String& operator+= (const char *);
	//String& operator+= (const char);

	int length () const;
	String& append (const String &);
	char *c_str () const {return data; }
	//String& append (const char *);
private:
	char *data;
	int end;
};

String::String ()
{
	data = new char [1];
	*data = '\0';
}
String::String (const char *str)
{
	data = new char [strlen (str) + 1];
	strcpy (data, str);
}
String::String (const String &str)
{
	data = new char [str.length () + 1];
	strcpy (data, str.data);
}
String& String::append (const String &str)
{
	data = (char *)realloc (data, strlen (data) + str.length () + 1);
	strcat (data, str.data);
	return *this;
}
String& String::operator= (const String &str)
{
	if (&str != this)
	{
		delete []data;
		data = new char[str.length() + 1];
		strcpy (data, str.data);
	}
	return *this;
}
String::~String ()
{
	delete []data;
}
char String::operator[] (unsigned int i) const
{
	return data[i];
}
char& String::operator[] (unsigned int i)
{
	return data[i];
}
int String::length() const
{
	return strlen (data);
}
	
//IO不能重载为成员
ostream &operator << (ostream &os, const String &str)
{
	os<<str.data;
	return os;
}
istream &operator >> (istream &in, String &str)
{
	char tmp[256] = {'\0'};
	in>>tmp;
	delete []str.data;
	str.data = new char [strlen (tmp)+1];
	strcpy (str.data, tmp);
	return in;
}
inline String operator+ (const String &strA, const String &strB)
{
	String tmp;
	tmp.append (strA).append (strB);
	return tmp;

}
String& String::operator+= (const String &str)
{
	return append (str);
}
// Operator== and operator!=
inline bool operator== (const String &strA, const String &strB)
{
	return !(strcmp (strA.c_str (), strB.c_str ()));
}
inline bool operator!= (const String &strA, const String &strB)
{
	return !(strA == strB);
}
// Operator< (and also >, <=, and >=).
inline bool operator< (const String &strA, const String &strB)
{
	return (strcmp (strA.c_str (), strB.c_str ())) < 0;
}
#endif