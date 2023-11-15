#pragma once

#include <string>
#include "AbilityT.h"

class ItemT {
   public:   
      ItemT() = default;
      std::string GetName() const;
      std::string GetDescription() const;
      AbilityT  GetAbility() const;

      void SetName(std::string newName);
      void SetDescription(std::string newDescription);
      void SetAbility(AbilityT newAbility);

   private:
      std::string name;
      std::string description;
      AbilityT ability;

};