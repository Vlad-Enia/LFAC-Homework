/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "homework.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "var_types.h"                  //in var_types sunt structurile var_data si fct_data;
extern FILE* yyin;
extern int yylineno;
extern char* yytext;
//char* tab = char* malloc(1);
char tab[100];

struct var_data table[100];             //tabelul variabilelor
int nrVars=0;                           //nr variabilelor din tabel
void printTable();                      //afiseaza toate elementele din tablou;
void updateTable(int i, int newVal);    //actualizeaza variabila de pe pozitia i cu valoarea newVal
void addVarName(int i, char * newName); //adauga pe pozitia i numele newName
void addVarType(int i, char * newType); //adauga pe pozitia i tipul newType
int findVar(char *newName);             //returneaza pozitia variabilei cu numele NewName
int undeclared(char *newName,char *scope);
int findScope(char* newName,char* scope); 
void PRINT_EVAL();                                    //ar trebui eventual si o functie addScope care adauga scope-ul pe pozitia i
char current_scope[100]="global";
int Eval_calls[100],nr_calls=0;

#line 92 "homework.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "homework.tab.h".  */
#ifndef YY_YY_HOMEWORK_TAB_H_INCLUDED
# define YY_YY_HOMEWORK_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    CHAR = 260,
    STRING = 261,
    BOOL = 262,
    ID = 263,
    BEGIN_P = 264,
    END_P = 265,
    STRUC = 266,
    STRUCEND = 267,
    CLAS = 268,
    CLASEND = 269,
    PUBLIC = 270,
    PRIVATE = 271,
    PROTECTED = 272,
    IF = 273,
    THEN = 274,
    ELSE_IF = 275,
    ENDIF = 276,
    ELSE = 277,
    FOR = 278,
    ENDFOR = 279,
    WHILE = 280,
    ENDWHILE = 281,
    FBEGIN = 282,
    FEND = 283,
    LWR = 284,
    LEQ = 285,
    GTR = 286,
    GEQ = 287,
    EQ = 288,
    NEQ = 289,
    PLUS = 290,
    MINUS = 291,
    MTP = 292,
    DVD = 293,
    MOD = 294,
    AND = 295,
    OR = 296,
    PRINT = 297,
    EVAL_FCT = 298,
    ASGN = 299,
    STRVAL = 300,
    INTVAL = 301,
    BOOLVAL = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 27 "homework.y" /* yacc.c:355  */

        int intval;
        double floatval;
        char* strval;
        int boolval;
        struct VAR                      //structura VAR reprezinta practic o variabila ce urmeaza a fi adaugata in tabel, si are aceleasi campuri ca var_data, care descrie tabelul
        {
                char name[100];
                char val[100];          //valoare numerica convertita in char; AR FI MAI EFICIENT sa stocam totusi in camp de tip int;
                char vartype[6];
                char scope[30];
        } var;


#line 195 "homework.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOMEWORK_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 212 "homework.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   378

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      50,    51,     2,     2,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    73,    73,    76,    87,    88,    89,    90,    93,    93,
      96,    97,   100,   100,   103,   104,   105,   106,   107,   110,
     111,   112,   115,   120,   129,   137,   150,   161,   161,   161,
     161,   162,   162,   162,   162,   165,   166,   169,   183,   187,
     188,   191,   191,   191,   194,   195,   198,   199,   216,   217,
     222,   223,   226,   226,   227,   227,   231,   232,   236,   236,
     237,   240,   240,   243,   244,   244,   245,   245,   248,   249,
     249,   250,   250,   253,   257,   258,   272,   273,   274,   275,
     276,   277,   278,   279,   282,   283,   284,   285,   286,   287,
     288,   289
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "CHAR", "STRING", "BOOL",
  "ID", "BEGIN_P", "END_P", "STRUC", "STRUCEND", "CLAS", "CLASEND",
  "PUBLIC", "PRIVATE", "PROTECTED", "IF", "THEN", "ELSE_IF", "ENDIF",
  "ELSE", "FOR", "ENDFOR", "WHILE", "ENDWHILE", "FBEGIN", "FEND", "LWR",
  "LEQ", "GTR", "GEQ", "EQ", "NEQ", "PLUS", "MINUS", "MTP", "DVD", "MOD",
  "AND", "OR", "PRINT", "EVAL_FCT", "ASGN", "STRVAL", "INTVAL", "BOOLVAL",
  "';'", "','", "'('", "')'", "$accept", "program", "glb_declarations",
  "struct_decl", "$@1", "struct_body", "class_decl", "$@2", "class_body",
  "acces_modifier", "var_decl", "variable_list", "fct_decl", "$@3", "$@4",
  "$@5", "$@6", "$@7", "$@8", "param_list", "param", "var_type",
  "main_body", "$@9", "$@10", "body", "statement", "fct_call", "$@11",
  "$@12", "param_called_list", "control", "$@13", "if2", "$@14", "if",
  "$@15", "$@16", "eif", "$@17", "$@18", "print_call", "expression",
  "binary_expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    59,    44,
      40,    41
};
# endif

#define YYPACT_NINF -127

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-127)))

#define YYTABLE_NINF -72

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -127,    27,    58,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,    50,  -127,  -127,    51,    55,   -38,
     -32,   126,  -127,  -127,    10,    21,  -127,    73,   -31,  -127,
      32,    33,  -127,    10,  -127,    80,    85,  -127,  -127,  -127,
    -127,    78,    42,   297,  -127,    23,    70,    53,   337,    30,
      54,    60,    10,    57,    62,    10,    10,   228,    69,  -127,
      66,  -127,  -127,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,    30,  -127,  -127,   -28,  -127,   109,  -127,
      10,   317,    10,    68,    10,   251,   274,  -127,    10,    63,
      63,    63,    63,    63,    63,   -35,   -35,  -127,  -127,  -127,
     208,   208,  -127,  -127,    30,  -127,  -127,    94,   337,  -127,
     -27,   337,  -127,   337,    75,  -127,    79,    86,  -127,   114,
    -127,    10,  -127,  -127,  -127,   111,  -127,  -127,   337,   132,
    -127,  -127,   156,  -127,    72,   180,  -127,  -127,  -127,   116,
    -127,  -127,    92,   122,   186,    10,  -127,  -127,    96,   129,
    -127,   103,  -127,   116,  -127,  -127,   206
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     0,     1,    38,    40,    39,    41,     8,    12,
       6,     5,     3,     4,     0,     2,    45,     0,     0,    25,
       0,    42,    11,    18,     0,    27,    22,     0,    75,    58,
       0,     0,    74,     0,    49,     0,     0,    44,    83,    48,
      60,     0,     0,     0,    81,     0,     0,    75,    24,     0,
       0,    23,     0,    52,     0,     0,     0,     0,    25,    43,
       0,    62,    50,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,     9,    10,    13,
      19,    20,    21,     0,    16,    17,     0,    36,     0,    32,
       0,     0,     0,     0,     0,     0,     0,    82,     0,    84,
      86,    85,    87,    89,    88,    76,    77,    78,    79,    80,
      90,    91,    14,    15,     0,    28,    37,     0,    26,    47,
       0,    57,    55,     0,    81,    73,     0,    81,    35,     0,
      33,     0,    53,    45,    51,     0,    29,    45,    56,    61,
      45,    45,    61,    59,    61,    61,    34,    63,    64,     0,
      30,    45,     0,     0,    61,     0,    67,    65,    81,     0,
      45,    61,    69,     0,    45,    72,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
       8,  -127,   -26,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
      36,     6,  -127,  -127,  -127,  -126,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,   -11,  -127,
    -127,  -127,   -24,   -93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    10,    17,    45,    11,    18,    46,    83,
      34,    20,    13,    49,   129,   141,    50,   117,   137,    86,
      87,    35,    15,    16,    36,    21,    37,    38,    92,    93,
     120,    39,    54,    40,    41,    61,   151,   149,   153,   164,
     163,    42,    43,    44
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,   124,    71,    72,    73,   127,    24,   139,    14,    57,
      12,   142,    25,    52,   144,   145,    26,    27,    47,    53,
      85,   114,   131,   115,   132,   154,     4,     3,    91,     5,
       6,    95,    96,     4,   161,    77,     5,     6,   166,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    14,    78,    84,    88,    32,   113,    19,    22,
      33,     4,   158,    23,     5,     6,   118,     7,   121,     8,
     123,     9,   -31,     4,   123,     4,     5,     6,     5,     6,
      28,    51,    55,    56,    79,    80,    81,    82,    58,    14,
      62,   112,   -66,   147,   148,    59,    60,    29,    69,    70,
      71,    72,    73,    53,    90,    89,     4,   138,   -54,     5,
       6,    28,    94,    24,    30,    31,    98,   116,    32,   122,
      88,   130,    33,   -71,   -68,   162,   133,   134,    29,     4,
     140,   123,     5,     6,    28,     4,   152,   135,     5,     6,
      28,   136,   155,   156,   -61,    30,    31,   159,   160,    32,
     128,    29,   165,    33,     0,     0,     0,    29,   143,     4,
       0,     0,     5,     6,    28,     0,     0,     0,    30,    31,
       0,     0,    32,     0,    30,    31,    33,     0,    32,     0,
       0,    29,    33,     4,   146,     0,     5,     6,    28,     4,
       0,     0,     5,     6,    28,     0,     0,     0,    30,    31,
       0,     0,    32,     0,     0,    29,    33,   157,   150,     4,
       0,    29,     5,     6,    28,     0,     0,     0,     0,     0,
       0,     0,    30,    31,     0,     0,    32,   -70,    30,    31,
      33,    29,    32,     0,     0,     0,    33,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    30,    31,
       0,     0,    32,     0,     0,     0,    33,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   125,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,     0,     0,     0,     0,    76,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
       0,     0,     0,     0,     0,   119,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75
};

static const yytype_int16 yycheck[] =
{
      24,    94,    37,    38,    39,    98,    44,   133,     2,    33,
       2,   137,    50,    44,   140,   141,    48,    49,     8,    50,
      46,    49,    49,    51,    51,   151,     3,     0,    52,     6,
       7,    55,    56,     3,   160,    12,     6,     7,   164,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    46,    45,    46,    49,    46,    83,     8,     8,
      50,     3,   155,     8,     6,     7,    90,     9,    92,    11,
      94,    13,    51,     3,    98,     3,     6,     7,     6,     7,
       8,     8,    50,    50,    14,    15,    16,    17,     8,    83,
      48,    83,    20,    21,    22,    10,    18,    25,    35,    36,
      37,    38,    39,    50,    44,    51,     3,   131,    51,     6,
       7,     8,    50,    44,    42,    43,    50,     8,    46,    51,
     114,    27,    50,    20,    21,    22,    51,    48,    25,     3,
      19,   155,     6,     7,     8,     3,    20,    51,     6,     7,
       8,    27,    50,    21,    18,    42,    43,    51,    19,    46,
     114,    25,   163,    50,    -1,    -1,    -1,    25,    26,     3,
      -1,    -1,     6,     7,     8,    -1,    -1,    -1,    42,    43,
      -1,    -1,    46,    -1,    42,    43,    50,    -1,    46,    -1,
      -1,    25,    50,     3,    28,    -1,     6,     7,     8,     3,
      -1,    -1,     6,     7,     8,    -1,    -1,    -1,    42,    43,
      -1,    -1,    46,    -1,    -1,    25,    50,    21,    28,     3,
      -1,    25,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    46,    21,    42,    43,
      50,    25,    46,    -1,    -1,    -1,    50,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    42,    43,
      -1,    -1,    46,    -1,    -1,    -1,    50,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,    54,     0,     3,     6,     7,     9,    11,    13,
      55,    58,    62,    64,    73,    74,    75,    56,    59,     8,
      63,    77,     8,     8,    44,    50,    48,    49,     8,    25,
      42,    43,    46,    50,    62,    73,    76,    78,    79,    83,
      85,    86,    93,    94,    95,    57,    60,     8,    94,    65,
      68,     8,    44,    50,    84,    50,    50,    94,     8,    10,
      18,    87,    48,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    48,    12,    62,    14,
      15,    16,    17,    61,    62,    64,    71,    72,    73,    51,
      44,    94,    80,    81,    50,    94,    94,    51,    50,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    62,    64,    49,    51,     8,    69,    94,    48,
      82,    94,    51,    94,    95,    51,    51,    95,    72,    66,
      27,    49,    51,    51,    48,    51,    27,    70,    94,    77,
      19,    67,    77,    26,    77,    77,    28,    21,    22,    89,
      28,    88,    20,    90,    77,    50,    21,    21,    95,    51,
      19,    77,    22,    92,    91,    90,    77
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    54,    54,    54,    56,    55,
      57,    57,    59,    58,    60,    60,    60,    60,    60,    61,
      61,    61,    62,    63,    63,    63,    63,    65,    66,    67,
      64,    68,    69,    70,    64,    71,    71,    72,    73,    73,
      73,    75,    76,    74,    77,    77,    78,    78,    78,    78,
      78,    78,    80,    79,    81,    79,    82,    82,    84,    83,
      83,    86,    85,    87,    88,    87,    89,    87,    90,    91,
      90,    92,    90,    93,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    95,    95,    95,    95,    95,    95,
      95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     0,     0,     5,
       2,     0,     0,     5,     3,     3,     2,     2,     0,     1,
       1,     1,     3,     3,     3,     1,     5,     0,     0,     0,
      11,     0,     0,     0,    10,     3,     1,     2,     1,     1,
       1,     0,     0,     5,     2,     0,     2,     4,     1,     1,
       2,     5,     0,     5,     0,     4,     3,     1,     0,     7,
       1,     0,     2,     7,     0,    10,     0,     9,     6,     0,
       9,     0,     8,     4,     1,     1,     3,     3,     3,     3,
       3,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 73 "homework.y" /* yacc.c:1646  */
    {printf("\nend main\n\n"); printTable(); printf("PROGRAM CORECT SINTACTIC\n"); PRINT_EVAL();}
#line 1456 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 77 "homework.y" /* yacc.c:1646  */
    {
                                strcpy(table[nrVars].scope,"global"); 
                                int j=nrVars-1;
                                while(j>=0 && strcmp(table[j].scope,"global")!=0)
                                {
                                        if(table[j].scope[0]=='\0')
                                                strcpy(table[j].scope,"global");
                                        j--;
                                }
                        }
#line 1471 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 93 "homework.y" /* yacc.c:1646  */
    {printf("structura declarata\n");}
#line 1477 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 100 "homework.y" /* yacc.c:1646  */
    {printf("clasa declarata\n");}
#line 1483 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 110 "homework.y" /* yacc.c:1646  */
    {printf("public ");}
#line 1489 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 111 "homework.y" /* yacc.c:1646  */
    {printf("private ");}
#line 1495 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 112 "homework.y" /* yacc.c:1646  */
    {printf("protected ");}
#line 1501 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 121 "homework.y" /* yacc.c:1646  */
    {
                        printf("%s%s declared\n",tab,(yyvsp[0].var).name);
                        addVarType(nrVars,table[nrVars-1].vartype);
                        addVarName(nrVars,(yyvsp[0].var).name);
                        nrVars++;
                        //strcpy(table[nrVars].vartype,table[nrVars-1].vartype);
                        //strcpy(table[nrVars++].name,$3.name); 
                }
#line 1514 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 130 "homework.y" /* yacc.c:1646  */
    {
                        printf("%s%s declared and assigned with %d\n",tab,(yyvsp[-2].var).name,(yyvsp[0].intval));
                        addVarName(nrVars,(yyvsp[-2].var).name);
                        updateTable(nrVars,(yyvsp[0].intval));
                        nrVars++;

                }
#line 1526 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 138 "homework.y" /* yacc.c:1646  */
    {
                        if(undeclared((yyvsp[0].var).name,current_scope)==-1)
                        {
                                printf("[Error][Line %d]: Variable already declared\n",yylineno);
                                exit(-1);
                        }   
                        printf("%s%s declared\n",tab,(yyvsp[0].var).name);
                        
                        addVarName(nrVars,(yyvsp[0].var).name);
                        nrVars++;
                        //strcpy(table[nrVars++].name,$1.name);
                }
#line 1543 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 151 "homework.y" /* yacc.c:1646  */
    {
                        printf("%s%s declared and assigned with %d\n",tab,(yyvsp[-2].var).name,(yyvsp[0].intval));
                        addVarName(nrVars,(yyvsp[-2].var).name);
                        addVarType(nrVars,table[nrVars-1].vartype);
                        strcpy(table[nrVars].scope,table[nrVars-1].scope);      
                        updateTable(nrVars,(yyvsp[0].intval));
                        nrVars++;
                }
#line 1556 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 161 "homework.y" /* yacc.c:1646  */
    {printf("Function %s declared! \n",(yyvsp[-1].var).name); strcat(tab,"\t");strcpy(current_scope,(yyvsp[-1].var).name);}
#line 1562 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 161 "homework.y" /* yacc.c:1646  */
    {strcpy(tab,tab+1);}
#line 1568 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 161 "homework.y" /* yacc.c:1646  */
    {strcat(tab,"\t");}
#line 1574 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 161 "homework.y" /* yacc.c:1646  */
    {strcpy(tab,tab+1);strcpy(current_scope,"global");}
#line 1580 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 162 "homework.y" /* yacc.c:1646  */
    {printf("Function %s declared! \n",(yyvsp[-1].var).name); strcat(tab,"\t");strcpy(current_scope,(yyvsp[-1].var).name);}
#line 1586 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 162 "homework.y" /* yacc.c:1646  */
    {strcpy(tab,tab+1);}
#line 1592 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 162 "homework.y" /* yacc.c:1646  */
    {strcat(tab,"\t");}
#line 1598 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 162 "homework.y" /* yacc.c:1646  */
    {strcpy(tab,tab+1);strcpy(current_scope,"global");}
#line 1604 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 170 "homework.y" /* yacc.c:1646  */
    {
        if(undeclared((yyvsp[0].var).name,current_scope)==-1)
        {
                printf("[Error][Line %d]: Variable already declared\n",yylineno);
                exit(-1);
        }   
        printf("%s parameter %s declared\n",tab,(yyvsp[0].var).name); 
        strcpy(table[nrVars].scope,current_scope);           
        addVarName(nrVars,(yyvsp[0].var).name);
        nrVars++; 
        }
#line 1620 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 184 "homework.y" /* yacc.c:1646  */
    {
                addVarType(nrVars,"int");
            }
#line 1628 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 191 "homework.y" /* yacc.c:1646  */
    {printf("\nmain\n");strcat(tab,"\t");strcpy(current_scope,"main");}
#line 1634 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 191 "homework.y" /* yacc.c:1646  */
    {strcpy(tab,tab+1);}
#line 1640 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 200 "homework.y" /* yacc.c:1646  */
    {  
                        {
                                printf("%s%s assigned with %d\n",tab,(yyvsp[-3].var).name,(yyvsp[-1].intval));
                                int j = findVar((yyvsp[-3].var).name);
                                if(j==-1)
                                        {
                                               printf("[Error][Line: %d]: variable with the name \"%s\" was not declared!\n",yylineno,(yyvsp[-3].var).name);
                                               exit(-1);
                                        } 
                                else
                                {
                                        updateTable(j,(yyvsp[-1].intval));
                                }

                        }
                }
#line 1661 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 216 "homework.y" /* yacc.c:1646  */
    {strcpy(tab,tab+1);}
#line 1667 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 217 "homework.y" /* yacc.c:1646  */
    {
                            int j=nrVars-1;      
                            strcpy(table[j].scope,current_scope); 
                         }
#line 1676 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 223 "homework.y" /* yacc.c:1646  */
    {Eval_calls[nr_calls++]=(yyvsp[-2].intval);}
#line 1682 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 226 "homework.y" /* yacc.c:1646  */
    {printf("%sFct call with parameters \n",tab);}
#line 1688 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 227 "homework.y" /* yacc.c:1646  */
    {printf("%sFct call \n",tab);}
#line 1694 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 236 "homework.y" /* yacc.c:1646  */
    {printf("%sWhile called\n",tab);strcat(tab,"\t");}
#line 1700 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 240 "homework.y" /* yacc.c:1646  */
    {printf("%sif called \n",tab); strcat(tab,"\t");}
#line 1706 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 244 "homework.y" /* yacc.c:1646  */
    {printf("%selse called \n",tab+1);}
#line 1712 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 245 "homework.y" /* yacc.c:1646  */
    {printf("%selse if called \n",tab+1);}
#line 1718 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 249 "homework.y" /* yacc.c:1646  */
    {printf("%s else called \n",tab+1);}
#line 1724 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 250 "homework.y" /* yacc.c:1646  */
    {printf("%s else if called \n",tab+1);}
#line 1730 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 253 "homework.y" /* yacc.c:1646  */
    {printf("%sprint() called \n",tab);}
#line 1736 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 257 "homework.y" /* yacc.c:1646  */
    {(yyval.intval) = (yyvsp[0].intval);}
#line 1742 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 258 "homework.y" /* yacc.c:1646  */
    { 
                   int j=findScope((yyvsp[0].var).name,current_scope);
                   if(j==-1) 
                        {
                              printf("[Error][Line: %d]: variable with the name \"%s\" was not declared!\n",yylineno,(yyvsp[0].var).name);
                              exit(-1);
                        }
                   if(strcmp(table[j].val,"NULL")==0)
                        {
                                printf("[Error][Line: %d]: variable with the name \"%s\" was not initialised!\n",yylineno,(yyvsp[0].var).name);
                                exit(-1);        
                        }
                   (yyval.intval)=atoi(table[j].val);
                   }
#line 1761 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 272 "homework.y" /* yacc.c:1646  */
    {(yyval.intval)=(yyvsp[-2].intval)+(yyvsp[0].intval);}
#line 1767 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 273 "homework.y" /* yacc.c:1646  */
    {(yyval.intval)=(yyvsp[-2].intval)-(yyvsp[0].intval);}
#line 1773 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 274 "homework.y" /* yacc.c:1646  */
    {(yyval.intval)=(yyvsp[-2].intval)*(yyvsp[0].intval);}
#line 1779 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 275 "homework.y" /* yacc.c:1646  */
    {(yyval.intval)=(yyvsp[-2].intval)/(yyvsp[0].intval);}
#line 1785 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 276 "homework.y" /* yacc.c:1646  */
    {(yyval.intval)=(yyvsp[-2].intval)%(yyvsp[0].intval);}
#line 1791 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 277 "homework.y" /* yacc.c:1646  */
    {(yyval.intval)=(yyvsp[0].intval);}
#line 1797 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 278 "homework.y" /* yacc.c:1646  */
    {(yyval.intval)=(yyvsp[-1].intval);}
#line 1803 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 279 "homework.y" /* yacc.c:1646  */
    {(yyval.intval)=atoi((yyvsp[0].var).val);}
#line 1809 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 282 "homework.y" /* yacc.c:1646  */
    {(yyval.intval)=(yyvsp[-2].intval)<(yyvsp[0].intval);}
#line 1815 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 283 "homework.y" /* yacc.c:1646  */
    {(yyval.intval)=(yyvsp[-2].intval)>(yyvsp[0].intval);}
#line 1821 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 284 "homework.y" /* yacc.c:1646  */
    {(yyval.intval)=(yyvsp[-2].intval)<=(yyvsp[0].intval);}
#line 1827 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 285 "homework.y" /* yacc.c:1646  */
    {(yyval.intval)=(yyvsp[-2].intval)>=(yyvsp[0].intval);}
#line 1833 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 286 "homework.y" /* yacc.c:1646  */
    {(yyval.intval)=(yyvsp[-2].intval)!=(yyvsp[0].intval);}
#line 1839 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 287 "homework.y" /* yacc.c:1646  */
    {(yyval.intval)=((yyvsp[-2].intval)==(yyvsp[0].intval));}
#line 1845 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 288 "homework.y" /* yacc.c:1646  */
    {(yyval.intval)=(yyvsp[-2].intval)&&(yyvsp[0].intval);}
#line 1851 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 289 "homework.y" /* yacc.c:1646  */
    {(yyval.intval)=(yyvsp[-2].intval)||(yyvsp[0].intval);  }
#line 1857 "homework.tab.c" /* yacc.c:1646  */
    break;


#line 1861 "homework.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 292 "homework.y" /* yacc.c:1906  */




int yyerror(char * s) /// Fa eroare ;
{
    printf("eroare: %s la linia:%d\n",s,yylineno);
    return 0;
}

void printTable()
{
        for(int j=0;j<nrVars;j++)
                printf("in tabel:%i %s = %s %s %s\n",j,table[j].name,table[j].val,table[j].vartype,table[j].scope); //MERGE BAAAAAAA!!!!!
}

void updateTable(int i, int newVal)
{
        sprintf(table[i].val,"%d",newVal);
}

void addVarName(int i, char * newName)
{
        strcpy(table[i].name,newName);
        strcpy(table[i].val,"NULL");
}

void addVarType(int i, char * newType)
{
        strcpy(table[i].vartype,newType);
}

int findVar(char *newName)
{
        for(int i=0;i<nrVars;i++)
        {
                if(strcmp(table[i].name,newName)==0)
                        return i;
        }
        return -1;
}

int findScope(char* newName,char* scope)
{
       for(int i=0;i<nrVars;i++)
        {
                if(strcmp(table[i].name,newName)==0&&strcmp(table[i].scope,scope)==0)
                        return i;
        }
        return -1;
}

int undeclared(char *newName,char *scope)
{
        for(int i=0;i<nrVars;i++)
        {
                if(strcmp(table[i].name,newName)==0&&strcmp(table[i].scope,scope)==0)
                        return -1;
        }
        return 0;
}

void PRINT_EVAL()
{
        for(int i=0;i<nr_calls;++i)
        {
                printf("Value of eval function for call %d:=%d\n",i+1,Eval_calls[i]);
        }
}

int main(int argc,char** argv)
{
    yyin = fopen(argv[1],"r");
    yyparse();
	exit(0);
}
