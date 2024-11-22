#include "../../include/model/Branch.h"

Branch::Branch(const string& id, const string& name, string& manager) 
: ID(id), Name(name), Manager(manager), next(nullptr){}

// Setter
void Branch::setManager(string& manager) {
    Manager = manager;
}

// Getters
string Branch::getId() const {
    return ID;
}

string Branch::getName() const {
    return Name;
}

string Branch::getManager() const {
    return Manager;
}


// Linked list methods
void Branch::setNextBranch(Branch* nextBranch) { // Set
    next = nextBranch;
}
Branch* Branch::getNextBranch() const { // Get
    return next;
}
