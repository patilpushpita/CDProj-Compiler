%{
	#include <stdio.h>
    #include <ctype.h>
    void yyerror(char *s);
    extern char *yytext;
    extern int yylex();
    extern int yyparse();
    extern int scope;
    struct entry {
                int token_type;
                char *data_type;
                char* token_name;
                char* scope;
				int dimension; //added
                int valid;
                struct entry *next;
             }*node;

    struct entry* head = NULL;
    
    int error_flag = 0;
    int f_arg = 0;
    char* f_name;
    extern char* text;
    extern int numtext;
    int main_flag=0;
    int array = 0;
	int dim_arr = 0;

    char st[1000][10];
    int top=0;
    int i=0;
    char temp[2]="t";
    
    int label[200];
    int iflabel[200];
    int iftop=0;
    int ifnum = 0;
    int lnum=0;
    int ltop=0;
    char type[10];
%}

%union{
  int   int_val;
  char*	op_val;
  float real_val;
}

%token INTEGER DOUBLE CHARACTER IDENTIFIER STRINGLITERAL FLOAT CHAR FUNCTION ARRAY
%token RETURN VOID INT MAIN IF FOR ELSE BREAK CONTINUE
%token ADD_OP SUB_OP MUL_OP DIV_OP GE_OP EE_OP NE_OP LE_OP L_OP G_OP NOT_OP ASSIGN_OP

%left ADD_OP SUB_OP MUL_OP DIV_OP GE_OP EE_OP NE_OP LE_OP L_OP G_OP NOT_OP
%right ASSIGN_OP
%nonassoc "then"
%nonassoc ELSE

%%

function
    : INT IDENTIFIER {set_f_name();STMT_DECLARE_FUNC(1);} '(' ')' '{' statementlist RETURN  arg_expression ';' '}' {set_valid();} mainfunction 
    | INT IDENTIFIER {set_f_name();STMT_DECLARE_FUNC(1);} '(' INT {setType();} IDENTIFIER {f_arg = 1;STMT_DECLARE_ID(); set_data_type();}')' '{' statementlist RETURN arg_expression ';' '}' {set_valid();} mainfunction 
    | mainfunction 
    ;

mainfunction
	: INT MAIN {set_f_name(); STMT_DECLARE_FUNC(1); set_mainflag();} '(' ')' '{' statementlist RETURN arg_expression ';' '}' {set_valid(0);}
	| VOID MAIN {set_f_name(); STMT_DECLARE_FUNC(0); set_mainflag();} '(' ')' '{' statementlist RETURN ';' '}' {set_valid(0);}
	; 

statementlist
    : statement
    | statement statementlist
    ;

statement
	: expressionstatement ';'
    | forstatement 
    | conditionalstatement 
	| compoundstatement 
	| declerationstatement
	| jumpstatement 
	| functioncallstatement
	| assignmentstatement
	| ';'
	;

assignmentstatement
    : IDENTIFIER {check();} ASSIGN_OP float_expression 
    | arrayindex ASSIGN_OP float_expression 
    ;

declerationstub
	: IDENTIFIER {STMT_DECLARE_ID();set_data_type();}
	| IDENTIFIER {dim_arr=1; set_arr(); STMT_DECLARE_ID();set_data_type(); dim_arr=0;} '[' arg_expression ']' //create another func
	| IDENTIFIER {STMT_DECLARE_ID();set_data_type();} ASSIGN_OP float_expression 
	;
        
c_declerationstub
	: IDENTIFIER {STMT_DECLARE_ID();set_data_type();}
	| IDENTIFIER {dim_arr=1; set_arr(); STMT_DECLARE_ID();set_data_type(); dim_arr=0;} '[' arg_expression ']' //create another func
	| IDENTIFIER {STMT_DECLARE_ID();set_data_type();} ASSIGN_OP CHARACTER 
	| IDENTIFIER {dim_arr=1; set_arr(); STMT_DECLARE_ID();set_data_type(); dim_arr=0;} '[' arg_expression ']' ASSIGN_OP STRINGLITERAL 
	;

declerationstatement
	: INT {setType();} declerationstub declerationlist ';'
	| FLOAT {setType();} declerationstub declerationlist ';'
	| CHAR {setType();} c_declerationstub c_declerationlist ';'
	;

declerationlist
	: ',' declerationstub declerationlist
	|
	;

c_declerationlist
	:',' c_declerationstub c_declerationlist
	|
	;

compoundstatement
	: '{' '}'
	| '{' statementlist '}'
	;

conditionalstatement
    : IF '(' float_expression ')' statement ELSESTMT 
	;
	
ELSESTMT
    : ELSE statement 
	;

functioncallstatement
    : IDENTIFIER {check_func();} '(' ')' ';' {check_f_arg(0);}
    | IDENTIFIER {check_func();} '(' arg_expression ')' ';' {check_f_arg(1);}
    ;

jumpstatement
    : BREAK ';' 
    | CONTINUE ';' 
    ;

forstatement
	: FOR '(' optionalassignstatement ';' optionaltestexpressionstatement ';' optionalassignstatement ')' statement 
	;
 
optionaltestexpressionstatement
    : {strcpy(st[++top],"true");}
    | float_expression
	| float_expression ',' float_expression
	;

optionalassignstatement
    :
    | optional_assign_expression 
    | optional_assign_expression ',' optionalassignstatement
    ;
    
optional_assign_expression
    :
    | IDENTIFIER {check(); } ASSIGN_OP float_expression 
	| arrayindex ASSIGN_OP float_expression 
	;

expressionstatement
	: float_expression                         
	| float_expression ',' expressionstatement
	;  

arg_expression
    : INTEGER 
    | IDENTIFIER {check();}
    | arg_expr
    ;

arg_expr
    : IDENTIFIER {check();}
    | INTEGER 
    | functioncallstatement                                  
    | '(' arg_expr ')'                               	
	| arg_expr ADD_OP arg_expr 
	| arg_expr SUB_OP arg_expr 
	| arg_expr MUL_OP arg_expr 
	| arg_expr DIV_OP arg_expr 
	;

float_expression
    : DOUBLE                                     
    | expression  
    | functioncallstatement                                  
    | '(' float_expression ')'                                  	
	| float_expression ADD_OP float_expression 
	| float_expression SUB_OP float_expression 
	| float_expression MUL_OP float_expression 
	| float_expression DIV_OP float_expression 
	| float_expression G_OP float_expression 
	| float_expression L_OP float_expression 
	| float_expression GE_OP float_expression 
	| float_expression LE_OP float_expression 
	| float_expression EE_OP float_expression 
	| float_expression NE_OP float_expression 
	| NOT_OP float_expression 
    ;
   
expression
	: INTEGER                                         
	| IDENTIFIER {check();}                                  
    | arrayindex 
	;

arrayindex
	: IDENTIFIER  {check_arr(); } '[' arg_expression ']' //create another func
	;

%%

void yyerror(char *s) {
    error_flag = 1;
    fprintf(stderr, "ERROR:%s %s \n", s, yytext);
}

//symboltable
int search_symbol(struct entry** head, char* token_name,char *scope)
{
    int flag=0;
    struct entry* temp = *head;
    while(temp!=NULL)
    {
        if((strcmp(temp->token_name,token_name)==0) && (strcmp(temp->scope,scope)==0) &&(temp->valid == 1))
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }
    return flag;
}

struct entry* insert_node(struct entry** head,int ntoken, char* yytext,int scope,char *type) {
    node = (struct entry*)malloc(sizeof(struct entry));
    node->token_type = ntoken;
    node->scope = malloc(8);
	node->dimension = dim_arr;	//accepts the default dim ifnon array, else the one that is sent.
    if(scope==-1)
        node->scope="NA";
     else if(scope==0)
        node->scope="global";
     else {
        sprintf(node->scope,"local%d",scope);
    }
    node->data_type=malloc(5);
    strcpy(node->data_type,type);
    node->token_name = malloc(strlen(yytext)+1);
    strcpy(node->token_name, yytext);
    node->valid = 1;
    node->next = NULL;
    yytext = NULL;
    int flag = search_symbol(head, node->token_name,node->scope);
    if(!(flag)) {
        if (*head == NULL) {
            *head = node;
            return *head;
        }
        else {
            struct entry * temp = *head;
            while(temp->next != NULL) {
                temp = temp -> next;
            }
            temp->next = node;
            return *head;
        }
        
    }
    else {
        return *head;
    }
}
void display_table(struct entry* head)
{
    FILE *fptr;
    fptr = fopen("symbol_table.txt","w");
    if(fptr == NULL)
     {
      printf("ERROR could not open file!");
      exit(1);
     }
    fprintf(fptr,"\nSYMBOL TABLE:\n_______________________________________\n\n|TOKEN TYPE |TOKEN NAME |DATA TYPE |SCOPE|DIMENSION\n_______________________________________\n");
    struct entry* temp = head;
    while(temp!=NULL)	
    {
        switch(temp->token_type) {
            
            case IDENTIFIER: fprintf(fptr,"%s\t\t%s\t\t\t%s\t\t%s\t\t%d\n","IDENTIFIER",temp->token_name,temp->data_type,temp->scope,temp->dimension);
                             break;
            case ARRAY: fprintf(fptr,"%s\t\t\t%s\t\t\t%s\t\t%s\t\t%d\n","ARRAY",temp->token_name,temp->data_type,temp->scope,temp->dimension);
                             break;

            case MAIN:
            case FUNCTION: fprintf(fptr,"%s\t\t%s\t\t%s\t\t%s\t\t%d\n","FUNCTION",temp->token_name,temp->data_type,temp->scope,temp->dimension);
                       break;
          
        }   
        
        temp=temp->next;
    }
        fclose(fptr);

}

//Semantic analyser
void set_valid()
{
    struct entry* temp = head;
    while(temp != NULL)
    {
        if(temp->valid == 1)
        {
            temp->valid = 0;
        }
        temp=temp->next;
    }
}
void set_f_name() {
    f_name = malloc(sizeof(text)+1);
    strcpy(f_name,text);
}

void check_f_arg(int arg) {
    if(f_arg != arg) {
        printf("ERROR: Number of parameters mismatch for function %s \n",f_name);
        error_flag = 1;
        exit(1);
    }
}

void set_data_type() 
{
    struct entry *temp = head;
    while(temp!=NULL)
    {
        if(strcmp(text,temp->token_name)==0)
        {
            strcpy(temp->data_type,type);
        }
        temp=temp->next;
    }
}

void check_arr()
{
    int flag=0;
    struct entry* temp = head;
    while(temp!=NULL)
    {
        if(strcmp(temp->token_name,text)==0 && temp->token_type==ARRAY && temp->valid == 1)
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==0) {
         printf("ERROR! array %s not declared\n", text);
         error_flag = 1;
         exit(1);
    } 
}

void check_func()
{
    int flag=0;
    struct entry* temp = head;
    while(temp!=NULL)
    {
        if(strcmp(temp->token_name,text)==0 && temp->token_type==FUNCTION)
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==0) {
         printf("ERROR! function %s not declared\n", yytext);
         error_flag = 1;
         exit(1);
    }
}

void check()
{
    int flag=0;
    struct entry* temp = head;
    while(temp!=NULL)
    {
        char *tscope;
        tscope = (char *)malloc(8);
        if(scope == -1)
            tscope="NA";
        else if(scope == 0)
            tscope="global";
        else {
            sprintf(tscope,"local%d",scope);
        }
        if((strcmp(temp->token_name,text)==0) && (strcmp(temp->scope,tscope)<=0) && (temp->valid == 1))
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==0) {
         printf("ERROR! variable %s not declared\n", text);
         error_flag = 1;
         exit(1);
    }
}

void set_mainflag()
{
    if(main_flag==0)
        main_flag=1;
    else
    {
        printf("ERROR: Two main functions not allowed\n");
        error_flag = 1;
        exit(1);
    }    
}

void setType()
{
	strcpy(type,yytext);
}

void set_arr()
{

    array = 1;
}

void STMT_DECLARE_ID()
{
    int flag=0;
    struct entry* temp = head;
    while(temp!=NULL)
    {
        char *tscope;
        tscope = (char *)malloc(8);
        if(scope==-1)
            tscope="NA";
        else if(scope==0)
            tscope="global";
        else {
            sprintf(tscope,"local%d",scope);
        }
        if((strcmp(temp->token_name,text)==0) && (strcmp(temp->scope,tscope) == 0) && (temp->valid == 1))
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==1) {
         printf("ERROR! variable %s redeclared\n",text);
         printf("present : %d old : %s\n",scope,temp->scope);
         error_flag = 1;
         exit(1);
    }
    if(array)
    {
        head = insert_node(&head,ARRAY,text,scope,type);// last parameter is the dimensions
    }
    else
        head = insert_node(&head,IDENTIFIER,text,scope,type);
    array = 0;
}

void STMT_DECLARE_FUNC(int type)
{
    int flag=0;
    struct entry* temp = head;
    while(temp!=NULL)
    {
        if(strcmp(temp->token_name,text)==0)
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==1) {
         printf("ERROR! function %s redeclared\n",text);
         exit(1);;
    }
    if(type)
        head = insert_node(&head,FUNCTION,text,0,"int");
    else
        head = insert_node(&head,FUNCTION,text,0,"void");
}

int main(int argc,char** argv)
{           
if (argc > 1)
{
    FILE *file;
    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Could not open %s\n", argv[1]);
        exit(1);
    }
    yyin = file;
}
yyparse();

if(error_flag == 0) {
    printf("FILE HAS NO SYNTAX ERRORS\n");
}

display_table(head);
return 0;
}
