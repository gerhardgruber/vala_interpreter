LEX=flex
CC=cc
CFLAGS=-ll -g -ly
PARSER_GEN=bison

all: vala_interpreter lexer_test parser_test

test: test_lexer test_parser

test_lexer: lexer_test
	./test_lexer.sh

test_parser: parser_test
	./test_parser.sh

vala_interpreter: vala_interpreter.o
	${CC} -o vala_interpreter vala_interpreter.o ${CFLAGS}

vala_interpreter.o: vala_interpreter.c
	${CC} -c vala_interpreter.c -o vala_interpreter.o ${CFLAGS}

parser.h parser.c: parser.y
	${PARSER_GEN}	--defines=parser.h -o parser.c parser.y

parser.o: parser.c
	${CC} -c parser.c -o parser.o ${CFLAGS}

lexer.yy.c lexer.yy.h: lexer.l parser.h
	${LEX} -o lexer.yy.c --header-file=lexer.yy.h lexer.l

lexer.o: lexer.yy.c lexer.yy.h
	${CC} -c lexer.yy.c -o lexer.o ${CFLAGS}

lexer_test: lexer_test.o lexer.o
	${CC} -o lexer_test lexer_test.o lexer.o ${CFLAGS}

lexer_test.o: lexer_test.c vala_interpreter_core.h lexer.yy.h parser.h
	${CC} -c lexer_test.c -o lexer_test.o ${CFLAGS}

parser_test: parser_test.o parser.o
	${CC} -o parser_test parser_test.o parser.o lexer.o ${CFLAGS}

parser_test.o: parser_test.c vala_interpreter_core.h lexer.yy.h parser.h
	${CC} -c parser_test.c -o parser_test.o ${CFLAGS}

clean:
	rm -rf vala_interpreter vala_interpreter.o
	rm -rf lexer.o lexer.yy.c lexer.yy.h
	rm -rf lexer_test lexer_test.o
	rm -rf parser.h parser.c
	rm -rf parser_test parser_test.o


