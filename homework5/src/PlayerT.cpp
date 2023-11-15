#include <iostream>
#include "PlayerT.h"

using namespace std;

std::string PlayerT::GetName() const{
    return name;
}

void PlayerT::SetName(std::string newName){
    name = newName;
}

const std::vector<AbilityT> PlayerT::GetAbilities() const {
    return abilities;
}

void PlayerT::AddAbility(AbilityT ability) {
    int match{0};
    int oppose{0};

    for (auto x: abilities) {
       if (x == ability) {
          ++match;
       }
       if (x == -ability) {
          ++ oppose;
       }
    }

    if (oppose == 0 and match < 2) {
        abilities.push_back(ability);
    }
}

const std::vector<ItemT> PlayerT::GetItems() const{
    return items;
}

void PlayerT::AddItem(ItemT item) {
     items.push_back(item);
}

int PlayerT::GetHealth()const  {
    return health;
}

int PlayerT::GetMaxHealth() const {
    return maxHealth;
}

void PlayerT::ChangeHealth(int amount){
    health += amount;
    health %= maxHealth;
}

void PlayerT::ChangeMaxHealth(int amount) {
    maxHealth += amount;
}

int PlayerT::GetGold() const {
    return gold;
}

void PlayerT::ChangeGold( int amount){
    gold += amount;
}

size_t PlayerT::GetPosition() const {
    return position;
}

void PlayerT::SetPosition(size_t newPosition){
    position = newPosition;
}