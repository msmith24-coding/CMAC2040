#include <iostream>
#include <string>
#include "AbilityT.h"
#include <sstream>

using namespace std;

// don't like this, but I don't know any other way to get these words.
const string ABILITY_NAMES[]{"strong", "weak", "tough", "sickly", "clever", "dense", "wise", "foolish", "dexterous", "fumbling", "agile", "clumsy", "fast", "slow", "charming", "unpleasant", "attractive", "ugly", "none"};

const size_t ABILITY_COUNT {static_cast<size_t>(AbilityT::NONE)};

void PrintTest();
void NegativeTest();
void PrePostTest();
void ReadTest();
void MixedWordTest();

int main() {

    srand(time(nullptr));

    PrintTest();
    ReadTest();
    MixedWordTest();
    NegativeTest();
    PrePostTest();

    return 0;
}

string Scramble(string s) {
    for(auto &x: s) {
       if (rand()/static_cast<float>(RAND_MAX)  >  0.5) {
          x = toupper(x);
       }
    }

    return s;
}

void CheckString(string word, AbilityT a) {
    AbilityT back;
    back = StringToAbilityT(word);
    if (back != a) {
        cout << "Error in MixedWordTest, got " << back
              << " but should have " << a
              << ", the word was " << word << endl;
    }
}

void MixedWordTest() {
    AbilityT i;
    int j;
    size_t pos{0};
    string mixedWord;


    for(i = FIRST_ABILITY; i != AbilityT::NONE; i = i + 1){
       for(j = 0; j < 10; ++j) {
           mixedWord = Scramble( ABILITY_NAMES[pos]);
           CheckString(mixedWord, i);
       }
       ++pos;
    }

    // now check some random things:
    for(i = FIRST_ABILITY; i != AbilityT::NONE; i = i + 1){
        mixedWord = Scramble( ABILITY_NAMES[pos]) + '1';
        CheckString(mixedWord, AbilityT::NONE);
        mixedWord = Scramble( ABILITY_NAMES[pos]) + "ed";
        CheckString(mixedWord, AbilityT::NONE);
        mixedWord = Scramble( ABILITY_NAMES[pos]) + '.';
        CheckString(mixedWord, AbilityT::NONE);
        mixedWord = "2"+Scramble( ABILITY_NAMES[pos]);
        CheckString(mixedWord, AbilityT::NONE);
    }
}

void PreTest(AbilityT i) {

   AbilityT old {i};
   AbilityT next { i + 2};
   AbilityT tmp = {++i};
   if (tmp != next) {
      cout << "++i test failed when i was " << old;
      cout << "  Wrong return value " << tmp << " not " << next << endl;
   }
   if (i != next) {
      cout << "++i test failed when i was " << old;
      cout << "  Wrong increment value " << i << " not " << next << endl;
   }
   return;
}

void PostTest(AbilityT i) {

   AbilityT old {i};
   AbilityT next { i + 2};
   AbilityT tmp = {i++};
   if (tmp != old) {
      cout << "i++ test failed when i was " << old;
      cout << "  Wrong return value " << tmp << " not " << old << endl;
   }
   if (i != next) {
      cout << "i++ test failed when i was " << old;
      cout << "  Wrong increment value " << i << " not " << next << endl;
   }
   return;
}

void PrePostTest() {
    AbilityT i;

    for(i = FIRST_ABILITY; i != AbilityT::NONE; i = i + 1) {
        PreTest(i);
        PostTest(i);
    }

    return;
}

void TestDoubleNegative(AbilityT i) {
    AbilityT negative, doubleNegative;

    negative = -i;
    doubleNegative = -negative;
    if (i != doubleNegative) {
       cout << "Error in TestDoubleNegative:"
           <<  " -" << i << " != " << doubleNegative << endl;
    }
    return;
}

void TestFollow(AbilityT i) {
    
    AbilityT follow{ i+1};
    AbilityT negative{-follow};
    if (i != negative) {
       cout << "Error in TestFollow:"
           <<  " -" << i << " != " << negative << endl;
    }
    return;
}

void TestProceed(AbilityT i) {
    AbilityT negative{-i};
    AbilityT proceed{negative+1};
    if (i != proceed) {
       cout << "Error in TestProceed:"
           <<  " -" << i << " != " << proceed << endl;
    }
    return;
}

   
void NegativeTest(){
    AbilityT i{FIRST_ABILITY};

    for(i = FIRST_ABILITY; i != AbilityT::NONE; ++i){
        TestDoubleNegative(i);
        TestFollow(i);
    }

    for(i = FIRST_ABILITY + 1; i != AbilityT::NONE; ++i){
        TestDoubleNegative(i);  
        TestProceed(i);
    }

    return;
}

void TestPrint(AbilityT a, string s) {
     
    string tmp;
    std::stringstream stream;
    auto old = cout.rdbuf(stream.rdbuf());
    cout << a;
    tmp = stream.str();

    cout.rdbuf(old);

    if (tmp != s) {
        cout << "Stream insertion failed for " << a << " got "
             << tmp << " not " << s << endl;
    }
}

void PrintTest() {
    AbilityT i{FIRST_ABILITY};
    size_t pos{0};
    
    for(i = FIRST_ABILITY ; i != AbilityT::NONE; i = i + 1){
       TestPrint(i, ABILITY_NAMES[pos]);
       pos++;
    }

    return;
}

void TestRead(string s, AbilityT a) {
    AbilityT tmp;
    std::stringstream stream;
    stream.str(s);

    auto old = cin.rdbuf(stream.rdbuf());
    cin >> tmp;
    cin.rdbuf(old);

    if (tmp != a) {
        cout << "Stream extraction failed for " << a << " got " << tmp 
            << " not " << a << endl;
    }

}

void ReadTest() {
    size_t pos{0};
    AbilityT i{FIRST_ABILITY};

    for(pos = 0; pos <= ABILITY_COUNT; ++pos) {
        TestRead(ABILITY_NAMES[pos], i);
        i = i + 1;
    }
}