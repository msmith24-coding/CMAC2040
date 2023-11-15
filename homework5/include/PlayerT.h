#pragma once
#include "AbilityT.h"
#include "ItemT.h"
#include <vector>
#include <string>

class PlayerT {
   public:
       PlayerT(){};

       std::string GetName() const;
       void SetName(std::string newName);

       const std::vector<AbilityT> GetAbilities() const;
       void AddAbility(AbilityT ability);

       const std::vector<ItemT> GetItems() const;
       void AddItem(ItemT item);

       int GetHealth()const ;
       int GetMaxHealth() const;
       void ChangeHealth(int amount);
       void ChangeMaxHealth(int amount);

       int GetGold() const;
       void ChangeGold( int amount);

       size_t GetPosition() const;
       void SetPosition(size_t newPosition);

   private:
       std::string name;
       int maxHealth{10};
       int health{maxHealth};
       int gold{0};
       std::vector<AbilityT> abilities;
       std::vector<ItemT> items;
       size_t position{0};
};