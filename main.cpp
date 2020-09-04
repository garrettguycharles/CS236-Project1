#include <iostream>
#include <fstream>
#include "TokenType.h"
#include "MatcherAutomaton.h"
#include "Lexer.h"


using namespace std;

int main() {

  Lexer lex;

  string inputString = "";
  string toAppendString = "";

  ifstream fin;
  fin.open("test.txt");

  while (getline(fin, toAppendString)) {
    toAppendString += "\n";
    inputString += toAppendString;
  }

  fin.close();

  lex.run(inputString);
  lex.toString();

}
