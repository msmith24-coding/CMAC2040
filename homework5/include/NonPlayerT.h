#ifndef NON_PLAYERT_H
#define NON_PLAYERT_H
#include "PlayerT.h"

enum class JobT
{
    QUEST_GIVER,
    RIDDLER,
    MERCHANT,
    ENCHANTER,
    MINION,
    GIVER,
    NONE
}; 

class NonPlayerT : public PlayerT
{
    public:
        JobT getJob() const;
        void setJob(JobT occupation);

    private:
        JobT job;
};

std::ostream & operator << (std::ostream & s, JobT a);

#endif