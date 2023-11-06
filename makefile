
PARSER = parser/parser_build/parser.cpp
LEXER = parser/parser_build/lexer.cpp
TOKENS = parser/parser_build/parser.hpp

build: *.cpp ${PARSER} ${LEXER}
	g++ $^ -DNDEBUG -o go_compiler

${PARSER} ${TOKENS}: parser/go.y
	bison $< -v -o ${PARSER} -l

parser/parser_build/lexer.cpp: parser/go.lex ${TOKENS}
	flex -o $@ $<

run: build
	./go_compiler $(target)

build_debug: *.cpp ${PARSER} ${LEXER}
	g++ $^
run_debug: build_debug
	./a.out $(target)

clean:
	rm -f ./go_compiler
	rm -f parser/parser_build/*