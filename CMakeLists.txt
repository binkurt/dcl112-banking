cmake_minimum_required(VERSION 3.14)
project(banking)
project(write-customer)
project(read-customer)

set(CMAKE_CXX_STANDARD 17)

add_executable(banking main.cpp Account.cpp Account.h Customer.cpp Customer.h CheckingAccount.cpp CheckingAccount.h InsufficientBalance.cpp InsufficientBalance.h)
add_executable(write-customer CustomerDao.cpp CustomerDao.h Account.cpp Account.h Customer.cpp Customer.h CheckingAccount.cpp CheckingAccount.h InsufficientBalance.cpp InsufficientBalance.h write-customer.cpp)
add_executable(read-customer CustomerDao.cpp CustomerDao.h Account.cpp Account.h Customer.cpp Customer.h CheckingAccount.cpp CheckingAccount.h InsufficientBalance.cpp InsufficientBalance.h read-customer.cpp)