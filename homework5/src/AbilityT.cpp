#include <iostream>

#include <string>
#include "AbilityT.h"

using namespace std;

const string ABILITY_NAMES[]{"strong", "weak", "tough", "sickly", "clever", "dense", "wise", "foolish", "dexterous", "fumbling", "agile", "clumsy", "fast", "slow", "charming", "unpleasant", "attractive", "ugly", "none"};

const size_t ABILITY_COUNT {static_cast<size_t>(AbilityT::NONE)};

std::ostream & operator << (std::ostream & s, AbilityT a) {
    s << AbilityTToString(a);
    return s;
}

AbilityT StringToAbilityT(const string & s){
    string t{s};
    for(auto &x: t) {
       x = tolower(x);
    }

    size_t pos = 0;
    while (pos < ABILITY_COUNT and ABILITY_NAMES[pos] != t) {
       pos++;
    }
    return static_cast<AbilityT>(pos);
}


std::istream & operator >> (std::istream & s, AbilityT & a){

     string tmp;
     s >> tmp;
     a = StringToAbilityT(tmp);

     return s;
}

AbilityT operator + (AbilityT a, size_t i){
    size_t offset{static_cast<size_t>(a)};
    offset += i;
    AbilityT rv{AbilityT::NONE};

    if (offset < ABILITY_COUNT) {
        rv = static_cast<AbilityT>(offset);
    }

    return rv;
}

//++i operator
AbilityT & operator ++(AbilityT & a) {
    
    a = a + 2;
    return a;
}

// i++
AbilityT operator ++(AbilityT & a, int) {

    AbilityT rv{a};
    a = a + 2;
    return rv;
}

AbilityT operator - (AbilityT a) {
    AbilityT rv{AbilityT::NONE};
    size_t offset = static_cast<size_t>(a);

    if (offset < ABILITY_COUNT) {
       if (offset %2 == 0) {
           rv = static_cast<AbilityT>(offset + 1);
       } else {
           rv = static_cast<AbilityT>(offset - 1);
       }
    }

    return rv;
}

string AbilityTToString (AbilityT a) {
   string rv{"NONE"};

   if (a < AbilityT::NONE) {
       size_t offset = static_cast<size_t>(a);
       rv = ABILITY_NAMES[offset];
   }
   return rv;
}