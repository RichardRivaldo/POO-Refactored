#ifndef ENGIMON_HPP
#define ENGIMON_HPP
#include <string>
#include <list>
#include <vector>
#include <iostream>
#include "Skill.hpp"

using namespace std;

class Engimon
{
protected:
    string name;
    string species;
    list<Skill> skill;
    vector<string> element;
    int* level;
    int* experience;
    int* cumulativeExperience;
    // string *parent1;
    // string *parent2;
    string* parent1;
    string* parent2;
    string message;

public:
    Engimon();
    Engimon(string nama, string species, vector<string> element);
    Engimon(const Engimon &engimon);
    ~Engimon();
    Engimon &operator=(const Engimon &);
    bool operator==(const Engimon &engimon) const;

    void CheckLevelUp(Engimon engimon);
    bool CheckDead(Engimon engimon);
    const Skill getHighestMastery();
    void showStats();
    void AddSkill(Skill skill);
    void RemoveSkillByIdx(int skillIdx);
    void RemoveSkill(Skill skill);
    bool containsSkill(list<Skill> listSkill, string skillName);

    Engimon breed(Engimon anotherEngimon);
    bool isSkillSizeValid(Engimon engimon);
    void addExp(int exp);

    //Getters
    string getName();
    string getSpecies();
    string getMessage();
    vector<string> getElement();
    int getLevel();
    int getExperience();
    int getCumulativeExperience();
    list<Skill> getSkill();

    //Setters
    void setLevel(int level); // Used for debugging purposes
    void pushToParents(Engimon parent);
    void setMessage(string newMessage);
    void setParent1(string engimon1);
    void setParent2(string engimon2);
};
#endif