#pragma once
#ifndef _SYSTEMFUNCTIONS_H
#define _SYSTEMFUNCTIONS_H

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define Max 1000  
const int REPEAT_NUM = 10;  // Number of repeats

struct Person {
	string m_Name;
	char m_Sex;
	int m_Age;
	string m_Phone;
	string m_Address;
};


struct AddressBooks {
	Person personArray[Max];
	int m_size = 0;
};

// Mnue.cpp
void controlMenue();
void showMnue();

void addPerson(AddressBooks& abs);
void showPerson(AddressBooks& abs);

int isExist(AddressBooks& abs, string name);
void deletePerson(AddressBooks& abs);

void findPerson(AddressBooks& abs);
void modifyPerson(AddressBooks& abs);
void clearPerson(AddressBooks& abs);
void ExitMnue(char& exist_flag);

#endif