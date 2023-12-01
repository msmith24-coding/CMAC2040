#pragma once
#include <string>

#include <iostream>
#include "AbilityT.h"
#include <string>
#include "PlayerT.h"

class EncounterT {
    public:
        EncounterT() = default;
        EncounterT(EncounterT & ) = default;
        EncounterT(EncounterT && ) = delete;

        virtual EncounterT * Clone() = 0;
        virtual ~EncounterT() = default;

        virtual bool DoEncounter(PlayerT & player) = 0;
};

class NonEncounterT : public EncounterT {
    public:
        NonEncounterT(): EncounterT() {};
        NonEncounterT(NonEncounterT & ) = default;
        NonEncounterT(NonEncounterT && ) = delete;

        virtual ~NonEncounterT( )  = default;
        NonEncounterT * Clone() override;

        bool DoEncounter(PlayerT & player) override;
};

class ChallengeEncounterT : public EncounterT {
     public:
        ChallengeEncounterT() = default;
        ChallengeEncounterT(ChallengeEncounterT & ) = default;
        ChallengeEncounterT(ChallengeEncounterT && ) = delete;

        ChallengeEncounterT(std::string newChallenge, 
                            std::string newSuccess, 
                            std::string newFail, AbilityT newAbility,
                            int newDifficulty);

        virtual ~ChallengeEncounterT() = default;
        ChallengeEncounterT * Clone() override;

        bool DoEncounter(PlayerT & player) override ;


     protected: 
        virtual int CountDie(const PlayerT & player);
        virtual int Roll();
     protected:
        unsigned int dieCount = 2;
        std::string challenge, success, fail;
        AbilityT ability;
        int difficulty;
};

class RewardEncounterT : public ChallengeEncounterT
{
   public:
      RewardEncounterT() = default;
      RewardEncounterT(RewardEncounterT &) = default;
      RewardEncounterT(RewardEncounterT &&) = delete;

      RewardEncounterT(std::string newChallenge,
                        std::string newSuccess,
                        std::string newFail,
                        AbilityT newAbility,
                        int newDifficulty,
                        int newGoldReward);
      
      RewardEncounterT(std::string newChallenge,
                        std::string newSuccess,
                        std::string newFail,
                        AbilityT newAbility,
                        int newDifficulty,
                        ItemT newItemReward);
      
      virtual ~RewardEncounterT() = default;
      RewardEncounterT * Clone() override;

      bool DoEncounter(PlayerT & player) override;
   private:
      int rewardGold;
      ItemT rewardItem;
};
