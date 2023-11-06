%{
#include "../syntaxtree.h"
#include "parser.hpp"
#include <algorithm>

  /* Keep track of current position of lex for error messages, i.e. 
     the position just *after* the last token read */
  int line_nr = 0;
  int col_nr = 1; 

  enum yytokentype lastTokenType = SEMICOLON;

  void adjust(){
    for (int i = 0; i < yyleng;++i){
      if (yytext[i] == '\n'){
        col_nr = 1;
        line_nr += 1;
      } else{
        col_nr += 1;
      }
    }
  }

  bool startsWith(std::string s, std::string prefix){
    if (s.rfind(prefix, 0) == 0) return true;
    return false;
  }

  char stringToEscape(std::string s){
    if (s == "\\a")
      return '\a';
    else if (s == "\\b")
      return '\b';
    else if (s == "\\f")
      return '\f';
    else if (s == "\\n")
      return '\n';
    else if (s == "\\r")
      return '\r';
    else if (s == "\\t")
      return '\t';
    else if (s == "\\v")
      return '\v';
    else if (s == "\\\\")
      return '\\';
    else if (s == "\\'")
      return '\'';
    else if (s == "\\\"")
      return '"';
    return ' ';
  }
%}

whitespace [\t ]
comment "/*".*"*/"|"//"[^\n{<<EOF>>}]*[\n{<<EOF>>}]
digit [0-9]
letter [a-zA-Z_]
bin_digit [01]
oct_digit [0-7]
hex_digit [0-9a-fA-F]
bin_prefix 0[bB]
oct_prefix 0[oO]
hex_prefix 0[xX]

decimal_lit {digit}+(_?{digit}+)*
binary_lit {bin_prefix}(_?{bin_digit})+
octal_lit {oct_prefix}(_?{oct_digit})+
hex_lit {hex_prefix}(_?{hex_digit})+

escape_char \\a|\\b|\\f|\\n|\\r|\\t|\\v|\\\\|\\'|\\\"
rune_lit '([^\\']|{escape_char})'
string_lit \"([^(\\.)\"]|{escape_char})*\"


%%
\n {
  adjust();

  switch (lastTokenType){
    case IDENTIFIER:
    case INTLITERAL:
    case RETURN:
    case RPAREN:
    case RBRACE:
    case INC:
    case DEC:
      lastTokenType = SEMICOLON;
      return SEMICOLON;
    default:
      break;
  }
}
{whitespace}|{comment}|\r {
  adjust();
  // ignore tabs,spaces and comments and carriage return
}
; {
  adjust();
  lastTokenType = SEMICOLON;
  return SEMICOLON;
}
, {
  adjust();
  lastTokenType = COMMA;
  return COMMA;
}
{decimal_lit}|{binary_lit}|{octal_lit}|{hex_lit} {
  adjust();
  std::string text{yytext};
  // remove "_" characters
  text.erase(std::remove(text.begin(), text.end(), '_'), text.end());

  int base = 10;

  if (startsWith(yytext, "0B") || startsWith(yytext, "0b")){
    base = 2;
  } else if (startsWith(yytext, "0X") || startsWith(yytext, "0x")){
    base = 16;
  } else if (startsWith(yytext, "0O") || startsWith(yytext, "0o")){
    base = 8;
  }
  if (base != 10){
    text.erase(0,2);  // erase prefix
  }
  yylval.integer = std::stol(text, 0, base);

  lastTokenType = INTLITERAL;
  return INTLITERAL;
}
true {
  adjust();
  yylval.boolean = true;
  lastTokenType = BOOLLITERAL;
  return BOOLLITERAL;
}
false {
  adjust();
  yylval.boolean = false;
  lastTokenType = BOOLLITERAL;
  return BOOLLITERAL;
}
package {
  adjust();
  lastTokenType = PACKAGE;
  return PACKAGE;
}
return {
  adjust();
  lastTokenType = RETURN;
  return RETURN;
}
var {
  adjust();
  lastTokenType = VAR;
  return VAR;
}
if {
  adjust();
  lastTokenType = IF;
  return IF;
}
else {
  adjust();
  lastTokenType = ELSE;
  return ELSE;
}
for {
  adjust();
  lastTokenType = FOR;
  return FOR;
}
func {
  adjust();
  lastTokenType = FUNC;
  return FUNC;
}
\( {
  adjust();
  lastTokenType = LPAREN;
  return LPAREN;
}
\) {
  adjust();
  lastTokenType = RPAREN;
  return RPAREN;
}
\{ {
  adjust();
  lastTokenType = LBRACE;
  return LBRACE;
}
\} {
  adjust();
  lastTokenType = RBRACE;
  return RBRACE;
}
\[ {
  adjust();
  lastTokenType = LBRACK;
  return LBRACK;
}
\] {
  adjust();
  lastTokenType = RBRACK;
  return RBRACK;
}
\+\+ {
  adjust();
  lastTokenType = INC;
  return INC;
}
\-\- {
  adjust();
  lastTokenType = DEC;
  return DEC;
}
\+ {
  adjust();
  lastTokenType = PLUS;
  return PLUS;
}
\- {
  adjust();
  lastTokenType = MIN;
  return MIN;
}
\* {
  adjust();
  lastTokenType = MUL;
  return MUL;
}
\/ {
  adjust();
  lastTokenType = DIV;
  return DIV;
}
\+= {
  adjust();
  lastTokenType = PLUSASSIGN;
  return PLUSASSIGN;
}
\-= {
  adjust();
  lastTokenType = MINASSIGN;
  return MINASSIGN;
}
\*= {
  adjust();
  lastTokenType = MULASSIGN;
  return MULASSIGN;
}
\/= {
  adjust();
  lastTokenType = DIVASSIGN;
  return DIVASSIGN;
}
&& {
  adjust();
  lastTokenType = AND;
  return AND;
}
\|\| {
  adjust();
  lastTokenType = OR;
  return OR;
}
! {
  adjust();
  lastTokenType = NOT;
  return NOT;
}
\> {
  adjust();
  lastTokenType = GT;
  return GT;
}
\>= {
  adjust();
  lastTokenType = GE;
  return GE;
}
\< {
  adjust();
  lastTokenType = LT;
  return LT;
}
\<= {
  adjust();
  lastTokenType = LE;
  return LE;
}
= {
  adjust();
  lastTokenType = ASSIGN;
  return ASSIGN;
}
== {
  adjust();
  lastTokenType = EQ;
  return EQ;
}
!= {
  adjust();
  lastTokenType = NE;
  return NE;
}
int {
  adjust();
  lastTokenType = INT;
  return INT;
}
bool {
  adjust();
  lastTokenType = BOOL;
  return BOOL;
}
rune {
  adjust();
  lastTokenType = RUNE;
  return RUNE;
}
string {
  adjust();
  lastTokenType = STRING;
  return STRING;
}

{letter}({letter}|{digit})* {
  adjust();
  char* s = new char[yyleng+1];
  strcpy(s, yytext);
  yylval.string = s;
  lastTokenType = IDENTIFIER;
  return IDENTIFIER;
}
{rune_lit} {
  adjust();
  lastTokenType = RUNELITERAL;
  if (yyleng == 3){
    yylval.character = yytext[1];
  }else {
    yytext[3] = '\0'; // remove ending '
    yylval.character = stringToEscape(yytext + 1);
  }
  return RUNELITERAL;
}
{string_lit} {
  adjust();
  lastTokenType = STRINGLITERAL;
  std::string string = yytext;

  // remove ""
  string.erase(0, 1);
  string.erase(string.size()-1, 1);

  // convert escape characters
  int i = 0;
  while (i < string.size()){
    if (string[i ] == '\\'){
      std::string escape = string.substr(i, 2);
      string.erase(i, 2);
      std::string c = std::string(1, stringToEscape(escape));
      string.insert(i, c);
    }
    ++i;
  }

  char* s = new char[string.size()+1];
  strcpy(s, string.c_str());
  yylval.string = s;
  return STRINGLITERAL;
}
. {
  if (yytext[0] < ' '){ /* non-printable char */
    /*yyerror*/ fprintf(stderr,"illegal character: ^%c",yytext[0] + '@'); 
  }
  else {
    if (yytext[0] > '~') {
      /* non-printable char printed as octal int padded with zeros, eg \012*/
      /*yyerror(*/fprintf(stderr,"illegal character: \\%03o", (int) yytext[0]);
    }
    else {
      /*yyerror(*/fprintf(stderr,"illegal character: %s",yytext);
    }
  }
  /* lex read exactly one char; the illegal one */
  fprintf(stderr," at line %d column %d: \"%s\"\n", line_nr, (col_nr-1), yytext);
  adjust();
}
%%

/* Function called by (f)lex when EOF is read. If yywrap returns a
   true (non-zero) (f)lex will terminate and continue otherwise.*/
int yywrap(){
  return (1);
}
