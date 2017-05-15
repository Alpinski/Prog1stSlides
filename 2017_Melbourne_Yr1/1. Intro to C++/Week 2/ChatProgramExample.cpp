#include <iostream>

using namespace std;

void main()
{
	cout << "Hello, what is you name?" << endl;

	char name[32];
	cin >> name;
	cin.clear();
	cin.ignore(999999, '\n');

	cout << "Hello " << name << " how are you?" << endl;

	char response[128];
	cin.getline(response, 128);

	cout << "I'm glad that you are " << response << endl;
	cout << "what is your surname?" << endl;
	
	char surname[32];
	cin >> surname;
	cin.clear();
	cin.ignore(999999, '\n');

	char fullname[128];
	strcpy(fullname, name);
	strcat(fullname, " ");
	strcat(fullname, surname);

	cout << "Your full name is " << fullname << ". Now I know everything about you." << endl;
	cout << "MWAHAHAHAHA!" <<endl;

	system("pause");
}