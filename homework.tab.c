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
void updateTable(int i, char* newVal);    //actualizeaza variabila de pe pozitia i cu valoarea newVal
void addVarName(int i, char * newName); //adauga pe pozitia i numele newName
void addVarType(int i, char * newType); //adauga pe pozitia i tipul newType
int findVar(char *newName);             //returneaza pozitia variabilei cu numele NewName
int undeclared(char *newName,char *scope);      //cauta in tablelul de variabile un nume si un scope 
int findScope(char* newName,char* scope);       //cam la fel da nu prea
void PRINT_EVAL();                                    //ar trebui eventual si o functie addScope care adauga scope-ul pe pozitia i
char current_scope[100]="global";
int Eval_calls[100],nr_calls=0;

struct fct_data fct_table[100];
int nrFct=0;
void printFctTable();
void addFctName(int i, char * newName);
void addFctType(int i, char * newType);
int findFct(char *newName);
int findScope(char *newName, char* scope);
char current_fct_scope[100];
char current_var_type[6];


#line 103 "homework.tab.c" /* yacc.c:339  */

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
    CALL = 299,
    ASGN = 300,
    STRVAL = 301,
    INTVAL = 302,
    BOOLVAL = 303,
    FLOATVAL = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 38 "homework.y" /* yacc.c:355  */

        int intval;
        double floatval;
        char strval[256];
        int boolval;
        struct VAR                      //structura VAR reprezinta practic o variabila ce urmeaza a fi adaugata in tabel, si are aceleasi campuri ca var_data, care descrie tabelul
        {
                char name[100];
                char val[100];          //valoare numerica convertita in char; AR FI MAI EFICIENT sa stocam totusi in camp de tip int;
                char vartype[10];
                char scope[30];
        } var;

        struct FCT
        {
                char name[100];
                char val[100];
                char fcttype[10];
                char scope[30];
                int nr_param;
                char parametersType[30][6];   //lista tipurilor la parametri => signatura;
                char parameters[30][30];      //numele parametrilor;
        } fct;

#line 218 "homework.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOMEWORK_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 235 "homework.tab.c" /* yacc.c:358  */

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
#define YYLAST   442

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

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
      52,    53,     2,     2,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    50,
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,   100,   111,   112,   113,   114,   117,   117,
     120,   121,   124,   124,   127,   128,   129,   130,   131,   134,
     135,   136,   139,   144,   153,   168,   183,   201,   203,   234,
     201,   236,   247,   247,   235,   250,   251,   254,   273,   281,
     287,   294,   301,   301,   301,   304,   305,   308,   309,   329,
     330,   337,   338,   342,   341,   354,   367,   368,   372,   372,
     373,   376,   376,   379,   380,   380,   381,   381,   384,   385,
     385,   386,   386,   389,   393,   403,   408,   416,   424,   442,
     485,   525,   557,   598,   626,   627,   628,   637,   664,   691,
     718,   745,   772,   800,   799
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
  "AND", "OR", "PRINT", "EVAL_FCT", "CALL", "ASGN", "STRVAL", "INTVAL",
  "BOOLVAL", "FLOATVAL", "';'", "','", "'('", "')'", "$accept", "program",
  "glb_declarations", "struct_decl", "$@1", "struct_body", "class_decl",
  "$@2", "class_body", "acces_modifier", "var_decl", "variable_list",
  "fct_decl", "$@3", "@4", "$@5", "@6", "$@7", "$@8", "param_list",
  "param", "var_type", "main_body", "$@9", "$@10", "body", "statement",
  "fct_call", "@11", "param_called_list", "control", "$@12", "if2", "$@13",
  "if", "$@14", "$@15", "eif", "$@16", "$@17", "print_call", "expression",
  "binary_expression", "@18", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
      59,    44,    40,    41
};
# endif

#define YYPACT_NINF -131

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-131)))

#define YYTABLE_NINF -72

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -131,     8,    14,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,    -3,  -131,  -131,     4,    11,
     -41,    39,   122,  -131,  -131,    16,   -38,  -131,    18,   -23,
    -131,   -17,   -12,    21,  -131,  -131,  -131,  -131,    16,  -131,
      34,    49,  -131,  -131,  -131,    43,    20,   334,  -131,   155,
     188,  -131,   391,   108,    13,    30,    16,    41,    16,    16,
      51,  -131,    48,    46,  -131,    55,  -131,  -131,    16,    16,
      16,    16,    16,    16,    16,    16,    16,    16,    16,    16,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,   108,  -131,  -131,
     -21,  -131,    92,  -131,    16,   356,    16,   278,   322,    63,
    -131,    16,    60,    60,    60,    60,    60,    60,    35,    35,
    -131,  -131,  -131,   391,  -131,  -131,   108,  -131,  -131,    86,
     391,  -131,   391,    65,  -131,    69,  -131,    16,    78,    16,
    -131,   105,  -131,  -131,  -131,   -15,   391,   114,   378,  -131,
    -131,   182,    16,  -131,  -131,    16,  -131,   193,  -131,   391,
     102,   403,   240,  -131,  -131,  -131,   115,  -131,  -131,    82,
     131,   251,    16,  -131,  -131,    83,   134,  -131,   135,  -131,
     115,  -131,  -131,   298
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     0,     1,    38,    41,    40,    39,    42,     8,
      12,     6,     5,     3,     4,     0,     2,    46,     0,     0,
      25,     0,    43,    11,    18,     0,    27,    22,     0,    78,
      58,     0,     0,     0,    75,    74,    76,    77,     0,    50,
       0,     0,    45,    49,    60,     0,     0,     0,    84,     0,
       0,    78,    24,     0,     0,    23,     0,     0,     0,     0,
       0,    86,     0,    25,    44,     0,    62,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     9,    10,    13,    19,    20,    21,     0,    16,    17,
       0,    36,     0,    32,     0,     0,     0,     0,     0,    53,
      85,     0,    87,    89,    88,    90,    92,    91,    79,    80,
      81,    82,    83,    93,    14,    15,     0,    28,    37,     0,
      26,    48,     0,    84,    73,     0,    55,     0,    84,     0,
      35,     0,    33,    46,    52,     0,    57,     0,     0,    29,
      46,    61,     0,    54,    46,     0,    46,    61,    59,    56,
      61,    94,    61,    34,    63,    64,     0,    30,    46,     0,
       0,    61,     0,    67,    65,    84,     0,    46,    61,    69,
       0,    46,    72,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
       7,  -131,   -48,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
      47,     5,  -131,  -131,  -131,  -130,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,     2,  -131,  -131,
    -131,   -25,   -95,  -131
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    11,    18,    49,    12,    19,    50,    87,
      39,    21,    14,    53,   131,   146,    54,   119,   140,    90,
      91,    40,    16,    17,    41,    22,    42,    61,   127,   135,
      43,    57,    44,    45,    66,   158,   156,   160,   171,   170,
      46,    47,    48,   129
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,   123,    89,   141,    25,    20,   128,    15,     3,    13,
     147,    26,    23,    62,   150,   -31,   152,     4,     5,    24,
       6,     7,    56,     8,    51,     9,    55,    10,   161,    60,
     116,    95,   117,    97,    98,    58,   142,   168,   143,   115,
      59,   173,    63,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    15,    82,    88,    92,    64,
      33,    65,    34,    35,    36,    37,    93,   165,    38,   120,
      67,   122,    76,    77,    78,    94,   122,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    27,
      28,    25,    15,    96,   114,    74,    75,    76,    77,    78,
     118,   100,   136,    99,   138,     4,     5,   101,     6,     7,
      29,     4,     5,   132,     6,     7,   126,   149,   133,   134,
     151,    92,   -66,   154,   155,     4,     5,    30,     6,     7,
      29,   137,   139,   144,   162,   159,   166,   122,     4,     5,
     -61,     6,     7,    29,    31,    32,    33,    30,    34,    35,
      36,    37,   163,   167,    38,   -71,   -68,   169,     4,     5,
      30,     6,     7,   130,    31,    32,    33,    81,    34,    35,
      36,    37,   172,     0,    38,     0,     0,    31,    32,    33,
       0,    34,    35,    36,    37,     4,     5,    38,     6,     7,
      29,     4,     5,     0,     6,     7,     4,     5,     0,     6,
       7,    29,    83,    84,    85,    86,     0,    30,   148,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,     0,
       0,   153,     0,     0,    31,    32,    33,     0,    34,    35,
      36,    37,     0,     0,    38,    31,    32,    33,     0,    34,
      35,    36,    37,     4,     5,    38,     6,     7,    29,     0,
       0,     0,     0,     0,     4,     5,     0,     6,     7,    29,
       0,     0,     0,     0,     0,    30,     0,     0,   157,     0,
       0,     0,   164,     0,     0,     0,    30,     0,     0,     0,
       0,     0,    31,    32,    33,     0,    34,    35,    36,    37,
       0,     0,    38,    31,    32,    33,     0,    34,    35,    36,
      37,     4,     5,    38,     6,     7,    29,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,   -70,
       0,     0,     0,    30,     0,     0,     0,     0,     0,     0,
       0,   124,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    32,    33,     0,    34,    35,    36,    37,     0,     0,
      38,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,   125,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,   145,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78
};

static const yytype_int16 yycheck[] =
{
      25,    96,    50,   133,    45,     8,   101,     2,     0,     2,
     140,    52,     8,    38,   144,    53,   146,     3,     4,     8,
       6,     7,    45,     9,     8,    11,     8,    13,   158,     8,
      51,    56,    53,    58,    59,    52,    51,   167,    53,    87,
      52,   171,     8,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    50,    49,    50,    53,    10,
      44,    18,    46,    47,    48,    49,    53,   162,    52,    94,
      50,    96,    37,    38,    39,    45,   101,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    50,
      51,    45,    87,    52,    87,    35,    36,    37,    38,    39,
       8,    53,   127,    52,   129,     3,     4,    52,     6,     7,
       8,     3,     4,    27,     6,     7,    53,   142,    53,    50,
     145,   116,    20,    21,    22,     3,     4,    25,     6,     7,
       8,    53,    27,    19,    52,    20,    53,   162,     3,     4,
      18,     6,     7,     8,    42,    43,    44,    25,    46,    47,
      48,    49,    21,    19,    52,    20,    21,    22,     3,     4,
      25,     6,     7,   116,    42,    43,    44,    12,    46,    47,
      48,    49,   170,    -1,    52,    -1,    -1,    42,    43,    44,
      -1,    46,    47,    48,    49,     3,     4,    52,     6,     7,
       8,     3,     4,    -1,     6,     7,     3,     4,    -1,     6,
       7,     8,    14,    15,    16,    17,    -1,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    28,    -1,    -1,    42,    43,    44,    -1,    46,    47,
      48,    49,    -1,    -1,    52,    42,    43,    44,    -1,    46,
      47,    48,    49,     3,     4,    52,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,     3,     4,    -1,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    28,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    -1,    46,    47,    48,    49,
      -1,    -1,    52,    42,    43,    44,    -1,    46,    47,    48,
      49,     3,     4,    52,     6,     7,     8,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    21,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    -1,    46,    47,    48,    49,    -1,    -1,
      52,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,    56,     0,     3,     4,     6,     7,     9,    11,
      13,    57,    60,    64,    66,    75,    76,    77,    58,    61,
       8,    65,    79,     8,     8,    45,    52,    50,    51,     8,
      25,    42,    43,    44,    46,    47,    48,    49,    52,    64,
      75,    78,    80,    84,    86,    87,    94,    95,    96,    59,
      62,     8,    95,    67,    70,     8,    45,    85,    52,    52,
       8,    81,    95,     8,    10,    18,    88,    50,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      50,    12,    64,    14,    15,    16,    17,    63,    64,    66,
      73,    74,    75,    53,    45,    95,    52,    95,    95,    52,
      53,    52,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    64,    66,    51,    53,     8,    71,
      95,    50,    95,    96,    53,    53,    53,    82,    96,    97,
      74,    68,    27,    53,    50,    83,    95,    53,    95,    27,
      72,    79,    51,    53,    19,    41,    69,    79,    26,    95,
      79,    95,    79,    28,    21,    22,    90,    28,    89,    20,
      91,    79,    52,    21,    21,    96,    53,    19,    79,    22,
      93,    92,    91,    79
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    56,    56,    58,    57,
      59,    59,    61,    60,    62,    62,    62,    62,    62,    63,
      63,    63,    64,    65,    65,    65,    65,    67,    68,    69,
      66,    70,    71,    72,    66,    73,    73,    74,    75,    75,
      75,    75,    77,    78,    76,    79,    79,    80,    80,    80,
      80,    80,    80,    82,    81,    81,    83,    83,    85,    84,
      84,    87,    86,    88,    89,    88,    90,    88,    91,    92,
      91,    93,    91,    94,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    96,    96,    96,
      96,    96,    96,    97,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     0,     0,     5,
       2,     0,     0,     5,     3,     3,     2,     2,     0,     1,
       1,     1,     3,     3,     3,     1,     5,     0,     0,     0,
      11,     0,     0,     0,    10,     3,     1,     2,     1,     1,
       1,     1,     0,     0,     5,     2,     0,     2,     4,     1,
       1,     2,     5,     0,     5,     3,     3,     1,     0,     7,
       1,     0,     2,     7,     0,    10,     0,     9,     6,     0,
       9,     0,     8,     4,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     1,     3,     2,     3,     3,     3,
       3,     3,     3,     0,     7
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
#line 97 "homework.y" /* yacc.c:1646  */
    {printf("\nend main\n\n"); printTable(); printf("\n"); printFctTable(); printf("\n"); printf("PROGRAM CORECT SINTACTIC\n"); PRINT_EVAL();}
#line 1496 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 101 "homework.y" /* yacc.c:1646  */
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
#line 1511 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 117 "homework.y" /* yacc.c:1646  */
    {printf("structura declarata\n");}
#line 1517 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 124 "homework.y" /* yacc.c:1646  */
    {printf("clasa declarata\n");}
#line 1523 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 134 "homework.y" /* yacc.c:1646  */
    {printf("public ");}
#line 1529 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 135 "homework.y" /* yacc.c:1646  */
    {printf("private ");}
#line 1535 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 136 "homework.y" /* yacc.c:1646  */
    {printf("protected ");}
#line 1541 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 145 "homework.y" /* yacc.c:1646  */
    {
                        printf("%s%s declared\n",tab,(yyvsp[0].var).name);
                        addVarType(nrVars,table[nrVars-1].vartype);
                        addVarName(nrVars,(yyvsp[0].var).name);
                        nrVars++;
                        //strcpy(table[nrVars].vartype,table[nrVars-1].vartype);
                        //strcpy(table[nrVars++].name,$3.name); 
                }
#line 1554 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 154 "homework.y" /* yacc.c:1646  */
    {
                        addVarType(nrVars,current_var_type);
                        strcpy((yyvsp[-2].var).vartype,current_var_type);
                        if(strcmp((yyvsp[-2].var).vartype,(yyvsp[0].var).vartype)!=0)
                        {
                                printf("[Error][Line %d]: Assignment between two different types: %s != %s\n",yylineno,(yyvsp[-2].var).vartype,(yyvsp[0].var).vartype);
                                exit(-1);
                        }
                        printf("%s%s declared and assigned with %s\n",tab,(yyvsp[-2].var).name,(yyvsp[0].var).val);
                        addVarName(nrVars,(yyvsp[-2].var).name);
                        updateTable(nrVars,(yyvsp[0].var).val);
                        nrVars++;

                }
#line 1573 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 169 "homework.y" /* yacc.c:1646  */
    {
                         addVarType(nrVars,current_var_type);
                        strcpy((yyvsp[0].var).vartype,current_var_type);
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
#line 1592 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 184 "homework.y" /* yacc.c:1646  */
    {
                        strcpy((yyvsp[-2].var).vartype,current_var_type);
                        
                        if(strcmp((yyvsp[-2].var).vartype,(yyvsp[0].var).vartype)!=0)
                        {
                                printf("[Error][Line %d]: Assignment between two different types: %s != %s\n",yylineno,(yyvsp[-2].var).vartype,(yyvsp[0].var).vartype);
                                exit(-1);
                        }
                        printf("%s%s declared and assigned with %s\n",tab,(yyvsp[-2].var).name,(yyvsp[0].var).val);
                        addVarName(nrVars,(yyvsp[-2].var).name);
                        addVarType(nrVars,table[nrVars-1].vartype);
                        strcpy(table[nrVars].scope,table[nrVars-1].scope);      
                        updateTable(nrVars,(yyvsp[0].var).val);
                        nrVars++;
                }
#line 1612 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 201 "homework.y" /* yacc.c:1646  */
    {strcat(tab,"\t"); strcpy(current_fct_scope,current_scope);strcpy(current_scope,(yyvsp[-1].var).name);}
#line 1618 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 203 "homework.y" /* yacc.c:1646  */
    {
                        strcpy(tab,tab+1);
                        strcpy((yyval.fct).name, (yyvsp[-4].var).name);
                        strcpy((yyval.fct).fcttype,(yyvsp[-5].var).vartype);
                        addFctName(nrFct,(yyvsp[-4].var).name);
                        addFctType(nrFct,(yyvsp[-5].var).vartype);
                        strcpy(fct_table[nrFct].scope,current_fct_scope);

                        int j = findFct((yyvsp[-4].var).name);
                        if(j!=nrFct)
                        {
                                if(fct_table[j].nr_param == fct_table[nrFct].nr_param)
                                {
                                        int ok=0;
                                        for(int i=0;i<fct_table[j].nr_param;i++)
                                        {
                                                if(strcmp(fct_table[j].parametersType[i],fct_table[nrFct].parametersType[i])!=0)
                                                {
                                                        ok=1;//gasit
                                                        break;
                                                }
                                        }
                                        if(ok==0)
                                        {
                                                printf("[Error][Line: %d] Function with the same signature alerady declared;\n",yylineno);\
                                                exit(-1);
                                        }
                                }
                        }
                        printf("Function %s declared! \n",(yyvsp[-4].var).name);                        
                        nrFct++;
                }
#line 1655 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 234 "homework.y" /* yacc.c:1646  */
    {strcat(tab,"\t");}
#line 1661 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 234 "homework.y" /* yacc.c:1646  */
    {strcpy(tab,tab+1);strcpy(current_scope,"global");}
#line 1667 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 236 "homework.y" /* yacc.c:1646  */
    {
                        printf("Function %s declared! \n",(yyvsp[-1].var).name); 
                        strcpy((yyval.fct).name, (yyvsp[-1].var).name);
                        strcpy((yyval.fct).fcttype,(yyvsp[-2].var).vartype);
                        strcat(tab,"\t");
                        
                        addFctName(nrFct,(yyvsp[-1].var).name);
                        addFctType(nrFct,(yyvsp[-2].var).vartype);
                        strcpy(fct_table[nrFct].scope,current_scope);
                        strcat(tab,"\t");strcpy(current_scope,(yyvsp[-1].var).name);
                }
#line 1683 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 247 "homework.y" /* yacc.c:1646  */
    {strcpy(tab,tab+1);nrFct++;}
#line 1689 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 247 "homework.y" /* yacc.c:1646  */
    {strcat(tab,"\t");}
#line 1695 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 247 "homework.y" /* yacc.c:1646  */
    {strcpy(tab,tab+1);strcpy(current_scope,"global");}
#line 1701 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 255 "homework.y" /* yacc.c:1646  */
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

                strcpy(fct_table[nrFct].parameters[fct_table[nrFct].nr_param],(yyvsp[0].var).name);
                strcpy(fct_table[nrFct].parametersType[fct_table[nrFct].nr_param],(yyvsp[-1].var).vartype);
                fct_table[nrFct].nr_param++;
                
        }
#line 1722 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 274 "homework.y" /* yacc.c:1646  */
    {
               
                addVarType(nrVars,"int");
                strcpy((yyval.var).vartype, "int");
                strcpy(current_var_type, "int");
            }
#line 1733 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 282 "homework.y" /* yacc.c:1646  */
    {
                strcpy((yyval.var).vartype, "bool");
                strcpy(current_var_type, "bool");
            }
#line 1742 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 288 "homework.y" /* yacc.c:1646  */
    {
                strcpy((yyval.var).vartype, "string");
                strcpy(current_var_type, "string");

            }
#line 1752 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 295 "homework.y" /* yacc.c:1646  */
    {
                strcpy((yyval.var).vartype, "float");
                strcpy(current_var_type, "float");
            }
#line 1761 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 301 "homework.y" /* yacc.c:1646  */
    {printf("\nmain\n");strcat(tab,"\t");strcpy(current_scope,"main");}
#line 1767 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 301 "homework.y" /* yacc.c:1646  */
    {strcpy(tab,tab+1);}
#line 1773 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 310 "homework.y" /* yacc.c:1646  */
    {  
                        int j = findScope((yyvsp[-3].var).name,current_scope);
                        if(j==-1)
                        {
                                printf("[Error][Line: %d]: variable with the name \"%s\" was not declared!\n",yylineno,(yyvsp[-3].var).name);
                                exit(-1);
                        } 
                        else
                        {
                                updateTable(j,(yyvsp[-1].var).val);
                        }
                        if(strcmp(table[j].vartype,(yyvsp[-1].var).vartype)!=0)
                        {
                                printf("[Error][Line %d]: Assignment between two different types: %s != %s\n",yylineno,table[j].vartype,(yyvsp[-1].var).vartype);
                                exit(-1);
                        }
                        printf("%s%s assigned with %s\n",tab,(yyvsp[-3].var).name,(yyvsp[-1].var).val);

                }
#line 1797 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 329 "homework.y" /* yacc.c:1646  */
    {strcpy(tab,tab+1);}
#line 1803 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 330 "homework.y" /* yacc.c:1646  */
    {
                     
                            int j=nrVars-1;      
                            strcpy(table[j].scope,current_scope); 
                            
                         }
#line 1814 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 338 "homework.y" /* yacc.c:1646  */
    {Eval_calls[nr_calls++]=atoi((yyvsp[-2].var).val);}
#line 1820 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 342 "homework.y" /* yacc.c:1646  */
    {
                int j = findFct((yyvsp[-1].var).name);
                if(j==-1)
                {
                        printf("[Error][Line: %d]: Function with name \"%s\" is not neclared!\n",yylineno,(yyvsp[-1].var).name);
                        exit(-1);
                }

                printf("%sFct call with parameters \n",tab);
                strcpy((yyval.var).vartype,fct_table[j].fcttype);
         }
#line 1836 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 355 "homework.y" /* yacc.c:1646  */
    {
                int j = findFct((yyvsp[-2].var).name);
                if(j==-1)
                {
                        printf("[Error][Line: %d]: Function with name \"%s\" is not neclared!\n",yylineno,(yyvsp[-2].var).name);
                        exit(-1);
                }
                 printf("%sFct call \n",tab);
         }
#line 1850 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 372 "homework.y" /* yacc.c:1646  */
    {printf("%sWhile called\n",tab);strcat(tab,"\t");}
#line 1856 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 376 "homework.y" /* yacc.c:1646  */
    {printf("%sif called \n",tab); strcat(tab,"\t");}
#line 1862 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 380 "homework.y" /* yacc.c:1646  */
    {printf("%selse called \n",tab+1);}
#line 1868 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 381 "homework.y" /* yacc.c:1646  */
    {printf("%selse if called \n",tab+1);}
#line 1874 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 385 "homework.y" /* yacc.c:1646  */
    {printf("%s else called \n",tab+1);}
#line 1880 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 386 "homework.y" /* yacc.c:1646  */
    {printf("%s else if called \n",tab+1);}
#line 1886 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 389 "homework.y" /* yacc.c:1646  */
    {printf("%sprint() called \n",tab);}
#line 1892 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 394 "homework.y" /* yacc.c:1646  */
    {
                   
                char buffer[20];
                sprintf(buffer,"%d",(yyvsp[0].intval));
                strcpy((yyval.var).val,buffer);
                //$$ = $1;
                strcpy((yyval.var).vartype,"int");
           }
#line 1905 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 404 "homework.y" /* yacc.c:1646  */
    {  
                strcpy((yyval.var).val,(yyvsp[0].strval));
                strcpy((yyval.var).vartype,"string");
           }
#line 1914 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 409 "homework.y" /* yacc.c:1646  */
    {
               char buffer[20];
                sprintf(buffer,"%d",(yyvsp[0].boolval));
                strcpy((yyval.var).val,buffer);
                //$$ = $1;
                strcpy((yyval.var).vartype,"bool");    
           }
#line 1926 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 417 "homework.y" /* yacc.c:1646  */
    {
                   char buffer[20];
                   sprintf(buffer,"%f",(yyvsp[0].floatval));
                    strcpy((yyval.var).val,buffer);
                //$$ = $1;
                strcpy((yyval.var).vartype,"float"); 
           }
#line 1938 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 425 "homework.y" /* yacc.c:1646  */
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
                //$$=atoi(table[j].val);
                strcpy((yyval.var).val,table[j].val);
                strcpy((yyval.var).vartype,table[j].vartype);
           }
#line 1960 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 443 "homework.y" /* yacc.c:1646  */
    {
                if(strcmp((yyvsp[-2].var).vartype,(yyvsp[0].var).vartype)!=0)
                {
                        printf("[Error][Line %d]: %s + %s is not possible!\n",yylineno,(yyvsp[-2].var).vartype,(yyvsp[0].var).vartype);      
                        exit(-1);
                }
                strcpy((yyval.var).vartype,(yyvsp[-2].var).vartype);
                if(strcmp((yyval.var).vartype,"int")==0 )
                {
                        int op1=atoi((yyvsp[-2].var).val);
                        int op2=atoi((yyvsp[0].var).val);
                        char buffer[20];
                        sprintf(buffer,"%d",op1+op2);
                        strcpy((yyval.var).val,buffer);
                        //$$=$1+$3;
                }
                else if(strcmp((yyval.var).vartype,"float")==0)
                {
                        float op1=atof((yyvsp[-2].var).val);
                        float op2=atof((yyvsp[0].var).val);
                        char buffer[20];
                        sprintf(buffer,"%f",op1+op2);
                        strcpy((yyval.var).val,buffer);
                        //$$=$1+$3;
                }
                else if(strcmp((yyval.var).vartype,"bool")==0)
                {
                        int op1=atoi((yyvsp[-2].var).val);
                        int op2=atoi((yyvsp[0].var).val);
                        char buffer[20];
                        sprintf(buffer,"%d",(op1+op2)%2);
                        strcpy((yyval.var).val,buffer);
                }
                else if(strcmp((yyval.var).vartype,"string")==0)
                {
                        char buffer[200];
                        strcpy(buffer,(yyvsp[-2].var).val);
                        strcat(buffer,(yyvsp[0].var).val);
                        strcpy((yyval.var).val,buffer);
                }

           }
#line 2007 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 486 "homework.y" /* yacc.c:1646  */
    {
                if(strcmp((yyvsp[-2].var).vartype,(yyvsp[0].var).vartype)!=0)
                {
                        printf("[Error][Line %d]: %s - %s is not possible!\n",yylineno,(yyvsp[-2].var).vartype,(yyvsp[0].var).vartype);      
                        exit(-1);
                }
                strcpy((yyval.var).vartype,(yyvsp[-2].var).vartype);
                if(strcmp((yyval.var).vartype,"int")==0 )      
                {
                        int op1=atoi((yyvsp[-2].var).val);
                        int op2=atoi((yyvsp[0].var).val);
                        char buffer[20];
                        sprintf(buffer,"%d",op1-op2);
                        strcpy((yyval.var).val,buffer);
                }
                else if(strcmp((yyval.var).vartype,"float")==0)
                {
                        float op1=atof((yyvsp[-2].var).val);
                        float op2=atof((yyvsp[0].var).val);
                        char buffer[20];
                        sprintf(buffer,"%f",op1-op2);
                        strcpy((yyval.var).val,buffer);
                        //$$=$1+$3;
                }
                else if(strcmp((yyval.var).vartype,"bool")==0)      
                {
                        int op1=atoi((yyvsp[-2].var).val);
                        int op2=atoi((yyvsp[0].var).val);
                        char buffer[20];
                        sprintf(buffer,"%d",(op1-op2)%2);
                        strcpy((yyval.var).val,buffer);
                }
                else
                {
                        printf("Error][Line %d]: string - string is not possible!\n",yylineno);
                        exit(-1);
                }
                //$$=$1-$3;
           }
#line 2051 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 526 "homework.y" /* yacc.c:1646  */
    {
                if(strcmp((yyvsp[-2].var).vartype,(yyvsp[0].var).vartype)!=0)
                {
                        printf("[Error][Line %d]: %s * %s is not possible!\n",yylineno,(yyvsp[-2].var).vartype,(yyvsp[0].var).vartype);      
                        exit(-1);
                }
                strcpy((yyval.var).vartype,(yyvsp[-2].var).vartype);
                if(strcmp((yyval.var).vartype,"string")!=0&&strcmp((yyval.var).vartype,"float")!=0)      //daca nu e string e float, int sau bool;
                {
                                printf("CUC\n");
                        int op1=atoi((yyvsp[-2].var).val);
                        int op2=atoi((yyvsp[0].var).val);
                        char buffer[20];
                        sprintf(buffer,"%f",op1*op2);
                        strcpy((yyval.var).val,buffer);
                }
                else if(strcmp((yyval.var).vartype,"float")==0)
                {
                        float op1=atof((yyvsp[-2].var).val);
                        float op2=atof((yyvsp[0].var).val);
                        char buffer[20];
                        sprintf(buffer,"%f",op1*op2);
                        strcpy((yyval.var).val,buffer);
                        //$$=$1+$3;
                }
                else            //putem implementa * ca + in c (str+3 de la pozitia 3)
                {
                        printf("Error][Line %d]: string * string is not possible!\n",yylineno);
                        exit(-1);
                }
           }
#line 2087 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 558 "homework.y" /* yacc.c:1646  */
    {
                if(strcmp((yyvsp[-2].var).vartype,(yyvsp[0].var).vartype)!=0)
                {
                        printf("[Error][Line %d]: %s / %s is not possible!\n",yylineno,(yyvsp[-2].var).vartype,(yyvsp[0].var).vartype);      
                        exit(-1);
                }
                strcpy((yyval.var).vartype,(yyvsp[-2].var).vartype);
                if(strcmp((yyval.var).vartype,"int")==0 || strcmp((yyval.var).vartype,"float")==0 )      //daca nu e string e float, int sau bool;
                {
                        if(strcmp((yyval.var).vartype,"int")==0)
                       { int op1=atoi((yyvsp[-2].var).val);
                        int op2=atoi((yyvsp[0].var).val);
                        if(op2==0)
                        {
                                printf("[Error][Line %d]: division by 0 is not possible!\n",yylineno);
                                exit(-1);
                        }
                        char buffer[20];
                        sprintf(buffer,"%d",op1/op2);
                        strcpy((yyval.var).val,buffer);
                       }
                        if(strcmp((yyval.var).vartype,"float")==0)
                       { float op1=atof((yyvsp[-2].var).val);
                         float op2=atof((yyvsp[0].var).val);
                        if(op2==0)
                        {
                                printf("[Error][Line %d]: division by 0 is not possible!\n",yylineno);
                                exit(-1);
                        }
                        char buffer[20];
                        sprintf(buffer,"%f",(float)op1/op2);
                        strcpy((yyval.var).val,buffer);
                       }
                }
                else           
                {
                        printf("[Error][Line %d]: %s / %s is not possible!\n",yylineno,(yyvsp[-2].var).vartype,(yyvsp[0].var).vartype);
                        exit(-1);
                }
           }
#line 2132 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 599 "homework.y" /* yacc.c:1646  */
    {
                
                if(strcmp((yyvsp[-2].var).vartype,(yyvsp[0].var).vartype)!=0)
                {
                        printf("[Error][Line %d]: %s % %s is not possible!\n",yylineno,(yyvsp[-2].var).vartype,(yyvsp[0].var).vartype);      
                        exit(-1);
                }
                strcpy((yyval.var).vartype,(yyvsp[-2].var).vartype);
                if(strcmp((yyval.var).vartype,"int")==0)      
                {
                        int op1=atoi((yyvsp[-2].var).val);
                        int op2=atoi((yyvsp[0].var).val);
                        if(op2==0)
                        {
                                printf("[Error][Line %d]: modulus by 0 is not possible!\n",yylineno);
                                exit(-1);
                        }
                        char buffer[20];
                        sprintf(buffer,"%d",op1%op2);
                        strcpy((yyval.var).val,buffer);
                }
                else            
                {
                        printf("[Error][Line %d]: %s % %s is not possible!\n",yylineno,(yyvsp[-2].var).vartype,(yyvsp[0].var).vartype);
                        exit(-1);
                }
           }
#line 2164 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 626 "homework.y" /* yacc.c:1646  */
    {strcpy((yyval.var).val,(yyvsp[0].var).val);strcpy((yyval.var).vartype,"int");}
#line 2170 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 627 "homework.y" /* yacc.c:1646  */
    {(yyval.var)=(yyvsp[-1].var);}
#line 2176 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 629 "homework.y" /* yacc.c:1646  */
    {
                   int j = findFct((yyvsp[0].var).name);
                   strcpy((yyval.var).val,(yyvsp[0].var).val);
                   strcpy((yyval.var).vartype,fct_table[j].fcttype);
          }
#line 2186 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 638 "homework.y" /* yacc.c:1646  */
    {
                        if(strcmp((yyvsp[-2].var).vartype,(yyvsp[0].var).vartype)!=0)
                        {
                                printf("[Error][Line %d]: %s % %s is not possible!\n",yylineno,(yyvsp[-2].var).vartype,(yyvsp[0].var).vartype);      
                                exit(-1);
                        }
                        if(strcmp((yyval.var).vartype,"string")!=0)      //inf float bool
                        {
                                int op1=atoi((yyvsp[-2].var).val);
                                int op2=atoi((yyvsp[0].var).val);
                                char buffer[2];
                                sprintf(buffer,"%d",op1<op2);
                                strcpy((yyval.var).val,buffer);
                        }
                        else
                        {
                                char buffer[2];
                                int rez;
                                if(strcmp((yyvsp[-2].var).val,(yyvsp[0].var).val)<0)
                                        rez=1;
                                else    rez=0;
                                sprintf(buffer,"%d",rez);
                                strcpy((yyval.var).val,buffer);
                        }
                        //$$=$1<$3;
                }
#line 2217 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 665 "homework.y" /* yacc.c:1646  */
    {
                        if(strcmp((yyvsp[-2].var).vartype,(yyvsp[0].var).vartype)!=0)
                        {
                                printf("[Error][Line %d]: %s % %s is not possible!\n",yylineno,(yyvsp[-2].var).vartype,(yyvsp[0].var).vartype);      
                                exit(-1);
                        }
                        if(strcmp((yyval.var).vartype,"string")!=0)      //inf float bool
                        {
                                int op1=atoi((yyvsp[-2].var).val);
                                int op2=atoi((yyvsp[0].var).val);
                                char buffer[2];
                                sprintf(buffer,"%d",op1>op2);
                                strcpy((yyval.var).val,buffer);
                        }
                        else
                        {
                                char buffer[2];
                                int rez;
                                if(strcmp((yyvsp[-2].var).val,(yyvsp[0].var).val)>0)
                                        rez=1;
                                else    rez=0;
                                sprintf(buffer,"%d",rez);
                                strcpy((yyval.var).val,buffer);
                        }
                        //$$=$1>$3;
                }
#line 2248 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 692 "homework.y" /* yacc.c:1646  */
    {
                        if(strcmp((yyvsp[-2].var).vartype,(yyvsp[0].var).vartype)!=0)
                        {
                                printf("[Error][Line %d]: %s % %s is not possible!\n",yylineno,(yyvsp[-2].var).vartype,(yyvsp[0].var).vartype);      
                                exit(-1);
                        }
                        if(strcmp((yyval.var).vartype,"string")!=0)      //inf float bool
                        {
                                int op1=atoi((yyvsp[-2].var).val);
                                int op2=atoi((yyvsp[0].var).val);
                                char buffer[2];
                                sprintf(buffer,"%d",op1<=op2);
                                strcpy((yyval.var).val,buffer);
                        }
                        else
                        {
                                char buffer[2];
                                int rez;
                                if(strcmp((yyvsp[-2].var).val,(yyvsp[0].var).val)<=0)
                                        rez=1;
                                else    rez=0;
                                sprintf(buffer,"%d",rez);
                                strcpy((yyval.var).val,buffer);
                        }
                        //$$=$1<=$3;
                }
#line 2279 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 719 "homework.y" /* yacc.c:1646  */
    {
                        if(strcmp((yyvsp[-2].var).vartype,(yyvsp[0].var).vartype)!=0)
                        {
                                printf("[Error][Line %d]: %s % %s is not possible!\n",yylineno,(yyvsp[-2].var).vartype,(yyvsp[0].var).vartype);      
                                exit(-1);
                        }
                        if(strcmp((yyval.var).vartype,"string")!=0)      //inf float bool
                        {
                                int op1=atoi((yyvsp[-2].var).val);
                                int op2=atoi((yyvsp[0].var).val);
                                char buffer[2];
                                sprintf(buffer,"%d",op1>=op2);
                                strcpy((yyval.var).val,buffer);
                        }
                        else
                        {
                                char buffer[2];
                                int rez;
                                if(strcmp((yyvsp[-2].var).val,(yyvsp[0].var).val)>=0)
                                        rez=1;
                                else    rez=0;
                                sprintf(buffer,"%d",rez);
                                strcpy((yyval.var).val,buffer);
                        }
                        //$$=$1>=$3;
                }
#line 2310 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 746 "homework.y" /* yacc.c:1646  */
    {
                        if(strcmp((yyvsp[-2].var).vartype,(yyvsp[0].var).vartype)!=0)
                        {
                                printf("[Error][Line %d]: %s % %s is not possible!\n",yylineno,(yyvsp[-2].var).vartype,(yyvsp[0].var).vartype);      
                                exit(-1);
                        }
                        if(strcmp((yyval.var).vartype,"string")!=0)      //inf float bool
                        {
                                int op1=atoi((yyvsp[-2].var).val);
                                int op2=atoi((yyvsp[0].var).val);
                                char buffer[2];
                                sprintf(buffer,"%d",op1!=op2);
                                strcpy((yyval.var).val,buffer);
                        }
                        else
                        {
                                char buffer[2];
                                int rez;
                                if(strcmp((yyvsp[-2].var).val,(yyvsp[0].var).val)!=0)
                                        rez=1;
                                else    rez=0;
                                sprintf(buffer,"%d",rez);
                                strcpy((yyval.var).val,buffer);
                        }
                        //$$=$1!=$3;
                }
#line 2341 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 773 "homework.y" /* yacc.c:1646  */
    {
                        if(strcmp((yyvsp[-2].var).vartype,(yyvsp[0].var).vartype)!=0)
                        {
                                printf("[Error][Line %d]: %s % %s is not possible!\n",yylineno,(yyvsp[-2].var).vartype,(yyvsp[0].var).vartype);      
                                exit(-1);
                        }
                        if(strcmp((yyval.var).vartype,"string")!=0)      //inf float bool
                        {
                                int op1=atoi((yyvsp[-2].var).val);
                                int op2=atoi((yyvsp[0].var).val);
                                char buffer[2];
                                sprintf(buffer,"%d",op1=op2);
                                strcpy((yyval.var).val,buffer);
                        }
                        else
                        {
                                char buffer[2];
                                int rez;
                                if(strcmp((yyvsp[-2].var).val,(yyvsp[0].var).val)==0)
                                        rez=1;
                                else    rez=0;
                                sprintf(buffer,"%d",rez);
                                strcpy((yyval.var).val,buffer);
                        }
                        //$$=($1==$3);
                }
#line 2372 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 800 "homework.y" /* yacc.c:1646  */
    {
                        int op1=atoi((yyvsp[-2].var).val);
                        if(op1==0)
                                strcpy((yyval.var).val,"0");
                        else 
                        {
                                int op2=atoi((yyvsp[0].var).val);
                                if(op2==0)
                                        strcpy((yyval.var).val,"0");
                                else
                                        strcpy((yyval.var).val,"1");

                        }
                        //$$=$1&&$3;
                }
#line 2392 "homework.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 816 "homework.y" /* yacc.c:1646  */
    {
                        int op1=atoi((yyvsp[-6].var).val);
                        if(op1==1)
                                strcpy((yyval.var).val,"1");
                        else
                        {
                                int op2=atoi((yyvsp[-4].var).val);
                                if(op2==0)
                                        strcpy((yyval.var).val,"0");
                                else
                                        strcpy((yyval.var).val,"1");
                                strcpy((yyval.var).val,(yyvsp[-4].var).val);
                        }
                        //$$=$1||$3;  
                }
#line 2412 "homework.tab.c" /* yacc.c:1646  */
    break;


#line 2416 "homework.tab.c" /* yacc.c:1646  */
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
#line 833 "homework.y" /* yacc.c:1906  */




int yyerror(char * s) /// Fa eroare ;
{
    printf("eroare: %s la linia:%d\n",s,yylineno);
    return 0;
}

void printTable()
{
        printf("Tabel variabile: \n");
        for(int j=0;j<nrVars;j++)
                printf("%i. %s = %s %s %s\n",j,table[j].name,table[j].val,table[j].vartype,table[j].scope); //MERGE BAAAAAAA!!!!!
}

void updateTable(int i, char* newVal)
{

        strcpy(table[i].val,newVal);
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
        for(int i=0;i<nrVars;i++)
        {
                if(strcmp(table[i].name,newName)==0&&strcmp(table[i].scope,"global")==0)
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

void printFctTable()
{
        printf("Tabel functii: \n");
        for(int i=0;i<nrFct;i++)
        {
                printf("%s %s %s (",fct_table[i].name,fct_table[i].fcttype,fct_table[i].scope);
                for(int j=0;j<fct_table[i].nr_param-1;j++)
                        printf("%s %s, ",fct_table[i].parametersType[j],fct_table[i].parameters[j]);
                printf("%s %s",fct_table[i].parametersType[fct_table[i].nr_param-1],fct_table[i].parameters[fct_table[i].nr_param-1]);
                printf(")\n");
        }
}

void addFctName(int i, char * newName)
{
        strcpy(fct_table[i].name,newName);
}

void addFctType(int i, char * newType)
{
        strcpy(fct_table[i].fcttype,newType);
}

int findFct(char *newName)
{
        for(int i=0;i<nrFct;i++)
                if(strcmp(fct_table[i].name,newName)==0)
                        return i;
        return -1;
}

int findfctScope(char *newName, char* scope)
{
        for(int i=0;i<nrFct;i++)
                if(strcmp(fct_table[i].name,newName)==0 && strcmp(fct_table[i].scope,scope)==0)
                        return i;
        return -1;
}

int main(int argc,char** argv)
{
    yyin = fopen(argv[1],"r");
    yyparse();
	exit(0);
}
