#pragma once

#include <string>

enum class AbilityT:unsigned char { STRONG, WEAK, TOUGH, SICKLY, CLEVER, DENSE, WISE, FOOLISH, DEXTEROUS, FUMBLING, AGILE, CLUMSY, FAST, SLOW, CHARMING, UNPLEASANT, ATTRACTIVE, UGLY, NONE }; 

const AbilityT FIRST_ABILITY{AbilityT::STRONG};

std::string AbilityTToString(AbilityT a);
AbilityT StringToAbilityT(const std::string & s);

std::ostream & operator << (std::ostream & s, AbilityT a);
std::istream & operator >> (std::istream & s, AbilityT & a);

AbilityT operator + (AbilityT a, size_t i);

AbilityT & operator ++(AbilityT & a);
AbilityT operator ++ (AbilityT & a, int);

AbilityT operator - (AbilityT a);