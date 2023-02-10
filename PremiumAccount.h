#ifndef PREMIUMACCOUNT_H_INCLUDED
#define PREMIUMACCOUNT_H_INCLUDED
#include "Account.h"
#include "Date.h"

class PremiumAccount : public Account
{
private:
    static const double MIN_BALANCE;

public:
    PremiumAccount(string nam, double amnt, Date d);
    bool withdraw(double amnt, Date d) override;
    static double getMinBalance();
    void print() const override;

};


#endif // PREMIUMACCOUNT_H_INCLUDED
