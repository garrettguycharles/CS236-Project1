#pragma once
#include "Automaton.h"
#include <string>

class IDAutomaton : public Automaton {
  public:
    IDAutomaton(TokenType tokenType);

    int Read(const string& input);
};
