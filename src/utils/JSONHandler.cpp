#include "JSONHandler.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

namespace JSONHandler {

    void loadBranchesFromFile(const string& filename, Branch*& head) {
        ifstream file(filename);
        json data;
        file >> data;
        
        for (const auto& item : data) {
            addBranch(head, item["id"], item["name"], item["location"]);
        }
    }

    void saveBranchesToFile(const string& filename, Branch* head) {
        json data;
        Branch* temp = head;
        while (temp != nullptr) {
            data.push_back({
                {"id", temp->id},
                {"name", temp->name},
                {"location", temp->location}
            });
            temp = temp->next;
        }
        ofstream file(filename);
        file << data.dump(4);
    }

    void loadAccountHoldersFromFile(const string& filename, AccountHolder*& head) {
        ifstream file(filename);
        json data;
        file >> data;

        for (const auto& item : data) {
            addAccountHolder(head, item["id"], item["name"], item["address"], item["balance"]);
        }
    }

    void saveAccountHoldersToFile(const string& filename, AccountHolder* head) {
        json data;
        AccountHolder* temp = head;
        while (temp != nullptr) {
            data.push_back({
                {"id", temp->id},
                {"name", temp->name},
                {"address", temp->address},
                {"balance", temp->balance}
            });
            temp = temp->next;
        }
        ofstream file(filename);
        file << data.dump(4);
    }

}

