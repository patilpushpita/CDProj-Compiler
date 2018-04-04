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
