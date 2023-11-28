#include <iostream>
#include "NonPlayerT.h"

const std::string JOB_NAMES[] {"Quest Giver", "Riddler", "Merchant", "Enchanter", "Minion", "Giver", "none"};
const size_t JOB_COUNT {static_cast<size_t>(JobT::NONE)};

JobT NonPlayerT::getJob() const
{
    return this->job;
}

void NonPlayerT::setJob(JobT occupation)
{
    this->job = occupation;
}

std::string JobTToString (JobT j) {
   std::string rv{"NONE"};

   if (j < JobT::NONE) {
       size_t offset = static_cast<size_t>(j);
       rv = JOB_NAMES[offset];
   }
   return rv;
}

JobT StringToJobT(const std::string & s){
    std::string t{s};
    for(auto &x: t) {
       x = tolower(x);
    }

    size_t pos = 0;
    while (pos < JOB_COUNT and JOB_NAMES[pos] != t) {
       pos++;
    }
    return static_cast<JobT>(pos);
}

std::ostream & operator << (std::ostream & s, JobT j) {
    s << JobTToString(j);
    return s;
}