#include "Lexer.h"

Lexer::Lexer() {

  this->machines = {new MatcherAutomaton(",", TokenType::COMMA),
                    new MatcherAutomaton(".", TokenType::PERIOD),
                    new MatcherAutomaton("?", TokenType::Q_MARK),
                    new MatcherAutomaton("(", TokenType::LEFT_PAREN),
                    new MatcherAutomaton(")", TokenType::RIGHT_PAREN),
                    new MatcherAutomaton(":", TokenType::COLON),
                    new MatcherAutomaton(":-", TokenType::COLON_DASH),
                    new MatcherAutomaton("*", TokenType::MULTIPLY),
                    new MatcherAutomaton("+", TokenType::ADD),
                    new MatcherAutomaton("Schemes", TokenType::SCHEMES),
                    new MatcherAutomaton("Facts", TokenType::FACTS),
                    new MatcherAutomaton("Rules", TokenType::RULES),
                    new MatcherAutomaton("Queries", TokenType::QUERIES),
                    new IDAutomaton(TokenType::ID),
                    new StringAutomaton(TokenType::STRING),
                    new CommentAutomaton(TokenType::COMMENT)};

}

void Lexer::run(string inputString) {
  /*for (int i = 0; i < machines.size(); i++) {
    cout << machines[i]->read(inputString) << endl;
  }*/
  string workingString = inputString;

  int lineNum = 1;

  while (workingString.size() > 0) {
    int maxRead = 0;
    Automaton* maxMachine = machines.at(0);
    int maxMachineNewLinesRead = 0;

    for (int i = 0; i < machines.size(); i++) {
      int inputRead = machines.at(i)->read(workingString);
      if (inputRead > maxRead) {
        maxRead = inputRead;
        maxMachine = machines.at(i);
        maxMachineNewLinesRead = maxMachine->newLinesRead();

      }
    }

    if (maxRead > 0) {
      string strVal = workingString.substr(0, maxRead);

      Token* newTok = maxMachine->CreateToken(strVal, lineNum);
      resultTokens.push_back(newTok);

      for (int lnitrtr = 0; lnitrtr < maxRead; lnitrtr++) {
        if (workingString[lnitrtr] == '\n') {
          lineNum++;
        }
      }
    }

    else {
      maxRead = 1;
      if (workingString[0] == '\n') {
        lineNum += maxRead;
      }
      else if (!isspace(workingString[0])) {
        Token* newTok = new Token(TokenType::UNDEFINED, workingString.substr(0,maxRead), lineNum);
        resultTokens.push_back(newTok);
      }
    }

    //lineNum += maxMachineNewLinesRead;

    workingString = workingString.substr(maxRead);

  }

  Token* eofTok = new Token(TokenType::END_OF_FILE, "", lineNum);
  resultTokens.push_back(eofTok);
}

string Lexer::toString() {
  string strToReturn = "";
  cout << endl;
  for (int i = 0; i < resultTokens.size(); i++) {

    cout << resultTokens.at(i)->toString() << endl;
    strToReturn += resultTokens.at(i)->toString() + "\n";

  }
  cout << "Total Tokens = " << resultTokens.size() << endl << endl;
  strToReturn += "Total Tokens: " + to_string(resultTokens.size());

  return strToReturn;

}
