#include "ItemT.h"

std::string ItemT::GetName() const {
    return name;
}

std::string ItemT::GetDescription() const{
    return description;
}

AbilityT  ItemT::GetAbility() const{
    return ability;
}

void ItemT::SetName(std::string newName){
    name = newName;
}

void ItemT::SetDescription(std::string newDescription){
    description = newDescription;
}

void ItemT::SetAbility(AbilityT newAbility){
    ability = newAbility;
}