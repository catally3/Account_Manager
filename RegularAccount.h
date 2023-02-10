#ifndef REGULARACCOUNT_H_INCLUDED
#define REGULARACCOUNT_H_INCLUDED
#include "Account.h"
class RegularAccount : public Account
{
public:
    RegularAccount(string nam, double amnt, Date d);
    void print() const override;
};

#endif // REGULARACCOUNT_H_INCLUDED
