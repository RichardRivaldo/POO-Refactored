#include "Skill.hpp"
#include "SkillCat.hpp"

using namespace std;

Skill::Skill() : skillName("Skill"), basePower(0), masteryLevel(1)
{
    vector<string> Elements;
}

Skill::Skill(string name, int power, vector<string> Elmts, int mastery) : skillName(name),
                                                                          basePower(power),
                                                                          masteryLevel(mastery),
                                                                          Elements(Elmts) {}

Skill::Skill(const Skill& skill){
    this->skillName = skill.skillName;
    this->basePower = skill.basePower;
    this->masteryLevel = skill.masteryLevel;
    this->Elements = skill.Elements;
}

Skill& Skill::operator=(const Skill& skill){
    this->skillName = skill.skillName;
    this->basePower = skill.basePower;
    this->masteryLevel = skill.masteryLevel;
    this->Elements = skill.Elements;
    
    return *this;
}

// Skill::~Skill(){
//     // Output Message
//     cout << this->skillName << " is deleted successfully." << endl;
// }

const bool Skill::isSkillLearnable(string engimonElmt)
{
    // STD::find and check if the species of the engimon can learn the skill
    return (find(this->Elements.begin(), this->Elements.end(), engimonElmt) != Elements.end());
}

void Skill::masteryLevelUp(int bpIncrease)
{
    // Increase mastery level and add BP
    this->masteryLevel++;
    this->basePower += bpIncrease;
}

const void Skill::skillInfo()
{
    // Output attributes info
    cout << "Skill Name         : " << this->skillName << endl;
    cout << "Base Power         : " << this->basePower << endl;
    cout << "Mastery Level      : " << this->masteryLevel << endl;
    cout << "Available Elements : [";

    // Iterate through vector with iterator
    for (vector<string>::iterator iter = Elements.begin(); iter != Elements.end(); iter++)
    {
        cout << *iter;

        if (next(iter) != Elements.end())
        {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

string Skill::getSkillName()
{
    return this->skillName;
}

const int Skill::getSkillPower()
{
    return this->basePower;
}

const int Skill::getSkillMastery()
{
    return this->masteryLevel;
}

const vector<string> Skill::getSuitableElmt()
{
    return this->Elements;
}