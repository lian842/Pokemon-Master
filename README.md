# Pokemon Master Kiung
## 2024-02 OOP Assignment3 in Yonsei University
Program that shows a Pokemon battle.
5 Pokemons available: Pikachu, Dratini, Eevee, Charmander, Palkia.
------------------------------------------------------------------


## Code Inspection
### Pokemons
To show the Type, HP of each Pokemon and skill sets, I made two strctures.
1. Pokemon
    struct Pokemon {    
    string name;
    string type;
    string latestskill;
    int effectiveness;
    int HP;
    vector <struct Pokestat> skills;
    };
Structure to set 5 Pokemons.
Shows the name, HP, type, recently used skill, effectiveness of the attack, and skills.


2. Pokestat
    struct Pokestat {   
    string skillname;
    string skilltype;
    int damage;
    int maxtry;
    int currenttry;
    };
Structure to set the skills.
Shows the name, type, damage, available try number, remaining number of the skill.
Each skill is structure, and it goes in to vector included in struct Pokemon.
Used this heriachy for convenience in showing the battle page.


### Type
1. typeeffective
    int typeeffective [6][6] ={ 
    {0, 0, 0, 0, 0, 0},     // Normal Type
    {0, 0, 1, 0, -1, 0},    // Ground Type
    {0, -1, -1, 1, -1, 0},  // Electric Type
    {0, 1, 0, -1, -1, 1},   // Water Type
    {0, -1, 0, 1, -1, -1},  // Grass Type
    {0, 0, 0, -1, 1, -1}    // Fire Type
    };
Made matrix to show the advantage/disadvantage due to the type.
1: super effective, 0: effective, -1: not very effective.
2: initial value (since we have to show the battle page before the first attack)

2. damageeff
    pair <int, int> damageeff(int a, int b){
        if (typeeffective[a][b] == 1){
            return {5, 1};
        } else if (typeeffective[a][b] == 0){
            return {0, 0};
        } else {
            return {-3, -1};
        }   
    }
Made the pair to return both the effectiveness, change in the damage.
When attack is effective, damage +5, not very effective, damage -3.


### main
When program executed, asks user which Pokemon they will choose.
When they pick the same Pokemon, program terminates.
When they pick different Pokemon, program continues.
1. battle
