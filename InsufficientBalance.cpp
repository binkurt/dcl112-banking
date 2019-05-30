//
// Created by Binnur on 5/30/2019.
//

#include "InsufficientBalance.h"

InsufficientBalance::InsufficientBalance(const string &message, double deficit) : message(message), deficit(deficit) {}

const string &InsufficientBalance::getMessage() const {
    return message;
}

const double InsufficientBalance::getDeficit() const {
    return deficit;
}
