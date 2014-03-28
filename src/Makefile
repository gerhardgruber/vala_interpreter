LEX=flex
CC=cc
CFLAGS=-ll -g

all: vala_interpreter lexer_test

test: test_lexer

test_lexer: lexer_test
	./test_lexer.sh

vala_interpreter: vala_interpreter.o
	${CC} -o vala_interpreter vala_interpreter.o ${CFLAGS}

vala_interpreter.o: vala_interpreter.c
	${CC} -c vala_interpreter.c -o vala_interpreter.o ${CFLAGS}
	
lexer.yy.c lexer.yy.h: lexer.l
	${LEX} -o lexer.yy.c --header-file=lexer.yy.h lexer.l

lexer.o: lexer.yy.c lexer.yy.h
	${CC} -c lexer.yy.c -o lexer.o ${CFLAGS}

lexer_test: lexer_test.o lexer.o
	${CC} -o lexer_test lexer_test.o lexer.o ${CFLAGS}

lexer_test.o: lexer_test.c vala_interpreter_core.h lexer.yy.h
	${CC} -c lexer_test.c -o lexer_test.o ${CFLAGS}


clean:
	rm -rf vala_interpreter vala_interpreter.o
	rm -rf lexer.o lexer.yy.c lexer.yy.h
	rm -rf lexer_test.o


