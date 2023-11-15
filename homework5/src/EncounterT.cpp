#include <iostream>
#include "EncounterT.h"

using namespace std;

NonEncounterT* NonEncounterT::NonEncounterT::Clone() {
    return new NonEncounterT(*this);
}

bool NonEncounterT::DoEncounter(PlayerT & player) {
     cout << "An encounter with " << player.GetName() << endl;
     cout << "Nothing Happens." << endl;
     cout << "So you get a gold piece." << endl;
     player.ChangeGold(1);
     cout << endl;

     return true ;
}