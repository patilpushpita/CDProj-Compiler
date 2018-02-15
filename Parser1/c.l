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
for  { insert(yytext, "forloop");return FOR;}
while	{ insert(yytext, "whileloop");return WHILE;}
if	{ insert(yytext, "ifcond");return IF;}
else	{ insert(yytext, "elsecond");return ELSE;}
struct 	{ insert(yytext, "struct");return STRUCT;}
switch  { insert(yytext, "switch");return SWITCH;}
^"#include".+ ; { insert(yytext, "fileinc");}
{digit}+       { insertC(yytext, "intconst");return NUM;}
{fpconst} { insertC(yytext, "floatconst");return FNUM;}
{alpha}({alpha}|{digit})* { insert(yytext, "identifier");return ID;}
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
