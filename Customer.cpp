#include <optional>
#include "Customer.h"

Customer::Customer(const string &identity, const string &fullname)
        : identity(identity), fullname(fullname) {

}

const string &Customer::getIdentity() const {
    return identity;
}

const string &Customer::getFullname() const {
    return fullname;
}

void Customer::setFullname(const string &fullname) {
    Customer::fullname = fullname;
}

void Customer::addAccount(Account &acc) {
    this->accounts.push_back(make_shared<Account>(acc));
}

int Customer::getNumOfAccounts() const {
    return this->accounts.size();
}

optional<shared_ptr<Account>> Customer::findAccount(const string &iban) const {
    for (auto &acc : accounts) {
        if (acc->getIban() == iban)
            return optional<shared_ptr<Account>>(acc);
    }
    return nullopt;
}

optional<shared_ptr<Account>> Customer::findAccount(int index) const {
    return optional<shared_ptr<Account>>(accounts[index]);
}

optional<shared_ptr<Account>> Customer::operator[](const string &iban) const {
    return this->findAccount(iban);
}

optional<shared_ptr<Account>> Customer::operator[](int index) const {
    return this->findAccount(index);
}

double Customer::operator()() const {
    //double totalBalance = double();
    auto totalBalance = 0.0; // c++11
    for (const auto& acc : accounts)
        totalBalance += acc->getBalance();
    return totalBalance;
}
