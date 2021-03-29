#include "SkillCat.hpp"
#include <cassert>

void test_constructor_skill(){
    // Init ELements
    vector<string> elmt = {"Fire", "Water", "Wind", "Earth"};

    // Construct the object
    Skill s1;
    Skill s2("Autokill", 100000, elmt);

    // Print Skill Info
    s1.skillInfo();
    cout << "--------------------" << endl;
    s2.skillInfo();
    cout << "--------------------" << endl;

    assert(s2.getSkillName() == "Autokill");
    assert(s2.getSkillMastery() == 1);
    assert(s1.getSkillPower() == 0);
    assert(s2.getSuitableElmt() == elmt);
}

void test_properties(){
    // Init ELements
    vector<string> elmt = {"Fire", "Water", "Wind", "Earth"};

    // Construct the object
    Skill s1;
    Skill s2("Autokill", 100000, elmt);

    // Method Check: isSkillLearnable
    if(!s2.isSkillLearnable("Dirt")){
        cout << "Not Learnable" << endl;
    }
    if(s2.isSkillLearnable("Fire")){
        cout << "Learnable" << endl;
    }
    cout << "--------------------" << endl;

    assert(!s2.isSkillLearnable("Dirt"));
    assert(s2.isSkillLearnable("Fire"));

    // Method Check: masteryLevelUp
    s2.masteryLevelUp(11111);

    // Check modified
    s2.skillInfo();
    cout << "--------------------" << endl;

    assert(s2.getSkillMastery() == 2);
    assert(s2.getSkillPower() == 111111);
}

void test_unique_special(){
    // Init ELements
    vector<string> elmt = {"Fire", "Water", "Wind", "Earth"};

    UniqueSkill unique("Endgame", 100000, elmt, "God");
    unique.skillInfo();
    cout << unique.getSkillSpecies() << endl;
    cout << "--------------------" << endl;

    // Special Skill
    SpecialSkill special("BOOM!", 100000, elmt, 1);
    special.skillInfo();
    cout << special.getAddPower() << endl;
    cout << special.totalDamage() << endl;
    cout << "--------------------" << endl;
}

int main(){
    test_constructor_skill();
    test_properties();
    test_unique_special();
    
    return 0;
}