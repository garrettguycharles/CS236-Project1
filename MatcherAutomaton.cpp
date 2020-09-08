#pragma once
#include "MatcherAutomaton.h"

MatcherAutomaton::MatcherAutomaton(string strToMatch, TokenType tokenType) : Automaton(tokenType) {
  this->strToMatch = strToMatch;
}

int MatcherAutomaton::Read(const string& input) {
  newLinesRead = 0;
  bool isMatch = true;
  int inputRead = 0;
  for (int i = 0; i < this->strToMatch.size(); i++) {
    if (input[i] != strToMatch[i]) {
      isMatch = false;
    }
  }

  if (isMatch) {
    inputRead = strToMatch.size();
  }

  return inputRead;
}
