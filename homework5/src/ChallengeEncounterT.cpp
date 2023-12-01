#include <iostream>
#include "EncounterT.h"

ChallengeEncounterT::ChallengeEncounterT(std::string newChallenge, 
                            std::string newSuccess, 
                            std::string newFail, AbilityT newAbility,
                            int newDifficulty)
                            {
                                this->challenge = newChallenge;
                                this->success = newSuccess,
                                this->fail = newFail,

                                this->ability = newAbility;
                                this->difficulty = newDifficulty;
                            }

int ChallengeEncounterT::CountDie(const PlayerT & player)
{
    std::cout << "Figuring out your dice pool:" << std::endl;
    std::cout << "\tYou start at " << this->dieCount << std::endl;

    unsigned int validAbilityCount = 0;
    unsigned int index = 0;
    while(index < player.GetAbilities().size()) {
        if(player.GetAbilities().at(index) == this->ability || validAbilityCount < 2) {
            validAbilityCount++;
            this->dieCount++;
            std::cout << "\tYou are " << this->ability << " so that adds 1 for " << this->dieCount << std::endl;
        }
        ++index;
        // std::cout << (index < player.GetAbilities().size() || validAbilityCount <= 2) << std::endl;
    }

    for(auto item : player.GetItems()) {
        if(item.GetAbility() == this->ability) {
            this->dieCount++;
            std::cout << "\tYour " << item.GetName() << " adds 1 for " << this->dieCount << std::endl;
        }
    }


    std::cout << "So you will roll " << this->dieCount << " dice." << std::endl;
    std::cout << std::endl;
    return this->dieCount;
}

ChallengeEncounterT * ChallengeEncounterT::Clone() 
{
    return new ChallengeEncounterT(this->challenge, this->success, this->fail, this->ability, this->difficulty);
}

int ChallengeEncounterT::Roll()
{
    return 1 + rand() % (6);
}
                            
bool ChallengeEncounterT::DoEncounter(PlayerT & player)
{
    std::cout << "This is a challenge encounter." << std::endl;
    std::cout << "Using your ability " << this->ability << " you must " << this->challenge << std::endl;
    std::cout << "And you must have at least " << this->difficulty << " successes" << std::endl;
    std::cout << std::endl;

    this->CountDie(player);

    std::cout << "Rolling" << std::endl;

    int successCount = 0;
    for(unsigned int i = 1; i <= this->dieCount; ++i) {
        int number = this->Roll();

        std::string result = (number >= this->difficulty) ? "success." : "fail.";

        if(number >= this->difficulty) {
            successCount++;
        }

        std::cout << "\t\tDie " << i << " is a " << number << " " << result << std::endl;
    }

    // int successRequirement = this->dieCount / 2;

    if(successCount >= this->difficulty) {
        std::cout << "\tThis is a success: " << this->success << std::endl;
        return true;
    } else {
        std::cout << "\tThis is a failure: " << this->fail << std::endl;
        dieCount = 2;
        return false;
    }
}