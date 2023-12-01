#include <iostream>
#include "EncounterT.h"

RewardEncounterT::RewardEncounterT(std::string newChallenge, 
                            std::string newSuccess, 
                            std::string newFail, 
                            AbilityT newAbility,
                            int newDifficulty,
                            int newGoldReward) : ChallengeEncounterT(newChallenge, newSuccess, newFail, newAbility, newDifficulty)
                            {
                                this->rewardGold = newGoldReward;
                            }

RewardEncounterT::RewardEncounterT(std::string newChallenge, 
                            std::string newSuccess, 
                            std::string newFail, 
                            AbilityT newAbility,
                            int newDifficulty,
                            ItemT newItemReward) : ChallengeEncounterT(newChallenge, newSuccess, newFail, newAbility, newDifficulty)
                            {
                                this->rewardGold = 0;
                                this->rewardItem = newItemReward;
                            }
                        
bool RewardEncounterT::DoEncounter(PlayerT & player)
{
    bool result = ChallengeEncounterT::DoEncounter(player);

    if(result) {
        if(this->rewardGold > 0) {
            std::cout << "You found " << this->rewardGold << " gold!" << std::endl;
            player.ChangeGold(this->rewardGold);
        } else {
            std::cout << "You found " << this->rewardItem.GetName() << "!" << std::endl;
            std::cout << "It has been added to your inventory." << std::endl;
            player.AddItem(this->rewardItem);
        }
        return true;
    }
    return false;

}

RewardEncounterT * RewardEncounterT::Clone() 
{
    if(this->rewardGold > 0) {
        return new RewardEncounterT(this->challenge, this->success, this->fail, this->ability, this->difficulty, this->rewardGold);
    }
    return new RewardEncounterT(this->challenge, this->success, this->fail, this->ability, this->difficulty, this->rewardItem);
}