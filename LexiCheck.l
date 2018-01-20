%{
#include "helper.h"
int cnto = 0;
int cntc = 0;
%}
datatype ("int"|"float"|"char"|"struct"|"enum")
intconst [0-9]+
fpconst [+-]?([0-9]*[.])?[0-9]+
a_operators [/*+%]
r_operators  (">"|"<"|">="|"<="|"==")
assignment_op [=]
identifier [_a-zA-Z][_a-zA-Z0-9]{0,30}
ConditionIf ("if")
Conditionelse ("else")
ConditionSwitch("switch"|"case"|"default") 
Control ("continue"|"break")
Loop ("for"|"while")
file ^"#include".+$
Comment "//".+$
oBracket \{
oPara \(
cBracket \}
cPara \)
funccall [_a-zA-Z][_a-zA-Z0-9]{0,30}\(\)
funcprot ("void"|"int"|"float"|"char")(" "){identifier}\(.*\)("\;")
funcheader ("void"|"int"|"float"|"char")(" "){identifier}\(.*\)
multicomment "/*".+"*/"
Delimiter "\;"
String ("\"").+("\"")
printf ("printf\("){String}("\)");
%%
{Comment} { insert("//", "comment"); }
{multicomment} {insert("/*", "multilinecomment");}
{printf} {insert(yytext , "print statement");}
{String} { insert(yytext, " String");}
{file} { insert("#", "file"); }
{funcprot} {insert(yytext, "function prototype");}
{funcheader} {insert(yytext, "function header");}
{funccall} {insert(yytext, "function call");}
{datatype} { insert(yytext, "datatype"); }
{ConditionIf} { insert(yytext, "ConditionIf"); }
{Conditionelse} { insert(yytext, "Conditionelse"); }
{ConditionSwitch} { insert(yytext, "ConditionSwitch"); }
{Control} { insert(yytext, "Control"); }
{Loop} { insert(yytext, "Loop"); }
{Delimiter} { insert(yytext, "Delimiter"); }
{intconst} { insertC(yytext,"integerconst"); }
{fpconst} { insertC(yytext, "floatingpconst"); }
{identifier} { insert(yytext, "identifier"); }
{a_operators} { insert(yytext, "arithmetic"); }
{r_operators} { insert(yytext, "relational"); }
{oBracket} { insert(yytext, "openBracket"); ++cnto; }
{cBracket} { insert(yytext, "closeBracket"); ++cntc; }
{oPara} { insert(yytext, "openaPara"); }
{cPara} { insert(yytext, "closePara"); }
{assignment_op} { insert(yytext, "assignment_op"); }
[\r] ;
[\n] ;
[\t] ;
: ;
, ;
[ ] ;
. { printf("%s error\n", yytext);}
%%
void main()
{
    yyin=fopen("ErrorFile2.txt","r");
    yylex();
    if(cnto!=cntc)
    {
	printf("\nParenthesis error!");
    }
    Display();
    printf("\n\n");
    DisplayC();
}

int yywrap()
{
    return(1);
}
