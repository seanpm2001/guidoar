/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse guidoarparse
#define yylex   guidoarlex
#define yyerror guidoarerror
#define yylval  guidoarlval
#define yychar  guidoarchar
#define yydebug guidoardebug
#define yynerrs guidoarnerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     PNUMBER = 259,
     NNUMBER = 260,
     FLOAT = 261,
     STARTCHORD = 262,
     ENDCHORD = 263,
     STARTSEQ = 264,
     ENDSEQ = 265,
     STARTPARAM = 266,
     ENDPARAM = 267,
     STARTRANGE = 268,
     ENDRANGE = 269,
     SEP = 270,
     IDSEP = 271,
     BAR = 272,
     TAGNAME = 273,
     ID = 274,
     DIATONIC = 275,
     CHROMATIC = 276,
     SOLFEGE = 277,
     EMPTY = 278,
     REST = 279,
     DOT = 280,
     DDOT = 281,
     SHARP = 282,
     FLAT = 283,
     MLS = 284,
     SEC = 285,
     UNIT = 286,
     MULT = 287,
     DIV = 288,
     EQUAL = 289,
     STRING = 290,
     EXTRA = 291
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define PNUMBER 259
#define NNUMBER 260
#define FLOAT 261
#define STARTCHORD 262
#define ENDCHORD 263
#define STARTSEQ 264
#define ENDSEQ 265
#define STARTPARAM 266
#define ENDPARAM 267
#define STARTRANGE 268
#define ENDRANGE 269
#define SEP 270
#define IDSEP 271
#define BAR 272
#define TAGNAME 273
#define ID 274
#define DIATONIC 275
#define CHROMATIC 276
#define SOLFEGE 277
#define EMPTY 278
#define REST 279
#define DOT 280
#define DDOT 281
#define SHARP 282
#define FLAT 283
#define MLS 284
#define SEC 285
#define UNIT 286
#define MULT 287
#define DIV 288
#define EQUAL 289
#define STRING 290
#define EXTRA 291




/* Copy the first part of user declarations.  */
#line 1 "guido.y"


#include <string>
#include <iostream>
#include <vector>
#include <assert.h>

#include "guidoelement.h"
#include "gmnreader.h"
#include "rational.h"

#include "guidoparse.hpp"
#include "guidolex.c++"

int guidoarerror(const char*s);
int	guidoarwrap()		{ return(1); }

extern guido::gmnreader* gReader;

static void vadd (std::vector<guido::Sguidoelement>* v1, std::vector<guido::Sguidoelement>* v2)
{
	for (std::vector<guido::Sguidoelement>::iterator i = v2->begin(); i != v2->end(); i++)
		v1->push_back(*i);
}

#include <math.h>
static float dotatof( const char * s ) 
{ 
	const char * dotPos = strchr(s,'.');
	if ( !dotPos )
	{
		return atof(s);
	}
	else
	{
		int x,y;
		int length = strlen(s);
		int digitsAfterDot = length - (dotPos - s + 1);
		if ( digitsAfterDot == 0 )
		{
			if ( length == 1 )
				return 0;
			else
			{
				sscanf( s , "%d." , &x );
				return x;
			}
		}
		else
		{
			float decimalDivisor = pow( 10.0f , digitsAfterDot );
			if ( dotPos == s )
			{
				sscanf( s , ".%d" , &x );
				return x / decimalDivisor;
			}
			else
			{
				sscanf( s , "%d.%d" , &x , &y );
				return x + y / pow(10.0f , digitsAfterDot);
			}
		}
	}
}

//#define parseDebug

#ifdef parseDebug
#define debug(msg)		cout << msg << endl;
#define vdebug(msg,v)	cout << msg << " " << v << endl;
#else
#define debug(msg)
#define vdebug(msg, v)
#endif

#define addElt(to,elt)	(to)->push(*elt); delete elt

using namespace std;

namespace guido
{



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 90 "guido.y"
{         
	long int		num;
	float			real;
	const char*		token;
	std::string*	str;
	char			c;
	guido::Sguidoelement *		elt;
	guido::Sguidoattribute*		attr;
	std::vector<guido::Sguidoelement>*	 velt;
	std::vector<guido::Sguidoattribute>* vattr;
	rational *		r;
}
/* Line 193 of yacc.c.  */
#line 273 "guidoparse.c++"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 286 "guidoparse.c++"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   105

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNRULES -- Number of states.  */
#define YYNSTATES  111

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,    10,    12,    14,    18,    22,    23,
      26,    29,    32,    34,    36,    38,    43,    48,    50,    52,
      56,    58,    60,    62,    65,    68,    70,    72,    74,    78,
      80,    84,    88,    90,    94,    96,    99,   102,   106,   108,
     110,   115,   117,   120,   122,   124,   128,   135,   140,   146,
     148,   153,   155,   157,   159,   161,   163,   166,   168,   170,
     171,   173,   174,   179,   182,   185,   186,   188,   190,   192,
     194,   196,   198,   200,   202,   204
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,     7,     8,    -1,     7,    39,     8,    -1,
      40,    -1,    40,    -1,    39,    15,    40,    -1,     9,    41,
      10,    -1,    -1,    41,    56,    -1,    41,    42,    -1,    41,
      50,    -1,    43,    -1,    44,    -1,    46,    -1,    46,    11,
      49,    12,    -1,    43,    13,    41,    14,    -1,    18,    -1,
      45,    -1,    45,    16,     3,    -1,    17,    -1,    71,    -1,
      70,    -1,    71,    31,    -1,    70,    31,    -1,    35,    -1,
      66,    -1,    47,    -1,    66,    34,    47,    -1,    48,    -1,
      49,    15,    48,    -1,     7,    51,     8,    -1,    52,    -1,
      51,    15,    52,    -1,    53,    -1,    55,    53,    -1,    53,
      55,    -1,    55,    53,    55,    -1,    56,    -1,    54,    -1,
      43,    13,    52,    14,    -1,    43,    -1,    55,    43,    -1,
      58,    -1,    57,    -1,    24,    64,    65,    -1,    24,    11,
       3,    12,    64,    65,    -1,    59,    63,    64,    65,    -1,
      59,    61,    63,    64,    65,    -1,    60,    -1,    60,    11,
       3,    12,    -1,    20,    -1,    21,    -1,    22,    -1,    23,
      -1,    62,    -1,    61,    62,    -1,    27,    -1,    28,    -1,
      -1,    71,    -1,    -1,    32,    67,    33,    67,    -1,    32,
      67,    -1,    33,    67,    -1,    -1,    25,    -1,    26,    -1,
      19,    -1,     3,    -1,     4,    -1,     5,    -1,     6,    -1,
      67,    -1,    68,    -1,    69,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   165,   165,   166,   167,   170,   171,   174,   177,   178,
     179,   180,   185,   186,   189,   190,   193,   196,   199,   200,
     201,   204,   205,   206,   207,   208,   209,   212,   213,   216,
     217,   224,   227,   228,   231,   232,   233,   234,   237,   238,
     241,   244,   245,   251,   252,   255,   256,   259,   260,   263,
     264,   267,   268,   269,   270,   273,   274,   277,   278,   281,
     282,   285,   286,   287,   288,   291,   292,   293,   299,   301,
     303,   305,   307,   309,   310,   311
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "PNUMBER", "NNUMBER", "FLOAT",
  "STARTCHORD", "ENDCHORD", "STARTSEQ", "ENDSEQ", "STARTPARAM", "ENDPARAM",
  "STARTRANGE", "ENDRANGE", "SEP", "IDSEP", "BAR", "TAGNAME", "ID",
  "DIATONIC", "CHROMATIC", "SOLFEGE", "EMPTY", "REST", "DOT", "DDOT",
  "SHARP", "FLAT", "MLS", "SEC", "UNIT", "MULT", "DIV", "EQUAL", "STRING",
  "EXTRA", "$accept", "score", "voicelist", "voice", "symbols", "tag",
  "positiontag", "rangetag", "tagname", "tagid", "tagarg", "tagparam",
  "tagparams", "chord", "chordsymbols", "tagchordsymbol", "chordsymbol",
  "rangechordtag", "taglist", "music", "rest", "note", "noteid",
  "notename", "accidentals", "accidental", "octave", "duration", "dots",
  "id", "number", "pnumber", "nnumber", "floatn", "signednumber", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    38,    38,    39,    39,    40,    41,    41,
      41,    41,    42,    42,    43,    43,    44,    45,    46,    46,
      46,    47,    47,    47,    47,    47,    47,    48,    48,    49,
      49,    50,    51,    51,    52,    52,    52,    52,    53,    53,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    60,    60,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    64,    64,    65,    65,    65,    66,    67,
      68,    69,    70,    71,    71,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     1,     1,     3,     3,     0,     2,
       2,     2,     1,     1,     1,     4,     4,     1,     1,     3,
       1,     1,     1,     2,     2,     1,     1,     1,     3,     1,
       3,     3,     1,     3,     1,     2,     2,     3,     1,     1,
       4,     1,     2,     1,     1,     3,     6,     4,     5,     1,
       4,     1,     1,     1,     1,     1,     2,     1,     1,     0,
       1,     0,     4,     2,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     8,     0,     4,     2,     0,     5,     0,     1,
       3,     0,     0,     7,    20,    17,    51,    52,    53,    54,
      61,    10,    12,    13,    18,    14,    11,     9,    44,    43,
      59,    49,     6,    41,     0,    32,    34,    39,     0,    38,
       0,     0,     0,    65,     8,     0,     0,    69,    70,    71,
      57,    58,    59,    55,    61,    73,    74,    75,    60,     0,
       0,    31,     0,    41,    36,    42,    35,     0,    63,    64,
      66,    67,    45,     0,    19,    72,    68,    25,    27,    29,
       0,    26,    22,    21,    56,    61,    65,     0,     0,    33,
      42,    37,    61,     0,    16,    15,     0,     0,    24,    23,
      65,    47,    50,    40,    65,    62,    30,    28,    26,    48,
      46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     6,     4,     8,    21,    33,    23,    24,    25,
      78,    79,    80,    26,    34,    35,    36,    37,    38,    39,
      28,    29,    30,    31,    52,    53,    54,    43,    72,    81,
      55,    56,    57,    82,    83
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -67
static const yytype_int8 yypact[] =
{
       6,    36,   -67,    14,   -67,   -67,    40,   -67,    50,   -67,
     -67,    10,    58,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
      -1,   -67,    16,   -67,    43,    15,   -67,   -67,   -67,   -67,
      13,    66,   -67,    48,    54,   -67,    46,   -67,    58,   -67,
      83,    86,    86,    59,   -67,    87,     2,   -67,   -67,   -67,
     -67,   -67,    13,   -67,    55,   -67,   -67,   -67,   -67,    88,
      58,   -67,    58,   -67,    46,    48,    46,    80,    60,   -67,
     -67,   -67,   -67,    29,   -67,   -67,   -67,   -67,   -67,   -67,
      12,    61,    63,    65,   -67,    55,    59,    85,    84,   -67,
     -67,    46,    55,    86,   -67,   -67,     2,     2,   -67,   -67,
      59,   -67,   -67,   -67,    59,   -67,   -67,   -67,   -67,   -67,
     -67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,   -67,    11,    56,   -67,    -8,   -67,   -67,   -67,
       4,     3,   -67,   -67,   -67,   -37,    64,   -67,   -27,    -7,
     -67,   -67,   -67,   -67,   -67,    51,    52,   -50,   -66,     8,
     -39,   -67,   -67,   -67,   -19
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      22,    27,    68,    69,    86,    47,    48,    49,    75,    64,
      40,    58,     7,     1,     9,     2,    47,    48,    49,     2,
     101,    76,    32,    88,    95,    89,    46,    96,    63,    44,
      65,    41,    42,    58,   109,   100,    12,    77,   110,    91,
      50,    51,   104,    94,     5,     2,    14,    15,    10,    16,
      17,    18,    19,    20,   105,    11,    90,    12,    63,    45,
      13,    60,    61,    14,    15,    22,    27,    14,    15,    62,
      16,    17,    18,    19,    20,    14,    15,    59,    16,    17,
      18,    19,    20,    90,    70,    71,    67,    41,    42,    47,
      74,    87,    92,    93,    98,    97,    99,   102,   103,   106,
      73,   107,    66,    84,    85,   108
};

static const yytype_uint8 yycheck[] =
{
       8,     8,    41,    42,    54,     3,     4,     5,     6,    36,
      11,    30,     1,     7,     0,     9,     3,     4,     5,     9,
      86,    19,    11,    60,    12,    62,    11,    15,    36,    13,
      38,    32,    33,    52,   100,    85,     7,    35,   104,    66,
      27,    28,    92,    14,     8,     9,    17,    18,     8,    20,
      21,    22,    23,    24,    93,    15,    64,     7,    66,    16,
      10,    13,     8,    17,    18,    73,    73,    17,    18,    15,
      20,    21,    22,    23,    24,    17,    18,    11,    20,    21,
      22,    23,    24,    91,    25,    26,     3,    32,    33,     3,
       3,     3,    12,    33,    31,    34,    31,    12,    14,    96,
      44,    97,    38,    52,    52,    97
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     9,    38,    40,     8,    39,    40,    41,     0,
       8,    15,     7,    10,    17,    18,    20,    21,    22,    23,
      24,    42,    43,    44,    45,    46,    50,    56,    57,    58,
      59,    60,    40,    43,    51,    52,    53,    54,    55,    56,
      11,    32,    33,    64,    13,    16,    11,     3,     4,     5,
      27,    28,    61,    62,    63,    67,    68,    69,    71,    11,
      13,     8,    15,    43,    55,    43,    53,     3,    67,    67,
      25,    26,    65,    41,     3,     6,    19,    35,    47,    48,
      49,    66,    70,    71,    62,    63,    64,     3,    52,    52,
      43,    55,    12,    33,    14,    12,    15,    34,    31,    31,
      64,    65,    12,    14,    64,    67,    48,    47,    66,    65,
      65
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 165 "guido.y"
    { debug("new score"); (yyval.elt) = gReader->newScore(); ;}
    break;

  case 3:
#line 166 "guido.y"
    { debug("score voicelist"); (yyval.elt) = gReader->newScore(); addElt(*(yyval.elt), (yyvsp[(2) - (3)].velt)); ;}
    break;

  case 4:
#line 167 "guido.y"
    { debug("score voice"); (yyval.elt) = gReader->newScore(); addElt(*(yyval.elt), (yyvsp[(1) - (1)].elt)); ;}
    break;

  case 5:
#line 170 "guido.y"
    { debug("new voicelist"); (yyval.velt) = new vector<Sguidoelement>; (yyval.velt)->push_back (*(yyvsp[(1) - (1)].elt)); delete (yyvsp[(1) - (1)].elt); ;}
    break;

  case 6:
#line 171 "guido.y"
    { debug("add voicelist"); (yyval.velt) = (yyvsp[(1) - (3)].velt); (yyval.velt)->push_back (*(yyvsp[(3) - (3)].elt)); delete (yyvsp[(3) - (3)].elt); ;}
    break;

  case 7:
#line 174 "guido.y"
    { debug("new voice"); (yyval.elt) = gReader->newVoice(); addElt(*(yyval.elt), (yyvsp[(2) - (3)].velt)); ;}
    break;

  case 8:
#line 177 "guido.y"
    { debug("new symbols"); (yyval.velt) = new vector<Sguidoelement>; ;}
    break;

  case 9:
#line 178 "guido.y"
    { debug("add music"); (yyval.velt) = (yyvsp[(1) - (2)].velt); (yyval.velt)->push_back(*(yyvsp[(2) - (2)].elt)); delete (yyvsp[(2) - (2)].elt); ;}
    break;

  case 10:
#line 179 "guido.y"
    { debug("add tag"); (yyval.velt) = (yyvsp[(1) - (2)].velt); (yyval.velt)->push_back(*(yyvsp[(2) - (2)].elt)); delete (yyvsp[(2) - (2)].elt); ;}
    break;

  case 11:
#line 180 "guido.y"
    { debug("add chord"); (yyval.velt) = (yyvsp[(1) - (2)].velt); (yyval.velt)->push_back(*(yyvsp[(2) - (2)].elt)); delete (yyvsp[(2) - (2)].elt); ;}
    break;

  case 12:
#line 185 "guido.y"
    { debug("position tag "); (yyval.elt) = (yyvsp[(1) - (1)].elt); ;}
    break;

  case 13:
#line 186 "guido.y"
    { debug("range tag "); (yyval.elt) = (yyvsp[(1) - (1)].elt); ;}
    break;

  case 14:
#line 189 "guido.y"
    { debug("new position tag "); (yyval.elt) = (yyvsp[(1) - (1)].elt); ;}
    break;

  case 15:
#line 190 "guido.y"
    { debug("new tag + params"); (yyval.elt) = (yyvsp[(1) - (4)].elt); (*(yyvsp[(1) - (4)].elt))->add (*(yyvsp[(3) - (4)].vattr)); delete (yyvsp[(3) - (4)].vattr); ;}
    break;

  case 16:
#line 193 "guido.y"
    { debug("new range tag "); (yyval.elt) = (yyvsp[(1) - (4)].elt); (*(yyvsp[(1) - (4)].elt))->push (*(yyvsp[(3) - (4)].velt)); delete (yyvsp[(3) - (4)].velt); ;}
    break;

  case 17:
#line 196 "guido.y"
    { debug("tag name "); (yyval.str) = new string(guidoartext); ;}
    break;

  case 18:
#line 199 "guido.y"
    { vdebug("new tag", *(yyvsp[(1) - (1)].str)); (yyval.elt) = gReader->newTag(*(yyvsp[(1) - (1)].str), 0); delete (yyvsp[(1) - (1)].str); if (!(yyval.elt)) { guidoarerror("unknown tag"); YYERROR;} ;}
    break;

  case 19:
#line 200 "guido.y"
    { debug("new tag::id"); (yyval.elt) = gReader->newTag(*(yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].c)); delete (yyvsp[(1) - (3)].str); if (!(yyval.elt)) { guidoarerror("unknown tag"); YYERROR;} ;}
    break;

  case 20:
#line 201 "guido.y"
    { debug("new bar"); (yyval.elt) = gReader->newTag("bar", 0); ;}
    break;

  case 21:
#line 204 "guido.y"
    { debug("new signednumber arg"); (yyval.attr) = gReader->newAttribute((yyvsp[(1) - (1)].num)); ;}
    break;

  case 22:
#line 205 "guido.y"
    { debug("new FLOAT arg"); (yyval.attr) = gReader->newAttribute((yyvsp[(1) - (1)].real)); ;}
    break;

  case 23:
#line 206 "guido.y"
    { debug("new signednumber UNIT arg"); (yyval.attr) = gReader->newAttribute((yyvsp[(1) - (2)].num)); (*(yyval.attr))->setUnit(guidoartext); ;}
    break;

  case 24:
#line 207 "guido.y"
    { debug("new FLOAT UNIT arg"); (yyval.attr) = gReader->newAttribute((yyvsp[(1) - (2)].real)); (*(yyval.attr))->setUnit(guidoartext); ;}
    break;

  case 25:
#line 208 "guido.y"
    { debug("new STRING arg"); (yyval.attr) = gReader->newAttribute(guidoartext, true); ;}
    break;

  case 26:
#line 209 "guido.y"
    { debug("new ID arg"); (yyval.attr) = gReader->newAttribute(*(yyvsp[(1) - (1)].str), false); delete (yyvsp[(1) - (1)].str); ;}
    break;

  case 27:
#line 212 "guido.y"
    { (yyval.attr) = (yyvsp[(1) - (1)].attr); ;}
    break;

  case 28:
#line 213 "guido.y"
    { (yyval.attr) = (yyvsp[(3) - (3)].attr); (*(yyvsp[(3) - (3)].attr))->setName(*(yyvsp[(1) - (3)].str)); delete (yyvsp[(1) - (3)].str); ;}
    break;

  case 29:
#line 216 "guido.y"
    { (yyval.vattr) = new vector<Sguidoattribute>; (yyval.vattr)->push_back(*(yyvsp[(1) - (1)].attr)); delete (yyvsp[(1) - (1)].attr); ;}
    break;

  case 30:
#line 217 "guido.y"
    { (yyval.vattr) = (yyvsp[(1) - (3)].vattr); (yyval.vattr)->push_back(*(yyvsp[(3) - (3)].attr)); delete (yyvsp[(3) - (3)].attr); ;}
    break;

  case 31:
#line 224 "guido.y"
    { debug("new chord"); (yyval.elt) = gReader->newChord(); (*(yyval.elt))->push(*(yyvsp[(2) - (3)].velt)); delete (yyvsp[(2) - (3)].velt); ;}
    break;

  case 32:
#line 227 "guido.y"
    { (yyval.velt) = new vector<Sguidoelement>; vadd((yyval.velt), (yyvsp[(1) - (1)].velt)); delete (yyvsp[(1) - (1)].velt); ;}
    break;

  case 33:
#line 228 "guido.y"
    { (yyval.velt) = (yyvsp[(1) - (3)].velt); vadd((yyval.velt), (yyvsp[(3) - (3)].velt)); delete (yyvsp[(3) - (3)].velt); ;}
    break;

  case 34:
#line 231 "guido.y"
    { (yyval.velt) = (yyvsp[(1) - (1)].velt);;}
    break;

  case 35:
#line 232 "guido.y"
    { (yyval.velt) = (yyvsp[(1) - (2)].velt); vadd((yyval.velt), (yyvsp[(2) - (2)].velt)); delete (yyvsp[(2) - (2)].velt); ;}
    break;

  case 36:
#line 233 "guido.y"
    { (yyval.velt) = (yyvsp[(1) - (2)].velt); vadd((yyval.velt), (yyvsp[(2) - (2)].velt)); delete (yyvsp[(2) - (2)].velt); ;}
    break;

  case 37:
#line 234 "guido.y"
    { (yyval.velt) = (yyvsp[(1) - (3)].velt); vadd((yyval.velt), (yyvsp[(2) - (3)].velt)); delete (yyvsp[(2) - (3)].velt); vadd((yyval.velt), (yyvsp[(3) - (3)].velt)); delete (yyvsp[(3) - (3)].velt); ;}
    break;

  case 38:
#line 237 "guido.y"
    { (yyval.velt) = new vector<Sguidoelement>; (yyval.velt)->push_back(*(yyvsp[(1) - (1)].elt)); delete (yyvsp[(1) - (1)].elt); ;}
    break;

  case 39:
#line 238 "guido.y"
    { (yyval.velt) = new vector<Sguidoelement>; (yyval.velt)->push_back(*(yyvsp[(1) - (1)].elt)); delete (yyvsp[(1) - (1)].elt); ;}
    break;

  case 40:
#line 241 "guido.y"
    { debug("range chord tag"); (yyval.elt) = (yyvsp[(1) - (4)].elt); (*(yyval.elt))->push(*(yyvsp[(3) - (4)].velt)); delete (yyvsp[(3) - (4)].velt); ;}
    break;

  case 41:
#line 244 "guido.y"
    { debug("new taglist 1"); (yyval.velt) = new vector<Sguidoelement>; (yyval.velt)->push_back(*(yyvsp[(1) - (1)].elt)); delete (yyvsp[(1) - (1)].elt); ;}
    break;

  case 42:
#line 245 "guido.y"
    { debug("new taglist 2"); (yyval.velt) = (yyvsp[(1) - (2)].velt); (yyval.velt)->push_back(*(yyvsp[(2) - (2)].elt)); delete (yyvsp[(2) - (2)].elt); ;}
    break;

  case 43:
#line 251 "guido.y"
    { (yyval.elt) = (yyvsp[(1) - (1)].elt); ;}
    break;

  case 44:
#line 252 "guido.y"
    { (yyval.elt) = (yyvsp[(1) - (1)].elt); ;}
    break;

  case 45:
#line 255 "guido.y"
    { debug("new rest 1"); (yyval.elt) = gReader->newRest((yyvsp[(2) - (3)].r), (yyvsp[(3) - (3)].num)); delete (yyvsp[(2) - (3)].r); ;}
    break;

  case 46:
#line 256 "guido.y"
    { debug("new rest 2"); (yyval.elt) = gReader->newRest((yyvsp[(5) - (6)].r), (yyvsp[(6) - (6)].num)); delete (yyvsp[(5) - (6)].r); ;}
    break;

  case 47:
#line 259 "guido.y"
    { debug("new note v1"); (yyval.elt) = gReader->newNote(*(yyvsp[(1) - (4)].str), 0, (yyvsp[(2) - (4)].num), (yyvsp[(3) - (4)].r), (yyvsp[(4) - (4)].num)); delete (yyvsp[(1) - (4)].str); delete (yyvsp[(3) - (4)].r); ;}
    break;

  case 48:
#line 260 "guido.y"
    { debug("new note v2"); (yyval.elt) = gReader->newNote(*(yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].num), (yyvsp[(3) - (5)].num), (yyvsp[(4) - (5)].r), (yyvsp[(5) - (5)].num)); delete (yyvsp[(1) - (5)].str); delete (yyvsp[(4) - (5)].r); ;}
    break;

  case 49:
#line 263 "guido.y"
    { vdebug("notename", *(yyvsp[(1) - (1)].str)); (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 50:
#line 264 "guido.y"
    { (yyval.str) = (yyvsp[(1) - (4)].str); ;}
    break;

  case 51:
#line 267 "guido.y"
    { debug("new diatonic note"); (yyval.str) = new string(guidoartext); ;}
    break;

  case 52:
#line 268 "guido.y"
    { debug("new chromatic note"); (yyval.str) = new string(guidoartext); ;}
    break;

  case 53:
#line 269 "guido.y"
    { debug("new solfege note"); (yyval.str) = new string(guidoartext); ;}
    break;

  case 54:
#line 270 "guido.y"
    { debug("new empty note"); (yyval.str) = new string(guidoartext); ;}
    break;

  case 55:
#line 273 "guido.y"
    { debug("accidental"); (yyval.num) = (yyvsp[(1) - (1)].num); ;}
    break;

  case 56:
#line 274 "guido.y"
    { debug("accidentals"); (yyval.num) = (yyvsp[(1) - (2)].num) + (yyvsp[(2) - (2)].num); ;}
    break;

  case 57:
#line 277 "guido.y"
    { debug("sharp"); (yyval.num) = 1; ;}
    break;

  case 58:
#line 278 "guido.y"
    { debug("flat"); (yyval.num) = -1; ;}
    break;

  case 59:
#line 281 "guido.y"
    { debug("no octave"); (yyval.num) = -1000; ;}
    break;

  case 60:
#line 282 "guido.y"
    { debug("octave"); (yyval.num) = (yyvsp[(1) - (1)].num); ;}
    break;

  case 61:
#line 285 "guido.y"
    { debug("implicit duration"); (yyval.r) = new rational(-1, 1); ;}
    break;

  case 62:
#line 286 "guido.y"
    { debug("duration ./."); (yyval.r) = new rational((yyvsp[(2) - (4)].num), (yyvsp[(4) - (4)].num)); ;}
    break;

  case 63:
#line 287 "guido.y"
    { debug("duration *"); (yyval.r) = new rational((yyvsp[(2) - (2)].num), 1); ;}
    break;

  case 64:
#line 288 "guido.y"
    { debug("duration /"); (yyval.r) = new rational(1, (yyvsp[(2) - (2)].num)); ;}
    break;

  case 65:
#line 291 "guido.y"
    { debug("dots 0"); (yyval.num) = 0; ;}
    break;

  case 66:
#line 292 "guido.y"
    { debug("dots 1"); (yyval.num) = 1; ;}
    break;

  case 67:
#line 293 "guido.y"
    { debug("dots 2"); (yyval.num) = 2; ;}
    break;

  case 68:
#line 299 "guido.y"
    { (yyval.str) = new string(guidoartext); ;}
    break;

  case 69:
#line 301 "guido.y"
    { vdebug("NUMBER", guidoartext); (yyval.num) = atol(guidoartext); ;}
    break;

  case 70:
#line 303 "guido.y"
    { vdebug("NUMBER", guidoartext); (yyval.num) = atol(guidoartext); ;}
    break;

  case 71:
#line 305 "guido.y"
    { vdebug("NUMBER", guidoartext); (yyval.num) = atol(guidoartext); ;}
    break;

  case 72:
#line 307 "guido.y"
    { (yyval.real) = dotatof(guidoartext); ;}
    break;

  case 73:
#line 309 "guido.y"
    { (yyval.num) = (yyvsp[(1) - (1)].num); ;}
    break;

  case 74:
#line 310 "guido.y"
    { (yyval.num) = (yyvsp[(1) - (1)].num); ;}
    break;

  case 75:
#line 311 "guido.y"
    { (yyval.num) = (yyvsp[(1) - (1)].num); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1958 "guidoparse.c++"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 313 "guido.y"


} // namespace

int guidoarerror(const char*s) {
	YY_FLUSH_BUFFER;
	return gReader->error(s, guidoarlineno);
}
