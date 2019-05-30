#include "Account.h"
#include "InsufficientBalance.h"

bool Account::deposit(double amount) {
    if (amount <= 0) return false;
    // this->balance = this->balance + amount;
    this->balance += amount;
    return true;
}

void Account::withdraw(double amount)  {
    if (amount <= 0) throw "Negative amount!";
    if (this->balance < amount)
        throw InsufficientBalance(
                "Your balance does nt cover your expenses",
                amount - balance
        );
    this->balance -= amount;
}

double Account::withdrawAvailable(double amount) {
    if (amount <= 0) throw "Negative amount!";
    double available = balance - amount;
    if (available >= 0) {
        balance -= available;
        return available;
    }
    return 0;
}

std::ostream &operator<<(std::ostream &os, const Account &account) {
    os << "iban: " << account.getIban() << " balance: " << account.getBalance();
    return os;
}
