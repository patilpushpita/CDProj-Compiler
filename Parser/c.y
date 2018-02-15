%{
#include <stdio.h>
#include <stdlib.h>

extern FILE *fp;

%}

%token INT FLOAT CHAR STRING ENUM VOID
%token FOR WHILE 
%token IF ELSE SWITCH CASE DEFAULT
%token CONTINUE BREAK 
%token STRUCT 
%token NUM ID FNUM
%token INCLUDE 
%token DOT

%right '='
%left AND OR
%left '<' '>' LE GE EQ NE LT GT
%%

start:	Function 
	| Declaration
	;

/* Declaration block */
Declaration: Type Assignment ';' 
	| Assignment ';'  	
	| FunctionCall ';' 	
	| ArrayUsage ';'	
	| Type ArrayUsage ';'   
	| StructStmt ';'	
	| error	
	;

/* Assignment block */
Assignment: ID '=' Assignment
	| ID '=' FunctionCall
	| ID '=' ArrayUsage
	| ArrayUsage '=' Assignment
	| ID ',' Assignment
	| NUM ',' Assignment
	| ID '+' Assignment
	| ID '-' Assignment
	| ID '*' Assignment
	| ID '/' Assignment	
	| NUM '+' Assignment
	| NUM '-' Assignment
	| NUM '*' Assignment
	| NUM '/' Assignment
	| '\'' Assignment '\''	
	| '(' Assignment ')'
	| '-' '(' Assignment ')'
	| '-' NUM
	| '-' ID
	|   NUM
	|   ID
	;

/* Function Call Block */
FunctionCall : ID'('')'
	| ID'('Assignment')'
	;

/* Array Usage */
ArrayUsage : ID'['Assignment']'
	;

/* Function block */
Function: Type ID '(' ArgListOpt ')' CompoundStmt 
	;
ArgListOpt: ArgList
	|
	;
ArgList:  ArgList ',' Arg
	| Arg
	;
Arg:	Type ID
	;
CompoundStmt:	'{' StmtList '}'
	;
StmtList:	StmtList Stmt
	|
	;
Stmt:	WhileStmt
	| Declaration
	| ForStmt
	| IfStmt
	| ';'
	;

/* Type Identifier block */
Type:	INT 
	| FLOAT
	| CHAR
	| STRING
	| ENUM
	| VOID 
	;

/* Loop Blocks */ 
WhileStmt: WHILE '(' Expr ')' Stmt  
	| WHILE '(' Expr ')' CompoundStmt 
	;

/* For Block */
ForStmt: FOR '(' Expr ';' Expr ';' Expr ')' Stmt 
       | FOR '(' Expr ';' Expr ';' Expr ')' CompoundStmt 
       | FOR '(' Expr ';' ';'')' Stmt
       | FOR '(' ';' Expr ';'')' Stmt
       | FOR '(' ';'';'Expr')' Stmt
       | FOR '(' Expr ';' ';'')' CompoundStmt
       | FOR '(' ';' Expr ';'')' CompoundStmt
       | FOR '(' ';'';'Expr')' CompoundStmt
       | FOR '('';' ';'')' CompoundStmt
       | FOR '('';' ';'')' Stmt
       ;

/* IfStmt Block */
IfStmt : IF '(' Expr ')' Stmt ELSE Stmt
        | IF '(' Expr ')' Stmt
        ;
/* Struct Statement */
StructStmt : STRUCT ID '{' Type Assignment '}'  
	;


/*Expression Block*/
Expr:	
	| Expr LE Expr 
	| Expr GE Expr
	| Expr NE Expr
	| Expr EQ Expr
	| Expr GT Expr
	| Expr LT Expr
	| Assignment
	| ArrayUsage
	;
%%
#include"lex.yy.c"

#include<ctype.h>
int count=0;

int main(int argc, char *argv[])
{
	yyin = fopen(argv[1], "r");
	
   if(!yyparse())
		printf("\nParsing complete\n");
	else
		printf("\nParsing failed\n");
	
	fclose(yyin);
	Display();
	printf("\n\n");
	DisplayC();
    return 0;
}
         
yyerror(char *s) {
	printf("%d : %s %s\n", yylineno, s, yytext );
}         

