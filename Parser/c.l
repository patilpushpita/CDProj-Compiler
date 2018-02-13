%{
#include "helper.h"
%}
alpha [a-zA-Z]
digit [0-9]
datatype ("int"|"float"|"char"|"struct"|"enum")
intconst [0-9]+
fpconst [+-]?([0-9]*[.])?[0-9]+
a_operators [/*+%]
r_operators  (">"|"<"|">="|"<="|"==")
identifier [_a-zA-Z][_a-zA-Z0-9]*
file ^"#include".+
String ("\"").+("\"")

%%
[ \t]		;
[ \n]   { yylineno = yylineno + 1;}
int	return INT;
float return FLOAT;
char return CHAR;
struct return STRUCT;
enum return ENUM;
{String} return STRING;
void return VOID;
for 	return FOR;
while	return WHILE;
if	return IF;
else	return ELSE;
switch return SWITCH;
continue return CONTINUE;
break return BREAK;
{file} ;
intconst {/*insertC(yytext,"integerconst")*/;return NUM;}
fpconst {/*insertC(yytext, "floatingpconst")*/; return NUM;}
stconst {/*insertC(yytext, "stringConstant")*/; return NUM;}
{alpha}({alpha}|{digit})* return ID;
"<="    return LE;
">="    return GE;
"=="    return EQ;
"!="    return NE;
">"	return GT;
"<"	return LT;
"."     return DOT;
\/\/.* ;
\/\*(.*\n)*.*\*\/ ;
.       return yytext[0];
%%


int yywrap()
{
    return(1);
}
