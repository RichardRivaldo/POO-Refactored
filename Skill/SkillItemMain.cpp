#include "SkillItem.hpp"
#include "SkillCat.hpp"
#include <cassert>

void test_constructor(){
    // Init Skill
    vector<string> elmt = {"Fire", "Water", "Wind", "Earth"};
    Skill autokill("Autokill", 100000, elmt, 1000000);

    // Skill Item
    SkillItem defItem;
    SkillItem autokillItem(autokill, 20);

    // Get Skill Item Information
    cout << "---------------------" << endl;
    defItem.skillItemInfo();
    autokillItem.skillItemInfo();
    cout << "---------------------" << endl;

    assert(autokillItem.getSkill().getSkillName() == autokill.getSkillName());
    assert(autokillItem.getAmount() == 20);
    assert(defItem.getAmount() == 1);
}

void test_properties(){
    // Init Skill
    vector<string> elmt = {"Fire", "Water", "Wind", "Earth"};
    Skill autokill("Autokill", 100000, elmt, 1000000);

    // Skill Item
    SkillItem defItem;
    SkillItem autokillItem(autokill, 20);

    // Decrease and Increase Amount
    defItem.addItemAmount(100);
    autokillItem.decItemAmount();

    // Get Skill Item Information
    cout << "---------------------" << endl;
    defItem.skillItemInfo();
    autokillItem.skillItemInfo();
    cout << "---------------------" << endl;

    assert(defItem.getAmount() == 101);
    assert(autokillItem.getAmount() == 19);
}

void test_unique_special(){
    // Init ELements
    vector<string> elmt = {"Fire", "Water", "Wind", "Earth"};

    // Unique and Special Skill Item
    SpecialSkill special("BOOM!", 100000, elmt, 1);
    UniqueSkill unique("Endgame", 100000, elmt, "God");

    SkillItem specialItem(special);
    SkillItem uniqueItem(unique);

    // Check
    cout << "---------------------" << endl;
    specialItem.skillItemInfo();
    uniqueItem.skillItemInfo();
    cout << "---------------------" << endl;

    assert(specialItem.getSkill().getSkillName() == special.getSkillName());
    assert(uniqueItem.getSkill().getSkillName() == unique.getSkillName());
    assert(uniqueItem.getAmount() == 1);
    assert(specialItem.getAmount() == 1);
}

int main(){
    test_constructor();
    test_properties();
    test_unique_special();

    return 0;
}