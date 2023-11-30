#include <iostream>
#include "NonPlayerT.h"
#include "PlayerT.h"
#include "EncounterT.h"

void MakePlayer(PlayerT & player);
void TellAboutNPC(NonPlayerT & p);

int main()
{
    srand(time(nullptr));
    
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
    std::cout << std::endl;

    PlayerT player;
    MakePlayer(player);

    ItemT item;
    item.SetName("Holy Hand Grenade");
    item.SetDescription("And the Lord spake, saying, \n''First shalt thou take out the Holy Pin.\n Then shalt thou count to three, no more, no less. \nThree shall be the number thou shalt count, and the number of the counting shall be three. \nFour shalt thou not count, neither count thou two, excepting that thou then proceed to three. \nFive is right out. Once the number three, being the third number, \nbe reached, then lobbest thou thy Holy Hand Grenade of Antioch towards thy foe, who, \nbeing naughty in My sight, shall snuff it.'");
    item.SetAbility(AbilityT::STRONG);

    RewardEncounterT encounter0("jump across columns to get past a pit fall", "you jumped across the pit fall", "you fell in the pit.", AbilityT::AGILE, 3, item);    

    encounter0.DoEncounter(player);

    return 0;
}

void MakePlayer(PlayerT & player){
    ItemT item;

    player.SetName("Giga Monty");
    player.AddAbility(AbilityT::STRONG);
    player.AddAbility(AbilityT::STRONG);
    player.AddAbility(AbilityT::AGILE);
    player.AddAbility(AbilityT::AGILE);
    player.AddAbility(AbilityT::WEAK);
    player.AddAbility(AbilityT::UGLY);

    item.SetName("Excalibur");
    item.SetDescription("The Lady of the Lake, her arm clad in the purest shimmering samite held aloft Excalibur from the bosom of the water, signifying by divine providence that I, Arthur, was to carry Excalibur. THAT is why I am your king.");
    item.SetAbility(AbilityT::STRONG);
    player.AddItem(item);

    item.SetName("Frodge");
    item.SetDescription("A fridge full of frog corpses");
    item.SetAbility(AbilityT::NONE);
    player.AddItem(item);
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