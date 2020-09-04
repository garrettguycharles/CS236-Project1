#pragma once

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

    virtual int read(const string& input) = 0;

    virtual Token* CreateToken(string input, int lineNumber) {
      return new Token(type, input, lineNumber);
    }

    virtual int newLinesRead() const {
      return newLines;
    }

};
