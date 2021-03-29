#include "Map.hpp"
#include "Position.hpp"
#include "Engimon.hpp"
#include <stdlib.h>
#include <iostream>
#include<fstream>
#include <vector>
#include <iterator>
#include <new>
using namespace std;

Map::Map()
{
    xmax = 10;
    ymax = 10;
    setCapital = 5;
    dimensiWater = 5;
    maxEngimonLiar = 5;
    engimonLiar = vector<pair<Position, Engimon>>();
    for (int i = 0; i < xmax; i++)
    {
        peta.push_back(vector<char>());
        for (int j = 0; j < ymax; j++)
        {
            if (i >= xmax - dimensiWater || j < ymax - dimensiWater)
            {
                peta.at(i).push_back('-');
            }
            else
            {
                peta.at(i).push_back('0');
            }
        }
    }
}

Map::~Map()
{
    //
}
void Map::printMap()
{
    for (int i = 0; i < xmax; i++)
    {
        for (int j = 0; j < ymax; j++)
        {
            cout << peta[i][j] << " ";
        }
        cout << endl;
    }
}

vector<pair<Position, Engimon>> Map::getengimonLiar()
{
    return this->engimonLiar;
}
void Map::addEngimonLiar()
{
    if (engimonLiar.size() < maxEngimonLiar)
    {
        int coorX;
        int coorY;
        bool foundx = false;
        bool foundy = false;
        while (!foundx)
        {
            coorX = rand() % (xmax - 1);
            if (coorX != getplayerPositionX() && coorX != getactiveEngimonPositionX())
            {
                foundx = true;
            }
        }
        while (!foundy)
        {
            coorY = rand() % (ymax - 1);
            if (coorY != getplayerPositionY() && coorY != getactiveEngimonPositionY())
            {
                foundy = true;
            }
        }
        Position engimonLiarpos = Position(coorX, coorY);
        //coorX dan coorY ketemu
        //random nama
        enum Name
        {
            Omnimon,
            Skull,
            Greymon,
            Piedmon,
            War_Greymon,
            MagnaAngemon,
            Garurumon,
            Devimon,
            Apocalypmon,
            Etemon,
            Agumon,
            Total
        };
        static const char *enum_str_name[] = {"Omnimon", "Skull", "Greymon", "Piedmon", "War_Greymon", "MagnaAngemon", "Garurumon", "Devimon", "Apocalypmon", "Etemon", "Agumon"};
        Name name = Name(rand() % 11);
        string nama(enum_str_name[name]);
        //nama ketemu
        //random species
        enum Species
        {
            Firemon,
            Watermon,
            Electromon,
            Groundmon,
            Icemon,
            Total3
        };
        static const char *enum_str_species[] = {"Firemon", "Watermon", "Electromon", "Groundmon", "Icemon"};
        Species species = Species(rand() % 5);
        string spesies(enum_str_species[species]);
        //spesies ketemu
        //random element (susah nih wkwk)
        vector<string> elemennya = vector<string>();
        if (coorX <= xmax - dimensiWater || coorY >= ymax - dimensiWater)
        { //grassland
            enum Element
            {
                F,
                G,
                E,
                L,
                N,
                Total2
            };
            static const char *enum_str_element[] = {"Fire", "Ground", "Electric", "Fire/Electric", "Water/Ground"};
            Element element = Element(rand() % 5);
            string elemen(enum_str_element[element]);
            if (elemen == "Fire/Electric")
            {
                elemennya.push_back("Fire");
                elemennya.push_back("Electric");
            }
            else if (elemen == "Water/Ground")
            {
                elemennya.push_back("Water");
                elemennya.push_back("Ground");
            }
            else
            {
                elemennya.push_back(elemen);
                elemennya.push_back(elemen);
            }
        }
        else
        {
            enum Element
            {
                W,
                I,
                S,
                N,
                Total1
            };
            static const char *enum_str_element[] = {"Water", "Ice", "Water/Ice", "Water/Ground"};
            Element element = Element(rand() % 4);
            string elemen(enum_str_element[element]);
            if (elemen == "Water/Ice")
            {
                elemennya.push_back("Water");
                elemennya.push_back("Ice");
            }
            else if (elemen == "Water/Ground")
            {
                elemennya.push_back("Water");
                elemennya.push_back("Ground");
            }
            else
            {
                elemennya.push_back(elemen);
                elemennya.push_back(elemen);
            }
        }
        Engimon engimonbaru = Engimon(nama, spesies, elemennya);
        pair<Position, Engimon> engimonnya;
        engimonnya.first = engimonLiarpos;
        engimonnya.second = engimonbaru;
        engimonLiar.push_back(engimonnya);
        setAlphabet(engimonbaru, coorX, coorY);
    }
}

void Map::moveAllEngimonLiar()
{
    //cleaning dulu
    for (int i = 0; i < xmax; i++)
    {
        for (int j = 0; j < ymax; j++)
        {
            if (peta[i][j] != 'P' && peta[i][j] != 'X')
            {
                if (i >= xmax - dimensiWater || j < ymax - dimensiWater)
                {
                    peta.at(i).at(j) = '-';
                }
                else
                {
                    peta.at(i).at(j) = '0';
                }
            }
        }
    }
    for (int a = 0; a < engimonLiar.size(); a++)
    {
        enum Direction
        {
            N,
            E,
            S,
            W
        };
        static const char *enum_str_direction[] = {"North", "East", "South", "West"};
        Direction direction = Direction(rand() % 3);
        string arah(enum_str_direction[direction]);
        if (arah == "North" && engimonLiar.at(a).first.getYCoordinate() - 1 >= 0 && engimonLiar.at(a).first.getYCoordinate() - 1 != playerPosition.getYCoordinate() && engimonLiar.at(a).first.getYCoordinate() - 1 != activeEngimonPositon.getYCoordinate())
        {
            if (engimonLiar.at(a).second.getElement().at(0) == "Water" && engimonLiar.at(a).second.getElement().at(0) == "Ground")
            {
                engimonLiar.at(a).first.setYCoordinate(engimonLiar.at(a).first.getYCoordinate() - 1);
            }
            else if (engimonLiar.at(a).second.getElement().at(0) == "Water" || engimonLiar.at(a).second.getElement().at(0) == "Ice")
            {
                if (engimonLiar.at(a).first.getXCoordinate() >= xmax - dimensiWater && engimonLiar.at(a).first.getYCoordinate() < ymax - dimensiWater)
                {
                    engimonLiar.at(a).first.setYCoordinate(engimonLiar.at(a).first.getYCoordinate() - 1);
                }
            }
            else
            {
                if (engimonLiar.at(a).first.getYCoordinate() - 1 >= ymax - dimensiWater)
                {
                    engimonLiar.at(a).first.setYCoordinate(engimonLiar.at(a).first.getYCoordinate() - 1);
                }
            }
        }
        else if (arah == "South" && engimonLiar.at(a).first.getYCoordinate() + 1 < ymax && engimonLiar.at(a).first.getYCoordinate() + 1 != playerPosition.getYCoordinate() && engimonLiar.at(a).first.getYCoordinate() + 1 != activeEngimonPositon.getYCoordinate())
        {
            if (engimonLiar.at(a).second.getElement().at(0) == "Water" || engimonLiar.at(a).second.getElement().at(0) == "Ice")
            {
                if (engimonLiar.at(a).first.getXCoordinate() >= xmax - dimensiWater && engimonLiar.at(a).first.getYCoordinate() < ymax - dimensiWater && engimonLiar.at(a).first.getYCoordinate() + 1 < ymax - dimensiWater)
                {
                    engimonLiar.at(a).first.setYCoordinate(engimonLiar.at(a).first.getYCoordinate() + 1);
                }
            }
            else
            {
                engimonLiar.at(a).first.setYCoordinate(engimonLiar.at(a).first.getYCoordinate() + 1);
            }
        }
        else if (arah == "West" && engimonLiar.at(a).first.getXCoordinate() - 1 >= 0 && engimonLiar.at(a).first.getXCoordinate() - 1 != playerPosition.getXCoordinate() && engimonLiar.at(a).first.getXCoordinate() - 1 != activeEngimonPositon.getXCoordinate())
        {
            if (engimonLiar.at(a).second.getElement().at(0) == "Water" || engimonLiar.at(a).second.getElement().at(0) == "Ice")
            {
                if (engimonLiar.at(a).first.getXCoordinate() >= xmax - dimensiWater && engimonLiar.at(a).first.getYCoordinate() < ymax - dimensiWater && engimonLiar.at(a).first.getXCoordinate() - 1 >= xmax - dimensiWater)
                {
                    engimonLiar.at(a).first.setXCoordinate(engimonLiar.at(a).first.getXCoordinate() - 1);
                }
            }
            else
            {
                engimonLiar.at(a).first.setXCoordinate(engimonLiar.at(a).first.getXCoordinate() - 1);
            }
        }
        else if (arah == "East" && engimonLiar.at(a).first.getXCoordinate() + 1 < xmax && engimonLiar.at(a).first.getXCoordinate() + 1 != playerPosition.getXCoordinate() && engimonLiar.at(a).first.getXCoordinate() + 1 != activeEngimonPositon.getXCoordinate())
        {
            if (engimonLiar.at(a).second.getElement().at(0) == "Water" && engimonLiar.at(a).second.getElement().at(0) == "Ground")
            {
                engimonLiar.at(a).first.setXCoordinate(engimonLiar.at(a).first.getXCoordinate() + 1);
            }
            else if (engimonLiar.at(a).second.getElement().at(0) == "Water" || engimonLiar.at(a).second.getElement().at(0) == "Ice")
            {
                if (engimonLiar.at(a).first.getXCoordinate() >= xmax - dimensiWater && engimonLiar.at(a).first.getYCoordinate() < ymax - dimensiWater)
                {
                    engimonLiar.at(a).first.setXCoordinate(engimonLiar.at(a).first.getXCoordinate() + 1);
                }
            }
            else
            {
                if (engimonLiar.at(a).first.getXCoordinate() + 1 < xmax - dimensiWater)
                {
                    engimonLiar.at(a).first.setXCoordinate(engimonLiar.at(a).first.getXCoordinate() - 1);
                }
            }
        }
        setAlphabet(engimonLiar.at(a).second, engimonLiar.at(a).first.getYCoordinate(), engimonLiar.at(a).first.getXCoordinate());
    }
}

void Map::setAlphabet(Engimon engimonbaru, int coorY, int coorX)
{
    if (engimonbaru.getElement().at(0) == "Fire" && engimonbaru.getElement().at(1) == "Fire")
    {
        peta[coorY][coorX] = 'f';
    }
    else if (engimonbaru.getElement().at(0) == "Water" && engimonbaru.getElement().at(1) == "Water")
    {
        peta[coorY][coorX] = 'w';
    }
    else if (engimonbaru.getElement().at(0) == "Ice" && engimonbaru.getElement().at(1) == "Ice")
    {
        peta[coorY][coorX] = 'i';
    }
    else if (engimonbaru.getElement().at(0) == "Ground" && engimonbaru.getElement().at(1) == "Ground")
    {
        peta[coorY][coorX] = 'g';
    }
    else if (engimonbaru.getElement().at(0) == "Electric" && engimonbaru.getElement().at(1) == "Electric")
    {
        peta[coorY][coorX] = 'e';
    }
    else if (engimonbaru.getElement().at(0) == "Fire" && engimonbaru.getElement().at(1) == "Electric")
    {
        peta[coorY][coorX] = 'l';
    }
    else if (engimonbaru.getElement().at(0) == "Water" && engimonbaru.getElement().at(1) == "Ice")
    {
        peta[coorY][coorX] = 's';
    }
    else if (engimonbaru.getElement().at(0) == "Water" && engimonbaru.getElement().at(1) == "Ground")
    {
        peta[coorY][coorX] = 'n';
    }
}
void Map::removeEngimonLiar(Engimon engimon)
{
    int index;
    int xnya;
    int ynya;
    for (int i = 0; i < engimonLiar.size(); i++)
    {
        if (engimonLiar.at(i).second == engimon)
        {
            index = i;
        }
    }
    xnya = engimonLiar.at(index).first.getXCoordinate();
    ynya = engimonLiar.at(index).first.getYCoordinate();
    if (xnya <= xmax - dimensiWater || ynya >= ymax - dimensiWater)
    {
        peta.at(xnya).at(ynya) == '-';
    }
    else
    {
        peta.at(xnya).at(ynya) == '0';
    }
    engimonLiar.erase(engimonLiar.begin() + index);
}
//getter
int Map::getmaxEngimonLiar() { return this->maxEngimonLiar; }
int Map::getxmax() { return this->xmax; }
int Map::getymax() { return this->ymax; }
Position Map::getplayerPosition() { return this->playerPosition; }
Position Map::getactiveEngimonPosition() { return this->activeEngimonPositon; }
int Map::getplayerPositionX() { return this->playerPosition.getXCoordinate(); }
int Map::getplayerPositionY() { return this->playerPosition.getYCoordinate(); }
int Map::getactiveEngimonPositionX() { return this->activeEngimonPositon.getXCoordinate(); }
int Map::getactiveEngimonPositionY() { return this->activeEngimonPositon.getYCoordinate(); }

//setter
void Map::setplayerPosition(int _x, int _y)
{
    playerPosition.setXCoordinate(_x);
    playerPosition.setYCoordinate(_y);
    for (int i = 0; i < xmax; i++)
    {
        for (int j = 0; j < ymax; j++)
        {
            if (peta[i][j] == 'P')
            {
                if (i >= xmax - dimensiWater || j < ymax - dimensiWater)
                {
                    peta.at(i).at(j) = '-';
                }
                else
                {
                    peta.at(i).at(j) = '0';
                }
            }
        }
    }
    peta[_y][_x] = 'P';
}
void Map::setactiveEngimonPosition(int _x, int _y)
{
    activeEngimonPositon.setXCoordinate(_x);
    activeEngimonPositon.setYCoordinate(_y);
    for (int i = 0; i < xmax; i++)
    {
        for (int j = 0; j < ymax; j++)
        {
            if (peta[i][j] == 'X')
            {
                if (i >= xmax - dimensiWater || j < ymax - dimensiWater)
                {
                    peta.at(i).at(j) = '-';
                }
                else
                {
                    peta.at(i).at(j) = '0';
                }
            }
        }
    }
    peta[_y][_x] = 'X';
}

void Map::bacaMap(string namafile){
    ifstream myReadFile;
    myReadFile.open(namafile);
    char output[100];
    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {
            myReadFile >> output;
            cout<<output;
        }
    }
}