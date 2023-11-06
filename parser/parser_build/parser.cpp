/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */

#include "../syntaxtree.h"
#include "../lexer.h"
Stm* syntree = nullptr;
bool parseSuccess = true;

void yyerror(const char* str);



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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INTLITERAL = 4,                 /* INTLITERAL  */
  YYSYMBOL_BOOLLITERAL = 5,                /* BOOLLITERAL  */
  YYSYMBOL_RUNELITERAL = 6,                /* RUNELITERAL  */
  YYSYMBOL_STRINGLITERAL = 7,              /* STRINGLITERAL  */
  YYSYMBOL_SEMICOLON = 8,                  /* SEMICOLON  */
  YYSYMBOL_COMMA = 9,                      /* COMMA  */
  YYSYMBOL_INT = 10,                       /* INT  */
  YYSYMBOL_BOOL = 11,                      /* BOOL  */
  YYSYMBOL_RUNE = 12,                      /* RUNE  */
  YYSYMBOL_STRING = 13,                    /* STRING  */
  YYSYMBOL_PACKAGE = 14,                   /* PACKAGE  */
  YYSYMBOL_RETURN = 15,                    /* RETURN  */
  YYSYMBOL_VAR = 16,                       /* VAR  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_LPAREN = 20,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 21,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 22,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 23,                    /* RBRACE  */
  YYSYMBOL_LBRACK = 24,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 25,                    /* RBRACK  */
  YYSYMBOL_PLUS = 26,                      /* PLUS  */
  YYSYMBOL_MIN = 27,                       /* MIN  */
  YYSYMBOL_MUL = 28,                       /* MUL  */
  YYSYMBOL_DIV = 29,                       /* DIV  */
  YYSYMBOL_ASSIGN = 30,                    /* ASSIGN  */
  YYSYMBOL_PLUSASSIGN = 31,                /* PLUSASSIGN  */
  YYSYMBOL_MINASSIGN = 32,                 /* MINASSIGN  */
  YYSYMBOL_MULASSIGN = 33,                 /* MULASSIGN  */
  YYSYMBOL_DIVASSIGN = 34,                 /* DIVASSIGN  */
  YYSYMBOL_AND = 35,                       /* AND  */
  YYSYMBOL_OR = 36,                        /* OR  */
  YYSYMBOL_NOT = 37,                       /* NOT  */
  YYSYMBOL_INC = 38,                       /* INC  */
  YYSYMBOL_DEC = 39,                       /* DEC  */
  YYSYMBOL_GT = 40,                        /* GT  */
  YYSYMBOL_GE = 41,                        /* GE  */
  YYSYMBOL_LT = 42,                        /* LT  */
  YYSYMBOL_LE = 43,                        /* LE  */
  YYSYMBOL_EQ = 44,                        /* EQ  */
  YYSYMBOL_NE = 45,                        /* NE  */
  YYSYMBOL_FUNC = 46,                      /* FUNC  */
  YYSYMBOL_UNARY = 47,                     /* UNARY  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_start = 49,                     /* start  */
  YYSYMBOL_prog = 50,                      /* prog  */
  YYSYMBOL_stm = 51,                       /* stm  */
  YYSYMBOL_ifstm = 52,                     /* ifstm  */
  YYSYMBOL_blockstm = 53,                  /* blockstm  */
  YYSYMBOL_realtype = 54,                  /* realtype  */
  YYSYMBOL_type = 55,                      /* type  */
  YYSYMBOL_exp = 56,                       /* exp  */
  YYSYMBOL_rel_exp = 57,                   /* rel_exp  */
  YYSYMBOL_add_exp = 58,                   /* add_exp  */
  YYSYMBOL_mul_exp = 59,                   /* mul_exp  */
  YYSYMBOL_index_exp = 60,                 /* index_exp  */
  YYSYMBOL_operand = 61,                   /* operand  */
  YYSYMBOL_binary_op = 62,                 /* binary_op  */
  YYSYMBOL_add_op = 63,                    /* add_op  */
  YYSYMBOL_mul_op = 64,                    /* mul_op  */
  YYSYMBOL_rel_op = 65,                    /* rel_op  */
  YYSYMBOL_unary_op = 66,                  /* unary_op  */
  YYSYMBOL_signature = 67,                 /* signature  */
  YYSYMBOL_parameters = 68,                /* parameters  */
  YYSYMBOL_parameter = 69,                 /* parameter  */
  YYSYMBOL_arguments = 70,                 /* arguments  */
  YYSYMBOL_assignment = 71                 /* assignment  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   202

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
static const yytype_uint8 yyrline[] =
{
       0,    77,    77,    81,    82,    83,    84,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    98,    99,   100,   101,
     103,   104,   106,   107,   109,   110,   111,   113,   114,   118,
     119,   120,   121,   122,   123,   127,   131,   132,   133,   134,
     137,   138,   142,   143,   146,   147,   150,   151,   154,   155,
     158,   159,   162,   163,   164,   165,   166,   167,   168,   169,
     173,   174,   177,   178,   181,   182,   185,   186,   187,   188,
     189,   190,   193,   194,   195,   199,   203,   204,   205,   209,
     213,   214,   215,   219,   220,   221,   222,   223
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INTLITERAL", "BOOLLITERAL", "RUNELITERAL", "STRINGLITERAL", "SEMICOLON",
  "COMMA", "INT", "BOOL", "RUNE", "STRING", "PACKAGE", "RETURN", "VAR",
  "IF", "ELSE", "FOR", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK",
  "RBRACK", "PLUS", "MIN", "MUL", "DIV", "ASSIGN", "PLUSASSIGN",
  "MINASSIGN", "MULASSIGN", "DIVASSIGN", "AND", "OR", "NOT", "INC", "DEC",
  "GT", "GE", "LT", "LE", "EQ", "NE", "FUNC", "UNARY", "$accept", "start",
  "prog", "stm", "ifstm", "blockstm", "realtype", "type", "exp", "rel_exp",
  "add_exp", "mul_exp", "index_exp", "operand", "binary_op", "add_op",
  "mul_op", "rel_op", "unary_op", "signature", "parameters", "parameter",
  "arguments", "assignment", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
#endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-28)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      46,   -91,   147,    11,    73,    20,   108,   108,   136,    24,
      10,   -91,    23,   -91,    40,   -91,    73,    73,    73,    73,
      73,    73,   -91,   -91,   -91,    39,   -91,   -91,   -91,   -91,
      73,   -91,   -91,   -91,   -23,   129,     7,    45,    17,   -91,
      73,    76,   163,    58,    34,    74,    34,    82,    87,   -91,
      21,    21,    55,    75,   -23,   -23,   -23,   -23,   -23,    73,
     -10,   -91,   -91,    73,   -91,   -91,   -91,   -91,   -91,   -91,
      73,   -91,   -91,    73,   -91,   -91,    73,    73,   -91,    78,
      96,    99,   100,    73,    73,    73,   113,    73,   -91,   -91,
     130,   110,   -91,   -91,    73,   -91,   115,   -91,   129,     7,
      45,   -91,    59,    73,    73,    73,    73,   -23,   117,    34,
      33,    22,   107,   119,   132,   -91,   -91,   -91,   -91,   -23,
     -23,   -23,   -23,   134,   125,   -91,   -91,   146,   -91,   -91,
     -91,   -91,   -91,   107,   130,    33,   110,   -91,   -91,   -91,
     -91,   -91,   -91
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    28,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     2,     4,    24,     6,    18,    82,     0,     0,     0,
       0,     0,    22,    23,    17,    52,    56,    55,    57,    58,
       0,    72,    73,    74,    20,    42,    44,    46,    48,    50,
       0,     0,    52,     0,     0,     0,     0,     0,     0,     1,
       0,     0,    81,     0,    83,    84,    85,    86,    87,    82,
       0,    60,    61,     0,    66,    67,    68,    69,    70,    71,
       0,    62,    63,     0,    64,    65,     0,     0,    59,     8,
      10,    12,    14,     0,    82,     0,    29,     0,    25,    35,
      78,     0,     3,     5,    82,    19,     0,    54,    43,    45,
      47,    49,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,     0,     0,    77,    16,    80,    53,    51,     7,
       9,    11,    13,    53,    30,    31,    32,     0,    36,    37,
      38,    39,    79,    41,    78,     0,     0,    40,    75,    76,
      33,    34,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -91,   -91,     1,    -6,   -90,   -38,    13,   -91,    -2,    85,
      86,    84,   -91,   -37,   -91,   -91,   -91,   -91,   -91,   -91,
      30,   -91,   -52,   -91
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    10,    11,    12,    13,    14,   132,   138,    52,    35,
      36,    37,    38,    39,    63,    73,    76,    70,    40,    91,
     113,   114,    53,    15
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    45,    34,    78,    44,    46,    86,    96,    88,    47,
      49,    97,    61,    62,    24,    54,    55,    56,    57,    58,
     125,   -27,     1,    41,     2,    61,    62,    48,    60,   -27,
     127,    50,   108,    71,    72,     3,     4,     5,     6,   101,
       7,    77,   116,     8,   -27,   140,   -27,     1,    51,     2,
       6,    92,    93,   115,   -27,     8,     8,    61,    62,    59,
       3,     4,     5,     6,    94,     7,    85,     9,     8,    61,
      62,   124,   126,    74,    75,   102,    25,    26,    27,    28,
      29,   107,    87,   109,   118,   111,    79,    80,    81,    82,
      61,    62,     9,    30,    61,    62,    95,   141,   142,    31,
      32,   119,   120,   121,   122,    89,    83,    90,   103,     1,
      33,    42,    26,    27,    28,    29,   -27,   128,   129,   130,
     131,   136,     3,     4,     5,     6,   104,     7,    30,   105,
     106,   110,     8,   112,    31,    32,   117,     1,   123,     2,
     133,   134,   -19,   135,   -27,    33,   137,     1,    98,     2,
       3,     4,     5,     6,     9,     7,    99,   100,     8,   -27,
       3,     4,     5,     6,   139,     7,     0,    16,   -27,    64,
      65,    66,    67,    68,    69,     0,     0,    17,    18,    19,
      20,    21,     9,    84,     0,    22,    23,     0,     0,     0,
       0,     0,     9,    17,    18,    19,    20,    21,     0,     0,
       0,    22,    23
};

static const yytype_int16 yycheck[] =
{
       6,     7,     4,    40,     6,     7,    44,    59,    46,     8,
       0,    21,    35,    36,     3,    17,    18,    19,    20,    21,
     110,     0,     1,     3,     3,    35,    36,     3,    30,     8,
       8,     8,    84,    26,    27,    14,    15,    16,    17,    76,
      19,    24,    94,    22,    23,   135,     0,     1,     8,     3,
      17,    50,    51,    91,     8,    22,    22,    35,    36,    20,
      14,    15,    16,    17,     9,    19,     8,    46,    22,    35,
      36,   109,   110,    28,    29,    77,     3,     4,     5,     6,
       7,    83,     8,    85,    25,    87,    10,    11,    12,    13,
      35,    36,    46,    20,    35,    36,    21,   135,   136,    26,
      27,   103,   104,   105,   106,    23,    30,    20,    30,     1,
      37,     3,     4,     5,     6,     7,     8,    10,    11,    12,
      13,   127,    14,    15,    16,    17,    30,    19,    20,    30,
      30,    18,    22,     3,    26,    27,    21,     1,    21,     3,
      21,     9,     8,    18,     8,    37,   133,     1,    63,     3,
      14,    15,    16,    17,    46,    19,    70,    73,    22,    23,
      14,    15,    16,    17,   134,    19,    -1,    20,    22,    40,
      41,    42,    43,    44,    45,    -1,    -1,    30,    31,    32,
      33,    34,    46,    20,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    46,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    14,    15,    16,    17,    19,    22,    46,
      49,    50,    51,    52,    53,    71,    20,    30,    31,    32,
      33,    34,    38,    39,     3,     3,     4,     5,     6,     7,
      20,    26,    27,    37,    56,    57,    58,    59,    60,    61,
      66,     3,     3,    51,    56,    51,    56,    50,     3,     0,
       8,     8,    56,    70,    56,    56,    56,    56,    56,    20,
      56,    35,    36,    62,    40,    41,    42,    43,    44,    45,
      65,    26,    27,    63,    28,    29,    64,    24,    61,    10,
      11,    12,    13,    30,    20,     8,    53,     8,    53,    23,
      20,    67,    50,    50,     9,    21,    70,    21,    57,    58,
      59,    61,    56,    30,    30,    30,    30,    56,    70,    56,
      18,    56,     3,    68,    69,    53,    70,    21,    25,    56,
      56,    56,    56,    21,    53,    52,    53,     8,    10,    11,
      12,    13,    54,    21,     9,    18,    51,    54,    55,    68,
      52,    53,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    50,    50,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    52,
      52,    52,    52,    52,    52,    53,    54,    54,    54,    54,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    65,    65,    65,
      65,    65,    66,    66,    66,    67,    68,    68,    68,    69,
      70,    70,    70,    71,    71,    71,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     3,     1,     5,     3,     5,
       3,     5,     3,     5,     3,     4,     4,     2,     1,     4,
       2,     1,     2,     2,     1,     3,     7,     0,     1,     3,
       5,     5,     5,     7,     7,     3,     1,     1,     1,     1,
       1,     0,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     4,     1,     4,     3,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     1,     0,     2,
       3,     1,     0,     3,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* start: prog  */
       {(yyval.stm) = (yyvsp[0].stm); syntree = (yyval.stm);}
    break;

  case 3: /* prog: stm SEMICOLON prog  */
                     {(yyval.stm) = new CompoundStm((yyvsp[-2].stm), (yyvsp[0].stm));}
    break;

  case 4: /* prog: stm  */
      {(yyval.stm) = new LastStm((yyvsp[0].stm));}
    break;

  case 5: /* prog: blockstm SEMICOLON prog  */
                          {(yyval.stm) = new CompoundStm((yyvsp[-2].blockstm), (yyvsp[0].stm));}
    break;

  case 6: /* prog: blockstm  */
           {(yyval.stm) = (yyvsp[0].blockstm);}
    break;

  case 7: /* stm: VAR IDENTIFIER INT ASSIGN exp  */
                               {(yyval.stm) = new IntCreateStm((yyvsp[-3].string), (yyvsp[0].exp));}
    break;

  case 8: /* stm: VAR IDENTIFIER INT  */
                     {(yyval.stm) = new IntCreateStm((yyvsp[-1].string));}
    break;

  case 9: /* stm: VAR IDENTIFIER BOOL ASSIGN exp  */
                                 {(yyval.stm) = new BoolCreateStm((yyvsp[-3].string), (yyvsp[0].exp));}
    break;

  case 10: /* stm: VAR IDENTIFIER BOOL  */
                      {(yyval.stm) = new BoolCreateStm((yyvsp[-1].string));}
    break;

  case 11: /* stm: VAR IDENTIFIER RUNE ASSIGN exp  */
                                 {(yyval.stm) = new RuneCreateStm((yyvsp[-3].string), (yyvsp[0].exp));}
    break;

  case 12: /* stm: VAR IDENTIFIER RUNE  */
                      {(yyval.stm) = new RuneCreateStm((yyvsp[-1].string));}
    break;

  case 13: /* stm: VAR IDENTIFIER STRING ASSIGN exp  */
                                   {(yyval.stm) = new StringCreateStm((yyvsp[-3].string), (yyvsp[0].exp));}
    break;

  case 14: /* stm: VAR IDENTIFIER STRING  */
                        {(yyval.stm) = new StringCreateStm((yyvsp[-1].string));}
    break;

  case 15: /* stm: VAR IDENTIFIER ASSIGN exp  */
                            {(yyval.stm) = new VarCreateStm((yyvsp[-2].string), (yyvsp[0].exp));}
    break;

  case 16: /* stm: FUNC IDENTIFIER signature blockstm  */
                                     {(yyval.stm) = new FunctionStm((yyvsp[-2].string), (yyvsp[-1].signature), (yyvsp[0].blockstm));}
    break;

  case 17: /* stm: PACKAGE IDENTIFIER  */
                     {(yyval.stm) = new PackageStm((yyvsp[0].string));}
    break;

  case 18: /* stm: assignment  */
             {(yyval.stm) = (yyvsp[0].stm);}
    break;

  case 19: /* stm: IDENTIFIER LPAREN arguments RPAREN  */
                                     {(yyval.stm) = new CallStm((yyvsp[-3].string), (yyvsp[-1].arguments));}
    break;

  case 20: /* stm: RETURN exp  */
             {(yyval.stm) = new ReturnStm((yyvsp[0].exp));}
    break;

  case 21: /* stm: RETURN  */
         {(yyval.stm) = new ReturnStm(nullptr);}
    break;

  case 22: /* stm: IDENTIFIER INC  */
                 {(yyval.stm) = new IncrementStm((yyvsp[-1].string));}
    break;

  case 23: /* stm: IDENTIFIER DEC  */
                 {(yyval.stm) = new DecrementStm((yyvsp[-1].string));}
    break;

  case 24: /* stm: ifstm  */
        {(yyval.stm) = (yyvsp[0].ifstm);}
    break;

  case 25: /* stm: FOR exp blockstm  */
                   {(yyval.stm) = new ForStm((yyvsp[-1].exp), (yyvsp[0].blockstm));}
    break;

  case 26: /* stm: FOR stm SEMICOLON exp SEMICOLON stm blockstm  */
                                               {(yyval.stm) = new ForStm((yyvsp[-3].exp), (yyvsp[0].blockstm), (yyvsp[-5].stm), (yyvsp[-1].stm));}
    break;

  case 27: /* stm: %empty  */
  {(yyval.stm) = new NoOpStm();}
    break;

  case 28: /* stm: error  */
        {(yyval.stm) = new ErrorStm();}
    break;

  case 29: /* ifstm: IF exp blockstm  */
                 {(yyval.ifstm) = new IfStm((yyvsp[-1].exp), (yyvsp[0].blockstm));}
    break;

  case 30: /* ifstm: IF stm SEMICOLON exp blockstm  */
                                {(yyval.ifstm) = new IfStm((yyvsp[-1].exp), (yyvsp[0].blockstm), (yyvsp[-3].stm));}
    break;

  case 31: /* ifstm: IF exp blockstm ELSE ifstm  */
                             {(yyval.ifstm) = new IfStm((yyvsp[-3].exp), (yyvsp[-2].blockstm), nullptr, (yyvsp[0].ifstm));}
    break;

  case 32: /* ifstm: IF exp blockstm ELSE blockstm  */
                                {(yyval.ifstm) = new IfStm((yyvsp[-3].exp), (yyvsp[-2].blockstm), nullptr, (yyvsp[0].blockstm));}
    break;

  case 33: /* ifstm: IF stm SEMICOLON exp blockstm ELSE ifstm  */
                                           {(yyval.ifstm) = new IfStm((yyvsp[-3].exp), (yyvsp[-2].blockstm), (yyvsp[-5].stm), (yyvsp[0].ifstm));}
    break;

  case 34: /* ifstm: IF stm SEMICOLON exp blockstm ELSE blockstm  */
                                              {(yyval.ifstm) = new IfStm((yyvsp[-3].exp), (yyvsp[-2].blockstm), (yyvsp[-5].stm), (yyvsp[0].blockstm));}
    break;

  case 35: /* blockstm: LBRACE prog RBRACE  */
                     {(yyval.blockstm) = new BlockStm((yyvsp[-1].stm));}
    break;

  case 36: /* realtype: INT  */
      {(yyval.type) = Type::intType;}
    break;

  case 37: /* realtype: BOOL  */
       {(yyval.type) = Type::boolType;}
    break;

  case 38: /* realtype: RUNE  */
       {(yyval.type) = Type::runeType;}
    break;

  case 39: /* realtype: STRING  */
         {(yyval.type) = Type::stringType;}
    break;

  case 41: /* type: %empty  */
  {(yyval.type) = Type::voidType;}
    break;

  case 43: /* exp: exp binary_op rel_exp  */
                        {(yyval.exp) = new OpExp((yyvsp[-2].exp), (yyvsp[-1].op), (yyvsp[0].exp));}
    break;

  case 45: /* rel_exp: rel_exp rel_op add_exp  */
                         {(yyval.exp) = new OpExp((yyvsp[-2].exp), (yyvsp[-1].op), (yyvsp[0].exp));}
    break;

  case 47: /* add_exp: add_exp add_op mul_exp  */
                         {(yyval.exp) = new OpExp((yyvsp[-2].exp), (yyvsp[-1].op), (yyvsp[0].exp));}
    break;

  case 49: /* mul_exp: mul_exp mul_op operand  */
                         {(yyval.exp) = new OpExp((yyvsp[-2].exp), (yyvsp[-1].op), (yyvsp[0].exp));}
    break;

  case 51: /* index_exp: index_exp LBRACK exp RBRACK  */
                              {(yyval.exp) = new IndexExp((yyvsp[-3].exp), (yyvsp[-1].exp));}
    break;

  case 52: /* operand: IDENTIFIER  */
             {(yyval.exp) = new IdExp((yyvsp[0].string));}
    break;

  case 53: /* operand: IDENTIFIER LPAREN arguments RPAREN  */
                                     {(yyval.exp) = new CallExp((yyvsp[-3].string), (yyvsp[-1].arguments));}
    break;

  case 54: /* operand: LPAREN exp RPAREN  */
                    {(yyval.exp) = (yyvsp[-1].exp);}
    break;

  case 55: /* operand: BOOLLITERAL  */
              {(yyval.exp) = new BoolLiteralExp((yyvsp[0].boolean));}
    break;

  case 56: /* operand: INTLITERAL  */
             {(yyval.exp) = new IntLiteralExp((yyvsp[0].integer));}
    break;

  case 57: /* operand: RUNELITERAL  */
              {(yyval.exp) = new RuneLiteralExp((yyvsp[0].character));}
    break;

  case 58: /* operand: STRINGLITERAL  */
                {(yyval.exp) = new StringLiteralExp((yyvsp[0].string));}
    break;

  case 59: /* operand: unary_op operand  */
                               {(yyval.exp) = new OpExp(nullptr,(yyvsp[-1].op), (yyvsp[0].exp));}
    break;

  case 60: /* binary_op: AND  */
     {(yyval.op) = Operator::And;}
    break;

  case 61: /* binary_op: OR  */
     {(yyval.op) = Operator::Or;}
    break;

  case 62: /* add_op: PLUS  */
       {(yyval.op) = Operator::Plus;}
    break;

  case 63: /* add_op: MIN  */
      {(yyval.op) = Operator::Minus;}
    break;

  case 64: /* mul_op: MUL  */
     {(yyval.op) = Operator::Mul;}
    break;

  case 65: /* mul_op: DIV  */
      {(yyval.op) = Operator::Div;}
    break;

  case 66: /* rel_op: GT  */
    {(yyval.op) = Operator::Greater;}
    break;

  case 67: /* rel_op: GE  */
     {(yyval.op) = Operator::GreaterOrEqual;}
    break;

  case 68: /* rel_op: LT  */
     {(yyval.op) = Operator::Lesser;}
    break;

  case 69: /* rel_op: LE  */
     {(yyval.op) = Operator::LesserOrEqual;}
    break;

  case 70: /* rel_op: EQ  */
     {(yyval.op) = Operator::Equal;}
    break;

  case 71: /* rel_op: NE  */
     {(yyval.op) = Operator::NotEqual;}
    break;

  case 72: /* unary_op: PLUS  */
       {(yyval.op) = Operator::Plus;}
    break;

  case 73: /* unary_op: MIN  */
      {(yyval.op) = Operator::Minus;}
    break;

  case 74: /* unary_op: NOT  */
      {(yyval.op) = Operator::Not;}
    break;

  case 75: /* signature: LPAREN parameters RPAREN type  */
                                {(yyval.signature) = new Signature((yyvsp[-2].parameters), (yyvsp[0].type));}
    break;

  case 76: /* parameters: parameter COMMA parameters  */
                             {(yyval.parameters) = new ParametersList((yyvsp[-2].parameter), (yyvsp[0].parameters));}
    break;

  case 77: /* parameters: parameter  */
            {(yyval.parameters) = new ParametersLast((yyvsp[0].parameter));}
    break;

  case 78: /* parameters: %empty  */
  {(yyval.parameters) = nullptr;}
    break;

  case 79: /* parameter: IDENTIFIER realtype  */
                      {(yyval.parameter) = new Parameter((yyvsp[-1].string), (yyvsp[0].type));}
    break;

  case 80: /* arguments: exp COMMA arguments  */
                      {(yyval.arguments) = new ArgumentsList((yyvsp[-2].exp), (yyvsp[0].arguments));}
    break;

  case 81: /* arguments: exp  */
      {(yyval.arguments) = new ArgumentsLast((yyvsp[0].exp));}
    break;

  case 82: /* arguments: %empty  */
  {(yyval.arguments) = nullptr;}
    break;

  case 83: /* assignment: IDENTIFIER ASSIGN exp  */
                        {(yyval.stm) = new VarAssignStm((yyvsp[-2].string), (yyvsp[0].exp));}
    break;

  case 84: /* assignment: IDENTIFIER PLUSASSIGN exp  */
                            {(yyval.stm) = new PlusAssignStm((yyvsp[-2].string), (yyvsp[0].exp));}
    break;

  case 85: /* assignment: IDENTIFIER MINASSIGN exp  */
                           {(yyval.stm) = new IntMinAssignStm((yyvsp[-2].string), (yyvsp[0].exp));}
    break;

  case 86: /* assignment: IDENTIFIER MULASSIGN exp  */
                           {(yyval.stm) = new IntMulAssignStm((yyvsp[-2].string), (yyvsp[0].exp));}
    break;

  case 87: /* assignment: IDENTIFIER DIVASSIGN exp  */
                           {(yyval.stm) = new IntDivAssignStm((yyvsp[-2].string), (yyvsp[0].exp));}
    break;



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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}


extern int line_nr;
extern int col_nr;
void yyerror(const char *s)
{
  // vul aan
  fprintf(stderr,"%s at line %d\n",s, line_nr);
  parseSuccess = false;
}
