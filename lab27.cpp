#include <iostream>
#include <limits>
#include <map>
#include <tuple>
using namespace std;

using VillagerInfo = tuple<int, string, string>;
using VillagerMap = map<string, VillagerInfo>;

void displayVillager(const string& name, const VillagerInfo& info) {
    cout << name << " [" << get<0>(info) << ", "
         << get<1>(info) << ", " << get<2>(info) << "]\n";
}

void displayVillagers(const VillagerMap& villagers) {
    cout << "\nVillager details:\n";
    for (const auto& villager : villagers)
        displayVillager(villager.first, villager.second);
    cout << endl;
}

int main() {
    VillagerMap villagers = {
        {"Audie", {8, "Wolf", "foxtrot"}},
        {"Marshal", {9, "Squirrel", "sulky"}},
        {"Raymond", {6, "Cat", "crisp"}}
    };

    int choice = 0;
    while (choice != 4) {
        cout << "1. Increase Friendship\n"
             << "2. Decrease Friendship\n"
             << "3. Search for Villager\n"
             << "4. Exit\n"
             << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice.\n\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 3) {
            string name;
            cout << "Enter the villager's name: ";
            getline(cin, name);

            auto it = villagers.find(name);
            if (it != villagers.end()) {
                cout << "Villager found:\n";
                displayVillager(it->first, it->second);
            } else {
                cout << name << " was not found.\n";
            }
            displayVillagers(villagers);
        } else if (choice == 1 || choice == 2) {
            // TODO: Implement friendship increase and decrease operations.
            cout << "Friendship update is not implemented yet.\n";
            displayVillagers(villagers);
        } else if (choice == 4) {
            cout << "Goodbye!\n";
        } else {
            cout << "Invalid choice.\n\n";
        }
    }

    return 0;
}
