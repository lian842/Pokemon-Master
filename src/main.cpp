#include <iostream>
#include <vector>
#include <string>

using namespace std;



int typeeffective [6][6] ={ // when super effective :1, effective :0, not very effective :-1
    {0, 0, 0, 0, 0, 0},     // Normal Type
    {0, 0, 1, 0, -1, 0},    // Ground Type
    {0, -1, -1, 1, -1, 0},  // Electric Type
    {0, 1, 0, -1, -1, 1},   // Water Type
    {0, -1, 0, 1, -1, -1},  // Grass Type
    {0, 0, 0, -1, 1, -1}    // Fire Type
};




struct Pokemon {
    string name;
    string type;
    int HP;
    vector <Pokestat> skill;
};


struct Pokestat {   // make struct to set the skillname, skilltype, damage, maxtry of each pokemon
    string skillname;
    string skilltype;
    int damage;
    int maxtry;
};


vector<Pokestat> Pikachu= { // setting of Pikachu
    {"Takcle", "Normal", 4, 5},
    {"Grass Knot", "Grass", 8, 5},
    {"Thunderbolt", "Electric", 10, 5},
    {"Megabolt", "Electric", 15, 3}
};
vector<Pokestat> Dratini= { // setting of Dratini
    {"Wrap", "Normal", 4, 10},
    {"Aqua Tail", "Water", 3, 5},
    {"Water Pulse", "Water", 13, 2},
    {"Hyper Beam", "Normal", 20, 1}
};
vector<Pokestat> Eevee= { // setting of Eevee
    {"Takcle", "Normal", 4, 5},
    {"Sand Attack", "Ground", 8, 3},
    {"Bite", "Normal", 12, 3},
    {"Rain Dance", "Water", 15, 1}
};
vector<Pokestat> Charmander= { // setting of Charmander
    {"Takcle", "Normal", 4, 5},
    {"Flamehrower", "Fire", 11, 5},
    {"Dig", "Ground", 7, 5},
    {"Heat Wave", "Fire", 14, 5}
};
vector<Pokestat> Palkia= { // setting of Palkia
    {"Hydro Pump", "Water", 12, 10},
    {"Earth Power", "Ground", 15, 10},
    {"Surf", "Water", 13, 10},
    {"Spatial Rend", "Normal", 30, 10}
};





int main(){
    return 0;
}