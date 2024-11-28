#include <iostream>
#include <vector>
#include <string>

using namespace std;

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
    cout << "Hi\n";
    return 0;
}