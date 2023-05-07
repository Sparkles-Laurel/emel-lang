CC=cc

# builds the Yacc grammar and Lex lexer as a single module
# synthesizes the grammar and lexer from .y and .l files
grammar:
	yacc -d grammar.y
	lex grammar.l
	$(CC) -o grammar y.tab.c lex.yy.c -ll

# builds the whole project (located at app/src)
build: grammar
	cd app/src && make

# cleans the whole project (located at app/src)
clean:
	cd app/src && make clean
	rm -f grammar y.tab.c y.tab.h lex.yy.c