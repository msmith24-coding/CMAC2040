#include <iostream>
#include "EncounterT.h"
#include "PlayerT.h"
#include "RoomT.h"

using namespace std;

ActionT::ActionT(string newName, EncounterT * enc ):
    name{newName}, encounter{enc} {
}

ActionT::ActionT(const ActionT & other) {
    name = other.name;

    if (other.encounter != nullptr) {
        encounter = other.encounter->Clone();
    } else {
       encounter = nullptr;
    }
}

ActionT::~ActionT() {
    delete encounter;
}

string ActionT::GetName() const {
    return name;
}

void ActionT::SetEncounter(EncounterT * enc) {
    if (nullptr == encounter) {
        delete encounter;
    } 
    encounter = enc;
}

EncounterT * ActionT::GetEncounter() const {
    return encounter;
}

RoomT::RoomT() {
    encounterTypes.push_back("Exit");

    ActionT tmp{"Exit", nullptr};
    encounters.push_back(tmp);
}

void RoomT::AddEncounter(std::string eName, EncounterT * enc) {
     bool addIt{true};

     for(auto & x: encounters) {
        if (x.GetName() == eName) {
            x.SetEncounter(enc);
            addIt = false;
        }
     }

     if (addIt) {
        encounterTypes.push_back(eName);

        ActionT tmp{eName, enc};
        encounters.push_back(tmp);
     }

     return;
}

const std::vector<std::string> RoomT::GetEncounterNames() const {
     return encounterTypes;
}

bool RoomT::DoEncounter(std::string eName, PlayerT & player) {
    bool success{false};
    size_t i{0};
    bool found{false};

    while (i < encounters.size() and not found) { 
        if (encounters[i].GetName() == eName) { 
            if (encounters[i].GetEncounter()!= nullptr) {
                 success = encounters[i].GetEncounter()->DoEncounter(player);
                 found = true;
            } else if (eName == "Exit") {
                 success = true;
                 found = true;
            }
        }
        ++i;
    }
    return success;
}