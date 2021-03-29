#ifndef __SKILL__HPP__
#define __SKILL__HPP__
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Skill
{
protected:
    // Skill name
    string skillName;
    // Power
    int basePower;
    // Mastery Level
    int masteryLevel;
    // Elements
    vector<string> Elements;

public:
    // Default Constructor, fill with default of each attribute
    Skill();
    // User-Defined Constructor
    Skill(string name, int power, vector<string> Elmts, int mastery = 1);
    // Destructor - Not really needed, just to ensure the object is destructed correctly
    // ~Skill();
    // Copy Constructor
    Skill(const Skill& skill);
    // Operator = 
    Skill& operator=(const Skill& skill);

    // Methods
    virtual const bool isSkillLearnable(string engimonElmt);
    void masteryLevelUp(int bpIncrease);
    virtual const void skillInfo();

    // Getter
    string getSkillName();
    const int getSkillPower();
    const int getSkillMastery();
    const vector<string> getSuitableElmt();

};

#endif