#include "PremiumAccount.h"

/*
constructor which passes the arguments to the Account constructor
*/
PremiumAccount::PremiumAccount(string name_, double amount_, Date date_)
    :Account(name_, amount_, date_)
{
} // end function PremiumAccount()

/*
overrides the withdraw() of Account. The function should first 
check if the existing balance is greater or equal to the
withdrawal amount + MIN_BALANCE. If so, withdrawal is processed 
and the function returns true. Otherwise the withdrawal is not
made and the function returns false. If the withdrawal is made, 
the withdrawal amount is deducted from balance. The date_ is only
a place holder for the extra credit version and not used in the 
basic version.
*/
bool PremiumAccount::withdraw(double amnt, Date d)
{
    if ((amnt + MIN_BALANCE) > balance)
    return false;
    else
    {
        balance -= amnt;
        return true;
    }
} // end function withdraw()

/*
static member function that returns MIN_BALANCE
*/
double PremiumAccount::getMinBalance()
{
    return MIN_BALANCE;
} // end function getMinBalance()

/*
prints the string "Premium account" then prints accountNumber, 
ownerName, balance. To print the accountNumber, ownerName, balance
*/
void PremiumAccount::print() const
{
    cout << "Premium account, ";
    this->Account::print();
} // end function print()