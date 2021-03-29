#include "SkillItem.hpp"

SkillItem::SkillItem()
{
    Skill defSkill;
    this->skillItem.first = defSkill;
    this->skillItem.second = new int(1);
}

SkillItem::SkillItem(Skill skill, int amount)
{
    this->skillItem.first = skill;
    this->skillItem.second = new int(amount);
}

SkillItem::SkillItem(const SkillItem &item)
{
    this->skillItem.first = item.skillItem.first;
    this->skillItem.second = item.skillItem.second;
}

SkillItem &SkillItem::operator=(const SkillItem &item)
{
    this->skillItem.first = item.skillItem.first;
    this->skillItem.second = item.skillItem.second;

    return *this;
}

void SkillItem::addItemAmount(int amount)
{
    cout << "menambahkan sebanyak " << amount << endl;
    cout << *(this->skillItem.second) << endl;
    *(this->skillItem.second) += amount;
    cout << *(this->skillItem.second) << endl;
}

void SkillItem::decItemAmount(int amount)
{
    cout << "mengurangi sebanyak " << amount << endl;
    cout << *(this->skillItem.second) << endl;
    *(this->skillItem.second) = *(this->skillItem.second) - amount;
    cout << *(this->skillItem.second) << endl;
}

const void SkillItem::skillItemInfo()
{
    cout << "Item of Skill   : " << this->skillItem.first.getSkillName() << endl;
    cout << "Amount of Items : " << *(this->skillItem.second) << endl;
}

Skill SkillItem::getSkill()
{
    return this->skillItem.first;
}
const int SkillItem::getAmount()
{
    return *(this->skillItem.second);
}