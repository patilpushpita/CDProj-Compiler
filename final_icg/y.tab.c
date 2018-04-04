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
    0,    0,    1,    7,    8,    2,    9,    2,    2,    3,
    3,    3,    3,    3,    4,    4,    4,    4,   10,   12,
   12,   13,   13,   15,   14,   14,   11,   11,    5,    5,
   16,   16,   16,   16,   16,   16,   16,   16,   16,   25,
   27,   24,   29,   24,   30,   31,   30,   32,   33,   30,
   34,   35,   34,   36,   37,   34,   38,   39,   34,   40,
   21,   42,   21,   43,   21,   41,   41,   44,   44,   20,
   20,   45,   19,   47,   46,   46,   48,   23,   49,   23,
   50,   23,   22,   22,   53,   54,   55,   56,   18,   52,
   52,   52,   51,   51,   51,   57,   58,   59,   57,   60,
   57,   17,   17,    6,    6,    6,   61,   61,   61,   61,
   62,   61,   63,   61,   64,   61,   65,   61,   26,   26,
   26,   26,   67,   26,   68,   26,   69,   26,   70,   26,
   71,   26,   72,   26,   73,   26,   74,   26,   75,   26,
   76,   26,   77,   26,   66,   66,   66,   78,   28,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    0,    0,   10,    0,    6,    4,    1,
    1,    1,    1,    1,    1,    4,    4,    3,    1,    1,
    3,    2,    1,    1,    1,    2,    1,    3,    1,    2,
    2,    1,    1,    1,    1,    1,    1,    1,    1,    0,
    0,    5,    0,    4,    1,    0,    5,    0,    0,    5,
    1,    0,    5,    0,    0,    5,    0,    0,    8,    0,
    5,    0,    5,    0,    5,    3,    0,    3,    0,    2,
    3,    0,    7,    0,    3,    0,    0,    5,    0,    6,
    0,    8,    2,    2,    0,    0,    0,    0,   13,    0,
    1,    3,    0,    1,    3,    0,    0,    0,    5,    0,
    4,    1,    3,    1,    1,    1,    1,    1,    1,    3,
    0,    4,    0,    4,    0,    4,    0,    4,    1,    1,
    1,    3,    0,    4,    0,    4,    0,    4,    0,    4,
    0,    4,    0,    4,    0,    4,    0,    4,    0,    4,
    0,    4,    0,    3,    1,    1,    1,    0,    5,
};
static const YYINT yydefred[] = {                         0,
   14,   15,   13,   11,   10,   12,    0,    1,    3,    0,
    0,    2,    0,    0,    0,    0,  145,  119,    0,   62,
   64,   60,    0,    0,    0,    0,  143,    0,   39,    0,
    0,    0,    0,   32,   33,   34,   35,   36,    0,   38,
    0,    0,  120,   27,   18,    0,    0,    0,    0,   20,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   83,   84,    0,   70,    0,    0,  121,    0,
  147,    9,   30,   31,  123,  125,  127,  129,  135,  139,
  141,  137,  133,  131,    0,   43,   26,   16,   17,    0,
    0,   24,   22,    4,    0,   41,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  144,   71,  122,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  103,    0,   28,   21,    0,    8,    0,
    0,    0,    0,    0,    0,    0,    0,  109,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   72,
    0,  100,   85,    0,  124,  126,  128,  130,  136,  140,
  142,  138,  134,  132,    0,    5,    0,   78,    0,    0,
  108,    0,    0,  149,  111,  113,  115,  117,    0,   49,
    0,   63,    0,   55,    0,    0,   65,   61,    0,   98,
    0,    0,   95,    0,   80,    0,  110,    0,    0,    0,
    0,    0,    0,   66,    0,    0,    0,   68,    0,    0,
    0,    0,    0,    0,    0,  112,  114,  116,  118,   47,
    0,   53,   56,    0,   74,   73,    0,    0,   86,    6,
   82,   58,    0,    0,    0,    0,   75,   87,   59,    0,
   88,    0,   89,
};
static const YYINT yydgoto[] = {                          7,
    8,    9,   46,   11,   31,  137,  128,  194,   95,   47,
   48,   49,   50,   51,   93,   32,   33,   34,   35,   36,
   37,   38,   69,   40,   53,   41,  130,   71,  125,  102,
  140,  141,  203,  104,  144,  145,  206,  146,  236,   60,
  143,   58,   59,  148,  189,  226,  233,   54,   55,   56,
  109,  213,  192,  235,  240,  242,  110,  151,  210,  191,
  139,  198,  199,  200,  201,   43,  114,  115,  116,  117,
  123,  122,  118,  121,  119,  120,   65,   57,
};
static const YYINT yysindex[] = {                      -200,
    0,    0,    0,    0,    0,    0, -200,    0,    0, -221,
  -31,    0,  -29,  121,  235,  121,    0,    0,    0,    0,
    0,    0,    5,   15,    7,   11,    0,   96,    0,  -34,
  -51,  121,   18,    0,    0,    0,    0,    0,    0,    0,
  162, -207,    0,    0,    0, -167,   38,   -7,   37,    0,
 -178, -183, -188,   58,   59,   63,   14, -150, -149, -150,
  -34, -147,    0,    0,  -34,    0,  -10,    0,    0,  132,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -34,    0,    0,    0,    0, -144,
 -167,    0,    0,    0,   -8,    0,   77, -140, -128,  -35,
    0,   89,    0,   90,   89,  142,    0, -146,   76,  100,
    0,    0,    0,  -34,  -34,  -34,  -34,  -34,  -34,  -34,
  -34,  -34,  -34,    0,  -34,    0,    0,  -35,    0,  -34,
   82,  104,  102,    0,    0,  -30,   54,    0, -168,   57,
 -136, -150,   91,   60, -132,   66, -149,   95,   99,    0,
 -126,    0,    0, -147,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -152,    0, -152,    0,  101,  -96,
    0,    0,  111,    0,    0,    0,    0,    0,  -35,    0,
   89,    0,  -35,    0,  -35,   90,    0,    0,  121,    0,
  -34,  -34,    0,  106,    0,  125,    0,  -30,  -30,  -30,
  -30,   74,  -34,    0,   78,  -87,   81,    0, -102,  -34,
 -152,  172,  116,   51,  118,    0,    0,    0,    0,    0,
 -152,    0,    0, -107,    0,    0, -152,  -34,    0,    0,
    0,    0,  121, -152, -147,  -82,    0,    0,    0,  141,
    0,  121,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -40,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -123,    0,    0,    0,    0,    0,    0,   17,    0,
  129,  152,    0,    0,    0,  -28,    0,    0,  143,    0,
    3,   64,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -13,    0,    0,    0,    0,    0,  -11,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -37,  133,  -32,  134,  133,    0,  -90,    0,    0,   -9,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  127,   97,    0,    0,    0,  -44,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -23,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   45,    0,   62,    0,    0,    0,
    0,  122,    0,    0,    0,    0,    0,    0,    0,    0,
  133,    0,    0,    0,    0,  134,    0,    0,    0,    0,
    0,  135,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   79,    0,
  -18,  138,    0,    0,    0,    0,    0,    0,    0,    0,
   -6,    0,    0,    0,    0,    0,  -16,    0,    0,    0,
    0,    0,    0,  139,   31,    0,    0,    0,    0,    0,
    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  184,    0,   35,  189,   24, -114,    0,    0,    0,    0,
    0,    0,  109,  155,    0, -169,  120,    0,    0,    0,
    0,    0,  442,    0,    0,  446,    0,  443,    0,  -52,
    0,    0,    0,   56,    0,    0,    0,    0,    0,    0,
  -88,    0,    0,   21,    0,    0,    0,    0,    0,    0,
 -151,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -112,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 685
static const YYINT yytable[] = {                         77,
  148,   29,  193,  146,  136,   30,   45,  105,   15,  136,
   15,   51,   25,  166,  106,   25,  149,   93,  146,  209,
   96,   45,  101,  173,   99,  101,   51,   99,   77,  146,
   96,   94,  146,   89,   10,   93,   90,   50,    2,   52,
  101,   10,   99,   23,   61,   93,   23,  146,  106,   94,
  148,   67,   50,   46,   62,   73,   37,    1,   52,    2,
  121,    3,    4,  237,  202,   63,    5,    6,  205,   64,
  207,   93,  243,   72,   96,   37,   74,   86,   88,  148,
   91,   92,   94,  238,   44,  216,  217,  218,  219,  181,
    1,   14,  204,   16,    3,    4,   96,   97,   98,    5,
    6,   42,   99,   44,  100,  175,  176,  177,  178,  101,
  103,  146,  107,  146,  112,  126,  129,  131,   76,  132,
   42,   75,   76,   77,   78,   79,   80,   81,   82,   83,
   84,  133,  142,  147,  153,   30,   77,   76,  152,   37,
  168,   37,   29,  154,  169,  170,  174,  179,  180,  182,
  183,  197,  184,  187,   29,  105,  185,  188,  190,  195,
   30,   77,  107,  196,  214,  215,  220,   44,  225,   44,
  222,  223,  113,  224,  229,  230,  231,  232,  239,   29,
  107,  241,  150,   19,   42,  104,   42,  102,    7,  105,
   12,   67,   69,   90,   97,  147,   91,   92,   13,  127,
   87,   76,  186,   76,  124,   85,  208,    0,    0,    0,
  147,    0,    0,    0,  107,  228,    0,    0,   28,  104,
   66,  134,   17,   18,  135,   68,  171,    0,    0,  172,
    0,   25,    0,  146,  146,  146,  146,  146,  146,  146,
  146,  146,  146,   28,   40,  146,  146,   48,  146,   27,
  146,  146,   54,    0,  146,    0,  146,  146,  146,  146,
  146,  146,  146,  146,  146,  146,  146,  146,  146,  146,
  146,  146,  146,   37,   37,   45,   37,    0,   37,   37,
    0,    0,   37,    0,   37,   37,   37,   37,   37,   37,
  121,  121,  121,  121,  121,  121,  121,  121,  121,  121,
   37,   44,   44,    0,   44,    0,   44,   44,    0,    0,
   44,    0,   44,   44,   44,   44,   44,   44,   42,   42,
    0,   42,    0,   42,   42,    0,    0,   42,   44,   42,
   42,   42,   42,   42,   42,   76,   76,    0,   76,    0,
   76,   76,    0,    0,   76,   42,   76,   76,   76,    0,
   76,   76,   17,   18,    0,   19,    0,   20,   21,    0,
    0,    0,   76,   22,   23,   24,    0,   25,   26,    0,
  107,  107,  107,  107,    0,    0,    0,   17,   18,   27,
   19,    0,   20,   21,  175,  176,  177,  178,   22,   23,
   24,    0,   25,   26,    0,  107,  107,  107,  107,    0,
  108,  108,  108,  108,   27,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,  147,  147,  147,  147,  147,
  147,  147,  147,  147,  147,   75,   76,   77,   78,   79,
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
  165,    0,    0,    0,    0,  167,    0,  138,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  108,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  138,    0,    0,    0,  138,    0,  138,    0,    0,    0,
   39,   42,    0,    0,    0,    0,  211,  212,    0,  138,
  138,  138,  138,    0,    0,    0,    0,    0,  221,    0,
    0,    0,    0,    0,    0,  227,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  234,   39,   42,    0,  108,    0,    0,
    0,    0,    0,   39,   42,
};
static const YYINT yycheck[] = {                         40,
   91,  125,  154,   44,   40,   40,   44,   60,   40,   40,
   40,   44,   41,  128,   59,   44,  105,   41,   59,  189,
   44,   59,   41,  136,   41,   44,   59,   44,   40,   41,
   44,   41,   44,   41,    0,   59,   44,   44,  260,   16,
   59,    7,   59,   41,   40,   59,   44,   59,   93,   59,
   91,   28,   59,   91,   40,   32,   40,  258,   91,  260,
   44,  262,  263,  233,  179,   59,  267,  268,  183,   59,
  185,   41,  242,  125,   44,   59,   59,  285,   41,   91,
   44,  260,  266,  235,   40,  198,  199,  200,  201,  142,
  258,  123,  181,  123,  262,  263,  285,   40,   40,  267,
  268,   40,   40,   59,   91,  274,  275,  276,  277,  260,
  260,  123,  260,  125,  125,  260,  125,   41,   40,  260,
   59,  274,  275,  276,  277,  278,  279,  280,  281,  282,
  283,  260,   44,   44,   59,   40,   40,   59,  285,  123,
   59,  125,  266,   44,   41,   44,   93,   91,  285,   59,
   91,   41,  285,   59,   59,   59,   91,   59,  285,   59,
   40,   40,   41,  260,   59,   41,   93,  123,  271,  125,
   93,  259,   41,   93,   59,  125,   59,  285,  261,   59,
   59,   41,   41,   41,  123,   59,  125,   59,  125,   93,
    7,   59,   59,   59,  285,   44,   59,   59,   10,   91,
   46,  123,  147,  125,   85,   44,  186,   -1,   -1,   -1,
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
  179,   -1,   -1,   -1,  183,   -1,  185,   -1,   -1,   -1,
  189,  189,   -1,   -1,   -1,   -1,  191,  192,   -1,  198,
  199,  200,  201,   -1,   -1,   -1,   -1,   -1,  203,   -1,
   -1,   -1,   -1,   -1,   -1,  210,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  228,  233,  233,   -1,  235,   -1,   -1,
   -1,   -1,   -1,  242,  242,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 286
#define YYUNDFTOKEN 367
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : translation_unit",
"translation_unit : external_declaration",
"translation_unit : translation_unit external_declaration",
"external_declaration : function_definition",
"$$1 :",
"$$2 :",
"function_definition : type_specifier declarator '{' statementlist RETURN $$1 arg_expression $$2 ';' '}'",
"$$3 :",
"function_definition : type_specifier declarator '{' statementlist $$3 '}'",
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
"$$4 :",
"$$5 :",
"assignmentstatement : IDENTIFIER $$4 ASSIGN_OP $$5 float_expression",
"$$6 :",
"assignmentstatement : arrayindex ASSIGN_OP $$6 float_expression",
"declerationstub : IDENTIFIER",
"$$7 :",
"declerationstub : IDENTIFIER $$7 '[' arg_expression ']'",
"$$8 :",
"$$9 :",
"declerationstub : IDENTIFIER $$8 ASSIGN_OP $$9 float_expression",
"c_declerationstub : IDENTIFIER",
"$$10 :",
"c_declerationstub : IDENTIFIER $$10 '[' arg_expression ']'",
"$$11 :",
"$$12 :",
"c_declerationstub : IDENTIFIER $$11 ASSIGN_OP $$12 CHARACTER",
"$$13 :",
"$$14 :",
"c_declerationstub : IDENTIFIER $$13 '[' arg_expression ']' ASSIGN_OP $$14 STRINGLITERAL",
"$$15 :",
"declerationstatement : INT $$15 declerationstub declerationlist ';'",
"$$16 :",
"declerationstatement : FLOAT $$16 declerationstub declerationlist ';'",
"$$17 :",
"declerationstatement : CHAR $$17 c_declerationstub c_declerationlist ';'",
"declerationlist : ',' declerationstub declerationlist",
"declerationlist :",
"c_declerationlist : ',' c_declerationstub c_declerationlist",
"c_declerationlist :",
"compoundstatement : '{' '}'",
"compoundstatement : '{' statementlist '}'",
"$$18 :",
"conditionalstatement : IF '(' float_expression ')' $$18 statement ELSESTMT",
"$$19 :",
"ELSESTMT : ELSE $$19 statement",
"ELSESTMT :",
"$$20 :",
"functioncallstatement : IDENTIFIER $$20 '(' ')' ';'",
"$$21 :",
"functioncallstatement : IDENTIFIER $$21 '(' IDENTIFIER ')' ';'",
"$$22 :",
"functioncallstatement : IDENTIFIER $$22 '(' IDENTIFIER ',' IDENTIFIER ')' ';'",
"jumpstatement : BREAK ';'",
"jumpstatement : CONTINUE ';'",
"$$23 :",
"$$24 :",
"$$25 :",
"$$26 :",
"forstatement : FOR '(' optionalassignstatement ';' $$23 optionaltestexpressionstatement ';' $$24 optionalassignstatement $$25 ')' $$26 statement",
"optionaltestexpressionstatement :",
"optionaltestexpressionstatement : float_expression",
"optionaltestexpressionstatement : float_expression ',' float_expression",
"optionalassignstatement :",
"optionalassignstatement : optional_assign_expression",
"optionalassignstatement : optional_assign_expression ',' optionalassignstatement",
"optional_assign_expression :",
"$$27 :",
"$$28 :",
"optional_assign_expression : IDENTIFIER $$27 ASSIGN_OP $$28 float_expression",
"$$29 :",
"optional_assign_expression : arrayindex ASSIGN_OP $$29 float_expression",
"expressionstatement : float_expression",
"expressionstatement : float_expression ',' expressionstatement",
"arg_expression : INTEGER",
"arg_expression : IDENTIFIER",
"arg_expression : arg_expr",
"arg_expr : IDENTIFIER",
"arg_expr : INTEGER",
"arg_expr : functioncallstatement",
"arg_expr : '(' arg_expr ')'",
"$$30 :",
"arg_expr : arg_expr ADD_OP $$30 arg_expr",
"$$31 :",
"arg_expr : arg_expr SUB_OP $$31 arg_expr",
"$$32 :",
"arg_expr : arg_expr MUL_OP $$32 arg_expr",
"$$33 :",
"arg_expr : arg_expr DIV_OP $$33 arg_expr",
"float_expression : DOUBLE",
"float_expression : expression",
"float_expression : functioncallstatement",
"float_expression : '(' float_expression ')'",
"$$34 :",
"float_expression : float_expression ADD_OP $$34 float_expression",
"$$35 :",
"float_expression : float_expression SUB_OP $$35 float_expression",
"$$36 :",
"float_expression : float_expression MUL_OP $$36 float_expression",
"$$37 :",
"float_expression : float_expression DIV_OP $$37 float_expression",
"$$38 :",
"float_expression : float_expression G_OP $$38 float_expression",
"$$39 :",
"float_expression : float_expression L_OP $$39 float_expression",
"$$40 :",
"float_expression : float_expression GE_OP $$40 float_expression",
"$$41 :",
"float_expression : float_expression LE_OP $$41 float_expression",
"$$42 :",
"float_expression : float_expression EE_OP $$42 float_expression",
"$$43 :",
"float_expression : float_expression NE_OP $$43 float_expression",
"$$44 :",
"float_expression : NOT_OP $$44 float_expression",
"expression : INTEGER",
"expression : IDENTIFIER",
"expression : arrayindex",
"$$45 :",
"arrayindex : IDENTIFIER $$45 '[' arg_expression ']'",

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

void set_func_label()
{
    fprintf(f1,"$L%s :\n",text);
}

void goto_func_label()
{
    fprintf(f1,"\tgoto $L%s \n",text);
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
#line 1146 "y.tab.c"

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
	{set_valid();}
break;
case 7:
#line 75 "parser.y"
	{check_func_type_void();}
break;
case 8:
#line 75 "parser.y"
	{set_valid();}
break;
case 9:
#line 76 "parser.y"
	{set_valid();}
break;
case 10:
#line 80 "parser.y"
	{setType();return_num=1;}
break;
case 11:
#line 81 "parser.y"
	{setType();return_num=2;}
break;
case 12:
#line 82 "parser.y"
	{setType();return_num=0;}
break;
case 13:
#line 83 "parser.y"
	{setType();return_num=3;}
break;
case 14:
#line 84 "parser.y"
	{setType();return_num=4;}
break;
case 15:
#line 88 "parser.y"
	{set_f_name(); STMT_DECLARE_FUNC(return_num); set_func_label();}
break;
case 24:
#line 109 "parser.y"
	{STMT_DECLARE_ID(); set_data_type();f_arg++;}
break;
case 27:
#line 118 "parser.y"
	{check();}
break;
case 40:
#line 153 "parser.y"
	{check(); push_text();}
break;
case 41:
#line 153 "parser.y"
	{push();}
break;
case 42:
#line 153 "parser.y"
	{codegen_assign();}
break;
case 43:
#line 154 "parser.y"
	{push();}
break;
case 44:
#line 154 "parser.y"
	{codegen_assign1();}
break;
case 45:
#line 158 "parser.y"
	{STMT_DECLARE_ID();set_data_type();}
break;
case 46:
#line 159 "parser.y"
	{set_arr(); STMT_DECLARE_ID();set_data_type();}
break;
case 48:
#line 160 "parser.y"
	{STMT_DECLARE_ID();push_text();set_data_type();}
break;
case 49:
#line 160 "parser.y"
	{push();}
break;
case 50:
#line 160 "parser.y"
	{codegen_assign();}
break;
case 51:
#line 164 "parser.y"
	{STMT_DECLARE_ID();set_data_type();}
break;
case 52:
#line 165 "parser.y"
	{set_arr(); STMT_DECLARE_ID();set_data_type();}
break;
case 54:
#line 166 "parser.y"
	{STMT_DECLARE_ID();push_text();set_data_type();}
break;
case 55:
#line 166 "parser.y"
	{push();}
break;
case 56:
#line 166 "parser.y"
	{codegen_assign();}
break;
case 57:
#line 167 "parser.y"
	{set_arr(); STMT_DECLARE_ID();push_text();set_data_type();}
break;
case 58:
#line 167 "parser.y"
	{push();}
break;
case 59:
#line 167 "parser.y"
	{codegen_assign();}
break;
case 60:
#line 171 "parser.y"
	{setType();}
break;
case 62:
#line 172 "parser.y"
	{setType();}
break;
case 64:
#line 173 "parser.y"
	{setType();}
break;
case 72:
#line 192 "parser.y"
	{if_label1();}
break;
case 74:
#line 196 "parser.y"
	{if_label2();}
break;
case 75:
#line 196 "parser.y"
	{if_label3();}
break;
case 76:
#line 197 "parser.y"
	{if_label3();}
break;
case 77:
#line 201 "parser.y"
	{check_func(); goto_func_label(); /*add_func_label();*/}
break;
case 78:
#line 201 "parser.y"
	{check_f_arg(0);}
break;
case 79:
#line 202 "parser.y"
	{check_func(); goto_func_label(); /*add_func_label();*/}
break;
case 80:
#line 202 "parser.y"
	{check_f_arg(1);}
break;
case 81:
#line 203 "parser.y"
	{check_func(); goto_func_label(); /*add_func_label();*/}
break;
case 82:
#line 203 "parser.y"
	{check_f_arg(2);}
break;
case 83:
#line 207 "parser.y"
	{stmt_break();}
break;
case 84:
#line 208 "parser.y"
	{stmt_continue();}
break;
case 85:
#line 212 "parser.y"
	{for_label1();}
break;
case 86:
#line 212 "parser.y"
	{for_label2();}
break;
case 87:
#line 212 "parser.y"
	{post_update();}
break;
case 88:
#line 212 "parser.y"
	{for_label3();}
break;
case 89:
#line 212 "parser.y"
	{for_label4();}
break;
case 90:
#line 216 "parser.y"
	{strcpy(st[++top],"true");}
break;
case 97:
#line 229 "parser.y"
	{check(); push_text();}
break;
case 98:
#line 229 "parser.y"
	{push();}
break;
case 99:
#line 229 "parser.y"
	{codegen_assign();}
break;
case 100:
#line 230 "parser.y"
	{push();}
break;
case 101:
#line 230 "parser.y"
	{codegen_assign1();}
break;
case 104:
#line 239 "parser.y"
	{push(); storevar();}
break;
case 105:
#line 240 "parser.y"
	{check(); push_text();}
break;
case 107:
#line 245 "parser.y"
	{check();push_text();}
break;
case 108:
#line 246 "parser.y"
	{ push();}
break;
case 111:
#line 249 "parser.y"
	{push();}
break;
case 112:
#line 249 "parser.y"
	{codegen_algebric();}
break;
case 113:
#line 250 "parser.y"
	{push();}
break;
case 114:
#line 250 "parser.y"
	{codegen_algebric();}
break;
case 115:
#line 251 "parser.y"
	{push();}
break;
case 116:
#line 251 "parser.y"
	{codegen_algebric();}
break;
case 117:
#line 252 "parser.y"
	{push();}
break;
case 118:
#line 252 "parser.y"
	{codegen_algebric();}
break;
case 119:
#line 256 "parser.y"
	{push();}
break;
case 123:
#line 260 "parser.y"
	{push();}
break;
case 124:
#line 260 "parser.y"
	{codegen_algebric();}
break;
case 125:
#line 261 "parser.y"
	{push();}
break;
case 126:
#line 261 "parser.y"
	{codegen_algebric();}
break;
case 127:
#line 262 "parser.y"
	{push();}
break;
case 128:
#line 262 "parser.y"
	{codegen_algebric();}
break;
case 129:
#line 263 "parser.y"
	{push();}
break;
case 130:
#line 263 "parser.y"
	{codegen_algebric();}
break;
case 131:
#line 264 "parser.y"
	{push();}
break;
case 132:
#line 264 "parser.y"
	{codegen_logical();}
break;
case 133:
#line 265 "parser.y"
	{push();}
break;
case 134:
#line 265 "parser.y"
	{codegen_logical();}
break;
case 135:
#line 266 "parser.y"
	{push();}
break;
case 136:
#line 266 "parser.y"
	{codegen_logical();}
break;
case 137:
#line 267 "parser.y"
	{push();}
break;
case 138:
#line 267 "parser.y"
	{codegen_logical();}
break;
case 139:
#line 268 "parser.y"
	{push();}
break;
case 140:
#line 268 "parser.y"
	{codegen_logical();}
break;
case 141:
#line 269 "parser.y"
	{push();}
break;
case 142:
#line 269 "parser.y"
	{codegen_logical();}
break;
case 143:
#line 270 "parser.y"
	{push();}
break;
case 144:
#line 270 "parser.y"
	{codegen_logicalnot();}
break;
case 145:
#line 274 "parser.y"
	{push();}
break;
case 146:
#line 275 "parser.y"
	{check(); push_text();}
break;
case 148:
#line 280 "parser.y"
	{check_arr(); push_text();}
break;
#line 1732 "y.tab.c"
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
