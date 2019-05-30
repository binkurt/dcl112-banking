#ifndef BANKING_INSUFFICIENTBALANCE_H
#define BANKING_INSUFFICIENTBALANCE_H

#include <stdexcept>
using namespace std;
class InsufficientBalance : public exception {
    const string message;
    const double deficit;
public:
    InsufficientBalance(const string &message, double deficit);

    const string &getMessage() const;

    const double getDeficit() const;
};


#endif //BANKING_INSUFFICIENTBALANCE_H
