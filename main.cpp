/*
Author: Alexandra Ontiveros
Compiler: Visual Studio 2019
Date: 24/4/2022
Purpose of program: user inputs account information 
or transaction information from a menu of choices
*/


#include "Date.h"
#include "Account.h"
#include "PremiumAccount.h"
#include "RegularAccount.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

Date stringToDate (string input);

const double PremiumAccount::MIN_BALANCE = 1000;
const int MAX_NUM_ACCOUNTS = 5;
Account * accountArray[MAX_NUM_ACCOUNTS];

int main()
{
    int numAccountsCreated = 0; // counter for number of accounts created
    int choice,                 // menu choice entered by user
        accountNum,             // account number entered by user
        accountNumFound;        // index where account num is found
    string name,            // owner name entered by user
           dateString;      // string entered by user to convert to date
    Date date;     // date returned from stringToDate function
    double amount; // amount for account creation or transaction entered by user
    cout << endl;
    do
    {
        cout << "1-> Create regular account, 2-> Create premium account, 3-> Deposit to account" << endl
            << "4-> Withdraw from account, 5-> Print acount info, 6-> Quit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (numAccountsCreated < MAX_NUM_ACCOUNTS)
            {
                cout << "Enter owner's name: ";
                cin >> name;
                cout << "Enter date, in the mm/dd/yyyy/hh format: ";
                cin >> dateString;
                date = stringToDate(dateString);
                cout << "Enter amount: ";
                cin >> amount;
                if (amount <= 0)
                {
                    cout << "Amount cannot be negative, account creation not executed" << endl << endl;
                    break;
                }
                accountArray[numAccountsCreated] = new RegularAccount(name, amount, date);
                cout << "Account created: " << endl;
                accountArray[numAccountsCreated]->print();
                cout << endl;
                numAccountsCreated++;
            }
            else 
                cout << "Max number of accounts reached, cannot add a new account" << endl << endl;
            break;

        case 2:
            if (numAccountsCreated < MAX_NUM_ACCOUNTS)
            {
                cout << "Enter owner's name: ";
                cin >> name;
                cout << "Enter date, in the mm/dd/yyyy/hh format: ";
                cin >> dateString;
                date = stringToDate(dateString);
                cout << "Enter amount: ";
                cin >> amount;

                if (amount <= 0)
                {
                    cout << "Amount cannot be negative, account creation not executed" << endl << endl;
                    break;
                }

                if (amount < PremiumAccount::getMinBalance())
                {
                    cout << "Insufficient amount, you need at least 1000.00 units to open a premium account" << endl << endl;
                    break;
                }

                accountArray[numAccountsCreated] = new PremiumAccount(name, amount, date);
                cout << "Account created: " << endl;
                accountArray[numAccountsCreated]->print();
                cout << endl;
                numAccountsCreated++;
            }
            else
                cout << "Max number of accounts reached, cannot add a new account" << endl << endl;
            break;

        case 3:
            cout << "Enter account number: ";
            cin >> accountNum;
            accountNumFound = -1;
            for (int i = 0; i < numAccountsCreated; i++)
            {
                if (accountNum == accountArray[i]->getAccountNumber())
                    accountNumFound = i;
            }

            if (accountNumFound < 0)
            {
                cout << "No such account" << endl << endl;
                break;
            }

            cout << "Enter date, in the mm/dd/yyyy/hh format: ";
            cin >> dateString;
            date = stringToDate(dateString);
            cout << "Enter amount: ";
            cin >> amount;

            if (amount < 0)
            {
                cout << "Amount cannot be negative, deposit not executed" << endl << endl;
                break;
            }

            if (accountArray[accountNumFound]->deposit(amount, date))
            {
                cout << "Deposit executed: " << endl;
                accountArray[accountNumFound]->print();
                cout << endl;
            }
            break;

        case 4:
            cout << "Enter account number: ";
            cin >> accountNum;
            accountNumFound = -1;
            for (int i = 0; i < numAccountsCreated; i++)
            {
                if (accountNum == accountArray[i]->getAccountNumber())
                    accountNumFound = i;
            }
            if (accountNumFound < 0)
            {
                cout << "No such account" << endl << endl;
                break;
            }

            cout << "Enter date, in the mm/dd/yyyy/hh format: ";
            cin >> dateString;
            date = stringToDate(dateString);
            cout << "Enter amount: ";
            cin >> amount;
            if (amount < 0)
            {
                cout << "Amount cannot be negative, withdraw not executed" << endl << endl;
                break;
            }
            if (accountArray[accountNumFound]->withdraw(amount, date))
            {
                cout << "Withdraw executed: " << endl;
                accountArray[accountNumFound]->print();
                cout << endl;
            }
            else
            {
                cout << "Insufficient balance, withdrawal not executed" << endl << endl;
            }
            break;

        case 5:
            cout << "Accounts" << endl << "========" << endl << endl;
            for (int i = 0; i < numAccountsCreated; i++)
            {
                accountArray[i]->print();
                cout << endl;
            }
            break;

        case 6:
            return EXIT_SUCCESS;
            break;

        default:
            cout << "Invalid input, please try again" << endl;
            break;
        }
        
    }
    while (choice != 6);
}

/*
takes a string as input and converts it to a Date,
then returns the Date
*/
Date stringToDate(string input)
{
    int month, day, year, hour;
    Date date;
    string number = "";
    for (int i = 0; i < 2; i++)
    {
        number += input[i];
    }
    month = stoi(number);
    number = "";
    for (int i = 3; i < 5; i++)
    {
        number += input[i];
    }
    day = stoi(number);
    number = "";
    for (int i = 6; i < 10; i++)
    {
        number += input[i];
    }
    year = stoi(number);
    number = "";
    for (int i = 11; i < 13; i++)
    {
        number += input[i];
    }
    hour = stoi(number);
    date.set(month, day,year, hour);
    return date;
} // end function stringToDate()