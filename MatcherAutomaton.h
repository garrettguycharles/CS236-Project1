#pragma once
#include "Automaton.h"
#include <string>

class MatcherAutomaton : public Automaton {
  private:
    string strToMatch;
    int newLinesRead = 0;
  public:
    MatcherAutomaton(string strToMatch, TokenType tokenType);

    int read(const string& input);

    int getNewLines() {return this->newLinesRead;}
};
