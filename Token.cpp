#pragma once

#include "Token.h"

Token::Token() {
  this->type = TokenType::UNDEFINED;
  this->value = "Value";
  this->lineNum = 1;
}

Token::Token(TokenType initType, string initValue, int initLineNum) {
  this->type = initType;
  this->value = initValue;
  this->lineNum = initLineNum;
}

string Token::toString() {
  // first, get string representation of tokenType
  string typeStr = "";

  switch (type) {

    case TokenType::COMMA:
      typeStr = "COMMA";
      break;
    case TokenType::PERIOD:
      typeStr = "PERIOD";
      break;
    case TokenType::Q_MARK:
      typeStr = "Q_MARK";
      break;
    case TokenType::LEFT_PAREN:
      typeStr = "LEFT_PAREN";
      break;
    case TokenType::RIGHT_PAREN:
      typeStr = "RIGHT_PAREN";
      break;
    case TokenType::COLON:
      typeStr = "COLON";
      break;
    case TokenType::COLON_DASH:
      typeStr = "COLON_DASH";
      break;
    case TokenType::MULTIPLY:
      typeStr = "MULTIPLY";
      break;
    case TokenType::ADD:
      typeStr = "ADD";
      break;
    case TokenType::SCHEMES:
      typeStr = "SCHEMES";
      break;
    case TokenType::FACTS:
      typeStr = "FACTS";
      break;
    case TokenType::RULES:
      typeStr = "RULES";
      break;
    case TokenType::QUERIES:
      typeStr = "QUERIES";
      break;
    case TokenType::ID:
      typeStr = "ID";
      break;
    case TokenType::STRING:
      typeStr = "STRING";
      break;
    case TokenType::COMMENT:
      typeStr = "COMMENT";
      break;
    case TokenType::UNDEFINED:
      typeStr = "UNDEFINED";
      break;
    case TokenType::END_OF_FILE:
      typeStr = "EOF";
      break;
    default:
      //do nothing
      break;

  }

  //then return
  return "(" + typeStr + ",\"" + this->value + "\"," + to_string(this->lineNum) + ")";
}
