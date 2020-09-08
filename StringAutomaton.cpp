#pragma once
#include "StringAutomaton.h"

StringAutomaton::StringAutomaton(TokenType tokenType) : Automaton(tokenType) {
  this->type = TokenType::STRING;
}

int StringAutomaton::Read(const string& input) {
  int inputRead = 0;
  bool isString = false;

  if (input[0] == '\'') {
    isString = true;
    inputRead++;
  }

  if (isString) {
    bool isBadString = true;
    for (int i = 1; i < input.size(); i++) {
      inputRead++;
      if (input[i] == '\'') {
        if ((i < (input.size() - 1)) and (input[(i + 1)] == '\'')) {
          //do nothing, go back to loop.
          i++;
          inputRead++;
        } else {
          isBadString = false;
          break;
        }
      }
    }

    if (isBadString) {
      this->type = TokenType::UNDEFINED;
    }

  }

  return inputRead;
}
