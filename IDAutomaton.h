#ifndef IDAUTOMATON_H
#define IDAUTOMATON_H

#include "Automaton.h"
#include <string>

class IDAutomaton : public Automaton {
  public:
    IDAutomaton(TokenType tokenType);

    int Read(const string& input);
};

#endif
