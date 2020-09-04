#pragma once

#include <iostream>
#include <string>
#include "TokenType.h"

using namespace std;

class Token {
  public:
    Token();
    Token(TokenType initType, string initValue, int initLineNum);
    string toString();

  private:
    TokenType type;
    string value;
    int lineNum;



};
