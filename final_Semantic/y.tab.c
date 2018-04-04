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
   16,   15,   36,   37,   19,   38,   19,   18,   18,   14,
   40,   40,   40,   39,   39,   39,   41,   42,   41,   41,
   13,   13,    3,    3,    3,   43,   43,   43,   43,   43,
   43,   43,   43,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   44,   44,
   44,   45,   23,
};
static const YYINT yylen[] = {                            2,
    0,    0,   13,    0,    0,    0,    0,   17,    1,    0,
   11,    0,   10,    1,    2,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    0,    4,    3,    1,    0,    5,
    0,    4,    1,    0,    5,    0,    4,    0,    7,    0,
    5,    0,    5,    0,    5,    3,    0,    3,    0,    2,
    3,    6,    2,    0,    5,    0,    6,    2,    2,    9,
    0,    1,    3,    0,    1,    3,    0,    0,    4,    3,
    1,    3,    1,    1,    1,    1,    1,    1,    3,    3,
    3,    3,    3,    1,    1,    1,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    2,    1,    1,
    1,    0,    5,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    9,   12,    1,   10,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    5,    0,    0,
    0,    0,    0,   99,   84,    0,   42,   44,   40,    0,
    0,    0,    0,    0,    0,    0,   24,    0,    0,    0,
   17,   18,   19,   20,   21,    0,   23,    0,    0,   85,
    0,    6,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   58,   59,    0,   86,   98,  101,    0,   50,
    0,    0,   15,   16,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   87,   51,    0,   88,   89,   90,   91,
   94,   96,   97,   95,   93,   92,   72,    0,    0,    0,
    0,    0,   78,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   13,   77,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   55,    0,  103,    0,
    0,    0,   43,    0,    0,    0,    0,   45,   41,    0,
    0,    0,    0,    0,   66,   79,    2,   80,   81,   82,
   83,    0,   11,   57,    0,    0,   46,    0,   37,    0,
   48,    0,   52,    0,    0,    0,    0,    0,   30,   35,
    0,   53,    0,    0,    0,    3,    0,    0,    0,    0,
   39,   60,    7,    0,    8,
};
static const YYINT yydgoto[] = {                          3,
    9,   38,  122,    4,  197,   10,   22,   88,  214,   11,
    8,   39,   40,   41,   42,   43,   44,   45,   66,   47,
   54,   48,   68,   95,  131,  132,   97,  135,  136,  137,
   60,  134,   58,   59,  139,  193,   55,   56,  102,  174,
  103,  142,  124,   50,   57,
};
static const YYINT yysindex[] = {                      -222,
 -248, -221,    0,    0,    0,    0,    0,  -14,   12,   37,
   39,   41,   44, -188,   45,  -36,  -33,    0,  -31,  105,
  105, -171,  105,    0,    0,    0,    0,    0,    0,   53,
   54,   43,   46,  -34,  -34,   84,    0, -170,  105,   49,
    0,    0,    0,    0,    0,    0,    0,  146, -183,    0,
 -162,    0, -157, -176,   71,   72,   23, -144, -143, -144,
  -34, -142,    0,    0,    0,    0,    0,    0,  116,    0,
   -6,   61,    0,    0,  -34,  -34,  -34,  -34,  -34,  -34,
  -34,  -34,  -34,  -34,  -34,  -34,  -39,   80,  -39,  -34,
   81,  -39,  -39,    0,   79,    0,   82,   79,  126,    0,
 -159,   69,   96,    0,    0,   16,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -145,    0,    0,
  -38,   93,    0, -177,   30,   95, -145,   97,  114,   65,
   68, -126, -144,  102,   77, -123,   83, -143,  111,  113,
  105, -111,  -34,  -34, -142,    0,    0,    0,  167,   52,
  -38,  -38,  -38,  -38,  105,   56,    0,  119,    0,  -39,
  -34,   79,    0,  -39,  -80,  -39,   82,    0,    0,  -90,
  -34, -145,  156,  124,    0,    0,    0,    0,    0,    0,
    0,  -81,    0,    0,   91, -145,    0,   94,    0,   99,
    0,  105,    0, -145,  -34, -142, -202,  -39,    0,    0,
 -100,    0, -145,  147,  -76,    0,  135,  -65,  105,   73,
    0,    0,    0, -202,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -40,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -117,    0,
    0,    0,    0,    0,    0,   19,    0,  138,  136,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -32,    0,    0,  -10,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -41,  142,  -37,  143,  142,    0,  -82,
    0,    0,  -24,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   48,  266,  106,
    0,    0,    0,  -26,    0,    0,   66,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  151,  -16,    0,    0,  110,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  142,    0,    0,    0,    0,  143,    0,    0,    0,
    0,   -4,  152,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    3,    0,    0,    0,    0,
    0,    0,    0,   17,    0,   31,    0,    0,    0,    0,
    0,    0,   43,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,   -7,  -69, -161,    0,    0,    0,    0,    0,    0,
    0, -136,  120,    0,    0,    0,    0,    0,  426,    0,
    0,  422,   21,  -49,    0,    0,   74,    0,    0,    0,
    0,  -88,    0,    0,   47,    0,    0,    0, -132,    0,
    0,    0,  -83,    0,    0,
};
#define YYTABLESIZE 635
static const YYINT yytable[] = {                         54,
  121,  121,   28,  100,  170,   35,   33,   14,  102,  140,
   98,   67,  175,   51,   75,   53,   65,   28,  100,  126,
    5,   33,  129,  130,   64,   12,   64,   67,   71,   54,
  100,   73,   75,  100,   65,  206,   70,  149,    6,   70,
   49,   49,   64,   49,    1,    2,   32,    7,  100,   29,
  102,   13,  215,   34,   70,  202,   49,   69,   22,   49,
   69,   32,   86,  204,    1,  205,   75,  178,  179,  180,
  181,   64,  212,  187,   67,   69,   14,   22,   15,   18,
  102,   16,  101,  162,   17,   19,   20,   27,   52,   21,
  185,   23,   61,   62,  188,   72,  190,  151,  152,  153,
  154,   63,   86,   87,   64,   26,   27,   74,   89,   90,
   91,   92,  100,   93,  100,   94,   96,  100,  105,  106,
  125,  128,  133,   35,   26,  138,  143,  144,  207,   75,
   76,   77,   78,   79,   80,   81,   82,   83,   84,  145,
  146,   22,   37,   22,   35,   54,   74,  182,   14,   54,
   76,  150,  155,  156,  158,  157,  104,  159,  160,  161,
  163,   49,  165,   37,   74,  101,  141,  164,   76,  168,
   27,  169,   27,  166,  171,   49,  177,  184,  189,  101,
  183,  192,  196,  199,  198,  208,  200,  209,   26,   85,
   26,  201,    7,  210,  101,  211,   71,  213,   74,  195,
   47,   49,   76,   68,  117,    0,   36,  176,   70,   61,
   62,  167,   49,  191,    0,    0,  101,  119,  147,    0,
  120,  148,   24,   25,    0,   65,    0,   36,    0,   49,
    0,    0,    0,    0,  100,  100,  100,  100,  100,  100,
  100,  100,  100,  100,   31,   25,  100,  100,   36,  100,
   34,  100,  100,    0,    0,  100,    0,  100,    0,  100,
  100,  100,  100,  100,  100,  100,  100,  100,  100,  100,
  100,  100,  100,  100,  100,   22,   22,    0,   22,    0,
   22,   22,    0,    0,   22,    0,   22,    0,   22,   22,
   22,   22,   22,   86,   86,   86,   86,   86,   86,   86,
   86,   86,   86,   22,   27,   27,   73,   27,    0,   27,
   27,    0,    0,   27,    0,   27,    0,   27,   27,   27,
   27,   27,   26,   26,   73,   26,    0,   26,   26,    0,
    0,   26,   27,   26,    0,   26,   26,   26,   26,   26,
   24,   25,    0,   26,    0,   27,   28,    0,    0,    0,
   26,   29,    0,   30,   31,    0,   32,   33,   73,    0,
    0,   24,   25,    0,   26,    0,   27,   28,   34,    0,
    0,    0,   29,    0,   30,   31,    0,   32,   33,    0,
   76,   76,   76,   76,   76,   76,   76,   76,    0,   34,
   75,   76,   77,   78,   79,   80,   81,   82,   83,   84,
   75,   76,   77,   78,   79,   80,   81,   82,   83,   84,
  101,  101,  101,  101,  101,  101,  101,  101,  101,  101,
   75,   76,   77,   78,   79,   80,   81,   82,   83,   84,
   75,   76,   77,   78,   79,   80,   81,   82,   83,   84,
    0,  151,  152,  153,  154,   46,   46,    0,   46,    0,
    0,    0,    0,    0,    0,   67,   69,    0,    0,    0,
    0,   46,    0,    0,   46,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   99,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  107,  108,  109,  110,
  111,  112,  113,  114,  115,  116,    0,  118,    0,    0,
    0,  127,  123,    0,  123,    0,    0,  123,  123,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   77,   77,   77,   77,    0,    0,  123,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  172,  173,   46,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  123,  123,  123,  123,
   46,    0,  186,    0,    0,  123,    0,    0,    0,  123,
    0,  123,  194,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  203,   46,    0,    0,
    0,    0,    0,  123,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   46,
};
static const YYINT yycheck[] = {                         40,
   40,   40,   44,   44,  141,   40,   44,  125,   91,   98,
   60,   44,  145,   21,   41,   23,   41,   59,   59,   89,
  269,   59,   92,   93,   41,   40,   59,   44,   36,   40,
   41,   39,   59,   44,   59,  197,   41,  121,  260,   44,
   20,   21,   59,   23,  267,  268,   44,  269,   59,   91,
   91,   40,  214,   91,   59,  192,   36,   41,   40,   39,
   44,   59,   44,  196,  267,  268,   93,  151,  152,  153,
  154,   41,  209,  162,   44,   59,   40,   59,   40,  268,
   91,   41,   62,  133,   41,   41,  123,   40,  260,  123,
  160,  123,   40,   40,  164,  266,  166,  275,  276,  277,
  278,   59,  286,  266,   59,   40,   59,   59,  266,  286,
   40,   40,  123,   91,  125,  260,  260,  260,  125,   59,
   41,   41,   44,   40,   59,   44,  286,   59,  198,  275,
  276,  277,  278,  279,  280,  281,  282,  283,  284,   44,
  125,  123,   59,  125,   40,   40,   41,  155,  266,   40,
   41,   59,  123,   59,   41,   59,   41,   93,   91,  286,
   59,  141,  286,   59,   59,  145,   41,   91,   59,   59,
  123,   59,  125,   91,  286,  155,  125,   59,  259,   44,
  125,  272,   59,   93,  266,  286,   93,   41,  123,   44,
  125,   93,  269,   59,   59,  261,   59,  125,   93,   44,
   59,   59,   93,  286,   85,   -1,  123,   41,  125,   59,
   59,  138,  192,  167,   -1,   -1,  196,  257,  257,   -1,
  260,  260,  257,  258,   -1,  260,   -1,  123,   -1,  209,
   -1,   -1,   -1,   -1,  275,  276,  277,  278,  279,  280,
  281,  282,  283,  284,  286,  286,  257,  258,  286,  260,
  285,  262,  263,   -1,   -1,  266,   -1,  268,   -1,  270,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  280,
  281,  282,  283,  284,  285,  257,  258,   -1,  260,   -1,
  262,  263,   -1,   -1,  266,   -1,  268,   -1,  270,  271,
  272,  273,  274,  275,  276,  277,  278,  279,  280,  281,
  282,  283,  284,  285,  257,  258,   41,  260,   -1,  262,
  263,   -1,   -1,  266,   -1,  268,   -1,  270,  271,  272,
  273,  274,  257,  258,   59,  260,   -1,  262,  263,   -1,
   -1,  266,  285,  268,   -1,  270,  271,  272,  273,  274,
  257,  258,   -1,  260,   -1,  262,  263,   -1,   -1,   -1,
  285,  268,   -1,  270,  271,   -1,  273,  274,   93,   -1,
   -1,  257,  258,   -1,  260,   -1,  262,  263,  285,   -1,
   -1,   -1,  268,   -1,  270,  271,   -1,  273,  274,   -1,
  275,  276,  277,  278,  275,  276,  277,  278,   -1,  285,
  275,  276,  277,  278,  279,  280,  281,  282,  283,  284,
  275,  276,  277,  278,  279,  280,  281,  282,  283,  284,
  275,  276,  277,  278,  279,  280,  281,  282,  283,  284,
  275,  276,  277,  278,  279,  280,  281,  282,  283,  284,
  275,  276,  277,  278,  279,  280,  281,  282,  283,  284,
   -1,  275,  276,  277,  278,   20,   21,   -1,   23,   -1,
   -1,   -1,   -1,   -1,   -1,   34,   35,   -1,   -1,   -1,
   -1,   36,   -1,   -1,   39,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   61,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   75,   76,   77,   78,
   79,   80,   81,   82,   83,   84,   -1,   86,   -1,   -1,
   -1,   90,   87,   -1,   89,   -1,   -1,   92,   93,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  275,  276,  277,  278,   -1,   -1,  121,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  143,  144,  141,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  151,  152,  153,  154,
  155,   -1,  161,   -1,   -1,  160,   -1,   -1,   -1,  164,
   -1,  166,  171,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  195,  192,   -1,   -1,
   -1,   -1,   -1,  198,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  209,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 287
#define YYUNDFTOKEN 335
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"conditionalstatement : IF '(' float_expression ')' statement ELSESTMT",
"ELSESTMT : ELSE statement",
"$$18 :",
"functioncallstatement : IDENTIFIER $$18 '(' ')' ';'",
"$$19 :",
"functioncallstatement : IDENTIFIER $$19 '(' arg_expression ')' ';'",
"jumpstatement : BREAK ';'",
"jumpstatement : CONTINUE ';'",
"forstatement : FOR '(' optionalassignstatement ';' optionaltestexpressionstatement ';' optionalassignstatement ')' statement",
"optionaltestexpressionstatement :",
"optionaltestexpressionstatement : float_expression",
"optionaltestexpressionstatement : float_expression ',' float_expression",
"optionalassignstatement :",
"optionalassignstatement : optional_assign_expression",
"optionalassignstatement : optional_assign_expression ',' optionalassignstatement",
"optional_assign_expression :",
"$$20 :",
"optional_assign_expression : IDENTIFIER $$20 ASSIGN_OP float_expression",
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
"$$21 :",
"arrayindex : IDENTIFIER $$21 '[' arg_expression ']'",

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
#line 219 "parser.y"

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
#line 859 "y.tab.c"

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
case 38:
#line 104 "parser.y"
	{dim_arr=1; set_arr(); STMT_DECLARE_ID();set_data_type(); dim_arr=0;}
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
case 54:
#line 137 "parser.y"
	{check_func();}
break;
case 55:
#line 137 "parser.y"
	{check_f_arg(0);}
break;
case 56:
#line 138 "parser.y"
	{check_func();}
break;
case 57:
#line 138 "parser.y"
	{check_f_arg(1);}
break;
case 61:
#line 151 "parser.y"
	{strcpy(st[++top],"true");}
break;
case 68:
#line 164 "parser.y"
	{check(); }
break;
case 74:
#line 175 "parser.y"
	{check();}
break;
case 76:
#line 180 "parser.y"
	{check();}
break;
case 100:
#line 210 "parser.y"
	{check();}
break;
case 102:
#line 215 "parser.y"
	{check_arr(); }
break;
#line 1185 "y.tab.c"
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
