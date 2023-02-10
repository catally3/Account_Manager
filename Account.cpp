#include "Account.h"
#include <iostream>
#include <iomanip>

int Account::numberAccounts = 0;

/*
constructor that initializes the account's member variables 
ownerName and balance. balance_ is the amount deposited when 
the account is created. accountNumber is set to 
(numberAccounts+1000) and numberAccounts is incremented. 
transactionHistory is set to nullptr, numberTransactions set 
to zero. The date_ is only a place holder for the extra 
credit version and not used in the basic version.
*/
Account::Account(string ownerName_, double balance_, Date date_)
{
    ownerName = ownerName_;
    balance = balance_;
    accountNumber = (numberAccounts+1000);
    numberAccounts++;
    transactionHistory = nullptr;
    numberTransactions = 0;
} // end function Account()

/*
virtual member function to withdraw a specified amount from 
the account. The function should first check if there is 
sufficient balance in the account. If the balance is sufficient,
withdrawal is processed and the function returns true. Otherwise
the withdrawal is not made and the function returns false. If 
the withdrawal is made, the withdrawal amount is deducted from 
balance. The date_ is only a place holder for the extra credit 
version and not used in the basic version.
*/
bool Account::withdraw(double amount, Date date_)
{
    if(amount > balance)
        return false;
    else
    {
        balance -= amount;
        return true;
    }
} // end function withdraw()

/*
deposit a specified amount of money to the account. The 
function should first check if the deposit amount is 
positive. If it is positive, deposit is processed and the 
function returns true. Otherwise the deposit is not made and 
the function returns false. If the deposit is made, the 
amount is added to balance. The date_ is only a place holder 
for the extra credit version and not used in the basic version.
*/
bool Account::deposit(double amount, Date date_)
{
    if (amount < 0)
        return false;
    else
    {
        balance += amount;
        return true;
    }
} // end function deposit()

/*
accessor function that returns the account number
*/
int Account::getAccountNumber() const
{
    return accountNumber;
} // end function getAccountNumber()

/*
 accessor function that returns the account balance
*/
double Account::getBalance() const
{
    return balance;
} // end function getBalance()

/*
static member function that returns numberAccounts
*/
int Account::getNumberAccounts()
{
    return numberAccounts;
} // end function getNumberAccounts()

/*
virtual member function that prints accountNumber, 
ownerName, balance. This function is called in a 
few instances in main, including when the user 
chooses "print info for all accounts".
*/
void Account::print() const
{
    cout << "#: " << accountNumber << ", Name: " << ownerName << ", Balance: " 
    << showpoint << fixed << setprecision(2) << balance << " Galactic units" << endl;
} // end function print()