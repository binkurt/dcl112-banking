#include <optional>
#include <algorithm>
#include "Customer.h"

Customer::Customer(const string &&identity, const string &&fullname)
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
    auto item = find_if(accounts.begin(), accounts.end(), [iban](auto &acc) {
        return acc->getIban() == iban;
    });
    if (item == accounts.end()) return nullopt;
    return optional<shared_ptr<Account>>(*item);
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
    for (const auto &acc : accounts)
        totalBalance += acc->getBalance();
    return totalBalance;
}

ostream &operator<<(ostream &os, const Customer &customer) {
    os << "identity: " << customer.identity << " fullname: " << customer.fullname;
    return os;
}
