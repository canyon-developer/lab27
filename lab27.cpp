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

bool readFriendshipLevel(int& level) {
    while (true) {
        cout << "Friendship level: ";
        if (cin >> level && level >= 0 && level <= 10) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;
        }
        if (cin.eof())
            return false;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a whole number from 0 to 10.\n";
    }
}

void addVillager(VillagerMap& villagers) {
    string name;
    cout << "Villager name: ";
    getline(cin, name);

    if (villagers.find(name) != villagers.end()) {
        cout << name << " is already in the map.\n";
        return;
    }

    int friendship;
    if (!readFriendshipLevel(friendship))
        return;

    string species;
    string catchphrase;
    cout << "Species: ";
    getline(cin, species);
    cout << "Catchphrase: ";
    getline(cin, catchphrase);

    villagers.emplace(name, make_tuple(friendship, species, catchphrase));
    cout << name << " added.\n";
}

void deleteVillager(VillagerMap& villagers) {
    string name;
    cout << "Villager name: ";
    getline(cin, name);

    if (villagers.erase(name) == 1)
        cout << name << " deleted.\n";
    else
        cout << name << " was not found.\n";
}

int main() {
    VillagerMap villagers = {
        {"Audie", {8, "Wolf", "foxtrot"}},
        {"Marshal", {9, "Squirrel", "sulky"}},
        {"Raymond", {6, "Cat", "crisp"}}
    };

    int choice = 0;
    while (choice != 6) {
        cout << "1. Add Villager\n"
             << "2. Delete Villager\n"
             << "3. Increase Friendship\n"
             << "4. Decrease Friendship\n"
             << "5. Search for Villager\n"
             << "6. Exit\n"
             << "Enter choice: ";

        if (!(cin >> choice)) {
            if (cin.eof())
                break;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number from 1 to 6.\n\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            addVillager(villagers);
        } else if (choice == 2) {
            deleteVillager(villagers);
        } else if (choice >= 3 && choice <= 5) {
            string name;
            cout << "Villager name: ";
            getline(cin, name);

            auto it = villagers.find(name);
            if (it == villagers.end()) {
                cout << name << " was not found.\n";
            } else if (choice == 3) {
                int& friendship = get<0>(it->second);
                if (friendship < 10)
                    ++friendship;
                cout << name << "'s friendship level is " << friendship << ".\n";
            } else if (choice == 4) {
                int& friendship = get<0>(it->second);
                if (friendship > 0)
                    --friendship;
                cout << name << "'s friendship level is " << friendship << ".\n";
            } else {
                cout << "Villager found:\n";
                displayVillager(it->first, it->second);
            }
        } else if (choice == 6) {
            cout << "Goodbye!\n";
            continue;
        } else {
            cout << "Invalid choice. Please enter a number from 1 to 6.\n\n";
            continue;
        }

        displayVillagers(villagers);
    }

    return 0;
}
