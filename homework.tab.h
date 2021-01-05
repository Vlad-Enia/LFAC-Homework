/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    IF = 266,
    ENDIF = 267,
    ELSE = 268,
    FOR = 269,
    ENDFOR = 270,
    WHILE = 271,
    ENDWHILE = 272,
    FBEGIN = 273,
    FEND = 274,
    LWR = 275,
    LEQ = 276,
    GTR = 277,
    GEQ = 278,
    EQ = 279,
    NEQ = 280,
    PLUS = 281,
    MINUS = 282,
    MTP = 283,
    DVD = 284,
    MOD = 285,
    AND = 286,
    OR = 287,
    PRINT = 288,
    ASGN = 289,
    STRVAL = 290,
    INTVAL = 291,
    BOOLVAL = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 11 "homework.y" /* yacc.c:1909  */

int intval;
double floatval;
char* strval;
int boolval;
struct  IND
{
	char name[100];
	int val;
} intnode;


#line 105 "homework.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOMEWORK_TAB_H_INCLUDED  */
