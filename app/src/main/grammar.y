%token NUMBER ID IF ELSE IN UNION INTERSECTION DIFFERENCE SYMMETRIC_DIFFERENCE
%token RT NRT POW
%token '+' '-' '*' '/' '^' '<' '>' '<=' '>=' '==' '!=' '&&' '||'
%token '-' '+' '!' 'sin' 'cos' 'tan' 'cot' 'sec' 'csc' 'log' 'ln' 'sqrt' 'cbrt' 'abs'
%token '(' ')' '{' '}' ',' ';' '=' 'is'

%%

program : statement_list

statement_list : statement
               | statement_list ';' statement

statement : expression
          | assignment
          | set_assignment
          | function_definition

expression : NUMBER
           | ID
           | '(' expression ')'
           | expression BINARY_OP expression
           | UNARY_OP expression
           | ID '(' arguments ')'
           | ID IF expression ELSE expression
           | variable '*' variable
           | expression POW expression
           | RT expression
           | NUMBER RT expression
           | '(' expression ')' RT expression
           | '(' expression ')' RT '(' expression ')' 
           | expression RT expression
           | expression RT '(' expression ')'
           | expression RT NUMBER
           | set_expression
           | cartesian_product

arguments : expression
          | arguments ',' expression

set_expression : ID
               | '{' '}'
               | '{' set_values '}'
               | '{' set_builder '}'
               | set_operation

set_values : expression
           | set_values ',' expression

set_builder : expression '|' ID IN set_expression IF expression

set_operation : set_expression UNION set_expression
              | set_expression INTERSECTION set_expression
              | set_expression DIFFERENCE set_expression
              | set_expression SYMMETRIC_DIFFERENCE set_expression

cartesian_product : set_expression 'x' set_expression
                  | set_expression '*' set_expression

assignment : ID '=' expression
           | ID 'is' set_expression

set_assignment : ID '=' set_expression

function_definition : FUNCTION ID '(' ID ')' 'is' TYPE_ARROW set_expression
                    | FUNCTION ID '(' ID ')' 'is' TYPE_ARROW set_expression '=' expression
                    | FUNCTION ID '(' ')' 'is' TYPE_ARROW set_expression
                    | FUNCTION ID '(' ')' 'is' TYPE_ARROW set_expression '=' expression

ID : [a-zA-Z][a-zA-Z0-9]*
NUMBER : [0-9]+
VARIABLE : ID | NUMBER

variable : ID

BINARY_OP : '+' | '-' | '*' | '/' | '^' | '<' | '>' | '<=' | '>=' | '==' | '!=' | '&&' | '||'

UNARY_OP : '-' | '+' | '!' | 'sin' | 'cos' | 'tan' | 'cot' | 'sec' | 'csc' | 'log' | 'ln' | 'sqrt' | 'cbrt' | 'abs'

POW : '^' | 'pw' | 'xpwn'

RT : 'rt' | 'nrt'

%%

/* C code section */
