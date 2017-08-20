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

#ifndef YY_YY_GT_GT_BISON_TAB_HH_INCLUDED
# define YY_YY_GT_GT_BISON_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yy_gt_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    STRING = 259,
    TAG = 260,
    kwINFO = 261,
    kwDESCRIPTION = 262,
    kwVERTEX = 263,
    kwEDGE = 264,
    kwAT = 265,
    kwWITH = 266,
    kwWEIGHT = 267,
    kwDASH = 268,
    kwLEFT = 269,
    kwRIGHT = 270
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define STRING 259
#define TAG 260
#define kwINFO 261
#define kwDESCRIPTION 262
#define kwVERTEX 263
#define kwEDGE 264
#define kwAT 265
#define kwWITH 266
#define kwWEIGHT 267
#define kwDASH 268
#define kwLEFT 269
#define kwRIGHT 270

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "gt-bison.y" /* yacc.c:1909  */

	int integer;
	char *str;

#line 89 "gt-bison.tab.hh" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yy_gt_lval;

int yy_gt_parse (void);

#endif /* !YY_YY_GT_GT_BISON_TAB_HH_INCLUDED  */
