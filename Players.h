#pragma once
#include <iostream>
#include <string>

using namespace std;

class Players
{
public:
	//
	Players(string fName, string lName)
	{
		firstName = fName;
		lastName = lName;
		end = false;
		turn = 1;
	}
	//
	string getLastName()
	{
		return lastName;
	}
	//
	string getFirstName()
	{
		return firstName;
	}
	//
	void setLastName(string name)
	{
		lastName = name;
	}
	//
	void setFirstName(string name)
	{
		firstName = name;
	}
	//
	void displayName()
	{
		string name;
		name = getFirstName();
		cout << name << " ";
		name = getLastName();
		cout << name << " ";
	}
	//
	void setInfo()
	{
		string name;
		cout << "Please enter your first name: ";
		cin >> name;
		firstName = name;
		cout << "Please enter your last name: ";
		cin >> name;
		lastName = name;
	}

	
private:
	string firstName;
	string lastName;
	bool end;
	int turn;
};