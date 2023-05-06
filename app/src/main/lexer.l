%option noyywrap

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "parser.tab.h"
%}

%union {
    char* str;
    double num;
}

%token <str> IDENTIFIER TYPE
%token <num> NUMBER
%token SEMICOLON LPAREN RPAREN COMMA ASSIGNMENT
%token PLUS MINUS TIMES DIVIDE POWER
%token LT GT EQ LTEQ GTEQ NOTEQ
%token IF IS THEN ELSE
%token AND OR NOT
%token SET INTERSECTION UNION DIFFERENCE SYMDIFF SETBUILDER
%token POLY FN LET BOOL
%token REAL INTEGER NATURAL RATIONAL IMAGINARY COMPLEX
%token LETTERS
%token EOL

%%
[a-zA-Z][a-zA-Z0-9]* {
    yylval.str = strdup(yytext);
    if(strcmp(yytext, "if") == 0) return IF;
    else if(strcmp(yytext, "is") == 0) return IS;
    else if(strcmp(yytext, "then") == 0) return THEN;
    else if(strcmp(yytext, "else") == 0) return ELSE;
    else if(strcmp(yytext, "and") == 0) return AND;
    else if(strcmp(yytext, "or") == 0) return OR;
    else if(strcmp(yytext, "not") == 0) return NOT;
    else if(strcmp(yytext, "set") == 0) return SET;
    else if(strcmp(yytext, "fn") == 0) return FN;
    else if(strcmp(yytext, "let") == 0) return LET;
    else if(strcmp(yytext, "bool") == 0) return BOOL;
    else if(strcmp(yytext, "real") == 0) return REAL;
    else if(strcmp(yytext, "integer") == 0) return INTEGER;
    else if(strcmp(yytext, "natural") == 0) return NATURAL;
    else if(strcmp(yytext, "rational") == 0) return RATIONAL;
    else if(strcmp(yytext, "imaginary") == 0) return IMAGINARY;
    else if(strcmp(yytext, "complex") == 0) return COMPLEX;
    else if(strcmp(yytext, "type") == 0) return TYPE;
    else if(strcmp(yytext, "sqrt") == 0 || strcmp(yytext, "root") == 0 || strcmp(yytext, "rt") == 0) return ROOT;
    else if(strcmp(yytext, "pw")) return POWER;
 
    else if(strcmp(yytext, "poly") == 0) return POLY;
    else yylval.str = strdup(yytext);
    return IDENTIFIER;
}

[0-9]*\.[0-9]+([eE][-+]?[0-9]+)? {
    yylval.num = atof(yytext);
    return NUMBER;
}

[0-9]+ {
    yylval.num = atoi(yytext);
    return NUMBER;
}

"=" {
    return ASSIGNMENT;
}

";" {
    return SEMICOLON;
}

"(" {
    return LPAREN;
}

")" {
    return RPAREN;
}

"," {
    return COMMA;
}

"+" {
    return PLUS;
}

"-" {
    return MINUS;
}

"*" {
    return TIMES;
}

"/" {
    return DIVIDE;
}

"^" {
    return POWER;
}

"<=" {
    return LTEQ;
}

">=" {
    return GTEQ;
}

"<" {
    return LT;
}

">" {
    return GT;
}