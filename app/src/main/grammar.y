%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
%}

%union {
    char* str;
    double num;
}

%token <str> IDENTIFIER TYPE
%token <num> NUMBER
%token SEMICOLON LPAREN RPAREN COMMA ASSIGNMENT
%token PLUS MINUS TIMES DIVIDE POWER ROOT
%token LT GT EQ LTEQ GTEQ NOTEQ
%token IF IS THEN ELSE
%token AND OR NOT
%token SET INTERSECTION UNION DIFFERENCE SYMDIFF SETBUILDER
%token POLY FN LET BOOL
%token REAL INTEGER NATURAL RATIONAL IMAGINARY COMPLEX
%token <str> LETTERS
%token EOL

%start program
%left OR
%left AND
%right NOT
%left EQ NOTEQ LT GT LTEQ GTEQ
%left PLUS MINUS
%left TIMES DIVIDE
%left POWER ROOT
%left UMINUS

%%

program: statement
        | program statement

statement: EOL
        | expression EOL
        | assignment EOL
        | declaration EOL
        | definition EOL

assignment: LET LETTERS "is" IDENTIFIER "equals" expression

declaration: TYPE IDENTIFIER "is" expression

definition: FN IDENTIFIER LPAREN IDENTIFIER RPAREN "is" TYPE "->" TYPE
            | FN IDENTIFIER LPAREN IDENTIFIER RPAREN "if" condition "is" expression

condition: expression EQ expression
            | expression NOTEQ expression
            | expression LT expression
            | expression GT expression
            | expression LTEQ expression
            | expression GTEQ expression

expression: IDENTIFIER
            | NUMBER
            | LETTERS LPAREN IDENTIFIER "," IDENTIFIER ")"
            | function
            | set
            | bool
            | "-" %prec UMINUS expression
            | expression PLUS expression
            | expression MINUS expression
            | expression TIMES expression
            | expression DIVIDE expression
            | expression POWER expression
            | expression ROOT expression
            | expression INTERSECTION expression
            | expression UNION expression
            | expression DIFFERENCE expression
            | expression SYMDIFF expression

function: FN IDENTIFIER LPAREN IDENTIFIER RPAREN {
            printf("Defining function %s with parameter %s\n", $2, $4);
        } "is" expression {
            printf("Function expression\n");
        }
        | FN IDENTIFIER LPAREN IDENTIFIER RPAREN "if" condition {
            printf("Defining function %s with parameter %s and conditional expression\n", $2, $4);
        } "is" expression {
            printf("Function expression\n");
        }

set: SET IDENTIFIER "=" "{" set_elements "}"

set_elements: expression {
                printf("Adding expression to set\n");
            }
            | set_elements "," expression {
                printf("Adding expression to set\n");
            }

bool: BOOL IDENTIFIER "=" expression

%%

int main(void) {
    yyparse();
    return 0;
}

int yyerror(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    return 1;
}