#ifndef BRANCH_H
#define BRANCH_H

#include <iostream>
#include <string>

using namespace std;

class Branch {
    private:
        string ID, Name, Manager;
        Branch* next;

    public:
        Branch(const string& id, const string& name, string& manager);

        // Setters
        void setManager( string& manager);

        // Getters
        string getId() const;
        string getName() const;
        string getManager() const;

        // Linked list methods
        void setNextBranch(Branch* nextBranch);
        Branch* getNextBranch() const;
};




#endif // BRANCH_H