#ifndef ACCOUNTHOLDER_H
#define ACCOUNTHOLDER_H

#include <iostream>
#include <string>

using namespace std;

class AccountHolder {
    private:
        string ID, Name, Address;
        double Balance;
        AccountHolder* next;

    public:
        AccountHolder(const string& id, const string& name, string& address, double balance);

        // Setter
        void setAddress(string& address);
        void setBalance(double balance);

        // Getters
        string getId() const;
        string getName() const;
        string getAddress() const;
        double getBalance() const;

        // Linked list methods
        void setNextAccountHolder(AccountHolder* nextAccountHolder); //Se 
        AccountHolder* getNextAccountHolder() const; //Get
};



#endif // ACCOUNTHOLDER_H