#pragma once
#include "Automaton.h"
#include <string>

class MatcherAutomaton : public Automaton {
  private:
    string strToMatch;
    int newLinesRead = 0;
  public:
    MatcherAutomaton(string strToMatch, TokenType tokenType);

    int Read(const string& input);

    int getNewLines() {return this->newLinesRead;}
};
