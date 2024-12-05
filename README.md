# Pokemon Master Kiung
## 2024-02 OOP Assignment3 in Yonsei University
- Program that shows a Pokemon battle.
- 5 Pokemons available: Pikachu, Dratini, Eevee, Charmander, Palkia.
------------------------------------------------------------------


## Code Inspection
### Pokemons
To show the Type, HP of each Pokemon and skill sets, made two strctures.
1. **Pokemon**
    ```cpp
    struct Pokemon {    
        string name;
        string type;
        string latestskill;
        int effectiveness;
        int HP;
        vector<struct Pokestat> skills;
    };
    ```
Structure to set 5 Pokemons.
Shows the name, HP, type, recently used skill, effectiveness of the attack, and skills.


2. **Pokestat**
    ```cpp
    struct Pokestat {   
        string skillname;
        string skilltype;
        int damage;
        int maxtry;
        int currenttry;
    };
    ```
Structure to set the skills.
Shows the name, type, damage, available try number, remaining number of the skill.
Each skill is structure, and it goes in to vector included in struct Pokemon.
Used this heriachy for convenience in showing the battle page.


### Type
1. **typeeffective**
    ```cpp
    int typeeffective[6][6] ={ 
        {0, 0, 0, 0, 0, 0},     // Normal Type
        {0, 0, 1, 0, -1, 0},    // Ground Type
        {0, -1, -1, 1, -1, 0},  // Electric Type
        {0, 1, 0, -1, -1, 1},   // Water Type
        {0, -1, 0, 1, -1, -1},  // Grass Type
        {0, 0, 0, -1, 1, -1}    // Fire Type
    };
    ```
Made matrix to show the advantage/disadvantage due to the type.
1: super effective, 0: effective, -1: not very effective.
2: initial value (since we have to show the battle page before the first attack)


2. **damageeff**
    ```cpp
    pair<int, int> damageeff(int a, int b) {
        if (typeeffective[a][b] == 1) {
            return {5, 1};
        } else if (typeeffective[a][b] == 0) {
            return {0, 0};
        } else {
            return {-3, -1};
        }
    }
    ```
Made the pair to return both the effectiveness, change in the damage.
When attack is effective, damage +5, not very effective, damage -3.


### main
0. **before battle**
When program executed, asks user which Pokemon they will choose.
When they pick the same Pokemon, program terminates.
When they pick different Pokemon, program continues.


1. **battle**
Shows the currency of the battle using battlePage
- What Pokemon is used, current turn, skill stat etc.
Let user to choose the skill they want to use.
- When the skill is available, reduces the available try number, reduces other Pokemon's HP, updates recently used skill & effectiveness.
- And shows how effective the attack was.
#### example
```txt
    +-------------------------------------------------------------+
    | 2024-02 Object-Oriented Programming Pokemon Master          |
    +------------------------------+------------------------------+
    | Charmander                   | Palkia (*)                   |
    | Type: Fire                   | Type: Water                  |
    | HP: 39                       | HP: 86                       |
    +------------------------------+------------------------------+
    | Latest Skill: Tackle         | Latest Skill: -              |
    | It was effective.            |                              |
    +------------------------------+------------------------------+ 
    | (0) Tackle                   | (0) Hydro Pump               |
    |     - Type: Normal           |     - Type: Water            |
    |     - Damage: 4              |     - Damage: 12             |
    |     - Count: 4(5)            |     - Count: 10(10)          |
    | (1) Flamethrower             | (1) Earth Power              |
    |     - Type: Fire             |     - Type: Ground           |
    |     - Damage: 11             |     - Damage: 15             |
    |     - Count: 5(5)            |     - Count: 10(10)          |
    | (2) Dig                      | (2) Surf                     |
    |     - Type: Ground           |     - Type: Water            |
    |     - Damage: 7              |     - Damage: 13             |
    |     - Count: 5(5)            |     - Count: 10(10)          |
    | (3) Heat Wave                | (3) Spatial Rend             |
    |     - Type: Fire             |     - Type: Normal           |
    |     - Damage: 14             |     - Damage: 30             |
    |     - Count: 5(5)            |     - Count: 10(10)          |
    +------------------------------+------------------------------+
    Choose a skill (0~3): Palkia used Hydro Pump.
    It was super effective.
```

- When the skill is unavailable, shows the user that it failed to perform.
Continue Until one of the Pokemon is dead. (HP <= 0)
#### example
```txt
    +-------------------------------------------------------------+
    | 2024-02 Object-Oriented Programming Pokemon Master          |
    +------------------------------+------------------------------+
    | Charmander                   | Eevee (*)                    |
    | Type: Fire                   | Type: Normal                 |
    | HP: 3                        | HP: 21                       |
    +------------------------------+------------------------------+
    | Latest Skill: Heat Wave      | Latest Skill: Rain Dance     |
    | It was effective.            | It was super effective.      |
    +------------------------------+------------------------------+
    | (0) Tackle                   | (0) Tackle                   |
    |     - Type: Normal           |     - Type: Normal           |
    |     - Damage: 4              |     - Damage: 4              |
    |     - Count: 0(5)            |     - Count: 1(5)            |
    | (1) Flamethrower             | (1) Sand Attack              |
    |     - Type: Fire             |     - Type: Ground           |
    |     - Damage: 11             |     - Damage: 8              |
    |     - Count: 5(5)            |     - Count: 3(3)            |
    | (2) Dig                      | (2) Bite                     |
    |     - Type: Ground           |     - Type: Normal           |
    |     - Damage: 7              |     - Damage: 12             |
    |     - Count: 5(5)            |     - Count: 3(3)            |
    | (3) Heat Wave                | (3) Rain Dance               |
    |     - Type: Fire             |     - Type: Water            |
    |     - Damage: 14             |     - Damage: 15             |
    |     - Count: 4(5)            |     - Count: 0(1)            |
    +------------------------------+------------------------------+
    Choose a skill (0~3): Eevee failed to perform Rain Dance.
    
```

2. **after battle**
Shows that one Pokemon defeated another.