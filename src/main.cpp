#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

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
    string latestskill;
    int effectiveness;
    int HP;
    vector <struct Pokestat> skills;
};


struct Pokestat {   // make struct to set the skillname, skilltype, damage, maxtry of each pokemon
    string skillname;
    string skilltype;
    int damage;
    int maxtry;
};

Pokemon Pikachu = {"Pikachu", "Electric", "-", 2, 35,   // Pikachu stat
    { 
    {"Takcle", "Normal", 4, 5},
    {"Grass Knot", "Grass", 8, 5},
    {"Thunderbolt", "Electric", 10, 5},
    {"Megabolt", "Electric", 15, 3}
    }
};

Pokemon Dratini = {"Dratini", "Water", "-", 2, 41,  // Dratini stat
    {
    {"Wrap", "Normal", 4, 10},
    {"Aqua Tail", "Water", 3, 5},
    {"Water Pulse", "Water", 13, 2},
    {"Hyper Beam", "Normal", 20, 1}
    }
};

Pokemon Eevee = {"Eevee", "Normal", "-", 2, 55,     // Eevee stat
    {
    {"Takcle", "Normal", 4, 5},
    {"Sand Attack", "Ground", 8, 3},
    {"Bite", "Normal", 12, 3},
    {"Rain Dance", "Water", 15, 1}  
    }
};

Pokemon Charmander = {"Charmander", "Fire", "-", 2, 39, // Charmander stat 
    {
    {"Takcle", "Normal", 4, 5},
    {"Flamehrower", "Fire", 11, 5},
    {"Dig", "Ground", 7, 5},
    {"Heat Wave", "Fire", 14, 5}
    }
};

Pokemon Palkia = {"Palkia", "Water", "-", 2, 90,    // Palkia stat
    {
    {"Hydro Pump", "Water", 12, 10},
    {"Earth Power", "Ground", 15, 10},
    {"Surf", "Water", 13, 10},
    {"Spatial Rend", "Normal", 30, 10}
    }
};


void battlePage (Pokemon &pkm1, Pokemon &pkm2, int i) {  
     // prints out the Battle Page 
    // gets two Pokemon and one int
    // int to check who is in the turn
    // no return, made the function to only print out the Battle Page
}








int main(){
    return 0;
}



void battlePage (Pokemon &pkm1, Pokemon &pkm2, int i) {    //since 63 == 1 + 60 + 1 + 60 + 1, we use setw to match the condition
    cout << "+-------------------------------------------------------------+"<< endl;
    cout << "| 2023149003 OOP Computer Science                             |"<< endl;
    cout << "+------------------------------+------------------------------+"<< endl;
    if (i%2 == 1){
        cout << "|" << setw(30) << left <<  pkm1.name + " (*)" << "|" << setw(30) << left << pkm2.name << "|" << endl; 
    } else {
        cout << "|" << setw(30) << left <<  pkm1.name << "|" << setw(30) << left << pkm2.name + " (*)" << "|" << endl; 
    }
    cout << "|" << setw(30) << left <<  pkm1.name + " (*)" << "|" << setw(30) << left << pkm2.name << "|" << endl; 
    cout << "|" << setw(30) << left << "Type: " + pkm1.type << "|" << setw(30) << left << "Type: " + pkm2.type << "|" <<endl;
    cout << "|" << setw(30) << left << "HP: " + pkm1.HP << "|" << setw(30) << left << "HP: " + pkm2.HP << "|" <<endl;
    cout << "+------------------------------+------------------------------+"<< endl;
    cout << "|" << setw(30) << left << "Latest skill: " + pkm1.latestskill << "|" << setw(30) << left << "Latest Skill: " + pkm2.latestskill << "|" <<endl;
    cout << "|" << setw(30) << left;
    if (pkm1.effectiveness == 1){
        cout << " It was super effective";
    } else if (pkm1.effectiveness == 0){
        cout << " It was effective";
    } else if (pkm1.effectiveness == -1) {
        cout << " It was not very effective";
    }
    cout << "|" << setw(30) << left;
        if (pkm2.effectiveness == 1){
        cout << " It was super effective";
    } else if (pkm2.effectiveness == 0){
        cout << " It was effective";
    } else if (pkm2.effectiveness == -1) {
        cout << " It was not very effective";
    }
    cout << "|" << endl;
    cout << "+------------------------------+------------------------------+"<< endl;
}