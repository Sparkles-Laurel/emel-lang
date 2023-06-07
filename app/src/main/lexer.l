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
    if(!strcmp(yytext, "if")) return IF;
    else if(!strcmp(yytext, "is")) return IS;
    else if(!strcmp(yytext, "then")) return THEN;
    else if(!strcmp(yytext, "else")) return ELSE;
    else if(!strcmp(yytext, "and")) return AND;
    else if(!strcmp(yytext, "or")) return OR;
    else if(!strcmp(yytext, "not")) return NOT;
    else if(!strcmp(yytext, "set")) return SET;
    else if(!strcmp(yytext, "fn")) return FN;
    else if(!strcmp(yytext, "let")) return LET;
    else if(!strcmp(yytext, "bool")) return BOOL;
    else if(!strcmp(yytext, "R")) return REAL;
    else if(!strcmp(yytext, "Z")) return INTEGER;
    else if(!strcmp(yytext, "N")) return NATURAL;
    else if(!strcmp(yytext, "Q")) return RATIONAL;
    else if(!strcmp(yytext, "i") || !strcmp(yytext, "j")) return IMAGINARY;
    else if(!strcmp(yytext, "C")) return COMPLEX;
    else if(!strcmp(yytext, "type")) return TYPE;
    else if(!strcmp(yytext, "rt")) return ROOT;
    else if(!strcmp(yytext, "pw") || !strcmp(yytext, "^")) return POWER;
 
    else if(strcmp(!yytext, "poly")) return POLY;
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
