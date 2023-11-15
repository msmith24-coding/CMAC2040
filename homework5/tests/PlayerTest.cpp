#include <iostream>
#include "PlayerT.h"

using namespace std;

void TellAboutPlayer(PlayerT & p);

int main() {
    PlayerT player1;

    player1.SetName("Bob");
    player1.AddAbility(AbilityT::STRONG);
    player1.AddAbility(AbilityT::STRONG);
    player1.AddAbility(AbilityT::STRONG);
    player1.AddAbility(AbilityT::WEAK);
    player1.AddAbility(AbilityT::UGLY);

    ItemT sword;
    sword.SetName("Sword");
    sword.SetDescription("A short sword");
    sword.SetAbility(AbilityT::STRONG);
    player1.AddItem(sword);

    TellAboutPlayer(player1);
}

void TellAboutPlayer(PlayerT & p){
 
    const vector<AbilityT> abilities{p.GetAbilities()};
    const vector<ItemT> items{p.GetItems()};

    cout << "There is a player called " << p.GetName() << endl;

    cout << "\tWith the following abilities: ";
    bool first{true};
    for(auto x: abilities) {
        if (first) {
           first = false;
        } else {
           cout << ", ";   
        }
        cout << x;
    }
    cout << endl;

    if (items.size() > 0) {
        cout << "\tCarring the following: " << endl;
        for(auto item: items) {
            cout << "\t\t\tName: " << item.GetName() << endl;
            cout << "\t\t\t" << item.GetDescription() << endl;
            cout << "\t\t\tAbility: " << item.GetAbility() << endl;
            cout << endl;
        }
    }

    cout << "\tHealth: " << p.GetHealth() << "/" << p.GetMaxHealth() << endl;
    cout << "\tGold: " << p.GetGold() << endl;
    cout << "\tAt Location: " << p.GetPosition() << endl;
}