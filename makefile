lexer: main.cpp Automaton.h IDAutomaton.h IDAutomaton.cpp MatcherAutomaton.h MatcherAutomaton.cpp StringAutomaton.h StringAutomaton.cpp TokenType.h Token.cpp Token.h Lexer.h Lexer.cpp CommentAutomaton.h CommentAutomaton.cpp
	g++ -Wall -Werror -std=c++17 -g *.cpp -o ./bin/lexer

clean:
	rm ./bin/*.o lexer
