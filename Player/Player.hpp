#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <iostream>
#include <list>
#include "Position.hpp"
#include "Inventory.hpp"
#include "Engimon.hpp"
#include "SkillItem.hpp"
#include "Map.hpp"

// #define MAX_CAPACITY 20

using namespace std;

class Player
{
private:
    static const int MAX_CAPACITY;
    Engimon ActiveEngimon;
    Inventory<Engimon> inventoryEngimon;
    Inventory<SkillItem> inventorySkillItem;
    Map map;

public:
    //Ctor
    Player();
    Player(Engimon activeEngimon);

    // Getter

    Map getMap();
    Inventory<Engimon> getInventoryEngimon();
    Inventory<SkillItem> getInventorySkillItem();
    Engimon getActiveEngimon();

    // Inventory
    void addSkillItem(SkillItem newSkillItem);
    void addEngimon(Engimon newEngimon);

    //Move Command
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    //Engimon Command
    void showOwnedEngimon();
    void showStatsEngimon(string engimonName);
    void showActiveEngimon();
    void swapActiveEngimon(string newEngimonName); // Swap active engimon with engimon from inventory
    void interactWithEngimon();

    //Skill Items Command
    void showOwnedItems();

    //Breed
    void doBreed(string firstEngimonName, string secondEngimonName);

    //Battle
    void doBattle();

    void learnSkill(string SkillName);
    void replaceSkillItem(int replacedSkillIdx, Skill newSkill);
};

#endif