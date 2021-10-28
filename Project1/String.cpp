#include "String.h"

String::String() {
	len = 0;
	str = NULL;
}
String::String(const char* s) {
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}
String::String(const String& s) {
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}
String& String::operator=(const String& s) {
	if (str != NULL)
		delete[] str;
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
}
String::~String() {
	if (str != NULL)
		delete[] str;
}
String& String::operator+=(const String& s) {
	len += (s.len - 1);
	char* temp = new char[len];
	strcpy(temp, str);
	if (str != NULL)
		delete[] str;
	strcat(temp, s.str);
	str = new char[len];
	str = temp;
	return *this;
}
bool String::operator==(const String& s) {
	if (strcmp(str, s.str) == 0)
		return true;
	else
		return false;
}
String String::operator+(const String& s) {
	len += (s.len - 1);
	char* temp = new char[len];
	strcpy(temp, str);
	strcat(temp, s.str);
	String plusedString(temp);
	delete[] temp;
	return plusedString;
}
ostream& operator<<(ostream& os, const String& s) {
	os << s.str;
	return os;
}
istream& operator>>(istream& is, String& s) {
	char str[100];
	is >> str;
	s = String(str);
	return is;
}