#ifndef SKILLS_AND_ELEMENTS_HPP
#define SKILLS_AND_ELEMENTS_HPP
#include "Skill.hpp"
#include "SkillCat.hpp"
#include "SkillItem.hpp"

using namespace std;

//Define elements
const string FIRE = "Fire";
const string WATER = "Water";
const string ELECTRIC = "Electric";
const string GROUND = "Ground";
const string ICE = "Ice";
// enum Elements {Fire, Water, Electric, Ground, Ice};

// Create Skills based on Elements
vector<Skill> createFireSkills()
{
    UniqueSkill Fireball("Fireball", 20, vector<string>{FIRE}, "Firemon");
    Skill CrimsonFire("CrimsonFire", 10, vector<string>{FIRE});
    Skill Flamethrower("FlameThrower", 12, vector<string>{FIRE, ELECTRIC});
    Skill HeatWave("HeatWave", 14, vector<string>{FIRE});
    Skill ScorchingSands("ScorchingSands", 12, vector<string>{GROUND, FIRE});
    SpecialSkill Hellfire("Hellfire", 65, vector<string>{FIRE}, 10);
    SpecialSkill ChasmTrample("ChasmTrample", 70, vector<string>{FIRE}, 10);

    return vector<Skill>{Fireball, CrimsonFire, Flamethrower, HeatWave, Hellfire, ChasmTrample, ScorchingSands};
}

vector<Skill> createWaterSkills()
{
    UniqueSkill Watercut("Watercut", 20, vector<string>{WATER}, "Watermon");
    Skill LittleWanderers("LittleWanderers", 10, vector<string>{WATER});
    Skill DancingRain("DancingRain", 12, vector<string>{WATER, ICE});
    Skill Tsunami("Tsunami", 14, vector<string>{WATER});
    Skill SubzeroSlammer("SubzeroSlammer", 10, vector<string>{ICE, WATER});
    SpecialSkill BubbleBeam("BubbleBeam", 60, vector<string>{WATER}, 10);
    SpecialSkill PoseidonWrath("Poseidon's Wrath", 75, vector<string>{WATER}, 10);

    return vector<Skill>{Watercut, LittleWanderers, DancingRain, Tsunami, BubbleBeam, PoseidonWrath, SubzeroSlammer};
}

vector<Skill> createElectricSkills()
{
    UniqueSkill Thunderslash("Thunderslash", 20, vector<string>{ELECTRIC}, "Electromon");
    Skill PlasmaFist("PlasmaFist", 10, vector<string>{ELECTRIC});
    Skill PikaPapow("PikaPapow", 12, vector<string>{ELECTRIC});
    Skill Flamethrower("FlameThrower", 12, vector<string>{FIRE, ELECTRIC});
    Skill StokedSparksurfer("StokedSparksurfer", 14, vector<string>{ELECTRIC, GROUND});
    SpecialSkill BOLT("10,000,000VoltThunderbolt", 75, vector<string>{ELECTRIC}, 10);
    SpecialSkill ForkedLightning("ForkedLightning", 60, vector<string>{ELECTRIC}, 10);

    return vector<Skill>{Thunderslash, PlasmaFist, PikaPapow, StokedSparksurfer, BOLT, ForkedLightning, Flamethrower};
}

vector<Skill> createGroundSkills()
{
    UniqueSkill Earthquake("Earthquake", 20, vector<string>{GROUND}, "Groundmon");
    Skill SpikesOfDeath("SpikesofDeath", 10, vector<string>{GROUND});
    Skill ScorchingSands("ScorchingSands", 12, vector<string>{GROUND, FIRE});
    Skill TempestOfBlades("TempestofBlades", 14, vector<string>{GROUND});
    Skill StokedSparksurfer("StokedSparksurfer", 14, vector<string>{ELECTRIC, GROUND});
    SpecialSkill Void("Void", 70, vector<string>{GROUND}, 10);
    SpecialSkill ThornedRose("ThornedRose", 75, vector<string>{GROUND}, 10);

    return vector<Skill>{Earthquake, SpikesOfDeath, ScorchingSands, TempestOfBlades, Void, ThornedRose, StokedSparksurfer};
}

vector<Skill> createIceSkills()
{
    UniqueSkill Blizzard("Blizzard", 20, vector<string>{ICE}, "Icemon");
    Skill SubzeroSlammer("SubzeroSlammer", 10, vector<string>{ICE, WATER});
    Skill IceSpearhead("IceSpearhead", 12, vector<string>{ICE});
    Skill Avalanche("Avalanche", 14, vector<string>{ICE});
    Skill DancingRain("DancingRain", 12, vector<string>{WATER, ICE});
    SpecialSkill CastleOfIce("CastleofIce", 55, vector<string>{ICE}, 10);
    SpecialSkill Avalon("Avalon", 80, vector<string>{ICE}, 10);

    return vector<Skill>{Blizzard, SubzeroSlammer, IceSpearhead, Avalanche, CastleOfIce, Avalon, DancingRain};
}

// Create Skill Items Based on Elements
vector<SkillItem> createSkillItem(vector<Skill> Skills)
{
    vector<SkillItem> skillItems;
    for (int i = 0; i < Skills.size(); i++)
    {
        SkillItem temp(Skills[i]);
        skillItems.push_back(temp);
    }

    return skillItems;
}

// Testing

// int main(){
//     vector<Skill> fireSkills = createFireSkills();
//     for(int i = 0; i < fireSkills.size(); i++){
//         cout << fireSkills[i].getSkillName() << endl;
//     }

//     vector<SkillItem> fireSkillItems = createSkillItem(fireSkills);
//     for(int i = 0; i < fireSkillItems.size(); i++){
//         cout << fireSkillItems[i].getSkill().getSkillName() << endl;
//     }
// }
#endif