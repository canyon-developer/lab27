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
            cout << "Invalid choice. Please enter a number from 1 to 4.\n\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice >= 1 && choice <= 3) {
            string name;
            cout << "Enter the villager's name: ";
            getline(cin, name);

            auto it = villagers.find(name);
            if (it == villagers.end()) {
                cout << name << " was not found.\n";
            } else if (choice == 1) {
                int& friendship = get<0>(it->second);
                if (friendship < 10) {
                    ++friendship;
                    cout << name << "'s friendship increased to "
                         << friendship << ".\n";
                } else {
                    cout << name << " is already at the maximum friendship level.\n";
                }
            } else if (choice == 2) {
                int& friendship = get<0>(it->second);
                if (friendship > 0) {
                    --friendship;
                    cout << name << "'s friendship decreased to "
                         << friendship << ".\n";
                } else {
                    cout << name << " is already at the minimum friendship level.\n";
                }
            } else {
                cout << "Villager found:\n";
                displayVillager(it->first, it->second);
            }

            displayVillagers(villagers);
        } else if (choice == 4) {
            cout << "Goodbye!\n";
        } else {
            cout << "Invalid choice. Please enter a number from 1 to 4.\n\n";
        }
    }

    return 0;
}
