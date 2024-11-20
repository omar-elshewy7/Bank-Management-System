#ifndef JSONHANDLER_H
#define JSONHANDLER_H

#include <iostream>
#include <string>
#include "../model/Branch.h"
#include "../model/AccountHolder.h"

using namespace std;

namespace JSONHandler {
    void loadBranchesFromFile(const string& filename, Branch*& head);
    void saveBranchesToFile(const string& filename, Branch* head);
    void loadAccountHoldersFromFile(const string& filename, AccountHolder*& head);
    void saveAccountHoldersToFile(const string& filename, AccountHolder* head);
}

#endif // JSONHANDLER_H
