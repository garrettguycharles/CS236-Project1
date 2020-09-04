#pragma once
#include "Automaton.h"
#include <string>

class StringAutomaton : public Automaton {
  public:
    StringAutomaton(TokenType tokenType);

    int read(const string& input);
};
