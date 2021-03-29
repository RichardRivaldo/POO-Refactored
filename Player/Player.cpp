#include <string>
#include <iostream>
#include <cmath>
#include "Player.hpp"
#include "Engimon.hpp"
#include "Skill.hpp"
#include "Map.hpp"

using namespace std;

const int Player::MAX_CAPACITY = 20;

Player::Player()
{
    this->map = Map();
    map.setplayerPosition(1, 1);
    map.setactiveEngimonPosition(0, 0);
}

Player::Player(Engimon activeEngimon) : ActiveEngimon(activeEngimon)
{
    this->map = Map();
    this->addEngimon(activeEngimon);
    map.setplayerPosition(1, 1);
    map.setactiveEngimonPosition(0, 0);
}

// Inventory
void Player::addSkillItem(SkillItem newSkillItem)
{
    if (this->inventoryEngimon.getInventorySize() + this->inventorySkillItem.getInventorySize() + 1 > Player::MAX_CAPACITY)
    {
        throw "Maximum capacity";
        return;
    }

    int i = 0;
    while (i < this->inventorySkillItem.getInventorySize())
    {
        if (this->inventorySkillItem.getInventoryVector()[i].getSkill().getSkillName().compare(newSkillItem.getSkill().getSkillName()) == 0)
        {
            cout << "Menambahkan Skill Item untuk " << newSkillItem.getSkill().getSkillName() << endl;
            this->inventorySkillItem.getInventoryVector()[i].addItemAmount(1);
            return;
        }
        i++;
    }

    this->inventorySkillItem << newSkillItem;
    cout << "Berhasil menambahkan skill item baru!" << endl;
}

void Player::addEngimon(Engimon newEngimon)
{
    if (this->inventoryEngimon.getInventorySize() + this->inventorySkillItem.getInventorySize() + 1 > Player::MAX_CAPACITY)
    {
        throw "Maximum capacity";
        return;
    }

    this->inventoryEngimon << newEngimon;
    cout << "Berhasil menambahkan engimon baru" << endl;
}

Map Player::getMap()
{
    return map;
}

Inventory<Engimon> Player::getInventoryEngimon() { return this->inventoryEngimon; }
Inventory<SkillItem> Player::getInventorySkillItem() { return this->inventorySkillItem; }

Engimon Player::getActiveEngimon() { return this->ActiveEngimon; }

void Player::learnSkill(string SkillName)
{
    int i = 0;
    bool found = false;
    SkillItem newSkillItem;
    Skill newSkill;

    while (i < this->inventorySkillItem.getInventorySize() && !found)
    {
        if (this->inventorySkillItem.getInventoryVector()[i].getSkill().getSkillName().compare(SkillName) == 0)
        {
            found = true;
            newSkillItem = this->inventorySkillItem.getInventoryVector()[i];
            newSkill = this->inventorySkillItem.getInventoryVector()[i].getSkill();
        }
        i++;
    }

    if (found != true)
    {
        cout << "Tidak ada Skill Item untuk Skill ini di dalam Inventory!" << endl;
        return;
    }
    else
    {
        int skillIdx;
        string choice;
        if (this->ActiveEngimon.getSkill().size() == 4)
        {
            cout << "Engimon kamu sudah memiliki 4 buah Skill." << endl;
            cout << "Apakah kamu ingin mengganti salah satu Skill tersebut? (Y/N)";
            cin >> choice;

            if (choice == "Y")
            {
                cout << "Pilih nomor Skill yang ingin kamu ganti: ";
                cin >> skillIdx;
                this->replaceSkillItem(skillIdx, newSkill);
                cout << "Skill berhasil ditambahkan!" << endl;

                // Remove or Decrease Item from Inventory here
                if (newSkillItem.getAmount() > 1)
                    this->inventorySkillItem.getInventoryVector()[i - 1].decItemAmount(1); // ini ngurangin di skill item
                else
                    this->inventorySkillItem.removeItem(i); // ini buang skill dari invent
            }
            else
            {
                cout << "Penggunaan Skill Item Dibatalkan!" << endl;
                return;
            }
        }
        else
        {
            this->ActiveEngimon.AddSkill(newSkill);
            cout << "Skill Berhasil Ditambahkan!" << endl;
            // Remove or Decrease Item from Inventory here
            if (newSkillItem.getAmount() > 1)
                this->inventorySkillItem.getInventoryVector()[i - 1].decItemAmount(1); // ini ngurangin di skill item
            else
                this->inventorySkillItem.removeItem(i); // ini buang skill dari invent
        }
    }
}

void Player::replaceSkillItem(int replacedSkillIdx, Skill newSkill)
{
    if (replacedSkillIdx - 1 > this->ActiveEngimon.getSkill().size() - 1)
    {
        cout << "Indeks Invalid! Pergantian Gagal" << endl;
        return;
    }
    else
    {
        this->ActiveEngimon.RemoveSkillByIdx(replacedSkillIdx);
        this->ActiveEngimon.AddSkill(newSkill);
    }
}

//Move Command
void Player::moveUp()
{
    if (this->map.getplayerPositionY() - 1 >= 0)
    {
        Position prevpos = Position(map.getplayerPosition());
        this->map.setplayerPosition(this->map.getplayerPositionX(), this->map.getplayerPositionY() - 1);
        this->map.setactiveEngimonPosition(prevpos.getXCoordinate(), prevpos.getYCoordinate());
        int peluang = rand() % 100;
        if (peluang > 50)
        {
            this->map.addEngimonLiar();
        }else{
            this->map.moveAllEngimonLiar();
        }
    }
    else
    {
        throw "Invalid move Player Up (Mentok)";
    }
}

void Player::moveDown()
{
    if (this->map.getplayerPositionY() + 1 <= map.getymax())
    {
        Position prevpos = Position(map.getplayerPosition());
        this->map.setplayerPosition(this->map.getplayerPositionX(), this->map.getplayerPositionY() + 1);
        this->map.setactiveEngimonPosition(prevpos.getXCoordinate(), prevpos.getYCoordinate());
        int peluang = rand() % 100;
        if (peluang > 50)
        {
            this->map.addEngimonLiar();
        }else{
            this->map.moveAllEngimonLiar();
        }
    }
    else
    {
        throw "Invalid move Player Down (Mentok)";
    }
}

void Player::moveLeft()
{
    if (this->map.getplayerPositionX() - 1 >= 0)
    {
        Position prevpos = Position(map.getplayerPosition());
        this->map.setplayerPosition(this->map.getplayerPositionX() - 1, this->map.getplayerPositionY());
        this->map.setactiveEngimonPosition(prevpos.getXCoordinate(), prevpos.getYCoordinate());
        int peluang = rand() % 100;
        if (peluang > 50)
        {
            this->map.addEngimonLiar();
        }else{
            this->map.moveAllEngimonLiar();
        }
    }
    else
    {
        throw "Invalid move Player Left (Mentok)";
    }
}

void Player::moveRight()
{
    if (this->map.getplayerPositionX() + 1 <= map.getxmax())
    {
        Position prevpos = Position(map.getplayerPosition());
        this->map.setplayerPosition(this->map.getplayerPositionX() + 1, this->map.getplayerPositionY());
        this->map.setactiveEngimonPosition(prevpos.getXCoordinate(), prevpos.getYCoordinate());
        int peluang = rand() % 100;
        if (peluang > 50)
        {
            this->map.addEngimonLiar();
        }else{
            this->map.moveAllEngimonLiar();
        }
    }
    else
    {
        throw "Invalid move Player Right (Mentok)";
    }
}

//Engimon Command
void Player::showOwnedEngimon()
{
    int index = 1;
    if (this->inventoryEngimon.getInventorySize() == 0)
        cout << "Tidak ada engimon di inventory" << endl;
    else
    {
        cout << "Daftar engimon yang dimiliki" << endl;
        for (Engimon engimon : this->inventoryEngimon.getInventoryVector())
        {
            cout << index << ". " << engimon.getName() << endl;
            index++;
        }
    }
}

void Player::showStatsEngimon(string engimonName)
{
    bool finish = false;
    int i = 0;
    while (i < this->inventoryEngimon.getInventorySize() && !finish)
    {
        if (this->inventoryEngimon.getInventoryVector()[i].getName().compare(engimonName) == 0)
        {
            finish = true;
            cout << "Engimon stats: " << endl;
            this->inventoryEngimon.getInventoryVector()[i].showStats();
        }
        i++;
    }
    if(!finish){
        cout << "Gagal menampilkan stats Engimon!" << endl;
    }
}

void Player::showActiveEngimon()
{
    cout << "Engimon yang sedang aktif berpetualang: " << endl;
    this->ActiveEngimon.showStats();
}

void Player::swapActiveEngimon(string newEngimonName)
{
    bool finish = false;
    int i = 0;
    while (i < this->inventoryEngimon.getInventorySize() && !finish)
    {
        if (this->inventoryEngimon.getInventoryVector()[i].getName().compare(newEngimonName) == 0)
        {
            this->ActiveEngimon = this->inventoryEngimon.getInventoryVector()[i];
            cout << "Success change active engimon" << endl;
            finish = true;
        }
        i++;
    }

    if (!finish)
        cout << "Gagal mengganti Engimon!" << endl;
}

void Player::interactWithEngimon() { cout << this->ActiveEngimon.getName() << " : " << this->ActiveEngimon.getMessage() << endl; }

//Skill Command
void Player::showOwnedItems()
{
    if (this->inventorySkillItem.getInventorySize() == 0)
    {
        cout << "Tidak ada Skill Items di Inventory!" << endl;
    }
    else
    {
        cout << "Daftar Skill Items yang dimiliki: " << endl;

        for (SkillItem items : this->inventorySkillItem.getInventoryVector())
        {
            items.skillItemInfo();
        }
    }
}

//Breed
void Player::doBreed(string firstEngimonName, string secondEngimonName)
{
    int firstEngimonIdx = -1, secondEngimonIdx = -1;
    for (int i = 0; i < this->inventoryEngimon.getInventorySize(); i++)
    {
        if (this->inventoryEngimon.getInventoryVector()[i].getName() == firstEngimonName && firstEngimonIdx == -1)
            firstEngimonIdx = i;
        else if (this->inventoryEngimon.getInventoryVector()[i].getName() == secondEngimonName && secondEngimonIdx == -1)
            secondEngimonIdx = i;
    }

    cout << "Breeding...." << endl;
    if (firstEngimonIdx != -1 && secondEngimonIdx != -1)
    {
        Engimon engimonParent1 = this->inventoryEngimon.getInventoryVector()[firstEngimonIdx];
        Engimon engimonParent2 = this->inventoryEngimon.getInventoryVector()[secondEngimonIdx];
        Engimon engimonChild = engimonParent1.breed(engimonParent2);

        if (engimonChild.getLevel() == -1)
        {
            cout << "Breeding gagal" << endl;
        }
        else
        {
            this->addEngimon(engimonChild);
            cout << "Breeding berhasil" << endl;
        }
    }
    else
    {
        cout << "No corresponding Engimons in your Inventory!" << endl;
        cout << "Breeding failed" << endl;
    }
}

//Battle
void Player::doBattle()
{
}