%{
#include "helper.h"
%}
alpha [a-zA-Z]
digit [0-9]
fpconst [+-]?([0-9]*[.])?[0-9]+
identifier [_a-zA-Z][_a-zA-Z0-9]{0,30}
file ^"#include".+$
Delimiter "\;"
String ("\"").+("\"")
%%
[ \t]		;
[ \n]   { yylineno = yylineno + 1;}
int	{ insert(yytext, "datatype");return INT;}
float { insert(yytext, "datatype");return FLOAT;}
char { insert(yytext, "datatype");return CHAR;}
void { insert(yytext, "datatype");return VOID;}
for  return FOR;
while	return WHILE;
if	return IF;
else	return ELSE;
struct 	return STRUCT;
switch  return SWITCH;
^"#include ".+ ; return FILE1;
{digit}+       return NUM;
{fpconst} return FNUM;
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
