#include "../../include/JSONHandler.h"
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

namespace JSONHandler {

    // Load branches data from JSON files
    void loadBranchesFromFile(const string& filename, Branch*& head) {
        if (!filesystem::exists(filename)) {
                cerr << "Warning: File " << filename << " does not exist. Creating a new file.\n";
                ofstream newFile(filename);
                return;
        }

        json data;
        file >> data;

        for (const auto& item : data) {
            Branch* newBranch = new Branch(
                item["id"].get<string>(),
                item["name"].get<string>(),
                item["manager"].get<string>()
            );
            newBranch->setNextBranch(head);
            head = newBranch;
        }
    }

    // Save branches data to JSON file
    void saveBranchesToFile(const string& filename, Branch* head) {
        if (!filesystem::exists(filename)) {
                cerr << "Warning: File " << filename << " does not exist. Creating a new file.\n";
                ofstream newFile(filename);
                return;
        }
        
        json data;
        Branch* temp = head;
        while (temp != nullptr) {
            data.push_back({
                {"id", temp->getId()},
                {"name", temp->getName()},
                {"manager", temp->getManager()}
            });
            temp = temp->getNextBranch();
        }
        file << data.dump(4);
    }

    // Load account data from JSON files
    void loadAccountHoldersFromFile(const string& filename, AccountHolder*& head) {
        if (!filesystem::exists(filename)) {
                cerr << "Warning: File " << filename << " does not exist. Creating a new file.\n";
                ofstream newFile(filename);
                return;
        }

        json data;
        file >> data;

        for (const auto& item : data) {
            AccountHolder* newAccount = new AccountHolder(
                item["id"].get<string>(),
                item["name"].get<string>(),
                item["balance"].get<double>()
            );
            newAccount->setNextAccount(head);
            head = newAccount;
        }
    }

    // Save account data to JSON file
    void saveAccountHoldersToFile(const string& filename, AccountHolder* head) {
        if (!filesystem::exists(filename)) {
                cerr << "Warning: File " << filename << " does not exist. Creating a new file.\n";
                ofstream newFile(filename);
                return;
        }

        json data;
        AccountHolder* temp = head;
        while (temp != nullptr) {
            data.push_back({
                {"id", temp->getId()},
                {"name", temp->getName()},
                {"balance", temp->getBalance()}
            });
            temp = temp->getNextAccount();
        }
        file << data.dump(4);
    }

}
