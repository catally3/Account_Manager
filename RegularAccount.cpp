#include "RegularAccount.h"

/*
constructor which passes the arguments to the Account constructor
*/
RegularAccount::RegularAccount(string ownerName_, double balance_, Date date_) 
: Account(ownerName_, balance_, date_)
{
} // end function RegularAccount()

/*
overrides the print() of Account. This function 
prints the string "Regular account" then prints 
accountNumber, ownerName, balance.
*/
void RegularAccount::print() const
{
    cout << "Regular account, "; 
    this->Account::print();
} // end function print()