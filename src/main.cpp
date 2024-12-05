#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <cstdio>

using namespace std;





int typeeffective [6][6] ={ // when super effective :1, effective :0, not very effective :-1
    {0, 0, 0, 0, 0, 0},     // Normal Type
    {0, 0, 1, 0, -1, 0},    // Ground Type
    {0, -1, -1, 1, -1, 0},  // Electric Type
    {0, 1, 0, -1, -1, 1},   // Water Type
    {0, -1, 0, 1, -1, -1},  // Grass Type
    {0, 0, 0, -1, 1, -1}    // Fire Type
};

map <string , int> Types ={
    {"Normal", 0}, {"Ground", 1}, {"Electric", 2}, {"Water", 3}, {"Grass", 4}, {"Fire", 5}
};


struct Pokestat {   // make struct to set the skillname, skilltype, damage, maxtry of each pokemon
    string skillname;
    string skilltype;
    int damage;
    int maxtry;
    int currenttry;
};


struct Pokemon {    // make struct to set each Pokemon (splitted the first struct to use the stat of Pokemon better)
    string name;
    string type;
    string latestskill;
    int effectiveness;
    int HP;
    vector <struct Pokestat> skills;
};



Pokemon Pikachu = {"Pikachu", "Electric", "-", 2, 35,   // Pikachu stat
    { 
    {"Tackle", "Normal", 4, 5, 5},
    {"Grass Knot", "Grass", 8, 5, 5},
    {"Thunderbolt", "Electric", 10, 5, 5},
    {"Megabolt", "Electric", 15, 3, 3}
    }
};

Pokemon Dratini = {"Dratini", "Water", "-", 2, 41,  // Dratini stat
    {
    {"Wrap", "Normal", 4, 10, 10},
    {"Aqua Tail", "Water", 3, 5, 5},
    {"Water Pulse", "Water", 13, 2, 2},
    {"Hyper Beam", "Normal", 20, 1, 1}
    }
};

Pokemon Eevee = {"Eevee", "Normal", "-", 2, 55,     // Eevee stat
    {
    {"Tackle", "Normal", 4, 5, 5},
    {"Sand Attack", "Ground", 8, 3, 3},
    {"Bite", "Normal", 12, 3, 3},
    {"Rain Dance", "Water", 15, 1, 1}  
    }
};

Pokemon Charmander = {"Charmander", "Fire", "-", 2, 39, // Charmander stat 
    {
    {"Tackle", "Normal", 4, 5, 5},
    {"Flamethrower", "Fire", 11, 5, 5},
    {"Dig", "Ground", 7, 5, 5},
    {"Heat Wave", "Fire", 14, 5, 5}
    }
};

Pokemon Palkia = {"Palkia", "Water", "-", 2, 90,    // Palkia stat
    {
    {"Hydro Pump", "Water", 12, 10, 10},
    {"Earth Power", "Ground", 15, 10, 10},
    {"Surf", "Water", 13, 10, 10},
    {"Spatial Rend", "Normal", 30, 10, 10}
    }
};

vector <Pokemon> Pokemons ={    // vector of Pokemon to put them in function
    Pikachu, Dratini, Eevee, Charmander, Palkia
};







void battle (Pokemon &pkm1, Pokemon &pkm2);
    // progress battle
    // gets two Pokemon from user input int
    // no return


void battlePage (Pokemon &pkm1, Pokemon &pkm2, int i);
    // prints out the Battle Page 
    // gets two Pokemon and one int
    // int to check who is in the turn
    // no return, made the function to only print out the Battle Page


pair <int, int> damageeff(int a, int b);
    // check the effectiveness of the attack
    // put in two types turned into int (using map)
    // when super effective, return 5
    // when effective, return 0
    // when not very effective, return -3
    // and the result of typeeffective


string setlen(const string &str);
    // gets the string that to be printed
    // and add the blank after the string to match the length (30)







int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);   // to prevent falseful redirection

    int pk1, pk2;
    cout << "Choose a Pokemon(0~4): " ;
    cin >> pk1;
    cout << "Choose a Pokemon(0~4): " ;
    cin >> pk2;
    //cout << "\n";
    if (pk1 == pk2){
        cout << "You have to choose Pokemons different from each other.";
        return 0;   // terminate the battle when the user chose the same Pokemon
    }
    battle (Pokemons[pk1], Pokemons[pk2]);  // run the battle
    return 0;
}



pair <int, int> damageeff(int a, int b){
    if (typeeffective[a][b] == 1){
        return {5, 1};
    } else if (typeeffective[a][b] == 0){
        return {0, 0};
    } else {
        return {-3, -1};
    }
}





void battle (Pokemon &pkm1, Pokemon &pkm2){
    int i = 1;  // int value to check the turn
    while (pkm1.HP > 0 && pkm2.HP > 0){ // battle until one of the Pokemon's HP <= 0
        int j;
        battlePage(pkm1, pkm2, i);
        cout << "Choose a skill (0~3): ";
        cin >> j;
        if (i % 2 == 1){    // when pkm1 turn
            pkm1.latestskill = pkm1.skills[j].skillname;    // change the latest skill to show in battle page
            int a = Types[pkm1.skills[j].skilltype];        
            int b = Types[pkm2.type];
            pair <int, int> result = damageeff(a, b);       // check the compatibility of the attack
            int c = result.first;
            int d = result.second;
            pkm1.effectiveness = d;                         // show the effectiveness
            if (pkm1.skills[j].currenttry == 0){    // when the skill ran out of try 
                cout << pkm1.name <<" failed to perform " << pkm1.skills[j].skillname << "." << "\n";
            } else {
                pkm1.skills[j].currenttry -= 1;
                pkm2.HP -= (pkm1.skills[j].damage + c);     // change the HP according to effectiveness       
                cout << pkm1.name << " used " << pkm1.skills[j].skillname <<"." << "\n";
                if (d == 1){
                    cout << "It was super effective." << endl;
                } else if (d == 0) {
                    cout << "It was effective." << endl;
                } else if (d == -1){
                    cout << "It was not very effective." << endl;
                }
            }
        } else {    // when pkm2 turn
            pkm2.latestskill = pkm2.skills[j].skillname;     // change the latest skill to show in battle page
            int a = Types[pkm2.skills[j].skilltype];
            int b = Types[pkm1.type];
            pair <int, int> result = damageeff(a, b);        // check the compatibility of the attack
            int c = result.first;
            int d = result.second;
            pkm2.effectiveness = d;                          // show the effectiveness
            if (pkm2.skills[j].currenttry == 0){
                cout << pkm2.name <<" failed to perform " << pkm2.skills[j].skillname << "." << "\n";    // when the skill ran out of try 
            } else {
                pkm2.skills[j].currenttry -= 1;  
                cout << pkm2.name << " used " << pkm2.skills[j].skillname <<"." << "\n";
                pkm1.HP -= (pkm2.skills[j].damage + c);      // change the HP according to effectiveness
                if (d == 1){
                    cout << "It was super effective." << endl;
                } else if (d == 0) {
                    cout << "It was effective." << endl;
                } else if (d == -1){
                    cout << "It was not very effective." << endl;
                }
            } 
        }
        cout << endl;
        i += 1;
    }
    cout << "===============================================================" << "\n";
    if (pkm1.HP <= 0){      // show the result
        cout << "Match Result: " << pkm2.name << " defeats " << pkm1.name << "\n";
    } else {
        cout << "Match Result: " << pkm1.name << " defeats " << pkm2.name << "\n";
    }
}

string setlen(const string &str) {
    int l = str.length();    // get the length of the string (str)
    string result = str + string(30 - l, ' ');
    return result; // add the blank to set the desired length
}


void battlePage(Pokemon &pkm1, Pokemon &pkm2, int i) {  // since 63 == 1 + 30 + 1 + 30 + 1, set the space with setlen
    cout << "+-------------------------------------------------------------+\n";
    cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |\n";
    cout << "+------------------------------+------------------------------+\n";
    if (i % 2 == 1) { // pkm1's turn
        cout << "|" << setlen(string(" ") + pkm1.name + " (*)")
             << "|" << setlen(string(" ") + pkm2.name) << "|\n";
    } else { // pkm2's turn
        cout << "|" << setlen(string(" ") + pkm1.name)
             << "|" << setlen(string(" ") + pkm2.name + " (*)") << "|\n" << flush;
    }
    cout << "|" << setlen(string(" Type: ") + pkm1.type)  // show type
         << "|" << setlen(string(" Type: ") + pkm2.type) << "|\n";
    cout << "|" << setlen(string(" HP: ") + to_string(pkm1.HP))   // show HP
         << "|" << setlen(string(" HP: ") + to_string(pkm2.HP)) << "|\n";
    cout << "+------------------------------+------------------------------+\n" << flush;
    cout << "|" << setlen(string(" Latest Skill: ") + pkm1.latestskill)   // show latest skill
         << "|" << setlen(string(" Latest Skill: ") + pkm2.latestskill) << "|\n";
    cout << "|";
    if (pkm1.effectiveness == 1) {  // show effectiveness of pkm1 
        cout << setlen(" It was super effective.");
    } else if (pkm1.effectiveness == 0) {
        cout << setlen(" It was effective.");
    } else if (pkm1.effectiveness == -1) {
        cout << setlen(" It was not very effective.");
    } else {
        cout << setlen(string(" ")); // for initiall (no latest skill)
    }
    cout << "|";
    if (pkm2.effectiveness == 1) {  // show effectiveness of pkm2
        cout << setlen(" It was super effective.");
    } else if (pkm2.effectiveness == 0) {
        cout << setlen(" It was effective.");
    } else if (pkm2.effectiveness == -1) {
        cout << setlen(" It was not very effective.");
    } else {
        cout << setlen(string(" ")); // for initiall (no latest skill)
    }
    cout << "|\n";
    cout << "+------------------------------+------------------------------+\n" << flush;
for (int i = 0; i < 4; i++) {
    cout << "|" << setlen(string(" (") + to_string(i) + string(") ") + pkm1.skills[i].skillname)
         << "|" << setlen(string(" (") + to_string(i) + string(") ") + pkm2.skills[i].skillname) << "|\n";

    cout << "|" << setlen(string("     - Type: ") + pkm1.skills[i].skilltype)
         << "|" << setlen(string("     - Type: ") + pkm2.skills[i].skilltype) << "|\n";

    cout << "|" << setlen(string("     - Damage: ") + to_string(pkm1.skills[i].damage))
         << "|" << setlen(string("     - Damage: ") + to_string(pkm2.skills[i].damage)) << "|\n";

    cout << "|" << setlen(string("     - Count: ") + to_string(pkm1.skills[i].currenttry) + string("(") + to_string(pkm1.skills[i].maxtry) + string(")"))
         << "|" << setlen(string("     - Count: ") + to_string(pkm2.skills[i].currenttry) + string("(") + to_string(pkm2.skills[i].maxtry) + string(")")) << "|\n";
}


    cout << "+------------------------------+------------------------------+\n";
    fflush(stdout);
}






