#include "Engimon.hpp"
#include "SkillandElementsInit.hpp"

using namespace std;

int main()
{
    ` vector<Skill> fireSkills = createFireSkills();
    vector<Skill> waterSkills = createWaterSkills();
    vector<Skill> electricSkills = createElectricSkills();
    vector<Skill> groundSkills = createGroundSkills();
    vector<Skill> iceSkills = createIceSkills();

    Engimon engimon1 = Engimon("Engimon A", "Firemon", {FIRE, FIRE});
    Engimon engimon2 = Engimon("Engimon B", "Firemon", {FIRE, FIRE});

    engimon1.AddSkill(fireSkills[0]);
    engimon1.AddSkill(fireSkills[1]);
    engimon1.AddSkill(fireSkills[2]);
    engimon1.AddSkill(fireSkills[3]);

    engimon2.AddSkill(fireSkills[0]);
    engimon2.AddSkill(fireSkills[1]);
    engimon2.AddSkill(fireSkills[2]);
    engimon2.AddSkill(fireSkills[3]);

    engimon1.showStats();
    cout << endl;
    engimon2.showStats();
    cout << endl;

    cout << "Getter tests" << endl;
    cout << engimon1.getName() << endl;
    cout << engimon1.getSpecies() << endl;
    cout << engimon1.getLevel() << endl;
    cout << engimon1.getExperience() << endl;
    cout << engimon1.getCumulativeExperience() << endl;

    cout << "Setter test" << endl;
    engimon1.setLevel(35);
    engimon2.setLevel(35);
    cout << engimon1.getLevel() << endl;
    cout << engimon1.getLevel() << endl;

    cout << engimon1.CheckDead(engimon1) << endl;
    cout << engimon2.CheckDead(engimon2) << endl;

    cout << engimon1.CheckLevelUp(engimon1) << endl;
    cout << engimon2.CheckLevelUp(engimon2) << endl;

    cout << "Breeding" << endl;
    Engimon engimonChild = engimonChild.breed(engimon1, engimon2);
    engimonChild.showStats();
    cout << engimonChild.getSkill().size();

    engimon1.~Engimon();
    engimon2.~Engimon();
}