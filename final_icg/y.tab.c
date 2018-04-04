/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
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
                int valid;
                struct entry *next;
             }*node;

    struct entry* head = NULL;
    FILE *f1;
    
	int return_num=6;

    int error_flag = 0;
    int f_arg = 0;	
    char* f_name;
	char* f_ret_type;
    extern char* text;
    /*extern char* ret_type_val;*/
    extern int numtext;
/*    int main_flag=0;*/
    int array = 0;
    char st[1000][10];
    int top=0;
    int i=0;
    char temp[2]="t";
/*    int return_flag=0;*/
    
    int label[200];
    int iflabel[200];
    int iftop=0;
    int ifnum = 0;
    int lnum=0;
    int ltop=0;
    char type[10];
#line 47 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
  int   int_val;
  char*	op_val;
  float real_val;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 78 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INTEGER 257
#define DOUBLE 258
#define CHARACTER 259
#define IDENTIFIER 260
#define STRINGLITERAL 261
#define FLOAT 262
#define CHAR 263
#define FUNCTION 264
#define ARRAY 265
#define RETURN 266
#define VOID 267
#define INT 268
#define IF 269
#define FOR 270
#define ELSE 271
#define BREAK 272
#define CONTINUE 273
#define ADD_OP 274
#define SUB_OP 275
#define MUL_OP 276
#define DIV_OP 277
#define GE_OP 278
#define EE_OP 279
#define NE_OP 280
#define LE_OP 281
#define L_OP 282
#define G_OP 283
#define NOT_OP 284
#define ASSIGN_OP 285
#define then 286
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    7,    8,    9,    2,   10,   11,    2,
    2,    3,    3,    3,    3,    3,    4,    4,    4,    4,
   12,   14,   14,   15,   15,   17,   16,   16,   13,   13,
    5,    5,   18,   18,   18,   18,   18,   18,   18,   18,
   18,   27,   29,   26,   31,   26,   32,   33,   32,   34,
   35,   32,   36,   37,   36,   38,   39,   36,   40,   41,
   36,   42,   23,   44,   23,   45,   23,   43,   43,   46,
   46,   22,   22,   47,   21,   49,   48,   48,   50,   25,
   51,   25,   52,   25,   24,   24,   55,   56,   57,   58,
   20,   54,   54,   54,   53,   53,   53,   59,   60,   61,
   59,   62,   59,   19,   19,    6,    6,    6,   63,   63,
   63,   63,   64,   63,   65,   63,   66,   63,   67,   63,
   28,   28,   28,   28,   69,   28,   70,   28,   71,   28,
   72,   28,   73,   28,   74,   28,   75,   28,   76,   28,
   77,   28,   78,   28,   79,   28,   68,   68,   68,   80,
   30,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    0,    0,    0,   11,    0,    0,    7,
    4,    1,    1,    1,    1,    1,    1,    4,    4,    3,
    1,    1,    3,    2,    1,    1,    1,    2,    1,    3,
    1,    2,    2,    1,    1,    1,    1,    1,    1,    1,
    1,    0,    0,    5,    0,    4,    1,    0,    5,    0,
    0,    5,    1,    0,    5,    0,    0,    5,    0,    0,
    8,    0,    5,    0,    5,    0,    5,    3,    0,    3,
    0,    2,    3,    0,    7,    0,    3,    0,    0,    5,
    0,    6,    0,    8,    2,    2,    0,    0,    0,    0,
   13,    0,    1,    3,    0,    1,    3,    0,    0,    0,
    5,    0,    4,    1,    3,    1,    1,    1,    1,    1,
    1,    3,    0,    4,    0,    4,    0,    4,    0,    4,
    1,    1,    1,    3,    0,    4,    0,    4,    0,    4,
    0,    4,    0,    4,    0,    4,    0,    4,    0,    4,
    0,    4,    0,    4,    0,    3,    1,    1,    1,    0,
    5,
};
static const YYINT yydefred[] = {                         0,
   16,   17,   15,   13,   12,   14,    0,    1,    3,    0,
    0,    2,    0,    0,    0,    0,  147,  121,    0,   64,
   66,   62,    0,    0,    0,    0,  145,    0,   41,    0,
    0,    0,    0,   34,   35,   36,   37,   38,    0,   40,
    0,    0,  122,   29,   20,    0,    0,    0,    0,   22,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   85,   86,    0,   72,    0,    0,  123,    0,
  149,   11,   32,   33,  125,  127,  129,  131,  137,  141,
  143,  139,  135,  133,    0,   45,   28,   18,   19,    0,
    0,   26,   24,    4,    9,   43,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  146,   73,  124,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  105,    0,   30,   23,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  111,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   74,
    0,  102,   87,    0,  126,  128,  130,  132,  138,  142,
  144,  140,  136,  134,    0,    5,   10,    0,   80,    0,
    0,  110,    0,    0,  151,  113,  115,  117,  119,    0,
   51,    0,   65,    0,   57,    0,    0,   67,   63,    0,
  100,    0,    0,   97,    0,   82,    0,  112,    0,    0,
    0,    0,    0,    0,   68,    0,    0,    0,   70,    0,
    0,    0,    0,    0,    6,    0,  114,  116,  118,  120,
   49,    0,   55,   58,    0,   76,   75,    0,    0,   88,
    0,   84,   60,    0,    0,    0,    7,    0,   77,   89,
   61,    0,   90,    0,   91,
};
static const YYINT yydgoto[] = {                          7,
    8,    9,   46,   11,   31,  137,  128,  195,  231,   95,
  129,   47,   48,   49,   50,   51,   93,   32,   33,   34,
   35,   36,   37,   38,   69,   40,   53,   41,  130,   71,
  125,  102,  140,  141,  204,  104,  144,  145,  207,  146,
  238,   60,  143,   58,   59,  148,  190,  227,  234,   54,
   55,   56,  109,  214,  193,  236,  242,  244,  110,  151,
  211,  192,  139,  199,  200,  201,  202,   43,  114,  115,
  116,  117,  123,  122,  118,  121,  119,  120,   65,   57,
};
static const YYINT yysindex[] = {                      -157,
    0,    0,    0,    0,    0,    0, -157,    0,    0, -243,
  -31,    0,  -29,  121,  235,  121,    0,    0,    0,    0,
    0,    0,    5,    7,  -25,    3,    0,   96,    0,  -34,
  -60,  121,   11,    0,    0,    0,    0,    0,    0,    0,
  162, -214,    0,    0,    0, -180,   31,   -5,   40,    0,
 -185, -175, -204,   46,   49,   53,   16, -151, -147, -151,
  -34, -145,    0,    0,  -34,    0,   -8,    0,    0,  132,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -34,    0,    0,    0,    0, -144,
 -180,    0,    0,    0,    0,    0,   67, -142, -128,  -35,
    0,   76,    0,   89,   76,  142,    0, -150,   75,   95,
    0,    0,    0,  -34,  -34,  -34,  -34,  -34,  -34,  -34,
  -34,  -34,  -34,    0,  -34,    0,    0,  -35,   20,  -34,
   82,  103,  102,    0,    0,  -30,   54,    0, -177,   57,
 -136, -151,   91,   60, -132,   63, -147,   98,   99,    0,
 -126,    0,    0, -145,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -152,    0,    0, -152,    0,  101,
  -96,    0,    0,  111,    0,    0,    0,    0,    0,  -35,
    0,   76,    0,  -35,    0,  -35,   89,    0,    0,  121,
    0,  -34,  -34,    0,  106,    0,  125,    0,  -30,  -30,
  -30,  -30,   74,  -34,    0,   78,  -85,   83,    0, -102,
  -34, -152,  172,  113,    0,  116,    0,    0,    0,    0,
    0, -152,    0,    0, -108,    0,    0, -152,  -34,    0,
   59,    0,    0,  121, -152, -145,    0,  -83,    0,    0,
    0,  138,    0,  121,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -40,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -123,    0,    0,    0,    0,    0,    0,   17,    0,
  123,  152,    0,    0,    0,  -28,    0,    0,  147,    0,
   14,   64,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -13,    0,    0,    0,    0,    0,  -11,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -37,  133,  -32,  134,  133,    0,  -90,    0,    0,  -17,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  127,   97,    0,    0,    0,  -44,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -18,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   45,    0,    0,   62,    0,    0,
    0,    0,  122,    0,    0,    0,    0,    0,    0,    0,
    0,  133,    0,    0,    0,    0,  134,    0,    0,    0,
    0,    0,  135,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   79,
    0,  -16,  139,    0,    0,    0,    0,    0,    0,    0,
    0,   -6,    0,    0,    0,    0,    0,   -9,    0,    0,
    0,    0,    0,    0,  140,   19,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  184,    0,   37,  187,   24, -107,    0,    0,    0,    0,
    0,    0,    0,    0,  109,  155,    0, -170,  118,    0,
    0,    0,    0,    0,  442,    0,    0,  446,    0,  443,
    0,  -52,    0,    0,    0,   58,    0,    0,    0,    0,
    0,    0,  -87,    0,    0,   21,    0,    0,    0,    0,
    0,    0, -140,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -133,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 687
static const YYINT yytable[] = {                         79,
  150,   31,  174,  148,  136,   30,   47,  105,   15,  136,
   15,   53,   27,  194,  108,   27,    2,  149,  148,  210,
  166,   47,   95,   96,  103,   98,   53,  103,   79,  148,
   98,  101,  148,   63,  101,   89,   10,   52,   90,   52,
   95,   96,  103,   10,   61,   95,   62,  148,  108,  101,
  150,   67,   52,   48,   25,   73,   39,   25,   54,   95,
  123,   64,   98,  239,   72,  217,  218,  219,  220,   74,
   86,   88,  203,  245,   92,   39,  206,    1,  208,  150,
   96,    3,    4,   91,   46,   97,    5,    6,   98,  182,
   94,   14,   99,   16,  205,  240,  176,  177,  178,  179,
    1,   44,    2,   46,    3,    4,  100,  131,  101,    5,
    6,  148,  103,  148,  107,  126,  112,  132,   78,  142,
   44,   75,   76,   77,   78,   79,   80,   81,   82,   83,
   84,  133,  147,  153,  152,   30,   79,   78,  154,   39,
  169,   39,   31,  170,  167,  171,  175,  180,  181,  183,
  184,  198,  185,  186,   29,  107,  188,  189,  191,  196,
   30,   79,  109,  197,  215,  216,  221,   46,  226,   46,
  223,  230,  113,  224,  232,  225,  233,  241,  243,   29,
  109,  104,  150,  237,   44,  106,   44,   21,    8,  107,
   12,   69,   71,   92,   99,  149,   13,   93,   94,  127,
   87,   78,  124,   78,  187,   85,    0,  209,    0,    0,
  149,    0,    0,    0,  109,  229,    0,    0,   28,  106,
   66,  134,   17,   18,  135,   68,  172,    0,    0,  173,
    0,   27,    0,  148,  148,  148,  148,  148,  148,  148,
  148,  148,  148,   28,   42,  148,  148,   50,  148,   27,
  148,  148,   56,    0,  148,    0,  148,  148,  148,  148,
  148,  148,  148,  148,  148,  148,  148,  148,  148,  148,
  148,  148,  148,   39,   39,   45,   39,    0,   39,   39,
    0,    0,   39,    0,   39,   39,   39,   39,   39,   39,
  123,  123,  123,  123,  123,  123,  123,  123,  123,  123,
   39,   46,   46,    0,   46,    0,   46,   46,    0,    0,
   46,    0,   46,   46,   46,   46,   46,   46,   44,   44,
    0,   44,    0,   44,   44,    0,    0,   44,   46,   44,
   44,   44,   44,   44,   44,   78,   78,    0,   78,    0,
   78,   78,    0,    0,   78,   44,   78,   78,   78,    0,
   78,   78,   17,   18,    0,   19,    0,   20,   21,    0,
    0,    0,   78,   22,   23,   24,    0,   25,   26,    0,
  109,  109,  109,  109,    0,    0,    0,   17,   18,   27,
   19,    0,   20,   21,  176,  177,  178,  179,   22,   23,
   24,    0,   25,   26,    0,  109,  109,  109,  109,    0,
  110,  110,  110,  110,   27,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,  149,  149,  149,  149,  149,
  149,  149,  149,  149,  149,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,   39,   42,   39,   42,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   39,
   42,    0,    0,   39,   42,   70,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    1,    0,   44,    0,    3,    4,    0,    0,
    0,    5,    6,    0,  108,    0,  106,    0,    0,    0,
  111,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  138,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  155,
  156,  157,  158,  159,  160,  161,  162,  163,  164,  138,
  165,    0,    0,    0,    0,  168,    0,  138,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  108,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  138,    0,    0,    0,  138,    0,  138,    0,    0,
    0,   39,   42,    0,    0,    0,    0,  212,  213,    0,
  138,  138,  138,  138,    0,    0,    0,    0,    0,  222,
    0,    0,    0,    0,    0,    0,  228,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  235,   39,   42,    0,  108,    0,
    0,    0,    0,    0,    0,   39,   42,
};
static const YYINT yycheck[] = {                         40,
   91,  125,  136,   44,   40,   40,   44,   60,   40,   40,
   40,   44,   41,  154,   59,   44,  260,  105,   59,  190,
  128,   59,   41,   41,   41,   44,   59,   44,   40,   41,
   44,   41,   44,   59,   44,   41,    0,   44,   44,   16,
   59,   59,   59,    7,   40,   59,   40,   59,   93,   59,
   91,   28,   59,   91,   41,   32,   40,   44,   91,   41,
   44,   59,   44,  234,  125,  199,  200,  201,  202,   59,
  285,   41,  180,  244,  260,   59,  184,  258,  186,   91,
  285,  262,  263,   44,   40,   40,  267,  268,   40,  142,
  266,  123,   40,  123,  182,  236,  274,  275,  276,  277,
  258,   40,  260,   59,  262,  263,   91,   41,  260,  267,
  268,  123,  260,  125,  260,  260,  125,  260,   40,   44,
   59,  274,  275,  276,  277,  278,  279,  280,  281,  282,
  283,  260,   44,   59,  285,   40,   40,   59,   44,  123,
   59,  125,  266,   41,  125,   44,   93,   91,  285,   59,
   91,   41,  285,   91,   59,   59,   59,   59,  285,   59,
   40,   40,   41,  260,   59,   41,   93,  123,  271,  125,
   93,   59,   41,  259,   59,   93,  285,  261,   41,   59,
   59,   59,   41,  125,  123,   59,  125,   41,  125,   93,
    7,   59,   59,   59,  285,   44,   10,   59,   59,   91,
   46,  123,   85,  125,  147,   44,   -1,  187,   -1,   -1,
   59,   -1,   -1,   -1,   93,   44,   -1,   -1,  123,   93,
  125,  257,  257,  258,  260,  260,  257,   -1,   -1,  260,
   -1,  260,   -1,  274,  275,  276,  277,  278,  279,  280,
  281,  282,  283,  123,  285,  257,  258,  285,  260,  284,
  262,  263,  285,   -1,  266,   -1,  268,  269,  270,  271,
  272,  273,  274,  275,  276,  277,  278,  279,  280,  281,
  282,  283,  284,  257,  258,   41,  260,   -1,  262,  263,
   -1,   -1,  266,   -1,  268,  269,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,  281,  282,  283,
  284,  257,  258,   -1,  260,   -1,  262,  263,   -1,   -1,
  266,   -1,  268,  269,  270,  271,  272,  273,  257,  258,
   -1,  260,   -1,  262,  263,   -1,   -1,  266,  284,  268,
  269,  270,  271,  272,  273,  257,  258,   -1,  260,   -1,
  262,  263,   -1,   -1,  266,  284,  268,  269,  270,   -1,
  272,  273,  257,  258,   -1,  260,   -1,  262,  263,   -1,
   -1,   -1,  284,  268,  269,  270,   -1,  272,  273,   -1,
  274,  275,  276,  277,   -1,   -1,   -1,  257,  258,  284,
  260,   -1,  262,  263,  274,  275,  276,  277,  268,  269,
  270,   -1,  272,  273,   -1,  274,  275,  276,  277,   -1,
  274,  275,  276,  277,  284,  274,  275,  276,  277,  278,
  279,  280,  281,  282,  283,  274,  275,  276,  277,  278,
  279,  280,  281,  282,  283,  274,  275,  276,  277,  278,
  279,  280,  281,  282,  283,  274,  275,  276,  277,  278,
  279,  280,  281,  282,  283,  274,  275,  276,  277,  278,
  279,  280,  281,  282,  283,   14,   14,   16,   16,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   28,
   28,   -1,   -1,   32,   32,   30,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  258,   -1,  260,   -1,  262,  263,   -1,   -1,
   -1,  267,  268,   -1,   62,   -1,   61,   -1,   -1,   -1,
   65,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  100,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  114,
  115,  116,  117,  118,  119,  120,  121,  122,  123,  128,
  125,   -1,   -1,   -1,   -1,  130,   -1,  136,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  154,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  180,   -1,   -1,   -1,  184,   -1,  186,   -1,   -1,
   -1,  190,  190,   -1,   -1,   -1,   -1,  192,  193,   -1,
  199,  200,  201,  202,   -1,   -1,   -1,   -1,   -1,  204,
   -1,   -1,   -1,   -1,   -1,   -1,  211,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  229,  234,  234,   -1,  236,   -1,
   -1,   -1,   -1,   -1,   -1,  244,  244,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 286
#define YYUNDFTOKEN 369
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"INTEGER","DOUBLE","CHARACTER","IDENTIFIER","STRINGLITERAL","FLOAT","CHAR",
"FUNCTION","ARRAY","RETURN","VOID","INT","IF","FOR","ELSE","BREAK","CONTINUE",
"ADD_OP","SUB_OP","MUL_OP","DIV_OP","GE_OP","EE_OP","NE_OP","LE_OP","L_OP",
"G_OP","NOT_OP","ASSIGN_OP","\"then\"",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : translation_unit",
"translation_unit : external_declaration",
"translation_unit : translation_unit external_declaration",
"external_declaration : function_definition",
"$$1 :",
"$$2 :",
"$$3 :",
"function_definition : type_specifier declarator '{' statementlist RETURN $$1 arg_expression $$2 ';' $$3 '}'",
"$$4 :",
"$$5 :",
"function_definition : type_specifier declarator '{' statementlist $$4 $$5 '}'",
"function_definition : declarator '{' statementlist '}'",
"type_specifier : VOID",
"type_specifier : CHAR",
"type_specifier : INT",
"type_specifier : FLOAT",
"type_specifier : DOUBLE",
"declarator : IDENTIFIER",
"declarator : declarator '(' parameter_type_list ')'",
"declarator : declarator '(' identifier_list ')'",
"declarator : declarator '(' ')'",
"parameter_type_list : parameter_list",
"parameter_list : parameter_declaration",
"parameter_list : parameter_list ',' parameter_declaration",
"parameter_declaration : declaration_specifiers declarator_para",
"parameter_declaration : declaration_specifiers",
"declarator_para : IDENTIFIER",
"declaration_specifiers : type_specifier",
"declaration_specifiers : type_specifier declaration_specifiers",
"identifier_list : IDENTIFIER",
"identifier_list : identifier_list ',' IDENTIFIER",
"statementlist : statement",
"statementlist : statement statementlist",
"statement : expressionstatement ';'",
"statement : forstatement",
"statement : conditionalstatement",
"statement : compoundstatement",
"statement : declerationstatement",
"statement : jumpstatement",
"statement : functioncallstatement",
"statement : assignmentstatement",
"statement : ';'",
"$$6 :",
"$$7 :",
"assignmentstatement : IDENTIFIER $$6 ASSIGN_OP $$7 float_expression",
"$$8 :",
"assignmentstatement : arrayindex ASSIGN_OP $$8 float_expression",
"declerationstub : IDENTIFIER",
"$$9 :",
"declerationstub : IDENTIFIER $$9 '[' arg_expression ']'",
"$$10 :",
"$$11 :",
"declerationstub : IDENTIFIER $$10 ASSIGN_OP $$11 float_expression",
"c_declerationstub : IDENTIFIER",
"$$12 :",
"c_declerationstub : IDENTIFIER $$12 '[' arg_expression ']'",
"$$13 :",
"$$14 :",
"c_declerationstub : IDENTIFIER $$13 ASSIGN_OP $$14 CHARACTER",
"$$15 :",
"$$16 :",
"c_declerationstub : IDENTIFIER $$15 '[' arg_expression ']' ASSIGN_OP $$16 STRINGLITERAL",
"$$17 :",
"declerationstatement : INT $$17 declerationstub declerationlist ';'",
"$$18 :",
"declerationstatement : FLOAT $$18 declerationstub declerationlist ';'",
"$$19 :",
"declerationstatement : CHAR $$19 c_declerationstub c_declerationlist ';'",
"declerationlist : ',' declerationstub declerationlist",
"declerationlist :",
"c_declerationlist : ',' c_declerationstub c_declerationlist",
"c_declerationlist :",
"compoundstatement : '{' '}'",
"compoundstatement : '{' statementlist '}'",
"$$20 :",
"conditionalstatement : IF '(' float_expression ')' $$20 statement ELSESTMT",
"$$21 :",
"ELSESTMT : ELSE $$21 statement",
"ELSESTMT :",
"$$22 :",
"functioncallstatement : IDENTIFIER $$22 '(' ')' ';'",
"$$23 :",
"functioncallstatement : IDENTIFIER $$23 '(' IDENTIFIER ')' ';'",
"$$24 :",
"functioncallstatement : IDENTIFIER $$24 '(' IDENTIFIER ',' IDENTIFIER ')' ';'",
"jumpstatement : BREAK ';'",
"jumpstatement : CONTINUE ';'",
"$$25 :",
"$$26 :",
"$$27 :",
"$$28 :",
"forstatement : FOR '(' optionalassignstatement ';' $$25 optionaltestexpressionstatement ';' $$26 optionalassignstatement $$27 ')' $$28 statement",
"optionaltestexpressionstatement :",
"optionaltestexpressionstatement : float_expression",
"optionaltestexpressionstatement : float_expression ',' float_expression",
"optionalassignstatement :",
"optionalassignstatement : optional_assign_expression",
"optionalassignstatement : optional_assign_expression ',' optionalassignstatement",
"optional_assign_expression :",
"$$29 :",
"$$30 :",
"optional_assign_expression : IDENTIFIER $$29 ASSIGN_OP $$30 float_expression",
"$$31 :",
"optional_assign_expression : arrayindex ASSIGN_OP $$31 float_expression",
"expressionstatement : float_expression",
"expressionstatement : float_expression ',' expressionstatement",
"arg_expression : INTEGER",
"arg_expression : IDENTIFIER",
"arg_expression : arg_expr",
"arg_expr : IDENTIFIER",
"arg_expr : INTEGER",
"arg_expr : functioncallstatement",
"arg_expr : '(' arg_expr ')'",
"$$32 :",
"arg_expr : arg_expr ADD_OP $$32 arg_expr",
"$$33 :",
"arg_expr : arg_expr SUB_OP $$33 arg_expr",
"$$34 :",
"arg_expr : arg_expr MUL_OP $$34 arg_expr",
"$$35 :",
"arg_expr : arg_expr DIV_OP $$35 arg_expr",
"float_expression : DOUBLE",
"float_expression : expression",
"float_expression : functioncallstatement",
"float_expression : '(' float_expression ')'",
"$$36 :",
"float_expression : float_expression ADD_OP $$36 float_expression",
"$$37 :",
"float_expression : float_expression SUB_OP $$37 float_expression",
"$$38 :",
"float_expression : float_expression MUL_OP $$38 float_expression",
"$$39 :",
"float_expression : float_expression DIV_OP $$39 float_expression",
"$$40 :",
"float_expression : float_expression G_OP $$40 float_expression",
"$$41 :",
"float_expression : float_expression L_OP $$41 float_expression",
"$$42 :",
"float_expression : float_expression GE_OP $$42 float_expression",
"$$43 :",
"float_expression : float_expression LE_OP $$43 float_expression",
"$$44 :",
"float_expression : float_expression EE_OP $$44 float_expression",
"$$45 :",
"float_expression : float_expression NE_OP $$45 float_expression",
"$$46 :",
"float_expression : NOT_OP $$46 float_expression",
"expression : INTEGER",
"expression : IDENTIFIER",
"expression : arrayindex",
"$$47 :",
"arrayindex : IDENTIFIER $$47 '[' arg_expression ']'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 284 "parser.y"

void yyerror(char *s) {
    error_flag = 1;
    fprintf(stderr, "%s %s \n", s, yytext);
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
    fprintf(fptr,"\nSYMBOL TABLE:\n_______________________________________\n\n|TOKEN TYPE |TOKEN NAME |DATA TYPE |SCOPE|\n_______________________________________\n");
    struct entry* temp = head;
    while(temp!=NULL)	
    {
        switch(temp->token_type) {
            
            case IDENTIFIER: fprintf(fptr,"%s\t\t%s\t\t\t%s\t\t%s\n","IDENTIFIER",temp->token_name,temp->data_type,temp->scope);
                             break;
            case ARRAY: fprintf(fptr,"%s\t\t\t%s\t\t\t%s\t\t%s\n","ARRAY",temp->token_name,temp->data_type,temp->scope);
                             break;
            case FUNCTION: fprintf(fptr,"%s\t\t%s\t\t%s\t\t%s\n","FUNCTION",temp->token_name,temp->data_type,temp->scope);
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
        printf("ERROR: Number of parameters mismatch for function %s : should be %d \n",f_name, f_arg);
        error_flag = 1;
        exit(1);
    }
}

void push()
{
  	strcpy(st[++top],yytext);
}

void push_text()
{
  	strcpy(st[++top],text);  
}

void codegen_logical()
{
 	sprintf(temp,"$t%d",i);
  	fprintf(f1,"\t%s\t=\t%s\t%s\t%s\n",temp,st[top-2],st[top-1],st[top]);
  	top-=2;
 	strcpy(st[top],temp);
 	i++;
}

void codegen_logicalnot()
{
 	sprintf(temp,"$t%d",i);
  	fprintf(f1,"\t%s\t=\t%s\t%s\n",temp,st[top-1],st[top]);
  	top-=1;
 	strcpy(st[top],temp);
 	i++;
}

void codegen_algebric()
{
 	sprintf(temp,"$t%d",i); // converts temp to read format
  	fprintf(f1,"\t%s\t=\t%s\t%s\t%s\n",temp,st[top-2],st[top-1],st[top]);
  	top-=2;
 	strcpy(st[top],temp);
 	i++;
}

void codegen_assign1()
{
 	fprintf(f1,"\t%s[%s]\t=\t%s\n",st[top-3],st[top-2],st[top]);
 	top-=4;
}

void codegen_assign()
{
 	fprintf(f1,"\t%s\t=\t%s\n",st[top-2],st[top]);
 	top-=3;
}
 
void if_label1()
{
 	ifnum++;
 	fprintf(f1,"\tif( not %s)",st[top]);
 	fprintf(f1,"\tgoto $I%d\n",ifnum);
 	iflabel[++iftop]=ifnum;
}

void if_label2()
{
	int x;
	ifnum++;
	x=iflabel[iftop--]; 
	fprintf(f1,"\t\tgoto $I%d\n",ifnum);
	fprintf(f1,"$I%d: \n",x); 
	iflabel[++iftop]=ifnum;
}

void if_label3()
{
    printf("iftop = %d\n",iftop);
	int y;
	y=iflabel[iftop--];
	fprintf(f1,"$I%d: \n",y);
}

void for_label1()
{
    lnum++;
 	label[++ltop]=lnum; //test_expr
 	label[++ltop]=++lnum; //update_expr
 	label[++ltop]=++lnum; // start_of_for_body
 	label[++ltop]=++lnum; //line_after_for
 	fprintf(f1,"$L%d : \n",label[ltop-3]);
 	
}

void for_label2()
{
    fprintf(f1,"\tif(not %s) goto $L%d\n",st[top],label[ltop]);
    fprintf(f1,"\telse goto $L%d\n",label[ltop-1]);
    fprintf(f1,"$L%d : \n",label[ltop-2]); 
}

void for_label3()
{
   fprintf(f1,"$L%d : \n",label[ltop-1]); 
}

void post_update()
{
    fprintf(f1,"\tgoto $L%d\n",label[ltop-3]);
}

void for_label4()
{
   fprintf(f1,"\tgoto $L%d\n",label[ltop-2]);
   fprintf(f1,"$L%d : \n",label[ltop]); 
   ltop-=4;
}

void stmt_break()
{
    int y;
	y=label[ltop];
	fprintf(f1,"\tgoto $L%d: \n",y);
}

void stmt_continue()
{ 
    int y;
	y=label[ltop-2];
	fprintf(f1,"\tgoto $L%d: \n",y);
}

void stmt_return(int args)
{
    if(args)
        fprintf(f1,"\treturn value = %s\n",text);
    fprintf(f1,"\tgoto $Lcontinue\n");
            
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

void endfunc()
{
    fprintf(f1,"EndFunc :\n");
}

void set_func_label()
{
    fprintf(f1,"$L%s :\n",text);
}

void goto_func_label()
{
    fprintf(f1,"\tFCall $L%s \n",text);
    fprintf(f1,"$Lcontinue :\n");
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

void check_func_type()
{
	if (strcmp(type,"VOID")==0)
	{
		printf("ERROR: func %s needs return statement! \n",f_name);
        error_flag = 1;
        exit(1);
	}
}

void check_func_type_void()
{
	if (strcmp(type,"VOID")!=0)
	{
		printf("ERROR: VOID func %s  has no return type! \n",f_name);
        error_flag = 1;
        exit(1);
	}
}

void isReturnType()
{
}

void storevar()
{ 
 	f_ret_type = malloc(sizeof(text)+1);
    strcpy(f_ret_type,text);
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
	printf("here\n");
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

/*void check_return_num()
{
    if(return_flag)
        fprintf(f1,"\treturn %d\n",numtext);
}
void check_return_id()
{
    if(return_flag)
        fprintf(f1,"\treturn %s\n",text);
}
void check_return_arg()
{
    if(return_flag)
    {
        fprintf(f1,"\treturn %s\n",st[top--]);
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
*/
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
        head = insert_node(&head,ARRAY,text,scope,type);
    }
    else
        head = insert_node(&head,IDENTIFIER,text,scope,type);
    array = 0;
}

void STMT_DECLARE_FUNC(int ret_type)
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
    if(ret_type==0)
        head = insert_node(&head,FUNCTION,text,0,"int");
    else if (ret_type==1)
        head = insert_node(&head,FUNCTION,text,0,"void");
	else if (ret_type==2)
        head = insert_node(&head,FUNCTION,text,0,"char");
	else if (ret_type==3)
        head = insert_node(&head,FUNCTION,text,0,"float");
	else if (ret_type==4)
        head = insert_node(&head,FUNCTION,text,0,"double");
	else
	{
		printf("ERROR: func %s needs proper return type! \n",f_name);
        error_flag = 1;
        exit(1);
	}
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
    f1=fopen("icg.txt","w");
    if (!f1)
    {
        fprintf(stderr, "Could not open semantic_analysis.txt\n");
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
#line 1155 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 4:
#line 74 "parser.y"
	{check_func_type();}
break;
case 5:
#line 74 "parser.y"
	{isReturnType();}
break;
case 6:
#line 74 "parser.y"
	{endfunc();}
break;
case 7:
#line 74 "parser.y"
	{set_valid();}
break;
case 8:
#line 75 "parser.y"
	{check_func_type_void();}
break;
case 9:
#line 75 "parser.y"
	{endfunc();}
break;
case 10:
#line 75 "parser.y"
	{set_valid();}
break;
case 11:
#line 76 "parser.y"
	{set_valid();}
break;
case 12:
#line 80 "parser.y"
	{setType();return_num=1;}
break;
case 13:
#line 81 "parser.y"
	{setType();return_num=2;}
break;
case 14:
#line 82 "parser.y"
	{setType();return_num=0;}
break;
case 15:
#line 83 "parser.y"
	{setType();return_num=3;}
break;
case 16:
#line 84 "parser.y"
	{setType();return_num=4;}
break;
case 17:
#line 88 "parser.y"
	{set_f_name(); STMT_DECLARE_FUNC(return_num); set_func_label();}
break;
case 26:
#line 109 "parser.y"
	{STMT_DECLARE_ID(); set_data_type();f_arg++;}
break;
case 29:
#line 118 "parser.y"
	{check();}
break;
case 42:
#line 153 "parser.y"
	{check(); push_text();}
break;
case 43:
#line 153 "parser.y"
	{push();}
break;
case 44:
#line 153 "parser.y"
	{codegen_assign();}
break;
case 45:
#line 154 "parser.y"
	{push();}
break;
case 46:
#line 154 "parser.y"
	{codegen_assign1();}
break;
case 47:
#line 158 "parser.y"
	{STMT_DECLARE_ID();set_data_type();}
break;
case 48:
#line 159 "parser.y"
	{set_arr(); STMT_DECLARE_ID();set_data_type();}
break;
case 50:
#line 160 "parser.y"
	{STMT_DECLARE_ID();push_text();set_data_type();}
break;
case 51:
#line 160 "parser.y"
	{push();}
break;
case 52:
#line 160 "parser.y"
	{codegen_assign();}
break;
case 53:
#line 164 "parser.y"
	{STMT_DECLARE_ID();set_data_type();}
break;
case 54:
#line 165 "parser.y"
	{set_arr(); STMT_DECLARE_ID();set_data_type();}
break;
case 56:
#line 166 "parser.y"
	{STMT_DECLARE_ID();push_text();set_data_type();}
break;
case 57:
#line 166 "parser.y"
	{push();}
break;
case 58:
#line 166 "parser.y"
	{codegen_assign();}
break;
case 59:
#line 167 "parser.y"
	{set_arr(); STMT_DECLARE_ID();push_text();set_data_type();}
break;
case 60:
#line 167 "parser.y"
	{push();}
break;
case 61:
#line 167 "parser.y"
	{codegen_assign();}
break;
case 62:
#line 171 "parser.y"
	{setType();}
break;
case 64:
#line 172 "parser.y"
	{setType();}
break;
case 66:
#line 173 "parser.y"
	{setType();}
break;
case 74:
#line 192 "parser.y"
	{if_label1();}
break;
case 76:
#line 196 "parser.y"
	{if_label2();}
break;
case 77:
#line 196 "parser.y"
	{if_label3();}
break;
case 78:
#line 197 "parser.y"
	{if_label3();}
break;
case 79:
#line 201 "parser.y"
	{check_func(); goto_func_label(); /*add_func_label();*/}
break;
case 80:
#line 201 "parser.y"
	{check_f_arg(0);}
break;
case 81:
#line 202 "parser.y"
	{check_func(); goto_func_label(); /*add_func_label();*/}
break;
case 82:
#line 202 "parser.y"
	{check_f_arg(1);}
break;
case 83:
#line 203 "parser.y"
	{check_func(); goto_func_label(); /*add_func_label();*/}
break;
case 84:
#line 203 "parser.y"
	{check_f_arg(2);}
break;
case 85:
#line 207 "parser.y"
	{stmt_break();}
break;
case 86:
#line 208 "parser.y"
	{stmt_continue();}
break;
case 87:
#line 212 "parser.y"
	{for_label1();}
break;
case 88:
#line 212 "parser.y"
	{for_label2();}
break;
case 89:
#line 212 "parser.y"
	{post_update();}
break;
case 90:
#line 212 "parser.y"
	{for_label3();}
break;
case 91:
#line 212 "parser.y"
	{for_label4();}
break;
case 92:
#line 216 "parser.y"
	{strcpy(st[++top],"true");}
break;
case 99:
#line 229 "parser.y"
	{check(); push_text();}
break;
case 100:
#line 229 "parser.y"
	{push();}
break;
case 101:
#line 229 "parser.y"
	{codegen_assign();}
break;
case 102:
#line 230 "parser.y"
	{push();}
break;
case 103:
#line 230 "parser.y"
	{codegen_assign1();}
break;
case 106:
#line 239 "parser.y"
	{push(); storevar();}
break;
case 107:
#line 240 "parser.y"
	{check(); push_text();}
break;
case 109:
#line 245 "parser.y"
	{check();push_text();}
break;
case 110:
#line 246 "parser.y"
	{ push();}
break;
case 113:
#line 249 "parser.y"
	{push();}
break;
case 114:
#line 249 "parser.y"
	{codegen_algebric();}
break;
case 115:
#line 250 "parser.y"
	{push();}
break;
case 116:
#line 250 "parser.y"
	{codegen_algebric();}
break;
case 117:
#line 251 "parser.y"
	{push();}
break;
case 118:
#line 251 "parser.y"
	{codegen_algebric();}
break;
case 119:
#line 252 "parser.y"
	{push();}
break;
case 120:
#line 252 "parser.y"
	{codegen_algebric();}
break;
case 121:
#line 256 "parser.y"
	{push();}
break;
case 125:
#line 260 "parser.y"
	{push();}
break;
case 126:
#line 260 "parser.y"
	{codegen_algebric();}
break;
case 127:
#line 261 "parser.y"
	{push();}
break;
case 128:
#line 261 "parser.y"
	{codegen_algebric();}
break;
case 129:
#line 262 "parser.y"
	{push();}
break;
case 130:
#line 262 "parser.y"
	{codegen_algebric();}
break;
case 131:
#line 263 "parser.y"
	{push();}
break;
case 132:
#line 263 "parser.y"
	{codegen_algebric();}
break;
case 133:
#line 264 "parser.y"
	{push();}
break;
case 134:
#line 264 "parser.y"
	{codegen_logical();}
break;
case 135:
#line 265 "parser.y"
	{push();}
break;
case 136:
#line 265 "parser.y"
	{codegen_logical();}
break;
case 137:
#line 266 "parser.y"
	{push();}
break;
case 138:
#line 266 "parser.y"
	{codegen_logical();}
break;
case 139:
#line 267 "parser.y"
	{push();}
break;
case 140:
#line 267 "parser.y"
	{codegen_logical();}
break;
case 141:
#line 268 "parser.y"
	{push();}
break;
case 142:
#line 268 "parser.y"
	{codegen_logical();}
break;
case 143:
#line 269 "parser.y"
	{push();}
break;
case 144:
#line 269 "parser.y"
	{codegen_logical();}
break;
case 145:
#line 270 "parser.y"
	{push();}
break;
case 146:
#line 270 "parser.y"
	{codegen_logicalnot();}
break;
case 147:
#line 274 "parser.y"
	{push();}
break;
case 148:
#line 275 "parser.y"
	{check(); push_text();}
break;
case 150:
#line 280 "parser.y"
	{check_arr(); push_text();}
break;
#line 1749 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
