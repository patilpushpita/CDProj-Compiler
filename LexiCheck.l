%{

%}
datatype ("int"|"float"|"char")
intconst [0-9]+
fpconst [+-]?([0-9]*[.])?[0-9]+
operators("/"|"*"|"-"|"="|"+")
identifier [_a-zA-Z][_a-zA-Z0-9]{0,30}

ConditionIf ("if")
Conditionelse ("else")
ConditionSwitch("switch"|"case"|"default") 
Control ("Continue"|"Break")

Loop ("for"|"while")

Comment "//".+

Delimiter ;


%%
{datatype} printf("\ndatatype");
{ConditionIf} printf("\nConditionIf");
{Conditionelse} printf("\nConditionelse");
{ConditionSwitch} printf("\nConditionSwitch");
{Control} printf("\nControl");
{Loop} printf("\nLoop");
{Delimiter} printf("\nDelimiter");
{intconst} printf("\nintconst");
{fpconst} printf("\nfpconst");
{identifier} printf("\nidentifier");
{operators} printf("\noperator");

%%
int main()
{
	yyin=fopen("NoErrorFile.txt","r");

	yylex();
}
int yywrap()
{
	return(1);
}
