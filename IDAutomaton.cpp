#pragma once
#include "IDAutomaton.h"
#include <cctype>

IDAutomaton::IDAutomaton(TokenType tokenType) : Automaton(tokenType) {
  this->type = TokenType::ID;
}

int IDAutomaton::Read(const string& input) {
  int inputRead = 0;
  bool isID = false;

  if (isalpha(input[0])) {
    isID = true;
    inputRead++;
  }

  if (isID) {
    for (int i = 1; i < input.size(); i++) {
      if (isalnum(input[i])) {
        inputRead++;
      } else {
        break;
      }
    }
  }

  return inputRead;
}
