#pragma once
#include "Automaton.h"
#include <string>

class CommentAutomaton : public Automaton {
  public:
    CommentAutomaton(TokenType tokenType);

    int read(const string& input);
};
