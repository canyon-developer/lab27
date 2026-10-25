#include <iostream>
#include <map>
#include <tuple>
using namespace std;

int main() {
    // declarations
    using VillagerInfo = tuple<int, string, string>;
    map<string, VillagerInfo> villagers;

    // insert elements into the map
    // Each tuple stores friendship level, species, and catchphrase.
    villagers["Audie"] = {8, "Wolf", "foxtrot"};
    villagers["Raymond"] = {6, "Cat", "crisp"};
    villagers.insert({"Marshal", {9, "Squirrel", "sulky"}});

    // access the map using a range-based for loop
    cout << "Villager information (range-based for loop):" << endl;
    for (const auto& pair : villagers) {
        cout << pair.first
             << ": friendship " << get<0>(pair.second)
             << ", species " << get<1>(pair.second)
             << ", catchphrase \"" << get<2>(pair.second) << "\"\n";
    }

    // access the map using iterators
    cout << "\nVillager information (iterators):" << endl;
    for (map<string, VillagerInfo>::iterator it = villagers.begin();
                                             it != villagers.end(); ++it) {
        cout << it->first
             << ": friendship " << get<0>(it->second)
             << ", species " << get<1>(it->second)
             << ", catchphrase \"" << get<2>(it->second) << "\"\n";
    }

    // delete an element
    villagers.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {
        cout << "\nFound " << searchKey
             << ": friendship " << get<0>(it->second)
             << ", species " << get<1>(it->second)
             << ", catchphrase \"" << get<2>(it->second) << "\"\n";
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;

    return 0;
}
