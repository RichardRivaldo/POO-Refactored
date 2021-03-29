#ifndef __SKILLCAT__HPP__
#define __SKILLCAT__HPP__
#include "Skill.hpp"

class UniqueSkill: public Skill{
    private:
        // Species of the Unique Skill
        string Species;
    public:
        // Default Constructor
        UniqueSkill();
        // User-Defined Constructor
        UniqueSkill(string name, int basePower, vector<string> elmts, string species, int mastery = 1);
        // Copy Constructor
        UniqueSkill(const UniqueSkill& unique);
        // Operator=
        UniqueSkill& operator=(const UniqueSkill& unique);

        // Methods
        const bool isSkillLearnable(string engimonElmt, string species);
        const void skillInfo();

        // Getter
        const string getSkillSpecies();
};

class SpecialSkill: public Skill{
    private:
        // Additional Power of The Special Skill
        int additionalPower;
    public:
        // Default Constructor
        SpecialSkill();
        // User-Defined Constructor
        SpecialSkill(string name, int basePower, vector<string> elmts, int addPower, int mastery = 1);
        // Copy Constructor
        SpecialSkill(const SpecialSkill& special);
        // Operator=
        SpecialSkill& operator=(const SpecialSkill& special);

        // Methods
        const int totalDamage();
        const void skillInfo();

        // Getter
        const int getAddPower();
};

#endif