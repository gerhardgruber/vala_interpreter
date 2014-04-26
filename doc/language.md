# General
This file contains the description of the language which can be interpreted by the vala_interpreter.
The language description will be done in the EBNF (http://de.wikipedia.org/wiki/Erweiterte_Backus-Naur-Form)


# Constants

## Numbers
```ebnf

digit_without_zero = "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" ;

digit = "0" | digit_without_zero ;

hex_digit = digit | "a" | "b" | "c" | "d" | "e" | "f" | "A" | "B" | "C" | "D" | "E" | "F" ;

decimal_number = [ "-" ] , digit_without_zero { digit } | "0" ;

hex_number = [ "-" ] "0x" hex_digit { hex_digit } ;

number = decimal_number | hex_number ;
```

## Boolean
```ebnf
boolean_value = "true" | "false" ;
```

## Strings
```ebnf
character = ? all unicode characters ? ;
alphabetic_character = ? a-z, A-Z ? ;
string = """ { character } """ ;
```

## Types
```ebnf
integer_types = "uint8" |
                "int8" |
                "uint16" |
                "int16" |
                "uint32" |
                "int32" |
                "uint64" |
                "int64" |
                "uint" |
                "int" |
                "ulong" |
                "long" ;

character_types = "char" | "uchar" | "unichar" ;

string_types = "string" ;

type = integer_types | character_types | string_types | "void" | "bool" ;
```

# Expressions
```ebnf
literal = "null" | number | boolean_value | string ;

identifier_character = alphabetic_character | digit | "_" ;

identifier = alphabetic_character { identifier_character } ;

expression = arithmetic_expression | boolean_expression | literal | idetifier | assignment | declaration | method_call | "(" expression ")";

arithmetic_expression = addition | subtraction | multiplication | division ;
addition = expression "+" expression ;
subtraction = expression "-" expression ;
multiplication = expression "*" expression ;
division = expression "/" expression ;

boolean_expression =  boolean_value |
                      compare_expression |
                      boolean_expression logical_operator boolean_expression |
                      "!" boolean_expression |
                      "(" boolean_expression ")" ;
logical_operator = "&&" | "||" ;
compare_operator = "<" | "<=" | "==" | ">=" | ">" ;
compare_expression = expression compare_operator expression ;

assignment = identifier "=" expression ;

declaration = type identifier { "," identifier } | type assignment { "," assignment } ;

method_call = identifier "(" [ call_parameter_list ] ")"
call_parameter_list = expression { "," call_parameter_list }
```

# Statements & Blocks
```ebnf
statement = expression ";" |
            if_statement |
            while_statement ;

block_or_statement = block | statement ;

while_statement = "while" "(" boolean_expression ")" block_or_statement ;

if_statement = "if" "(" boolean_expression ")" block_or_statement { elseif_statement } { else_statement } ;
elseif_statement = "else if" "(" boolean_expression ")" block_or_statement ;
else_statement = "else" block_or_statement ;

block = "{" { statement } "}" ;

method_declaration = type identifier "(" [ parameter_list ] ")" block ;
parameter = type identifier ;
parameter_list = parameter { "," parameter } ;

program = { block | statement | method_declaration } ;
```