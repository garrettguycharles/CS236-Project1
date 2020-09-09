#ifndef LEXER_H
#define LEXER_H

#include "MatcherAutomaton.h"
#include "IDAutomaton.h"
#include "StringAutomaton.h"
#include "CommentAutomaton.h"
#include <vector>
#include <cctype>

using namespace std;

class Lexer {
  private:
    vector<Automaton*> machines;
    vector<Token*> resultTokens;

  public:
    Lexer();
    virtual ~Lexer();
    void run(string inputString);
    string toString();
};

#endif
