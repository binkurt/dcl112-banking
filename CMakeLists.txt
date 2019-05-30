cmake_minimum_required(VERSION 3.14)
project(banking)

set(CMAKE_CXX_STANDARD 17)

add_executable(banking main.cpp Account.cpp Account.h Customer.cpp Customer.h CheckingAccount.cpp CheckingAccount.h InsufficientBalance.cpp InsufficientBalance.h)