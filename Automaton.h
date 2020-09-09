#ifndef AUTOMATON_H
#define  AUTOMATON_H


#include <iostream>
#include <string>
#include "TokenType.h"
#include "Token.h"

using namespace std;

class Automaton {
  protected:
    int newLines = 0;
    TokenType type;

  public:
    Automaton(TokenType type) {
      this->type = type;
    };

    virtual ~Automaton() {};

    virtual int Read(const string& input) = 0;

    virtual Token* CreateToken(string input, int lineNumber) {
      return new Token(type, input, lineNumber);
    }

    virtual int newLinesRead() const {
      return newLines;
    }

};

#endif
