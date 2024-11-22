#include "../../include/model/AccountHolder.h"

AccountHolder::AccountHolder(const string& id, const string& name, string& address, double balance)
: ID(id), Name(name), Address(address), Balance(balance) {}

// Setter
void AccountHolder::setAddress(string& address) {
    Address = address;
}
void AccountHolder::setBalance(double balance) {
    Balance = balance;
}

// Getters
string AccountHolder::getId() const {
    return ID;
}
string AccountHolder::getName() const {
    return Name;
}
string AccountHolder::getAddress() const {
    return Address;
}
double AccountHolder::getBalance() const {
    return Balance;
}

// Linked list methods
void AccountHolder::setNextAccountHolder(AccountHolder *nextAccountHolder) { // Set
    next = nextAccountHolder;
}
AccountHolder *AccountHolder::getNextAccountHolder() const { //Get
    return next;
}
