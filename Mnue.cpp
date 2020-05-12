#include "SystemFunctions.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::ios;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void controlMenue() {
    showMnue();

    AddressBooks abs;
    abs.m_size = 0;

    int choice = 0;
    char exist_flag = 'n';

    while ('n' == exist_flag) {

        cout << "(current location: page one)The serial number you entered is: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addPerson(abs);
            break;
        case 2:
            showPerson(abs);
            break;
        case 3:
            deletePerson(abs);
            break;
        case 4:
            findPerson(abs);
            break;
        case 5:
            modifyPerson(abs);
            break;
        case 6:
            clearPerson(abs);
            break;
        case 7:
            ExitMnue(exist_flag);
            break;
        default:
            break;
        }
    }

}
void showMnue() {
    cout << endl
        << "*********************************************************" << endl
        << "*     Welcome to the address book management system     *" << endl
        << "*                      page one                         *" << endl
        << "* Please select the following operation sequence number *" << endl
        << "*                  1.Add Contacts                       *" << endl
        << "*                  2.Show contacts                      *" << endl
        << "*                  3.Delete Contact                     *" << endl
        << "*                  4.find contact                       *" << endl
        << "*                  5.Modify contact                     *" << endl
        << "*                  6.Empty contacts                     *" << endl
        << "*                  7.Exit the system                    *" << endl
        << "*********************************************************" << endl << endl;
}

void addPerson(AddressBooks& abs) {

    if (Max == abs.m_size) {  // [1, Max]
        cout << "Address book is full." << endl;
        return;
    }

    Person p;
    string name;
    char sex;
    int age;
    string phoneNumber;
    string address;

    cout << "Please enter information about the contact you want to add." << endl
        << "(Including: name, gender (male m, female f), age, telephone number, address)" << endl;

    cout << "name: ";  cin >> p.m_Name;

    cout << "sex: ";
    do {
        cin >> p.m_Sex;
        if ('f' != p.m_Sex && 'm' != p.m_Sex)
            cout << "Input error, male input m, female input f, please input again: ";

    } while (p.m_Sex != 'f' && p.m_Sex != 'm');

    cout << "age: ";
    do {
        cin >> p.m_Age;
        if (p.m_Age < 0 || p.m_Age > 150)
            cout << "The age input is illegal. Please enter the correct age: ";
    } while (p.m_Age < 0 || p.m_Age > 150);

    cout << "telephone number: ";
    do {
        cin >> p.m_Phone;
        if (p.m_Phone.length() != 11 && p.m_Phone.length() != 7)
            cout << "The format of the phone number is incorrect. Please enter 11 digit mobile number or 7 digit phone number: ";

    } while (p.m_Phone.length() != 11 && p.m_Phone.length() != 7);

    cout << "address: ";
    cin >> p.m_Address;

    abs.personArray[++abs.m_size] = p;

    cout << endl << "Successfully added!" << endl << "The new contact information is: " << endl
        << "name: " << abs.personArray[abs.m_size].m_Name << endl
        << "sex: " << abs.personArray[abs.m_size].m_Sex << endl
        << "age: " << abs.personArray[abs.m_size].m_Age << endl
        << "telephone number: " << abs.personArray[abs.m_size].m_Phone << endl
        << "address: " << abs.personArray[abs.m_size].m_Address << endl
        << "The current number of contacts is: " << abs.m_size << endl;

}
void showPerson(AddressBooks& abs) {

    if (abs.m_size <= 0) {
        cout << "This address book is empty!" << endl;
        return;
    }

    // cout << "abs.size = " << abs.m_size << endl << endl;

    for (int i = 1; i <= abs.m_size; ++i) {
        cout << "name: " << abs.personArray[i].m_Name << endl
            << "sex: " << abs.personArray[i].m_Sex << endl
            << "age: " << abs.personArray[i].m_Age << endl
            << "phone_number: " << abs.personArray[i].m_Phone << endl
            << "address: " << abs.personArray[i].m_Address << endl << endl;
    }

    cout << "All contacts have been displayed." << endl << endl;
}

int isExist(AddressBooks& abs, string name) {
      
    int ret;  // Record contact subscript

    if (0 >= abs.m_size) {
        cout << "the address book is empty!" << endl;
        ret = -1;
        return ret;
    }
        
    for (int i = 1; i <= abs.m_size; ++i) 
        if (name == abs.personArray[i].m_Name) {
            ret = i;
        }

    return ret;
}
void deletePerson(AddressBooks& abs) {

    string name;
    cout << "Please enter the name of the contact you are looking for: ";
    cin >> name;

    char judge = 'y';

    int ret = isExist(abs, name);
    switch (ret) {
    case 0:
        cout << "The contact was not found." << endl;
        break;
    case -1:
        cout << "No contacts in address book." << endl;
        break;
    default:
        
        cout << "To delete a contact: " << endl
            << "name: " << abs.personArray[ret].m_Name << endl
            << "sex: " << abs.personArray[ret].m_Sex << endl
            << "age: " << abs.personArray[ret].m_Age << endl
            << "telephone number: " << abs.personArray[ret].m_Phone << endl
            << "address: " << abs.personArray[ret].m_Address << endl
            << "Are you sure to delete?(y/n)";

        cin >> judge;

        if ('y' == judge) {
            for (int i = ret + 1; i <= abs.m_size; ++i)
                abs.personArray[i - 1] = abs.personArray[i];
            abs.m_size--;
        }
        else if ('n' == judge)
            cout << "Operation cancelled!" << endl;

        break;
    }
    return;
}

void findPerson(AddressBooks& abs) {  

    if (abs.m_size <= 0) {
        cout << "This address book is empty!" << endl;
        return;
    }
    else {

        string name;
        cout << "Please enter the name of the contact you want to find: ";
        cin >> name;

        int ret = isExist(abs, name);

        switch (ret) {
        case -1:
            cout << "No one!" << endl;
            break;
        case 0:
            cout << "The contact was not found." << endl;
            break;
        default:
            cout << "Contact information: " << endl 
                << "name: " << abs.personArray[ret].m_Name << endl
                << "sex: " << abs.personArray[ret].m_Sex << endl
                << "age: " << abs.personArray[ret].m_Age << endl
                << "telephone number: " << abs.personArray[ret].m_Phone << endl
                << "address: " << abs.personArray[ret].m_Address << endl;
            break;
        }
    }
}
void modifyInfo(Person& p) {

    string ModiName;
    char ModiSex;
    int ModiAge;
    string ModiPhoneNumber;
    string ModiAddress;

    int Serial_number = 0;

    cout << "Contact information: (before modify)" << endl
        << "name: " << p.m_Name << endl
        << "sex: " << p.m_Sex << endl
        << "age: " << p.m_Age << endl
        << "phone number: " << p.m_Phone << endl
        << "address: " << p.m_Address << endl;

    cout << "Please enter the number where you need to change the information: " << endl
        << "(1.name 2.sex 3.age 4.phone number 5.address)" << endl;
    cin >> Serial_number;

    switch (Serial_number) {
    case 1:
        cout << "Please enter the name you changed: ";
        cin >> ModiName;
        p.m_Name = ModiName;
        cout << "修改成功!" << endl;
        break;
    case 2:
        cout << "Please enter the sex you changed: ";
        cin >> ModiSex;
        p.m_Sex = ModiSex;
        cout << "修改成功!" << endl;
        break;
    case 3:
        cout << "Please enter the age you changed: ";
        cin >> ModiAge;
        p.m_Age = ModiAge;
        cout << "修改成功!" << endl;
        break;
    case 4:
        cout << "Please enter the phone number you changed: ";
        cin >> ModiPhoneNumber;
        p.m_Phone = ModiPhoneNumber;
        cout << "修改成功!" << endl;
        break;
    case 5:
        cout << "Please enter the address you changed: ";
        cin >> ModiAddress;
        p.m_Address = ModiAddress;
        cout << "修改成功!" << endl;
        break;
    default:
        cout << "Invalid input!" << endl;
        break;
    }
    cout << "Contact information: (after modify)" << endl
        << "name: " << p.m_Name << endl
        << "sex: " << p.m_Sex << endl
        << "age: " << p.m_Age << endl
        << "phone number: " << p.m_Phone << endl
        << "address: " << p.m_Address << endl;

}
void modifyPerson(AddressBooks& abs) {

    if (abs.m_size <= 0) {
        cout << "This address book is empty!" << endl;
        return;
    }
    else {
        char input_judge = 'n';
        string name;
        cout << "Please enter the contact name to be modified: ";
        cin >> name;

        int ret = isExist(abs, name);  

        switch (ret) {
        case -1:
            cout << "No one!" << endl;
            break;
        case 0:
            cout << "The contact was not found." << endl;
            break;
        default:
            modifyInfo(abs.personArray[ret]);
            break;
        }
    }
}
void clearPerson(AddressBooks& abs) {
    abs.m_size = 0;
}

void ExitMnue(char& exist_flag) {
    exist_flag = 'y';
}