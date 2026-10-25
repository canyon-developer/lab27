#include <iostream>
#include <map>
#include <tuple>
using namespace std;

int main() {
    // The map has been converted to store each villager's information in a tuple.
    using VillagerInfo = tuple<int, string, string>;
    map<string, VillagerInfo> villagers;

    // Each tuple stores friendship level, species, and catchphrase.
    villagers["Audie"] = {8, "Wolf", "foxtrot"};
    villagers["Raymond"] = {6, "Cat", "crisp"};
    villagers.insert({"Marshal", {9, "Squirrel", "sulky"}});

    // The range-based loop has been converted to read the tuple fields.
    cout << "Villager information (range-based for loop):" << endl;
    for (const auto& pair : villagers) {
        cout << pair.first
             << ": friendship " << get<0>(pair.second)
             << ", species " << get<1>(pair.second)
             << ", catchphrase \"" << get<2>(pair.second) << "\"\n";
    }

    // TODO: Convert the remaining vector-based code to use the tuple.
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin();
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second)
            cout << color << " ";
        cout << endl;
    }

    villagerColors.erase("Raymond");

    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}
