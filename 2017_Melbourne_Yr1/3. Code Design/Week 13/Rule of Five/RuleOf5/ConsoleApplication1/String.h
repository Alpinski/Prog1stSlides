#pragma once

class String
{
public:
	//default Constructor
	String();

	//Overloaded Constructor
	String(char* data);

	//Destructor
	~String();

	//Copy
	String(const String& other);

	//Move
	String(String&& other);

	//Copy assignment
	String& operator= (const String& other);

	//Move assignment
	String& operator= (String&& other);

private:
	char* m_data;
	int m_length;
};

