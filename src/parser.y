%token	IDENTIFIER DECIMAL_NUMBER HEXADECIMAL_NUMBER BOOLEAN_TRUE BOOLEAN_FALSE SEMICOLON STRING TYPE NULL_VALUE
%token  PAREN_OPEN PAREN_CLOSE BRACE_OPEN BRACE_CLOSE OP_PLUS OP_MINUS OP_MULTIPLY OP_DIVIDE OP_NOT OP_AND OP_OR COMMA
%token  IF ELSE WHILE OP_EQ OP_NE OP_GT OP_GE OP_LT OP_LE EQUALS
%start	Program

%{
  extern int yylex( );
  extern void yyerror( const char* );
%}

%%

Expression:             ArithmeticExpression
                        | BooleanExpression
                        | Literal
                        | IDENTIFIER
                        | Assignment
                        | Declaration
                        | MethodCall
                        | PAREN_OPEN Expression PAREN_CLOSE ;

Literal:                NULL_VALUE
                        | Number
                        | BooleanValue
                        | STRING ;

Number:                 DECIMAL_NUMBER
                        | HEXADECIMAL_NUMBER ;

ArithmeticExpression:   Addition
                        | Subtraction
                        | Multiplication
                        | Division ;

Addition:               Expression OP_PLUS Expression ;
Subtraction:            Expression OP_MINUS Expression ;
Multiplication:         Expression OP_MULTIPLY Expression ;
Division:               Expression OP_DIVIDE Expression ;

BooleanExpression:      CompareExpression
                        | Expression LogicalOperator Expression
                        | OP_NOT Expression ;

BooleanValue:           BOOLEAN_TRUE
                        | BOOLEAN_FALSE ;

LogicalOperator:        OP_AND
                        | OP_OR ;

CompareExpression:      Expression CompareOperator Expression ;

CompareOperator:        OP_EQ
                        | OP_NE
                        | OP_LT
                        | OP_LE
                        | OP_GT
                        | OP_GE ;

Assignment:             IDENTIFIER EQUALS Expression ;

Declaration:            TYPE Identifiers
                        | TYPE Assignments ;

Identifiers:            Identifiers COMMA IDENTIFIER
                        | IDENTIFIER ;

Assignments:            Assignments COMMA Assignment
                        | Assignment ;

MethodCall:             IDENTIFIER PAREN_OPEN ParameterList PAREN_CLOSE ;

ParameterList:          /* empty */
                        | ParameterList COMMA Expression
                        | Expression ;

Statement:              Expression SEMICOLON ;
                        | IfStatement
                        | WhileStatement ;

IfCondition:            PAREN_OPEN BooleanExpression PAREN_CLOSE ;

IfStatement:            IF IfCondition BlockOrStatement ElseIfStatements ;

ElseIfStatements:       ElseStatement
                        | ElseIfStatements ElseIfStatement ;

ElseIfStatement:        ELSE IF IfCondition BlockOrStatement ;

ElseStatement:          /* empty */
                        | ELSE BlockOrStatement ;

WhileStatement:         WHILE PAREN_OPEN BooleanExpression PAREN_CLOSE BlockOrStatement ;

BlockOrStatement:       Block
                        | Statement ;

MethodDeclaration:      TYPE IDENTIFIER PAREN_OPEN DeclParameterList PAREN_CLOSE Block ;

DeclParameterList:      /* empty */
                        | DeclParameterList COMMA Parameter
                        | Parameter ;

Parameter:              TYPE IDENTIFIER ;

BlockCode:              /* empty */
                        | BlockCode Block
                        | BlockCode Statement ;

Block:                  BRACE_OPEN BlockCode BRACE_CLOSE ;

Program:	              /* empty */
                        | Program Block
                        | Program Statement
                        | Program MethodDeclaration ;

%%

