#pragma once
#include "CommentAutomaton.h"

CommentAutomaton::CommentAutomaton(TokenType tokenType) : Automaton(tokenType) {
  this->type = TokenType::COMMENT;
}

int CommentAutomaton::Read(const string& input) {
  int inputRead = 0;
  bool isLineComment = false;
  bool isBlockComment = false;

  if (input[0] == '#') {
    if (input[1] == '|') {
      isBlockComment = true;
    } else {
      isLineComment = true;
    }
    inputRead++;
  }

  if (isLineComment) {
    for(int i = 1; i < input.size(); i++) {
      if (input[i] == '\n') {
        break;
      } else {
        inputRead++;
      }
    }
  } else if (isBlockComment) {
    inputRead++;
    bool isBadComment = true;
    for (int i = 2; i < (input.size() - 1); i++) {
      inputRead++;
      if (input[i] == '|') {
        if ((i < (input.size() - 1)) and !(input[(i + 1)] == '#')) {
          //do nothing, go back to loop.
        } else {
          inputRead++;
          isBadComment = false;
          break;
        }
      }
    }

    if (isBadComment) {
      this->type = TokenType::UNDEFINED;
    }

  }

  return inputRead;
}
