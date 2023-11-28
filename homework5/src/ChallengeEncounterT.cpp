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

ChallengeEncounterT * ChallengeEncounterT::Clone() 
{
    return new ChallengeEncounterT(this->challenge, this->success, this->fail, this->ability, this->difficulty)
}
                            
bool ChallengeEncounterT::DoEncounter(PlayerT & player)
{
    std::cout << "This is a challenge encounter." << std::endl;
    std::cout << "Using your ability " << this->ability << " you must " << this->challenge << std::endl;
    std::cout << "And you must have at least " << this->difficulty << "successes" << std::endl;
    std::cout << std::endl;

    std::cout << "Figuring out your dice pool:" << std::endl;
    std::cout << "\tYou start at " << this->dieCount << std::endl;

    unsigned int validAbilityCount = 0;
    unsigned int index = 0;
    while(index < player.GetAbilities().size() || validAbilityCount <= 2) {
        if(player.GetAbilities().at(index) == this->ability) {
            validAbilityCount++;
            this->dieCount++;
            std::cout << "\tYou are " << this->ability << " so that adds 1 for " << this->dieCount << std::endl;
        }
    }

    for(auto item : player.GetItems()) {
        if(item.GetAbility() == this->ability) {
            this->dieCount++;
            std::cout << "\tYour " << item.GetName() << " adds 1 for " << this->dieCount << std::endl;
        }
    }


    std::cout << "So you will roll " << this->dieCount << "dice." << std::endl;
    std::cout << std::endl;
    std::cout << "Rolling" << std::endl;

    unsigned int successCount = 0;
    for(unsigned int i = 1; i <= this->dieCount; ++i) {
        int number = 1 + rand() % (6);

        std::string result = (number >= this->difficulty) ? "success." : "fail.";

        if(number >= this->difficulty) {
            successCount++;
        }

        std::cout << "\t\tDie " << i << " is a " << number << " " << result << std::endl;
    }

    // int successRequirement = this->dieCount / 2;

    if(successCount >= this->difficulty) {
        std::cout << "\tThis is a success: " << this->success << std::endl;
    } else {
        std::cout << "\tThis is a failure: " << this->fail << std::endl;
    }

}