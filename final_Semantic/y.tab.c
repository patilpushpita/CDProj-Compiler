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
				int dimension; /*added*/
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
#line 44 "parser.y"
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
#line 75 "y.tab.c"

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
#define MAIN 269
#define IF 270
#define FOR 271
#define ELSE 272
#define BREAK 273
#define CONTINUE 274
#define ADD_OP 275
#define SUB_OP 276
#define MUL_OP 277
#define DIV_OP 278
#define GE_OP 279
#define EE_OP 280
#define NE_OP 281
#define LE_OP 282
#define L_OP 283
#define G_OP 284
#define NOT_OP 285
#define ASSIGN_OP 286
#define then 287
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    1,    5,    0,    6,    7,    8,    9,    0,    0,   10,
    4,   11,    4,    2,    2,   12,   12,   12,   12,   12,
   12,   12,   12,   12,   21,   20,   20,   24,   25,   24,
   26,   24,   27,   28,   27,   29,   27,   30,   27,   31,
   17,   33,   17,   34,   17,   32,   32,   35,   35,   16,
   16,   36,   15,   38,   37,   37,   39,   19,   40,   19,
   18,   18,   43,   14,   42,   42,   42,   41,   41,   41,
   44,   45,   44,   44,   13,   13,    3,    3,    3,   46,
   46,   46,   46,   46,   46,   46,   46,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   47,   47,   47,   48,   23,
};
static const YYINT yylen[] = {                            2,
    0,    0,   13,    0,    0,    0,    0,   17,    1,    0,
   11,    0,   10,    1,    2,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    0,    4,    3,    1,    0,    5,
    0,    4,    1,    0,    5,    0,    4,    0,    7,    0,
    5,    0,    5,    0,    5,    3,    0,    3,    0,    2,
    3,    0,    7,    0,    3,    0,    0,    5,    0,    6,
    2,    2,    0,   10,    0,    1,    3,    0,    1,    3,
    0,    0,    4,    3,    1,    3,    1,    1,    1,    1,
    1,    1,    3,    3,    3,    3,    3,    1,    1,    1,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    2,    1,    1,    1,    0,    5,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    9,   12,    1,   10,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    5,    0,    0,
    0,    0,    0,  103,   88,    0,   42,   44,   40,    0,
    0,    0,    0,    0,    0,    0,   24,    0,    0,    0,
   17,   18,   19,   20,   21,    0,   23,    0,    0,   89,
    0,    6,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   61,   62,    0,   90,  102,  105,    0,   50,
    0,    0,   15,   16,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   91,   51,    0,   92,   93,   94,   95,
   98,  100,  101,   99,   97,   96,   76,    0,    0,    0,
    0,    0,   82,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   52,    0,    0,   63,    0,   13,   81,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   58,    0,  107,    0,
    0,    0,   43,    0,    0,    0,    0,   45,   41,    0,
    0,    0,    0,   70,   83,    2,   84,   85,   86,   87,
    0,   11,   60,    0,    0,   46,    0,   37,    0,   48,
    0,    0,    0,    0,    0,    0,   30,   35,    0,   54,
   53,    0,    0,    0,    3,    0,    0,    0,    0,    0,
    0,   39,   55,    0,    7,   64,    0,    8,
};
static const YYINT yydgoto[] = {                          3,
    9,   38,  122,    4,  195,   10,   22,   88,  217,   11,
    8,   39,   40,   41,   42,   43,   44,   45,   66,   47,
   54,   48,   68,   95,  131,  132,   97,  135,  136,  137,
   60,  134,   58,   59,  139,  170,  201,  208,   55,   56,
  102,  194,  173,  103,  142,  124,   50,   57,
};
static const YYINT yysindex[] = {                      -211,
 -253, -228,    0,    0,    0,    0,    0,    7,   14,   22,
   32,   33,   35, -195,   36,  -44,  -43,    0,  -33,  126,
  126, -171,  126,    0,    0,    0,    0,    0,    0,   42,
   52,   34,   37,  -34,  -34,  105,    0, -172,  126,   39,
    0,    0,    0,    0,    0,    0,    0,  167, -187,    0,
 -166,    0, -165, -184,   63,   64,   17, -155, -151, -155,
  -34, -150,    0,    0,    0,    0,    0,    0,  137,    0,
  -13,   55,    0,    0,  -34,  -34,  -34,  -34,  -34,  -34,
  -34,  -34,  -34,  -34,  -34,  -34,  -38,   70,  -38,  -34,
   75,  -38,  -38,    0,   73,    0,   74,   73,  147,    0,
 -167,   61,   77,    0,    0,   -3,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -147,    0,    0,
  -28,   67,    0, -191,   15,   80, -147,   81,   82,   54,
   57, -136, -155,   90,   60, -134,   62, -151,   95,   96,
    0, -130,  -34,    0, -150,    0,    0,    0,  131,   38,
  -28,  -28,  -28,  -28,  126,   40,    0,   98,    0,  -38,
  -34,   73,    0,  -38, -101,  -38,   74,    0,    0,  126,
  -34, -147,  -34,    0,    0,    0,    0,    0,    0,    0,
 -107,    0,    0,   68, -147,    0,   69,    0,   76,    0,
 -112, -147,  177,  111, -203,  -38,    0,    0, -111,    0,
    0,  -34, -150,  -95,    0,  117,  -84,  126, -147,  138,
   56,    0,    0,  126,    0,    0, -203,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -40,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -120,    0,
    0,    0,    0,    0,    0,   19,    0,  121,  157,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -23,    0,    0,  -10,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -41,  123,  -31,  124,  123,    0,  -90,
    0,    0,   -6,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   48,  266,  127,
    0,    0,    0,  -26,    0,    0,   66,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -15,    0,    0,  422,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  123,    0,    0,    0,    0,  124,    0,    0,    0,
    0,   -4,  125,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -17,    0,    0,    0,    0,    0,
   84,    2,  128,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    4,    0,    0,    0,    0,    0,  133,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,  -14,  -69, -178,    0,    0,    0,    0,    0,    0,
    0, -156,  108,    0,    0,    0,    0,    0,  444,    0,
    0,  473,  448,  -50,    0,    0,   59,    0,    0,    0,
    0,  -87,    0,    0,   23,    0,    0,    0,    0,    0,
 -137,    0,    0,    0,    0,  -83,    0,    0,
};
#define YYTABLESIZE 700
static const YYINT yytable[] = {                         57,
  106,  121,   28,  104,   14,   35,   51,  174,   53,   98,
  140,  121,   33,  191,   79,    5,  205,   28,  104,  126,
   71,   71,  129,  130,   73,   68,   32,   33,   71,   57,
  104,    6,   79,  104,   69,   68,   74,  149,  218,   74,
    7,   32,   73,   68,   68,   73,   12,   71,  104,   29,
  106,  213,   69,   13,   74,    1,    2,  216,   22,   34,
   73,   14,   90,    1,  204,  210,   79,  177,  178,  179,
  180,   15,   18,   16,  186,   17,   19,   22,   20,   21,
  106,   61,  162,  151,  152,  153,  154,   27,   52,   23,
  184,   62,   63,   72,  187,   64,  189,   74,   86,   87,
   89,   90,   91,   92,   94,   26,   27,   93,   96,  100,
  125,  105,  104,  106,  104,  128,  133,  138,  143,  144,
  145,  146,  158,   56,   26,  150,  206,   75,   76,   77,
   78,   79,   80,   81,   82,   83,   84,  155,  156,  157,
  181,   22,   56,   22,   35,   14,  159,  160,  163,  161,
  164,  165,  166,  168,  169,  171,  183,  188,  196,  200,
  197,  198,  176,   37,  182,   35,   57,   78,  199,  203,
   27,  175,   27,    7,  207,  211,  212,  104,  214,   75,
  215,   47,   49,   65,   37,   78,   66,  141,   26,  190,
   26,   67,  117,    0,    0,   72,  167,    0,    0,    0,
  105,    0,    0,    0,    0,    0,   56,    0,   56,    0,
   85,    0,    0,    0,    0,  105,    0,    0,  119,   78,
  202,  120,   24,   25,    0,   65,    0,   36,  147,   70,
    0,  148,    0,    0,  104,  104,  104,  104,  104,  104,
  104,  104,  104,  104,   31,   25,  104,  104,   36,  104,
   34,  104,  104,    0,   36,  104,    0,  104,    0,  104,
  104,  104,  104,  104,  104,  104,  104,  104,  104,  104,
  104,  104,  104,  104,  104,   22,   22,    0,   22,    0,
   22,   22,    0,    0,   22,    0,   22,    0,   22,   22,
   22,   22,   22,   90,   90,   90,   90,   90,   90,   90,
   90,   90,   90,   22,   27,   27,   77,   27,    0,   27,
   27,    0,    0,   27,    0,   27,    0,   27,   27,   27,
   27,   27,   26,   26,   77,   26,    0,   26,   26,    0,
    0,   26,   27,   26,    0,   26,   26,   26,   26,   26,
   56,   56,    0,   56,    0,   56,   56,    0,    0,   56,
   26,   56,    0,   56,   56,    0,   56,   56,   77,    0,
    0,   24,   25,    0,   26,    0,   27,   28,   56,    0,
    0,    0,   29,    0,   30,   31,    0,   32,   33,    0,
    0,    0,   24,   25,    0,   26,    0,   27,   28,   34,
    0,    0,    0,   29,    0,   30,   31,    0,   32,   33,
    0,   80,   80,   80,   80,  151,  152,  153,  154,    0,
   34,   75,   76,   77,   78,   79,   80,   81,   82,   83,
   84,   75,   76,   77,   78,   79,   80,   81,   82,   83,
   84,  105,  105,  105,  105,  105,  105,  105,  105,  105,
  105,   75,   76,   77,   78,   79,   80,   81,   82,   83,
   84,   75,   76,   77,   78,   79,   80,   81,   82,   83,
   84,   57,   80,   46,   46,    0,   46,   49,   49,    0,
   49,    0,    0,    0,    0,    0,    0,    0,    0,   46,
   80,    0,   46,   49,    0,    0,   49,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   67,   69,    0,  101,
    0,    0,    0,    0,   80,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  123,    0,  123,   99,    0,  123,  123,    0,    0,    0,
   81,   81,   81,   81,    0,    0,    0,  107,  108,  109,
  110,  111,  112,  113,  114,  115,  116,    0,  118,    0,
    0,    0,  127,    0,  123,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  101,    0,  123,  123,  123,  123,   46,    0,
    0,    0,   49,  123,    0,    0,    0,  123,    0,  123,
    0,    0,    0,   46,    0,  172,    0,   49,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  185,    0,    0,    0,    0,    0,  123,
    0,    0,    0,  192,    0,  193,    0,    0,    0,    0,
  101,   46,    0,    0,    0,   49,    0,   46,    0,    0,
    0,   49,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  209,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   80,   80,   80,   80,
};
static const YYINT yycheck[] = {                         40,
   91,   40,   44,   44,  125,   40,   21,  145,   23,   60,
   98,   40,   44,  170,   41,  269,  195,   59,   59,   89,
   44,   36,   92,   93,   39,   41,   44,   59,   44,   40,
   41,  260,   59,   44,   41,   59,   41,  121,  217,   44,
  269,   59,   41,   59,   41,   44,   40,   44,   59,   91,
   91,  208,   59,   40,   59,  267,  268,  214,   40,   91,
   59,   40,   44,  267,  268,  203,   93,  151,  152,  153,
  154,   40,  268,   41,  162,   41,   41,   59,  123,  123,
   91,   40,  133,  275,  276,  277,  278,   40,  260,  123,
  160,   40,   59,  266,  164,   59,  166,   59,  286,  266,
  266,  286,   40,   40,  260,   40,   59,   91,  260,  260,
   41,  125,  123,   59,  125,   41,   44,   44,  286,   59,
   44,  125,   41,   40,   59,   59,  196,  275,  276,  277,
  278,  279,  280,  281,  282,  283,  284,  123,   59,   59,
  155,  123,   59,  125,   40,  266,   93,   91,   59,  286,
   91,  286,   91,   59,   59,  286,   59,  259,  266,  272,
   93,   93,  125,   59,  125,   40,   40,   41,   93,   59,
  123,   41,  125,  269,  286,   59,  261,   41,   41,   59,
  125,   59,   59,   59,   59,   59,   59,   41,  123,  167,
  125,   59,   85,   -1,   -1,  286,  138,   -1,   -1,   -1,
   44,   -1,   -1,   -1,   -1,   -1,  123,   -1,  125,   -1,
   44,   -1,   -1,   -1,   -1,   59,   -1,   -1,  257,   93,
   44,  260,  257,  258,   -1,  260,   -1,  123,  257,  125,
   -1,  260,   -1,   -1,  275,  276,  277,  278,  279,  280,
  281,  282,  283,  284,  286,  286,  257,  258,  123,  260,
  285,  262,  263,   -1,  286,  266,   -1,  268,   -1,  270,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  280,
  281,  282,  283,  284,  285,  257,  258,   -1,  260,   -1,
  262,  263,   -1,   -1,  266,   -1,  268,   -1,  270,  271,
  272,  273,  274,  275,  276,  277,  278,  279,  280,  281,
  282,  283,  284,  285,  257,  258,   41,  260,   -1,  262,
  263,   -1,   -1,  266,   -1,  268,   -1,  270,  271,  272,
  273,  274,  257,  258,   59,  260,   -1,  262,  263,   -1,
   -1,  266,  285,  268,   -1,  270,  271,  272,  273,  274,
  257,  258,   -1,  260,   -1,  262,  263,   -1,   -1,  266,
  285,  268,   -1,  270,  271,   -1,  273,  274,   93,   -1,
   -1,  257,  258,   -1,  260,   -1,  262,  263,  285,   -1,
   -1,   -1,  268,   -1,  270,  271,   -1,  273,  274,   -1,
   -1,   -1,  257,  258,   -1,  260,   -1,  262,  263,  285,
   -1,   -1,   -1,  268,   -1,  270,  271,   -1,  273,  274,
   -1,  275,  276,  277,  278,  275,  276,  277,  278,   -1,
  285,  275,  276,  277,  278,  279,  280,  281,  282,  283,
  284,  275,  276,  277,  278,  279,  280,  281,  282,  283,
  284,  275,  276,  277,  278,  279,  280,  281,  282,  283,
  284,  275,  276,  277,  278,  279,  280,  281,  282,  283,
  284,  275,  276,  277,  278,  279,  280,  281,  282,  283,
  284,   40,   41,   20,   21,   -1,   23,   20,   21,   -1,
   23,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   36,
   59,   -1,   39,   36,   -1,   -1,   39,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   34,   35,   -1,   62,
   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   87,   -1,   89,   61,   -1,   92,   93,   -1,   -1,   -1,
  275,  276,  277,  278,   -1,   -1,   -1,   75,   76,   77,
   78,   79,   80,   81,   82,   83,   84,   -1,   86,   -1,
   -1,   -1,   90,   -1,  121,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  145,   -1,  151,  152,  153,  154,  155,   -1,
   -1,   -1,  155,  160,   -1,   -1,   -1,  164,   -1,  166,
   -1,   -1,   -1,  170,   -1,  143,   -1,  170,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  161,   -1,   -1,   -1,   -1,   -1,  196,
   -1,   -1,   -1,  171,   -1,  173,   -1,   -1,   -1,   -1,
  203,  208,   -1,   -1,   -1,  208,   -1,  214,   -1,   -1,
   -1,  214,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  202,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  275,  276,  277,  278,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 287
#define YYUNDFTOKEN 338
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
"FUNCTION","ARRAY","RETURN","VOID","INT","MAIN","IF","FOR","ELSE","BREAK",
"CONTINUE","ADD_OP","SUB_OP","MUL_OP","DIV_OP","GE_OP","EE_OP","NE_OP","LE_OP",
"L_OP","G_OP","NOT_OP","ASSIGN_OP","\"then\"",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : function",
"$$1 :",
"$$2 :",
"function : INT IDENTIFIER $$1 '(' ')' '{' statementlist RETURN arg_expression ';' '}' $$2 mainfunction",
"$$3 :",
"$$4 :",
"$$5 :",
"$$6 :",
"function : INT IDENTIFIER $$3 '(' INT $$4 IDENTIFIER $$5 ')' '{' statementlist RETURN arg_expression ';' '}' $$6 mainfunction",
"function : mainfunction",
"$$7 :",
"mainfunction : INT MAIN $$7 '(' ')' '{' statementlist RETURN arg_expression ';' '}'",
"$$8 :",
"mainfunction : VOID MAIN $$8 '(' ')' '{' statementlist RETURN ';' '}'",
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
"$$9 :",
"assignmentstatement : IDENTIFIER $$9 ASSIGN_OP float_expression",
"assignmentstatement : arrayindex ASSIGN_OP float_expression",
"declerationstub : IDENTIFIER",
"$$10 :",
"declerationstub : IDENTIFIER $$10 '[' arg_expression ']'",
"$$11 :",
"declerationstub : IDENTIFIER $$11 ASSIGN_OP float_expression",
"c_declerationstub : IDENTIFIER",
"$$12 :",
"c_declerationstub : IDENTIFIER $$12 '[' arg_expression ']'",
"$$13 :",
"c_declerationstub : IDENTIFIER $$13 ASSIGN_OP CHARACTER",
"$$14 :",
"c_declerationstub : IDENTIFIER $$14 '[' arg_expression ']' ASSIGN_OP STRINGLITERAL",
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
"functioncallstatement : IDENTIFIER $$21 '(' arg_expression ')' ';'",
"jumpstatement : BREAK ';'",
"jumpstatement : CONTINUE ';'",
"$$22 :",
"forstatement : FOR '(' optionalassignstatement ';' $$22 optionaltestexpressionstatement ';' optionalassignstatement ')' statement",
"optionaltestexpressionstatement :",
"optionaltestexpressionstatement : float_expression",
"optionaltestexpressionstatement : float_expression ',' float_expression",
"optionalassignstatement :",
"optionalassignstatement : optional_assign_expression",
"optionalassignstatement : optional_assign_expression ',' optionalassignstatement",
"optional_assign_expression :",
"$$23 :",
"optional_assign_expression : IDENTIFIER $$23 ASSIGN_OP float_expression",
"optional_assign_expression : arrayindex ASSIGN_OP float_expression",
"expressionstatement : float_expression",
"expressionstatement : float_expression ',' expressionstatement",
"arg_expression : INTEGER",
"arg_expression : IDENTIFIER",
"arg_expression : arg_expr",
"arg_expr : IDENTIFIER",
"arg_expr : INTEGER",
"arg_expr : functioncallstatement",
"arg_expr : '(' arg_expr ')'",
"arg_expr : arg_expr ADD_OP arg_expr",
"arg_expr : arg_expr SUB_OP arg_expr",
"arg_expr : arg_expr MUL_OP arg_expr",
"arg_expr : arg_expr DIV_OP arg_expr",
"float_expression : DOUBLE",
"float_expression : expression",
"float_expression : functioncallstatement",
"float_expression : '(' float_expression ')'",
"float_expression : float_expression ADD_OP float_expression",
"float_expression : float_expression SUB_OP float_expression",
"float_expression : float_expression MUL_OP float_expression",
"float_expression : float_expression DIV_OP float_expression",
"float_expression : float_expression G_OP float_expression",
"float_expression : float_expression L_OP float_expression",
"float_expression : float_expression GE_OP float_expression",
"float_expression : float_expression LE_OP float_expression",
"float_expression : float_expression EE_OP float_expression",
"float_expression : float_expression NE_OP float_expression",
"float_expression : NOT_OP float_expression",
"expression : INTEGER",
"expression : IDENTIFIER",
"expression : arrayindex",
"$$24 :",
"arrayindex : IDENTIFIER $$24 '[' arg_expression ']'",

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
#line 220 "parser.y"

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
//icg from here

void cg_logical()
{
 	sprintf(temp,"$t%d",i);
  	top-=2;
 	strcpy(st[top],temp);
 	i++;
}

void cg_logicalnot()
{
 	sprintf(temp,"$t%d",i);
  	top-=1;
 	strcpy(st[top],temp);
 	i++;
}

void cg_algebric()
{
 	sprintf(temp,"$t%d",i);
  	top-=2;
 	strcpy(st[top],temp);
 	i++;
}

void cg_assign1()
{
 	top-=4;
}

void cg_assign()
{
 	top-=3;
}
 
void if_label1()
{
 	ifnum++;
 	iflabel[++iftop]=ifnum;
}

void if_label2()
{
	int x;
	ifnum++;
	x=iflabel[iftop--]; 
	iflabel[++iftop]=ifnum;
}

void if_label3()
{
    printf("iftop = %d\n",iftop);
	int y;
	y=iflabel[iftop--];
}

void for_label1()
{
    lnum++;
 	label[++ltop]=lnum; //test_expr
 	label[++ltop]=++lnum; //update_expr
 	label[++ltop]=++lnum; // start_of_for_body
 	label[++ltop]=++lnum; //line_after_for
 	
}

void for_label4()
{
   ltop-=4;
}

void stmt_break()
{
    int y;
	y=label[ltop];
}

void stmt_continue()
{ 
    int y;
	y=label[ltop-2];
}

void stmt_return(int args)
{
    if(args);
            
}
//till here

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
#line 966 "y.tab.c"

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
case 1:
#line 62 "parser.y"
	{set_f_name();STMT_DECLARE_FUNC(1);}
break;
case 2:
#line 62 "parser.y"
	{set_valid();}
break;
case 4:
#line 63 "parser.y"
	{set_f_name();STMT_DECLARE_FUNC(1);}
break;
case 5:
#line 63 "parser.y"
	{setType();}
break;
case 6:
#line 63 "parser.y"
	{f_arg = 1;STMT_DECLARE_ID(); set_data_type();}
break;
case 7:
#line 63 "parser.y"
	{set_valid();}
break;
case 10:
#line 68 "parser.y"
	{set_f_name(); STMT_DECLARE_FUNC(1); set_mainflag();}
break;
case 11:
#line 68 "parser.y"
	{set_valid(0);}
break;
case 12:
#line 69 "parser.y"
	{set_f_name(); STMT_DECLARE_FUNC(0); set_mainflag();}
break;
case 13:
#line 69 "parser.y"
	{set_valid(0);}
break;
case 25:
#line 90 "parser.y"
	{check();}
break;
case 26:
#line 90 "parser.y"
	{cg_assign();}
break;
case 27:
#line 91 "parser.y"
	{cg_assign1();}
break;
case 28:
#line 95 "parser.y"
	{STMT_DECLARE_ID();set_data_type();}
break;
case 29:
#line 96 "parser.y"
	{dim_arr=1; set_arr(); STMT_DECLARE_ID();set_data_type(); dim_arr=0;}
break;
case 31:
#line 97 "parser.y"
	{STMT_DECLARE_ID();set_data_type();}
break;
case 32:
#line 97 "parser.y"
	{cg_assign();}
break;
case 33:
#line 101 "parser.y"
	{STMT_DECLARE_ID();set_data_type();}
break;
case 34:
#line 102 "parser.y"
	{dim_arr=1; set_arr(); STMT_DECLARE_ID();set_data_type(); dim_arr=0;}
break;
case 36:
#line 103 "parser.y"
	{STMT_DECLARE_ID();set_data_type();}
break;
case 37:
#line 103 "parser.y"
	{cg_assign();}
break;
case 38:
#line 104 "parser.y"
	{dim_arr=1; set_arr(); STMT_DECLARE_ID();set_data_type(); dim_arr=0;}
break;
case 39:
#line 104 "parser.y"
	{cg_assign();}
break;
case 40:
#line 108 "parser.y"
	{setType();}
break;
case 42:
#line 109 "parser.y"
	{setType();}
break;
case 44:
#line 110 "parser.y"
	{setType();}
break;
case 52:
#line 129 "parser.y"
	{if_label1();}
break;
case 54:
#line 133 "parser.y"
	{if_label2();}
break;
case 55:
#line 133 "parser.y"
	{if_label3();}
break;
case 56:
#line 134 "parser.y"
	{if_label3();}
break;
case 57:
#line 138 "parser.y"
	{check_func();}
break;
case 58:
#line 138 "parser.y"
	{check_f_arg(0);}
break;
case 59:
#line 139 "parser.y"
	{check_func();}
break;
case 60:
#line 139 "parser.y"
	{check_f_arg(1);}
break;
case 61:
#line 143 "parser.y"
	{stmt_break();}
break;
case 62:
#line 144 "parser.y"
	{stmt_continue();}
break;
case 63:
#line 148 "parser.y"
	{for_label1();}
break;
case 64:
#line 148 "parser.y"
	{for_label4();}
break;
case 65:
#line 152 "parser.y"
	{strcpy(st[++top],"true");}
break;
case 72:
#line 165 "parser.y"
	{check(); }
break;
case 73:
#line 165 "parser.y"
	{cg_assign();}
break;
case 74:
#line 166 "parser.y"
	{cg_assign1();}
break;
case 78:
#line 176 "parser.y"
	{check();}
break;
case 80:
#line 181 "parser.y"
	{check();}
break;
case 84:
#line 185 "parser.y"
	{cg_algebric();}
break;
case 85:
#line 186 "parser.y"
	{cg_algebric();}
break;
case 86:
#line 187 "parser.y"
	{cg_algebric();}
break;
case 87:
#line 188 "parser.y"
	{cg_algebric();}
break;
case 92:
#line 196 "parser.y"
	{cg_algebric();}
break;
case 93:
#line 197 "parser.y"
	{cg_algebric();}
break;
case 94:
#line 198 "parser.y"
	{cg_algebric();}
break;
case 95:
#line 199 "parser.y"
	{cg_algebric();}
break;
case 96:
#line 200 "parser.y"
	{cg_logical();}
break;
case 97:
#line 201 "parser.y"
	{cg_logical();}
break;
case 98:
#line 202 "parser.y"
	{cg_logical();}
break;
case 99:
#line 203 "parser.y"
	{cg_logical();}
break;
case 100:
#line 204 "parser.y"
	{cg_logical();}
break;
case 101:
#line 205 "parser.y"
	{cg_logical();}
break;
case 102:
#line 206 "parser.y"
	{cg_logicalnot();}
break;
case 104:
#line 211 "parser.y"
	{check();}
break;
case 106:
#line 216 "parser.y"
	{check_arr(); }
break;
#line 1412 "y.tab.c"
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
