#ifndef __INVENTORY__HPP__
#define __INVENTORY__HPP__
#include <vector>
#include "SkillItem.hpp"
#include "Engimon.hpp"
#include "Skill.hpp"
using namespace std;

template <class T>
class Inventory
{
protected:
    vector<T> vector_inventory;

public:
    // Constructor
    Inventory() {}

    // Operator
    Inventory<T> &operator<<(const T &inventory_item)
    {
        this->vector_inventory.push_back(inventory_item);

        return *this;
    }

    void removeItem(int index)
    {
        if (index - 1 > this->vector_inventory.size())
            throw "index out of bound";
        else
            this->vector_inventory.erase(this->vector_inventory.begin() + (index - 1));
    }

    vector<T> getInventoryVector() { return this->vector_inventory; }

    int getInventorySize() { return this->vector_inventory.size(); }

    void setInventoryItem(int idx, T value) { this->vector_inventory[idx] = value; }
};

#endif