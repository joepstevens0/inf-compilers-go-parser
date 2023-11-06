/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_PARSER_BUILD_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_PARSER_BUILD_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INTLITERAL = 259,              /* INTLITERAL  */
    BOOLLITERAL = 260,             /* BOOLLITERAL  */
    RUNELITERAL = 261,             /* RUNELITERAL  */
    STRINGLITERAL = 262,           /* STRINGLITERAL  */
    SEMICOLON = 263,               /* SEMICOLON  */
    COMMA = 264,                   /* COMMA  */
    INT = 265,                     /* INT  */
    BOOL = 266,                    /* BOOL  */
    RUNE = 267,                    /* RUNE  */
    STRING = 268,                  /* STRING  */
    PACKAGE = 269,                 /* PACKAGE  */
    RETURN = 270,                  /* RETURN  */
    VAR = 271,                     /* VAR  */
    IF = 272,                      /* IF  */
    ELSE = 273,                    /* ELSE  */
    FOR = 274,                     /* FOR  */
    LPAREN = 275,                  /* LPAREN  */
    RPAREN = 276,                  /* RPAREN  */
    LBRACE = 277,                  /* LBRACE  */
    RBRACE = 278,                  /* RBRACE  */
    LBRACK = 279,                  /* LBRACK  */
    RBRACK = 280,                  /* RBRACK  */
    PLUS = 281,                    /* PLUS  */
    MIN = 282,                     /* MIN  */
    MUL = 283,                     /* MUL  */
    DIV = 284,                     /* DIV  */
    ASSIGN = 285,                  /* ASSIGN  */
    PLUSASSIGN = 286,              /* PLUSASSIGN  */
    MINASSIGN = 287,               /* MINASSIGN  */
    MULASSIGN = 288,               /* MULASSIGN  */
    DIVASSIGN = 289,               /* DIVASSIGN  */
    AND = 290,                     /* AND  */
    OR = 291,                      /* OR  */
    NOT = 292,                     /* NOT  */
    INC = 293,                     /* INC  */
    DEC = 294,                     /* DEC  */
    GT = 295,                      /* GT  */
    GE = 296,                      /* GE  */
    LT = 297,                      /* LT  */
    LE = 298,                      /* LE  */
    EQ = 299,                      /* EQ  */
    NE = 300,                      /* NE  */
    FUNC = 301,                    /* FUNC  */
    UNARY = 302                    /* UNARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{

  char* string;
  int integer;
  bool boolean;
  char character;
  Operator op;
  Stm* stm;
  Exp* exp;
  Type type;
  Signature* signature;
  Arguments* arguments;
  Parameters* parameters;
  Parameter* parameter;
  BlockStm* blockstm;
  IfStm* ifstm;


};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_PARSER_BUILD_PARSER_HPP_INCLUDED  */
