#include "String.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

//Default Constructor
String::String()
{
	std::cout << "Default Constructor" << std::endl;
}

//Overloaded Constructor
String::String(char* data)
{
	m_length = strlen(data);
	m_data = new char[m_length + 1];
	strcpy_s(m_data, m_length + 1, data);

	std::cout << "Overloaded Constructor" << std::endl;
}

//Destructor
String::~String()
{
	delete m_data;

	std::cout << "Destructor" << std::endl;
}

//Copy
String::String(const String& other)
{
	m_length = other.m_length;
	m_data = new char[m_length + 1];
	strcpy_s(m_data, m_length + 1, other.m_data);

	std::cout << "Copy Constructor" << std::endl;
}

//Move
String::String(String&& other)
{
	m_length = other.m_length;
	m_data = other.m_data;
	other.m_length = 0;
	other.m_data = nullptr;

	std::cout << "Move Constructor" << std::endl;
}

//Copy assignment
String& String::operator= (const String& other)
{
	std::cout << "Copy Assign Opperator" << std::endl;

	m_length = other.m_length;
	strcpy_s(m_data, m_length + 1, other.m_data);

	return *this;
}

//Move assignment
String& String::operator= (String&& other)
{
	std::cout << "Move Assign Opperator" << std::endl;

	m_length = other.m_length;
	m_data = other.m_data;
	other.m_length = 0;
	other.m_data = nullptr;

	return *this;
}