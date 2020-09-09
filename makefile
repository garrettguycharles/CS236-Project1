lexer: main.cpp Automaton.h IDAutomaton.h IDAutomaton.cpp MatcherAutomaton.h MatcherAutomaton.cpp StringAutomaton.h StringAutomaton.cpp TokenType.h Token.cpp Token.h Lexer.h Lexer.cpp CommentAutomaton.h CommentAutomaton.cpp
	g++ -std=c++11 main.cpp Automaton.h IDAutomaton.h IDAutomaton.cpp MatcherAutomaton.h MatcherAutomaton.cpp StringAutomaton.h StringAutomaton.cpp TokenType.h Token.cpp Token.h Lexer.h Lexer.cpp CommentAutomaton.h CommentAutomaton.cpp -o ./bin/lexer

clean:
	rm *.o lexer
