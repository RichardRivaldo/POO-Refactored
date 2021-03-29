#include "Player.hpp"
#include "Engimon.hpp"
#include "Inventory.hpp"
#include "Skill.hpp"
#include "SkillCat.hpp"
#include "SkillItem.hpp"
#include "Map.hpp"
#include "Battle.hpp"
#include "SkillandElementsInit.hpp"
#include <string>
#include <cmath>

using namespace std;

void showHelp()
{
    cout << "HELP HERE!" << endl;
    cout << "-------------------------" << endl;
    cout << "w : Move Up" << endl;
    cout << "a : Move Left" << endl;
    cout << "s : Move Down" << endl;
    cout << "d : Move Right" << endl;
    cout << "help : Show Help Menu" << endl;
    cout << "items : Show Skill Items" << endl;
    cout << "engimons : Show Engimons" << endl;
    cout << "breed : Breed Two Engimons" << endl;
    cout << "show: Show Active Engimons" << endl;
    cout << "stats: Show Engimons Stats" << endl;
    cout << "engi: Interact With Engimons" << endl;
    cout << "swap: Swap Active Engimons" << endl;
    cout << "learn: Learn New Skills" << endl;
    cout << "battle: Challenge Engimons!" << endl;
    cout << "quit: Exit The Game." << endl;
}

Engimon initializeStarterEngimon(vector<Skill> fireSkills, vector<Skill> waterSkills, vector<Skill> electricSkills, vector<Skill> groundSkills, vector<Skill> iceSkills)
{
    string nama;
    int pilihan;
    cout << "Pilih Engimon kamu (1 - 5): " << endl;
    cout << "1. Firemon" << endl;
    cout << "2. Watermon" << endl;
    cout << "3. Electromon" << endl;
    cout << "4. Groundmon" << endl;
    cout << "5. Icemon" << endl;
    while (true)
    {
        cin >> pilihan;
        if (pilihan == 1)
        {
            cout << "Masukkan nama Firemon mu : ";
            cin >> nama;
            cout << endl;
            Engimon starterEngimon(nama, "Firemon", vector<string>{FIRE, FIRE});
            starterEngimon.AddSkill(fireSkills[0]);
            return starterEngimon;
        }
        else if (pilihan == 2)
        {
            cout << "Masukkan nama Watermon mu : ";
            cin >> nama;
            cout << endl;
            Engimon starterEngimon(nama, "Watermon", {WATER, WATER});
            starterEngimon.AddSkill(waterSkills[0]);
            return starterEngimon;
        }
        else if (pilihan == 3)
        {
            cout << "Masukkan nama Electricmon mu : ";
            cin >> nama;
            cout << endl;
            Engimon starterEngimon(nama, "Electromon", {ELECTRIC, ELECTRIC});
            starterEngimon.AddSkill(electricSkills[0]);
            return starterEngimon;
        }
        else if (pilihan == 4)
        {
            cout << "Masukkan nama Groundmon mu : ";
            cin >> nama;
            cout << endl;
            Engimon starterEngimon(nama, "Groundmon", {GROUND, GROUND});
            starterEngimon.AddSkill(groundSkills[0]);
            return starterEngimon;
        }
        else if (pilihan == 5)
        {
            cout << "Masukkan nama Icemon mu : ";
            cin >> nama;
            cout << endl;
            Engimon starterEngimon(nama, "Icemon", {ICE, ICE});
            starterEngimon.AddSkill(iceSkills[0]);
            return starterEngimon;
        }
        else
        {
            cout << "Masukan tidak valid, coba lagi" << endl;
        }
    }
}

void showWelcomingMessage()
{
    cout << "    Welcome to Willy Wangky's Engimon Factory. For those of you who do not recognise me, allow me to introduce myself. Hi, I'm Willy Wangky, the greatest theme park builder. Why am I great? you may ask. Well, the answer is because I do not build the theme park myself. I get students to do it for me." << endl;
    cout << "    Type in 'help' to see the list of all available commands" << endl;
}

int main()
{
    bool gameEnd = false;

    showWelcomingMessage();

    // Init Skills
    vector<Skill> fireSkills = createFireSkills();
    vector<Skill> waterSkills = createWaterSkills();
    vector<Skill> electricSkills = createElectricSkills();
    vector<Skill> groundSkills = createGroundSkills();
    vector<Skill> iceSkills = createIceSkills();

    // Init Skill Items
    vector<SkillItem> fireItems = createSkillItem(fireSkills);
    vector<SkillItem> waterItems = createSkillItem(waterSkills);
    vector<SkillItem> electricItems = createSkillItem(electricSkills);
    vector<SkillItem> groundItems = createSkillItem(groundSkills);
    vector<SkillItem> iceItems = createSkillItem(iceSkills);

    // Starting game, initialize starter engimon

    Engimon starterEngimon = initializeStarterEngimon(fireSkills, waterSkills, electricSkills, groundSkills, iceSkills);
    Player player(starterEngimon);

    while (!gameEnd)
    {
        try
        {
            // Ngeprint tampilan
            player.getMap().printMap();
            cout << "---------------------" << endl;
            string command;
            cout << "$ ";
            cin >> command;
            cout << endl;

            // Jalanin Commands
            if (command == "help")
            {
                showHelp();
            }
            else if (command == "w")
            {
                player.moveUp();
            }
            else if (command == "a")
            {
                player.moveLeft();
            }
            else if (command == "s")
            {
                player.moveDown();
            }
            else if (command == "d")
            {
                player.moveRight();
            }
            else if (command == "items")
            {
                player.showOwnedItems();
            }
            else if (command == "engimons")
            {
                player.showOwnedEngimon();
            }
            else if (command == "breed")
            {
                string pilihan1, pilihan2;
                player.showOwnedEngimon();
                cout << "Input nama engimon yang akan di breed : " << endl;
                cout << "$ ";
                cin >> pilihan1;
                cout << endl;
                cout << "Input nama pasangannya : " << endl;
                cout << "$ ";
                cin >> pilihan2;
                cout << endl;
                player.doBreed(pilihan1, pilihan2);
            }
            else if (command == "show")
            {
                player.showActiveEngimon();
            }
            else if (command == "stats"){
                cout << "Masukkan nama Engimon yang ingin dicek: " << endl;
                string engimonName;
                cin >> engimonName;
                player.showStatsEngimon(engimonName);
            }
            else if (command == "engi")
            {
                player.interactWithEngimon();
            }
            else if (command == "swap")
            {
                string engimonName;
                cout << "Enter the name of Engimon that you want to swap!" << endl;
                cin >> engimonName;
                cout << "Swapping Active Engimon..." << endl;
                player.swapActiveEngimon(engimonName);
            }
            else if (command == "learn")
            {
                string skillName;
                cout << "Enter the name of the Skill that you want to learn!" << endl;
                cin >> skillName;
                cout << "Learning the new skill..." << endl;
                player.learnSkill(skillName);
            }
            else if (command == "battle")
            {
                bool found = false;
                for (int i = 0; i < player.getMap().getengimonLiar().size(); i++)
                {
                    if (player.getMap().getengimonLiar().at(i).first == player.getMap().getplayerPosition() || (player.getMap().getengimonLiar().at(i).first.getXCoordinate() == player.getMap().getplayerPositionX() - 1 && player.getMap().getengimonLiar().at(i).first.getYCoordinate() == player.getMap().getplayerPositionY()) || (player.getMap().getengimonLiar().at(i).first.getXCoordinate() == player.getMap().getplayerPositionX() + 1 && player.getMap().getengimonLiar().at(i).first.getYCoordinate() == player.getMap().getplayerPositionY()) || (player.getMap().getengimonLiar().at(i).first.getXCoordinate() == player.getMap().getplayerPositionX() && player.getMap().getengimonLiar().at(i).first.getYCoordinate() == player.getMap().getplayerPositionY() - 1) || (player.getMap().getengimonLiar().at(i).first.getXCoordinate() == player.getMap().getplayerPositionX() && player.getMap().getengimonLiar().at(i).first.getYCoordinate() == player.getMap().getplayerPositionY() + 1))
                    {
                        found = true;
                        Battle B(player, player.getActiveEngimon(), player.getMap().getengimonLiar().at(i).second);
                        B.doBattle();
                        if (B.getWinner() == player.getActiveEngimon().getName())
                        {
                            SkillItem item = B.getRandomSkill(fireItems, waterItems, electricItems, groundItems, iceItems);
                            player.addSkillItem(item);
                            player.addEngimon(player.getMap().getengimonLiar().at(i).second);
                            int exp = floor(100 / player.getActiveEngimon().getLevel()); 
                            // cout << exp;
                            player.getActiveEngimon().addExp(exp);
                            player.getMap().removeEngimonLiar(player.getMap().getengimonLiar().at(i).second);
                            cout << "Player mendapatkan skill item baru: " << item.getSkill().getSkillName() << endl;
                        }
                        else
                        {
                            player.getActiveEngimon().~Engimon();
                        }
                    }
                    else if (found == true)
                    {
                        break;
                    }
                }
            }
            else if (command == "quit")
            {
                cout << "Thank you for playing!" << endl;
                gameEnd = true;
            }
            else
            {
                cout << "Invalid Command!" << endl;
            }
        }
        catch (char const* e)
        {
            cout << "Error ";
            cout << e << endl;
        }
        // Cek kondisi game end disini
    }

    //Tambahin firstEngimon ke inventory player

    return 0;
}