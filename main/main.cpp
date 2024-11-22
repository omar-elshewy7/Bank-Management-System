#include <iostream>
#include "../include/model/Branch.h"
#include "../include/model/AccountHolder.h"
#include "../include/utils/JSONHandler.h"

using namespace std;

int main() {


    // Load data from JSON files
    JSONHandler::loadBranchesFromFile("data/branches.json", ranches);
    JSONHandler::loadAccountHoldersFromFile("data/account_holders.json", AccountHolders);



    // Save updated data back to JSON
    // JSONHandler::saveBranchesToFile(branches, "data/branches.json");
    // JSONHandler::saveAccountHoldersToFile(accountHolders, "data/account_holders.json");

    return 0;
}
