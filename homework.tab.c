/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "homework.y"

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


#line 105 "homework.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 36 "homework.y"

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

        struct FCT
        {
                char name[100];
                char val[100];
                char fcttype[6];
                char scope[30];
                int nr_param;
                char parametersType[30][6];   //lista tipurilor la parametri => signatura;
                char parameters[30][30];      //numele parametrilor;
        } fct;

#line 230 "homework.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOMEWORK_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   393

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

#define YYUNDEFTOK  2
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
static const yytype_int16 yyrline[] =
{
       0,    93,    93,    96,   107,   108,   109,   110,   113,   113,
     116,   117,   120,   120,   123,   124,   125,   126,   127,   130,
     131,   132,   135,   140,   149,   157,   170,   181,   183,   214,
     181,   216,   227,   227,   215,   230,   231,   234,   253,   258,
     262,   266,   272,   272,   272,   275,   276,   279,   280,   297,
     298,   303,   304,   307,   307,   308,   308,   312,   313,   317,
     317,   318,   321,   321,   324,   325,   325,   326,   326,   329,
     330,   330,   331,   331,   334,   338,   339,   353,   354,   355,
     356,   357,   358,   359,   360,   363,   364,   365,   366,   367,
     368,   369,   370
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
  "acces_modifier", "var_decl", "variable_list", "fct_decl", "$@3", "@4",
  "$@5", "@6", "$@7", "$@8", "param_list", "param", "var_type",
  "main_body", "$@9", "$@10", "body", "statement", "fct_call", "$@11",
  "$@12", "param_called_list", "control", "$@13", "if2", "$@14", "if",
  "$@15", "$@16", "eif", "$@17", "$@18", "print_call", "expression",
  "binary_expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    59,    44,
      40,    41
};
# endif

#define YYPACT_NINF (-129)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-73)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -129,    11,   213,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,     7,  -129,  -129,    17,    19,
     -42,   -45,   129,  -129,  -129,     8,   -32,  -129,    22,   -15,
    -129,   -28,   -16,  -129,     8,  -129,    45,    49,  -129,  -129,
    -129,  -129,    43,    23,   293,  -129,    14,   352,    27,   341,
      69,    29,    40,     8,    34,    36,     8,     8,   224,    54,
    -129,    51,  -129,  -129,     8,     8,     8,     8,     8,     8,
       8,     8,     8,     8,     8,     8,     8,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,    69,  -129,  -129,   -13,  -129,    85,
    -129,     8,   313,     8,    48,     8,   247,   270,  -129,     8,
      76,    76,    76,    76,    76,    76,    26,    26,  -129,  -129,
    -129,   354,   354,  -129,  -129,    69,  -129,  -129,    81,   341,
    -129,    18,   341,  -129,   341,    52,  -129,    62,    65,  -129,
      92,  -129,     8,  -129,  -129,  -129,    83,  -129,  -129,   341,
     135,  -129,  -129,   145,  -129,    75,   161,  -129,  -129,  -129,
     102,  -129,  -129,    73,   103,   193,     8,  -129,  -129,    77,
     110,  -129,    84,  -129,   102,  -129,  -129,   202
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       7,     0,     0,     1,    38,    41,    40,    39,    42,     8,
      12,     6,     5,     3,     4,     0,     2,    46,     0,     0,
      25,     0,    43,    11,    18,     0,    27,    22,     0,    76,
      59,     0,     0,    75,     0,    50,     0,     0,    45,    84,
      49,    61,     0,     0,     0,    82,     0,     0,    76,    24,
       0,     0,    23,     0,    53,     0,     0,     0,     0,    25,
      44,     0,    63,    51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,     9,    10,
      13,    19,    20,    21,     0,    16,    17,     0,    36,     0,
      32,     0,     0,     0,     0,     0,     0,     0,    83,     0,
      85,    87,    86,    88,    90,    89,    77,    78,    79,    80,
      81,    91,    92,    14,    15,     0,    28,    37,     0,    26,
      48,     0,    58,    56,     0,    82,    74,     0,    82,    35,
       0,    33,     0,    54,    46,    52,     0,    29,    46,    57,
      62,    46,    46,    62,    60,    62,    62,    34,    64,    65,
       0,    30,    46,     0,     0,    62,     0,    68,    66,    82,
       0,    46,    62,    70,     0,    46,    73,    62
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
      10,  -129,   -24,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
      25,     5,  -129,  -129,  -129,  -128,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,   -20,  -129,
    -129,  -129,   -25,   -94
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    11,    18,    46,    12,    19,    47,    84,
      35,    21,    14,    50,   130,   142,    51,   118,   138,    87,
      88,    36,    16,    17,    37,    22,    38,    39,    93,    94,
     121,    40,    55,    41,    42,    62,   152,   150,   154,   165,
     164,    43,    44,    45
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,   125,    25,    27,    28,   128,   140,    15,    26,    58,
     143,     3,    13,   145,   146,    20,    48,     4,     5,   -31,
       6,     7,    56,    86,   155,    23,    78,    24,    92,    53,
      52,    96,    97,   162,    57,    54,   115,   167,   116,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,    15,    59,    33,    89,    79,    85,    34,    60,
     114,    61,   159,    72,    73,    74,   119,   132,   122,   133,
     124,    63,     4,     5,   124,     6,     7,    54,     4,     5,
      90,     6,     7,    29,    91,   -55,    95,     4,     5,    15,
       6,     7,    29,   117,   113,   -67,   148,   149,    25,   123,
      30,    99,   141,   134,   -72,   -69,   163,   139,   131,    30,
     135,    70,    71,    72,    73,    74,   136,    31,    32,   137,
      89,    33,   153,   156,   157,    34,    31,    32,   160,   161,
      33,   124,     4,     5,    34,     6,     7,    29,     4,     5,
     129,     6,     7,    29,   166,     0,     0,   -62,     4,     5,
       0,     6,     7,    29,    30,     0,     0,     0,     0,     0,
      30,   144,     0,     0,     4,     5,     0,     6,     7,    29,
      30,    31,    32,   147,     0,    33,     0,    31,    32,    34,
       0,    33,     0,     0,     0,    34,    30,    31,    32,   151,
       0,    33,     0,     0,     0,    34,     4,     5,     0,     6,
       7,    29,     0,    31,    32,     4,     5,    33,     6,     7,
      29,    34,     0,     0,   158,     0,     4,     5,    30,     6,
       7,     0,     8,   -71,     9,     0,    10,    30,     0,     0,
       0,     0,     0,     0,     0,    31,    32,     0,     0,    33,
       0,     0,     0,    34,    31,    32,     0,     0,    33,     0,
       0,     0,    34,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,     0,     0,     0,     0,     0,
       0,    77,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,     4,     5,     0,     6,     7,
       0,   120,     0,     0,     0,     0,    80,    81,    82,    83,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74
};

static const yytype_int16 yycheck[] =
{
      25,    95,    44,    48,    49,    99,   134,     2,    50,    34,
     138,     0,     2,   141,   142,     8,     8,     3,     4,    51,
       6,     7,    50,    47,   152,     8,    12,     8,    53,    44,
       8,    56,    57,   161,    50,    50,    49,   165,    51,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    47,     8,    46,    50,    46,    47,    50,    10,
      84,    18,   156,    37,    38,    39,    91,    49,    93,    51,
      95,    48,     3,     4,    99,     6,     7,    50,     3,     4,
      51,     6,     7,     8,    44,    51,    50,     3,     4,    84,
       6,     7,     8,     8,    84,    20,    21,    22,    44,    51,
      25,    50,    19,    51,    20,    21,    22,   132,    27,    25,
      48,    35,    36,    37,    38,    39,    51,    42,    43,    27,
     115,    46,    20,    50,    21,    50,    42,    43,    51,    19,
      46,   156,     3,     4,    50,     6,     7,     8,     3,     4,
     115,     6,     7,     8,   164,    -1,    -1,    18,     3,     4,
      -1,     6,     7,     8,    25,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    -1,     3,     4,    -1,     6,     7,     8,
      25,    42,    43,    28,    -1,    46,    -1,    42,    43,    50,
      -1,    46,    -1,    -1,    -1,    50,    25,    42,    43,    28,
      -1,    46,    -1,    -1,    -1,    50,     3,     4,    -1,     6,
       7,     8,    -1,    42,    43,     3,     4,    46,     6,     7,
       8,    50,    -1,    -1,    21,    -1,     3,     4,    25,     6,
       7,    -1,     9,    21,    11,    -1,    13,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    46,
      -1,    -1,    -1,    50,    42,    43,    -1,    -1,    46,    -1,
      -1,    -1,    50,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     3,     4,    -1,     6,     7,
      -1,    48,    -1,    -1,    -1,    -1,    14,    15,    16,    17,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    53,    54,     0,     3,     4,     6,     7,     9,    11,
      13,    55,    58,    62,    64,    73,    74,    75,    56,    59,
       8,    63,    77,     8,     8,    44,    50,    48,    49,     8,
      25,    42,    43,    46,    50,    62,    73,    76,    78,    79,
      83,    85,    86,    93,    94,    95,    57,    60,     8,    94,
      65,    68,     8,    44,    50,    84,    50,    50,    94,     8,
      10,    18,    87,    48,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    48,    12,    62,
      14,    15,    16,    17,    61,    62,    64,    71,    72,    73,
      51,    44,    94,    80,    81,    50,    94,    94,    51,    50,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    62,    64,    49,    51,     8,    69,    94,
      48,    82,    94,    51,    94,    95,    51,    51,    95,    72,
      66,    27,    49,    51,    51,    48,    51,    27,    70,    94,
      77,    19,    67,    77,    26,    77,    77,    28,    21,    22,
      89,    28,    88,    20,    90,    77,    50,    21,    21,    95,
      51,    19,    77,    22,    92,    91,    90,    77
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    54,    54,    54,    54,    56,    55,
      57,    57,    59,    58,    60,    60,    60,    60,    60,    61,
      61,    61,    62,    63,    63,    63,    63,    65,    66,    67,
      64,    68,    69,    70,    64,    71,    71,    72,    73,    73,
      73,    73,    75,    76,    74,    77,    77,    78,    78,    78,
      78,    78,    78,    80,    79,    81,    79,    82,    82,    84,
      83,    83,    86,    85,    87,    88,    87,    89,    87,    90,
      91,    90,    92,    90,    93,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    95,    95,    95,    95,    95,
      95,    95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     0,     0,     5,
       2,     0,     0,     5,     3,     3,     2,     2,     0,     1,
       1,     1,     3,     3,     3,     1,     5,     0,     0,     0,
      11,     0,     0,     0,    10,     3,     1,     2,     1,     1,
       1,     1,     0,     0,     5,     2,     0,     2,     4,     1,
       1,     2,     5,     0,     5,     0,     4,     3,     1,     0,
       7,     1,     0,     2,     7,     0,    10,     0,     9,     6,
       0,     9,     0,     8,     4,     1,     1,     3,     3,     3,
       3,     3,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 93 "homework.y"
                                            {printf("\nend main\n\n"); printTable(); printf("\n"); printFctTable(); printf("\n"); printf("PROGRAM CORECT SINTACTIC\n"); PRINT_EVAL();}
#line 1575 "homework.tab.c"
    break;

  case 3:
#line 97 "homework.y"
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
#line 1590 "homework.tab.c"
    break;

  case 8:
#line 113 "homework.y"
                         {printf("structura declarata\n");}
#line 1596 "homework.tab.c"
    break;

  case 12:
#line 120 "homework.y"
                        {printf("clasa declarata\n");}
#line 1602 "homework.tab.c"
    break;

  case 19:
#line 130 "homework.y"
                                {printf("public ");}
#line 1608 "homework.tab.c"
    break;

  case 20:
#line 131 "homework.y"
                                {printf("private ");}
#line 1614 "homework.tab.c"
    break;

  case 21:
#line 132 "homework.y"
                                {printf("protected ");}
#line 1620 "homework.tab.c"
    break;

  case 23:
#line 141 "homework.y"
                {
                        printf("%s%s declared\n",tab,(yyvsp[0].var).name);
                        addVarType(nrVars,table[nrVars-1].vartype);
                        addVarName(nrVars,(yyvsp[0].var).name);
                        nrVars++;
                        //strcpy(table[nrVars].vartype,table[nrVars-1].vartype);
                        //strcpy(table[nrVars++].name,$3.name); 
                }
#line 1633 "homework.tab.c"
    break;

  case 24:
#line 150 "homework.y"
                {
                        printf("%s%s declared and assigned with %d\n",tab,(yyvsp[-2].var).name,(yyvsp[0].intval));
                        addVarName(nrVars,(yyvsp[-2].var).name);
                        updateTable(nrVars,(yyvsp[0].intval));
                        nrVars++;

                }
#line 1645 "homework.tab.c"
    break;

  case 25:
#line 158 "homework.y"
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
#line 1662 "homework.tab.c"
    break;

  case 26:
#line 171 "homework.y"
                {
                        printf("%s%s declared and assigned with %d\n",tab,(yyvsp[-2].var).name,(yyvsp[0].intval));
                        addVarName(nrVars,(yyvsp[-2].var).name);
                        addVarType(nrVars,table[nrVars-1].vartype);
                        strcpy(table[nrVars].scope,table[nrVars-1].scope);      
                        updateTable(nrVars,(yyvsp[0].intval));
                        nrVars++;
                }
#line 1675 "homework.tab.c"
    break;

  case 27:
#line 181 "homework.y"
                                {strcat(tab,"\t");strcpy(current_scope,(yyvsp[-1].var).name);}
#line 1681 "homework.tab.c"
    break;

  case 28:
#line 183 "homework.y"
                {
                        strcpy(tab,tab+1);
                        strcpy((yyval.fct).name, (yyvsp[-4].var).name);
                        strcpy((yyval.fct).fcttype,(yyvsp[-5].var).vartype);
                        addFctName(nrFct,(yyvsp[-4].var).name);
                        addFctType(nrFct,(yyvsp[-5].var).vartype);
                        strcpy(fct_table[nrFct].scope,current_scope);

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
#line 1718 "homework.tab.c"
    break;

  case 29:
#line 214 "homework.y"
                          {strcat(tab,"\t");}
#line 1724 "homework.tab.c"
    break;

  case 30:
#line 214 "homework.y"
                                                          {strcpy(tab,tab+1);strcpy(current_scope,"global");}
#line 1730 "homework.tab.c"
    break;

  case 31:
#line 216 "homework.y"
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
#line 1746 "homework.tab.c"
    break;

  case 32:
#line 227 "homework.y"
                    {strcpy(tab,tab+1);nrFct++;}
#line 1752 "homework.tab.c"
    break;

  case 33:
#line 227 "homework.y"
                                                         {strcat(tab,"\t");}
#line 1758 "homework.tab.c"
    break;

  case 34:
#line 227 "homework.y"
                                                                                       {strcpy(tab,tab+1);strcpy(current_scope,"global");}
#line 1764 "homework.tab.c"
    break;

  case 37:
#line 235 "homework.y"
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
#line 1785 "homework.tab.c"
    break;

  case 38:
#line 254 "homework.y"
            {
                addVarType(nrVars,"int");
                strcpy((yyval.var).vartype, "int");
            }
#line 1794 "homework.tab.c"
    break;

  case 39:
#line 259 "homework.y"
            {
                strcpy((yyval.var).vartype, "bool");
            }
#line 1802 "homework.tab.c"
    break;

  case 40:
#line 263 "homework.y"
            {
                strcpy((yyval.var).vartype, "string");
            }
#line 1810 "homework.tab.c"
    break;

  case 41:
#line 267 "homework.y"
            {
                strcpy((yyval.var).vartype, "float");
            }
#line 1818 "homework.tab.c"
    break;

  case 42:
#line 272 "homework.y"
                      {printf("\nmain\n");strcat(tab,"\t");strcpy(current_scope,"main");}
#line 1824 "homework.tab.c"
    break;

  case 43:
#line 272 "homework.y"
                                                                                               {strcpy(tab,tab+1);}
#line 1830 "homework.tab.c"
    break;

  case 48:
#line 281 "homework.y"
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
#line 1851 "homework.tab.c"
    break;

  case 49:
#line 297 "homework.y"
                        {strcpy(tab,tab+1);}
#line 1857 "homework.tab.c"
    break;

  case 50:
#line 298 "homework.y"
                         {
                            int j=nrVars-1;      
                            strcpy(table[j].scope,current_scope); 
                         }
#line 1866 "homework.tab.c"
    break;

  case 52:
#line 304 "homework.y"
                                              {Eval_calls[nr_calls++]=(yyvsp[-2].intval);}
#line 1872 "homework.tab.c"
    break;

  case 53:
#line 307 "homework.y"
                  {printf("%sFct call with parameters \n",tab);}
#line 1878 "homework.tab.c"
    break;

  case 55:
#line 308 "homework.y"
                  {printf("%sFct call \n",tab);}
#line 1884 "homework.tab.c"
    break;

  case 59:
#line 317 "homework.y"
                {printf("%sWhile called\n",tab);strcat(tab,"\t");}
#line 1890 "homework.tab.c"
    break;

  case 62:
#line 321 "homework.y"
            {printf("%sif called \n",tab); strcat(tab,"\t");}
#line 1896 "homework.tab.c"
    break;

  case 65:
#line 325 "homework.y"
                                                      {printf("%selse called \n",tab+1);}
#line 1902 "homework.tab.c"
    break;

  case 67:
#line 326 "homework.y"
                                                 {printf("%selse if called \n",tab+1);}
#line 1908 "homework.tab.c"
    break;

  case 70:
#line 330 "homework.y"
                                                           {printf("%s else called \n",tab+1);}
#line 1914 "homework.tab.c"
    break;

  case 72:
#line 331 "homework.y"
                                                      {printf("%s else if called \n",tab+1);}
#line 1920 "homework.tab.c"
    break;

  case 74:
#line 334 "homework.y"
                                       {printf("%sprint() called \n",tab);}
#line 1926 "homework.tab.c"
    break;

  case 75:
#line 338 "homework.y"
                    {(yyval.intval) = (yyvsp[0].intval);}
#line 1932 "homework.tab.c"
    break;

  case 76:
#line 339 "homework.y"
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
#line 1951 "homework.tab.c"
    break;

  case 77:
#line 353 "homework.y"
                                        {(yyval.intval)=(yyvsp[-2].intval)+(yyvsp[0].intval);}
#line 1957 "homework.tab.c"
    break;

  case 78:
#line 354 "homework.y"
                                         {(yyval.intval)=(yyvsp[-2].intval)-(yyvsp[0].intval);}
#line 1963 "homework.tab.c"
    break;

  case 79:
#line 355 "homework.y"
                                       {(yyval.intval)=(yyvsp[-2].intval)*(yyvsp[0].intval);}
#line 1969 "homework.tab.c"
    break;

  case 80:
#line 356 "homework.y"
                                       {(yyval.intval)=(yyvsp[-2].intval)/(yyvsp[0].intval);}
#line 1975 "homework.tab.c"
    break;

  case 81:
#line 357 "homework.y"
                                       {(yyval.intval)=(yyvsp[-2].intval)%(yyvsp[0].intval);}
#line 1981 "homework.tab.c"
    break;

  case 82:
#line 358 "homework.y"
                               {(yyval.intval)=(yyvsp[0].intval);}
#line 1987 "homework.tab.c"
    break;

  case 83:
#line 359 "homework.y"
                                {(yyval.intval)=(yyvsp[-1].intval);}
#line 1993 "homework.tab.c"
    break;

  case 84:
#line 360 "homework.y"
                      {(yyval.intval)=atoi((yyvsp[0].var).val);}
#line 1999 "homework.tab.c"
    break;

  case 85:
#line 363 "homework.y"
                                              {(yyval.intval)=(yyvsp[-2].intval)<(yyvsp[0].intval);}
#line 2005 "homework.tab.c"
    break;

  case 86:
#line 364 "homework.y"
                                            {(yyval.intval)=(yyvsp[-2].intval)>(yyvsp[0].intval);}
#line 2011 "homework.tab.c"
    break;

  case 87:
#line 365 "homework.y"
                                            {(yyval.intval)=(yyvsp[-2].intval)<=(yyvsp[0].intval);}
#line 2017 "homework.tab.c"
    break;

  case 88:
#line 366 "homework.y"
                                            {(yyval.intval)=(yyvsp[-2].intval)>=(yyvsp[0].intval);}
#line 2023 "homework.tab.c"
    break;

  case 89:
#line 367 "homework.y"
                                            {(yyval.intval)=(yyvsp[-2].intval)!=(yyvsp[0].intval);}
#line 2029 "homework.tab.c"
    break;

  case 90:
#line 368 "homework.y"
                                           {(yyval.intval)=((yyvsp[-2].intval)==(yyvsp[0].intval));}
#line 2035 "homework.tab.c"
    break;

  case 91:
#line 369 "homework.y"
                                            {(yyval.intval)=(yyvsp[-2].intval)&&(yyvsp[0].intval);}
#line 2041 "homework.tab.c"
    break;

  case 92:
#line 370 "homework.y"
                                           {(yyval.intval)=(yyvsp[-2].intval)||(yyvsp[0].intval);  }
#line 2047 "homework.tab.c"
    break;


#line 2051 "homework.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 373 "homework.y"




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
