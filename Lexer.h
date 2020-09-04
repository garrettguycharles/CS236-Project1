#pragma once
#include "MatcherAutomaton.h"
#include "StringAutomaton.h"
#include <vector>
#include <cctype>

using namespace std;

class Lexer {
  private:
    vector<Automaton*> machines;
    vector<Token*> resultTokens;

  public:
    Lexer();
    void run(string inputString);
    void toString();
};
