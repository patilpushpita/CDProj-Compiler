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
extern YYSTYPE yylval;
