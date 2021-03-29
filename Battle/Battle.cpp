#include <string>
#include <iostream>
#include <cmath>
#include "Battle.hpp"
using namespace std;

Battle::Battle(Player Player, Engimon EngimonPlayer, Engimon EngimonWild) : player(Player), engimonWild(EngimonWild), engimonPlayer(EngimonPlayer)
{
    this->levelEngimonPlayer = EngimonPlayer.getLevel();
    this->levelEngimonWild = EngimonWild.getLevel();
    this->setMultiplierEngimon();
    this->setSkillPower();
    this->setTotalPower();

    cout << "Battle antara " << EngimonPlayer.getName() << " dan " << EngimonWild.getName() << " dimulai" << endl;
}

Battle::~Battle()
{
    cout << "Battle selesai" << endl;
    if (this->winner != "")
    {
        cout << "Battle dimenangkan oleh " << this->winner << endl;
        cout << this->loser << " mati karena kalah melawan " << this->winner << endl;
    }
    else
    {
        cout << "Tidak ada yang memenangkan battle" << endl;
        cout << this->loser << " keduanya mati dalam battle" << endl;
    }
}

int Battle::getlevelEngimonPlayer()
{
    return this->levelEngimonPlayer;
}

int Battle::getlevelEngimonWild()
{
    return this->levelEngimonWild;
}

int Battle::getMultiplierEngimonPlayer()
{
    return this->multiplierEngimonPlayer;
}

int Battle::getMultiplierEngimonWild()
{
    return this->multiplierEngimonWild;
}

int Battle::getskillPowerPlayer()
{
    return this->skillPowerPlayer;
}

int Battle::getskillPowerWild()
{
    return this->skillPowerWild;
}

float Battle::getTotalPowerPlayer()
{
    return this->totalPowerPlayer;
}

float Battle::getTotalPowerWild()
{
    return this->totalPowerWild;
}

string Battle::getWinner()
{
    return this->winner;
}

void Battle::setMultiplierEngimon()
{
    int max1 = 0, max2 = 0;
    int mult1, mult2;
    vector<string> elemen1, elemen2;

    elemen1 = this->engimonPlayer.getElement();
    elemen2 = this->engimonWild.getElement();

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            mult1 = checkMultiplier(elemen1[i], elemen2[j]);
            mult2 = checkMultiplier(elemen2[j], elemen1[i]);

            if (max1 < mult1)
            {
                max1 = mult1;
            }

            if (max2 < mult2)
            {
                max2 = mult2;
            }
        }
    }

    this->multiplierEngimonPlayer = max1;
    this->multiplierEngimonWild = max2;
}

void Battle::setSkillPower()
{
    list<Skill> list1 = this->engimonPlayer.getSkill(), list2 = this->engimonWild.getSkill();
    int PowerPlayer = 0, PowerWild = 0;
    Skill skill1, skill2;

    list<Skill>::iterator it1 = list1.begin();
    list<Skill>::iterator it2 = list2.begin();

    for (int i = 0; i < list1.size(); i++)
    {
        skill1 = *it1;
        PowerPlayer += skill1.getSkillPower() * skill1.getSkillMastery();
        advance(it1, 1);
    }

    for (int i = 0; i < list2.size(); i++)
    {
        skill2 = *it2;
        PowerPlayer += skill2.getSkillPower() * skill2.getSkillMastery();
        advance(it2, 1);
    }

    this->skillPowerPlayer = PowerPlayer;
    this->skillPowerWild = PowerWild;
}

void Battle::setTotalPower()
{
    int total1, total2;
    total1 = this->levelEngimonPlayer * this->multiplierEngimonPlayer + this->skillPowerPlayer;
    total2 = this->levelEngimonWild * this->multiplierEngimonWild + this->skillPowerWild;

    this->totalPowerPlayer = total1;
    this->totalPowerWild = total2;
}

float Battle::checkMultiplier(string elemen1, string elemen2)
{
    if (elemen1 == "Fire")
    {
        if (elemen2 == "Fire")
        {
            return 1;
        }
        else if (elemen2 == "Water")
        {
            return 0;
        }
        else if (elemen2 == "Electric")
        {
            return 1;
        }
        else if (elemen2 == "Ground")
        {
            return 0.5;
        }
        else if (elemen2 == "Ice")
        {
            return 2;
        }
        // else
        // {
        //     cout << "test" << endl;
        //     throw elemen2;
        // }
    }
    else if (elemen2 == "Water")
    {
        if (elemen2 == "Fire")
        {
            return 2;
        }
        else if (elemen2 == "Water")
        {
            return 1;
        }
        else if (elemen2 == "Electric")
        {
            return 0;
        }
        else if (elemen2 == "Ground")
        {
            return 1;
        }
        else if (elemen2 == "Ice")
        {
            return 1;
        }
        // else
        // {
        //     throw elemen2;
        // }
    }
    else if (elemen2 == "Electric")
    {
        if (elemen2 == "Fire")
        {
            return 1;
        }
        else if (elemen2 == "Water")
        {
            return 2;
        }
        else if (elemen2 == "Electric")
        {
            return 1;
        }
        else if (elemen2 == "Ground")
        {
            return 0;
        }
        else if (elemen2 == "Ice")
        {
            return 1.5;
        }
        // else
        // {
        //     throw elemen2;
        // }
    }
    else if (elemen2 == "Ground")
    {
        if (elemen2 == "Fire")
        {
            return 1.5;
        }
        else if (elemen2 == "Water")
        {
            return 1;
        }
        else if (elemen2 == "Electric")
        {
            return 2;
        }
        else if (elemen2 == "Ground")
        {
            return 1;
        }
        else if (elemen2 == "Ice")
        {
            return 0;
        }
        // else
        // {
        //     throw elemen2;
        // }
    }
    else if (elemen2 == "Ice")
    {
        if (elemen2 == "Fire")
        {
            return 0;
        }
        else if (elemen2 == "Water")
        {
            return 1;
        }
        else if (elemen2 == "Electric")
        {
            return 0.5;
        }
        else if (elemen2 == "Ground")
        {
            return 2;
        }
        else if (elemen2 == "Ice")
        {
            return 1;
        }
        // else
        // {
        //     throw elemen2;
        // }
    }
    // else
    // {
    //     if ((elemen2 == "Ice") || (elemen2 == "Fire") || (elemen2 == "Water") || (elemen2 == "Electric") || (elemen2 == "Ground"))
    //     {
    //         throw elemen1;
    //     }
    //     else
    //     {
    //         throw elemen1, elemen2;
    //     }
    // }
    return 0;
}

void Battle::showTotalPower()
{
    string elemenPlayer, elemenWild;

    if (this->engimonPlayer.getElement()[0] == this->engimonPlayer.getElement()[1])
    {
        elemenPlayer = (this->engimonPlayer.getElement())[0];
    }
    else
    {
        elemenPlayer = (this->engimonPlayer.getElement())[0] + " / " + (this->engimonPlayer.getElement())[1];
    }

    if (this->engimonWild.getElement()[0] == this->engimonWild.getElement()[1])
    {
        elemenWild = (this->engimonWild.getElement())[0];
    }
    else
    {
        elemenWild = (this->engimonWild.getElement())[0] + " / " + (this->engimonWild.getElement())[1];
    }

    cout << endl;
    cout << "ENGIMON PLAYER" << endl;
    cout << "Nama           : " << this->engimonPlayer.getName() << endl;
    cout << "Level          : " << this->levelEngimonPlayer << endl;
    cout << "Elemen         : " << elemenPlayer << endl;
    cout << "Total Power    : " << this->totalPowerPlayer << endl;
    ;

    cout << endl;
    cout << "ENGIMON WILD" << endl;
    cout << "Nama           : " << this->engimonWild.getName() << endl;
    cout << "Level          : " << this->levelEngimonWild << endl;
    cout << "Elemen         : " << elemenWild << endl;
    cout << "Total Power    : " << this->totalPowerWild << endl;
    ;
    cout << endl;
}

void Battle::doBattle()
{
    this->showTotalPower();

    if (this->totalPowerPlayer > this->totalPowerWild)
    {
        this->winner = this->engimonPlayer.getName();
        this->loser = this->engimonWild.getName();
    }
    else if (this->totalPowerPlayer < this->totalPowerWild)
    {
        this->winner = this->engimonWild.getName();
        this->loser = this->engimonPlayer.getName();
        this->engimonPlayer.~Engimon();
    }
    else
    {
        if (this->levelEngimonPlayer > this->levelEngimonWild)
        {
            this->winner = this->engimonPlayer.getName();
            this->loser = this->engimonWild.getName();
        }
        else if (this->levelEngimonPlayer < this->levelEngimonWild)
        {
            this->winner = this->engimonPlayer.getName();
            this->loser = this->engimonWild.getName();
            this->engimonPlayer.~Engimon();
        }
        else
        {
            if (this->multiplierEngimonPlayer > this->multiplierEngimonWild)
            {
                this->winner = this->engimonPlayer.getName();
                this->loser = this->engimonWild.getName();
            }
            else if (this->multiplierEngimonPlayer < this->multiplierEngimonWild)
            {
                this->winner = this->engimonPlayer.getName();
                this->loser = this->engimonWild.getName();
                this->engimonPlayer.~Engimon();
            }
            else
            {
                this->winner = "";
                this->loser = this->engimonPlayer.getName() + " dan " + this->engimonWild.getName();
                this->engimonPlayer.~Engimon();
                this->engimonWild.~Engimon();
            }
        }
    }
}

SkillItem Battle::getRandomSkill(vector<SkillItem> fireItems, vector<SkillItem> waterItems, vector<SkillItem> electricItems, vector<SkillItem> groundItems, vector<SkillItem> iceItems)
{
    int i = rand() % 7;
    int j;

    SkillItem skillItem;
    vector<string> elemen = this->engimonWild.getElement();

    if (elemen.size() == 2)
    {
        j = rand() % 2;
    }
    else
    {
        j = 0;
    }

    if (elemen[j] == "Fire")
    {
        skillItem = fireItems[i];
    }
    else if (elemen[j] == "Water")
    {
        skillItem = waterItems[i];
    }
    else if (elemen[j] == "Electric")
    {
        skillItem = electricItems[i];
    }
    else if (elemen[j] == "Ground")
    {
        skillItem = groundItems[i];
    }
    else if (elemen[j] == "Ice")
    {
        skillItem = iceItems[i];
    }
    else
    {
        throw elemen[j];
    }

    return skillItem;
}