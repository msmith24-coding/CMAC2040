#include <iostream>
#include "NonPlayerT.h"

void TellAboutNPC(NonPlayerT & p);

int main()
{
    NonPlayerT npc0;
    npc0.SetName("Npc0");
    npc0.setJob(JobT::MERCHANT);
    npc0.AddAbility(AbilityT::NONE);

    NonPlayerT npc1;
    npc1.SetName("Npc1");
    npc1.setJob(JobT::QUEST_GIVER);
    npc1.AddAbility(AbilityT::NONE);
    npc1.ChangeGold(10);

    TellAboutNPC(npc0);
    std::cout << std::endl;

    TellAboutNPC(npc1);

    return 0;
}

void TellAboutNPC(NonPlayerT & p){
 
    const std::vector<AbilityT> abilities{p.GetAbilities()};
    const std::vector<ItemT> items{p.GetItems()};

    std::cout << "There is a NPC called " << p.GetName() << std::endl;

    std::cout << "\tWith the following abilities: ";
    bool first{true};
    for(auto x: abilities) {
        if (first) {
           first = false;
        } else {
           std::cout << ", ";   
        }
        std::cout << x;
    }
    std::cout << std::endl;

    if (items.size() > 0) {
        std::cout << "\tCarring the following: " << std::endl;
        for(auto item: items) {
            std::cout << "\t\t\tName: " << item.GetName() << std::endl;
            std::cout << "\t\t\t" << item.GetDescription() << std::endl;
            std::cout << "\t\t\tAbility: " << item.GetAbility() << std::endl;
            std::cout << std::endl;
        }
    }

    std::cout << "\tJob: " << p.getJob() << std::endl;
    std::cout << "\tHealth: " << p.GetHealth() << "/" << p.GetMaxHealth() << std::endl;
    std::cout << "\tGold: " << p.GetGold() << std::endl;
    std::cout << "\tAt Location: " << p.GetPosition() << std::endl;
}