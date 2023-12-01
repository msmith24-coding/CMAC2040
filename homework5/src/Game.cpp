#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "PlayerT.h"
#include "RoomT.h"
#include "AbilityT.h"
#include <iomanip>

using namespace std;

void MakeGame(BoardT & board);
void MakePlayer(PlayerT & player);
void PlayGame(PlayerT & player, BoardT & board);
bool DoAction(PlayerT & player, BoardT & board);
size_t ActionMenu(PlayerT & player, BoardT & board);
void TellAboutPlayer(PlayerT & p);

int main() {

    srand(time(nullptr));

    BoardT board;
    PlayerT player;
    MakePlayer(player);
    MakeGame(board);

    cout << "Welcome to the game." << endl;
    cout << endl;
    cout << "A little about yourself first." << endl;
    TellAboutPlayer(player);
    cout << endl;

    PlayGame(player, board);

    return 0;
}

size_t ActionMenu(PlayerT & player, BoardT & board) {

    // get the choices from the room
    size_t pos {player.GetPosition()};
    const vector<string> actions{board[pos].GetEncounterNames()};

    size_t actionNo{0};
    size_t actionChoice{actions.size()};

    // make the user select a valid choice.
    while ( actionChoice >= actions.size()) {
        actionNo = 0;

        // present the list of choices.
        while (actionNo < actions.size()) {
            cout  << setfill(' ') << setw(10) << actionNo << " "
                 << setw(20) << setfill('.') << " " + actions[actionNo] << endl;
            ++actionNo;
        }

        cout << endl;
        cout << "\tWhat do you want to do? ";
        cin >>  actionChoice;
        cout << endl;
    }

    return actionChoice;
}

bool DoAction(PlayerT & player, BoardT & board) {
    size_t choice{ActionMenu(player, board)};
    size_t pos {player.GetPosition()};
    const vector<string> actions{board[pos].GetEncounterNames()};
    bool success{false};

    success = board[pos].DoEncounter(actions[choice], player);

    if (success and actions[choice] ==  "Exit") {
        player.SetPosition(player.GetPosition() + 1);
        cout << "You move to the next room" << endl;
    }
    cout << endl;

    return success;
}

void PlayGame(PlayerT & player, BoardT & board){
   
    // play the game until the player dies or is off the board.
    while (player.GetPosition() != board.size() and  player.GetHealth() > 0){
        cout << endl;
        cout << "+===+===+===+===+===+===+===+===+===+===+===+===+" << endl;
        cout << player.GetName() <<  " is at position "
             << player.GetPosition() << "."  << endl;

        while (!DoAction(player, board)) {
            cout << "Oops that didn't work.  Try again" << endl;
        }

        cout << endl;
    }

    // did the player win?
    if (player.GetHealth() <= 0)  {
       cout << "You died" << endl;
    } else {
       cout << "You finish the game with " << player.GetGold() << " gold!" 
            << endl;
    }
}


// this should be replaced with somethig that interacts witht he player
// to build the character.  More of a stub than any thing else.
void MakePlayer(PlayerT & player){
    ItemT item;

    player.SetName("Bob");
    player.AddAbility(AbilityT::STRONG);
    player.AddAbility(AbilityT::STRONG);
    player.AddAbility(AbilityT::WEAK);
    player.AddAbility(AbilityT::CLEVER);

    item.SetName("Sword");
    item.SetDescription("Normal Sword");
    item.SetAbility(AbilityT::STRONG);

    player.AddItem(item);

    item.SetName("Gem");
    item.SetDescription("Gem of Ugly");
    item.SetAbility(AbilityT::UGLY);
    player.AddItem(item);
}


// this should be replaced with something that loads the game from a file.
// Again more of a stub.
void MakeGame(BoardT & board){
    // make the first room
    RoomT room1;
    NonEncounterT * e1{new NonEncounterT}; 
    NonEncounterT * e2{new NonEncounterT}; 
    NonEncounterT * e3{new NonEncounterT};

    room1.AddEncounter("Look Around", e1);
    room1.AddEncounter("Sleep",e2);
    room1.AddEncounter("Search",e3);
    board.push_back(room1);

    // make the second room
    // RoomT room2;
    // e1 = new NonEncounterT;
    // room2.AddEncounter("Exit", e1);
    // e2 = new NonEncounterT;
    // room2.AddEncounter("Sleep", e2);
    // e3 = new NonEncounterT;
    // room2.AddEncounter("Search", e3);
    // board.push_back(room2);

    RoomT room2;
    ChallengeEncounterT * c1 = new 
           ChallengeEncounterT("jump a deep ditch.", 
                               "you sail over the ditch.",
                               "you fall in the ditch.", AbilityT::STRONG, 3);
    room2.AddEncounter("Exit",c1);
    board.push_back(room2);


    // make the third room
    RoomT room3;
    ChallengeEncounterT * c2 = new 
           ChallengeEncounterT("pick a door lock.", 
                               "you opened the door.",
                               "you can't open the door.", AbilityT::CLEVER, 2);
    room3.AddEncounter("Exit",c2);
    board.push_back(room3);

    RoomT room4;
    ChallengeEncounterT * c3 = new 
           ChallengeEncounterT("beat a gambler in a dice roll.", 
                               "you leave watching the gambler down a bottle of rum.",
                               "the gambler punches you back to the previous room.", AbilityT::DEXTEROUS, 1);
    room4.AddEncounter("Exit",c3);
    board.push_back(room4);

    // Reward shit

    RoomT room5;
    RewardEncounterT * r1 = new 
           RewardEncounterT("you have to slay Barney the purple dinosaur.", 
                               "you behead Barney finding 10 gold coins on his body.",
                               "the Barney theme song plays leaving you dancing out of the room.", AbilityT::TOUGH, 3, 10);
    room5.AddEncounter("Exit",r1);
    board.push_back(room5);

    ItemT cheeseItem;
    cheeseItem.SetName("Cheese of Truth");
    cheeseItem.SetDescription("This cheese contains the souls of the innocence. More voices were added to your head.");
    cheeseItem.SetAbility(AbilityT::WISE);


    RoomT room6;
    RewardEncounterT * r2 = new 
           RewardEncounterT("you must open a locked chest.", 
                               "you find the legndary Cheese of Truth.",
                               "you failed to unlock the chest. The dungeon now mocks you.", AbilityT::WISE, 2, cheeseItem);
    room6.AddEncounter("Exit", r2);
    board.push_back(room6);

    ItemT truffulaItem;
    truffulaItem.SetName("Full Grown Truffula Tree");
    truffulaItem.SetDescription("Forced to carry this tree where ever you go.");
    truffulaItem.SetAbility(AbilityT::SLOW);

    RoomT room7;
    RewardEncounterT * r3 = new 
           RewardEncounterT("you have to spot the Lorax in the trees.", 
                               "you find the Lorax and he gives you 3 gold and states \"I am the Lorax and I speak for the trees, and for some reason they are speaking Vietnamese.\".",
                               "you failed to find the Lorax, but instead you get pumbled by Vietcong snipers.", AbilityT::FAST, 3, truffulaItem);
    room7.AddEncounter("Exit",r3);
    board.push_back(room7);

    RoomT room8;
    RewardEncounterT * r4 = new 
           RewardEncounterT("grab gold coins hanging from the ceiling.", 
                               "you grab 3 gold pieces.",
                               "you fail to grab any gold.", AbilityT::AGILE, 2, 3);
    room8.AddEncounter("Exit", r4);
    board.push_back(room8);

    return;
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