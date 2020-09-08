#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "TokenType.h"
#include "MatcherAutomaton.h"
#include "Lexer.h"


using namespace std;

int main(int argc, char* argv[]) {
  string srcPath;
  string destPath;

  /*
  for (int i = 0; i < argc; i++) {
    cout << i << ": " << argv[i] << endl;
  }
  */


  vector<string> args;
  for (int i = 0; i < argc; i++) {
    string toAppend = "";
    stringstream ss;
    ss << argv[i];
    ss >> toAppend;
    args.push_back(toAppend);
  }

  /*
  for (int i = 0; i < args.size(); i++) {
    cout << i << ": " << args.at(i) << endl;
  }
  */

  srcPath = args.at(1);

  for (int i = 0; i < (argc - 1); i++) {
    //cout << args.at(i) << endl;
    if ((args.at(i).find("-o") != string::npos) or (args.at(i).find("-O") != string::npos) or (args.at(i).find("-output") != string::npos) or (args.at(i).find("-Output") != string::npos)) {
      destPath = args.at(i + 1);
    }
  }

  Lexer lex;

  string inputString = "";
  string toAppendString = "";

  ifstream fin;
  fin.open(srcPath);

  if (!fin.is_open()) {
    cout << "Could not open input path." << endl;
  }

  while (getline(fin, toAppendString)) {
    toAppendString += "\n";
    inputString += toAppendString;
  }

  fin.close();

  //cout << inputString << endl;

  lex.run(inputString);

  ofstream fout;
  fout.open(destPath);
  if (!fout.is_open()) {
    cout << "Couldn't open output file." << endl;
    //cout << "destPath: " << destPath << endl;
  }
  fout << lex.toString();
  fout.close();

  cout << "Saved output to " << destPath << endl;

  return 0;

}
