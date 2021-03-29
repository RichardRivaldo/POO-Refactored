#include <string>
#include <list>
#include <iostream>
#include <vector>
#include "Engimon.hpp"
#include "Skill.hpp"

using namespace std;

Engimon::Engimon()
{
    this->name = "NO NAME";
    this->species = "NO SPECIES";
    this->element = {"NULL", "NULL"};
    this->level = new int(-1);
    this->experience = new int(-1);
    this->cumulativeExperience = new int(-1);
    this->message = "";
    this->parent1 = new string("");
    this->parent2 = new string("");
}

Engimon::Engimon(string nama, string species, vector<string> element)
{
    this->name = nama;
    this->element = element;
    this->species = species;
    this->level = new int (1);
    this->experience = new int(0);
    this->cumulativeExperience = new int(0);
    this->message = "I'm an Engimon";
    this->parent1 = new string("");
    this->parent2 = new string("");
}

Engimon::Engimon(const Engimon &engimon)
{
    this->name = engimon.name;
    this->element = engimon.element;
    this->species = engimon.species;
    this->level = engimon.level;
    this->experience = engimon.experience;
    this->cumulativeExperience = engimon.cumulativeExperience;
    this->skill = engimon.skill;
    this->message = engimon.message;
    this->parent1 = new string(*engimon.parent1);
    this->parent2 = new string(*engimon.parent2);
}

Engimon::~Engimon()
{
}

Engimon &Engimon::operator=(const Engimon &engimon)
{
    this->name = engimon.name;
    this->species = engimon.species;
    this->skill = engimon.skill;
    this->element = engimon.element;
    this->level = new int(*engimon.level);
    this->experience = new int (*engimon.experience);
    this->cumulativeExperience = new int (*engimon.cumulativeExperience);
    this->message = engimon.message;
    this->parent1 = new string(*engimon.parent1);
    this->parent2 = new string(*engimon.parent2);
    for (list<Skill>::iterator iter = this->skill.begin(); iter != this->skill.end(); iter++)
    {
        this->skill.push_back(*iter);
    }
    return *this;
}

bool Engimon::operator==(const Engimon &engimon) const{
    return (this->name == engimon.name 
    && this->species == engimon.species
    && this->level == engimon.level
    && this->experience == engimon.experience
    && this->cumulativeExperience == engimon.cumulativeExperience
    && this->message == engimon.message);
}

// bool Engimon::CheckDead(Engimon engimon)
// {
//     // Engimon akan mati jika jumlah experience kumulatif >= 3000
//     if (engimon.cumulativeExperience >= 5000)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// void Engimon::CheckLevelUp(Engimon engimon)
// {
//     // Level up akan terjadi setiap experience mencapai lebih dari 100
//     if (engimon.experience >= 100)
//     {
//         this->level += 1;
//         this->experience -= 100;
//     }
// }

const Skill Engimon::getHighestMastery()
{
    int highest = -9999;
    Skill highestMasterySkill;
    for (list<Skill>::iterator iter = skill.begin(); iter != skill.end(); iter++)
    {
        if (highest <= (*iter).getSkillMastery())
        {
            highest = (*iter).getSkillMastery();
            highestMasterySkill = (*iter);
        }
    }
    return highestMasterySkill;
}

void Engimon::showStats()
{
    cout << "Nama : " << this->getName() << endl;
    cout << "Spesies : " << this->getSpecies() << endl;

    cout << "Parents : ";
    if (*this->parent1 != "") {
        cout << *(this->parent1) << ", " << *(this->parent2);
    }
    cout << endl;
    
    list<Skill>::iterator it;
    cout << "List Skills : | ";
    for (it = this->skill.begin(); it != this->skill.end(); it++)
    {
        cout << (*it).getSkillName() << " | ";
    }
    cout << endl;

    if (element[0] != element[1]) {
        cout << "Element : " << element[0] << " / " << element[1] << endl;
    }
    else {
        cout << "Element : " << element[0] << endl;
    }
    cout << "Level : " << this->getLevel() << endl;
    cout << "Experience : " << this->getExperience() << endl;
    cout << "Cumulative experience : " << this->getCumulativeExperience() << endl;
}

void Engimon::AddSkill(Skill skill)
{
    list<Skill>::iterator it;
    it = this->skill.begin();
    this->skill.insert(it, skill);
}

void Engimon::RemoveSkillByIdx(int SkillIdx)
{
    list<Skill>::iterator iter = skill.begin();
    advance(iter, SkillIdx - 1);
    this->skill.erase(iter);
}

void Engimon::RemoveSkill(Skill skill)
{
    if (this->skill.size() == 1)
    {
        if (skill.getSkillName() == (*(this->skill.begin())).getSkillName())
        {
            this->skill.erase(this->skill.begin());
        }
    }
    for (list<Skill>::iterator iter = this->skill.begin(); iter != this->skill.end(); iter++)
    {
        if (skill.getSkillName() == (*iter).getSkillName())
        {
            this->skill.erase(iter);
        }
    }
}

// void Engimon::pushToParents(Engimon parent)
// {
//     this->parents.push_back(parent);
// }

// void Engimon::setParent1(string engimon1) {
//     this->parent1 = &engimon1;
// }

// void Engimon::setParent2(string engimon2) {
//     this->parent2 = &engimon2;
// }

Engimon Engimon::breed(Engimon anotherEngimon)
{
    Engimon engimonAnak = Engimon();
    if (this->getElement() == anotherEngimon.getElement())
    {
        return engimonAnak;
    }
    else if (this->getLevel() < 1 || anotherEngimon.getLevel() < 1)
    {
        return engimonAnak;
    }
    else
    {
        Engimon engimon1tmp = *this;
        Engimon engimon2tmp = anotherEngimon;

        // this->setLevel(this->getLevel() - 29);
        // anotherEngimon.setLevel(anotherEngimon.getLevel() - 29);

        string nama;
        cout << "Masukkan nama Engimon mu : ";
        cin >> nama;
        cout << endl;
        Engimon tmp(nama, this->species, this->element);
        // engimonAnak = Engimon(nama, this->species, this->element);
        engimonAnak = tmp;

        engimonAnak.parent1 = new string(this->getName());
        engimonAnak.parent2 = new string(anotherEngimon.getName());

        for (int i = 0; i < this->getSkill().size(); i++)
        {
            Skill highest1 = engimon1tmp.getHighestMastery();
            Skill highest2 = engimon2tmp.getHighestMastery();

            //case 1
            if (highest1.getSkillMastery() > highest2.getSkillMastery())
            {
                if (containsSkill(engimon2tmp.getSkill(), highest1.getSkillName()))
                {
                    engimonAnak.AddSkill(highest1);
                    engimon1tmp.RemoveSkill(highest1);
                    engimon2tmp.RemoveSkill(highest2);
                }
                else
                {
                    engimonAnak.AddSkill(highest1);
                    engimon1tmp.RemoveSkill(highest1);
                }
            }
            else if (highest1.getSkillMastery() < highest2.getSkillMastery())
            {
                if (containsSkill(engimon1tmp.getSkill(), highest2.getSkillName()))
                {
                    engimonAnak.AddSkill(highest2);
                    engimon1tmp.RemoveSkill(highest1);
                    engimon2tmp.RemoveSkill(highest2);
                }
                else
                {
                    engimonAnak.AddSkill(highest2);
                    engimon2tmp.RemoveSkill(highest2);
                }
            }
            else
            {
                if (highest1.getSkillName() == highest2.getSkillName())
                {
                    Skill tmp = highest1;
                    tmp.masteryLevelUp(highest1.getSkillPower());
                    engimonAnak.AddSkill(tmp);
                    engimon1tmp.RemoveSkill(highest1);
                    engimon2tmp.RemoveSkill(highest2);
                }
                else
                {
                    engimonAnak.AddSkill(highest1);
                    engimon1tmp.RemoveSkill(highest1);
                }
            }
        }

        return engimonAnak;
    }
}

bool Engimon::isSkillSizeValid(Engimon engimon)
{
    return (engimon.skill.size() <= 4);
}

bool Engimon::containsSkill(list<Skill> listSkill, string skillName)
{
    for (list<Skill>::iterator iter = this->skill.begin(); iter != this->skill.end(); iter++)
    {
        if (skillName == (*iter).getSkillName())
        {
            return true;
        }
    }
    return false;
}

void Engimon::addExp(int exp)
{
    this->experience = new int (*(this->experience + exp));
    this->cumulativeExperience = new int (*(this->cumulativeExperience + exp));
    if (*this->experience >= 100)
    {
        *(this->experience) -= 100;
        *(this->level) += 1;
    }
}

//Getters
string Engimon::getName() { return this->name; }
string Engimon::getSpecies() { return this->species; }
vector<string> Engimon::getElement() { return this->element; }
int Engimon::getLevel() { return *this->level; }
int Engimon::getExperience() { return *this->experience; }
int Engimon::getCumulativeExperience() { return *this->cumulativeExperience; }
list<Skill> Engimon::getSkill() { return this->skill; }
string Engimon::getMessage() { return this->message; }

//Setters
void Engimon::setLevel(int level) { *this->level = level; }
void Engimon::setMessage(string newMessage) { this->message = newMessage; }