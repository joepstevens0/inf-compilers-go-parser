%{
#include "../syntaxtree.h"
#include "../lexer.h"
Stm* syntree = nullptr;
bool parseSuccess = true;

void yyerror(const char* str);

%}
%union {
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
}

// tokens
%token <string> IDENTIFIER
%token <integer> INTLITERAL
%token <boolean> BOOLLITERAL
%token <character> RUNELITERAL
%token <string> STRINGLITERAL
%token
SEMICOLON COMMA INT BOOL RUNE STRING PACKAGE RETURN VAR IF ELSE FOR
LPAREN RPAREN LBRACE RBRACE LBRACK RBRACK
PLUS MIN MUL DIV 
ASSIGN PLUSASSIGN MINASSIGN MULASSIGN DIVASSIGN
AND OR NOT 
INC DEC 
GT GE LT LE EQ NE
FUNC

// types
%type <stm> start;
%type <stm> stm;
%type <exp> exp;
%type <stm> prog;
%type <type> type;
%type <type> realtype;
%type <signature> signature;
%type <arguments> arguments;
%type <parameters> parameters;
%type <parameter> parameter;
%type <stm> assignment;
%type <blockstm> blockstm;
%type <ifstm> ifstm;
%type <exp> operand;
%type <op> binary_op;
%type <op> rel_op;
%type <op> add_op;
%type <op> mul_op;
%type <op> unary_op;
%type <exp> rel_exp;
%type <exp> add_exp;
%type <exp> mul_exp;
%type <exp> index_exp;

%left PLUS MIN 
%left MUL DIV 
%left OR AND
%right UNARY

%defines

%%
start:
  prog {$$ = $1; syntree = $$;}
;

prog:
  stm SEMICOLON prog {$$ = new CompoundStm($1, $3);}
| stm {$$ = new LastStm($1);}
| blockstm SEMICOLON prog {$$ = new CompoundStm($1, $3);}
| blockstm {$$ = $1;}
;

stm: 
 VAR IDENTIFIER INT ASSIGN exp {$$ = new IntCreateStm($2, $5);}
| VAR IDENTIFIER INT {$$ = new IntCreateStm($2);}
| VAR IDENTIFIER BOOL ASSIGN exp {$$ = new BoolCreateStm($2, $5);}
| VAR IDENTIFIER BOOL {$$ = new BoolCreateStm($2);}
| VAR IDENTIFIER RUNE ASSIGN exp {$$ = new RuneCreateStm($2, $5);}
| VAR IDENTIFIER RUNE {$$ = new RuneCreateStm($2);}
| VAR IDENTIFIER STRING ASSIGN exp {$$ = new StringCreateStm($2, $5);}
| VAR IDENTIFIER STRING {$$ = new StringCreateStm($2);}
| VAR IDENTIFIER ASSIGN exp {$$ = new VarCreateStm($2, $4);}

| FUNC IDENTIFIER signature blockstm {$$ = new FunctionStm($2, $3, $4);}
| PACKAGE IDENTIFIER {$$ = new PackageStm($2);}
| assignment {$$ = $1;}
| IDENTIFIER LPAREN arguments RPAREN {$$ = new CallStm($1, $3);}

| RETURN exp {$$ = new ReturnStm($2);}
| RETURN {$$ = new ReturnStm(nullptr);}

| IDENTIFIER INC {$$ = new IncrementStm($1);}
| IDENTIFIER DEC {$$ = new DecrementStm($1);}

| ifstm {$$ = $1;}
| FOR exp blockstm {$$ = new ForStm($2, $3);}
| FOR stm SEMICOLON exp SEMICOLON stm blockstm {$$ = new ForStm($4, $7, $2, $6);}

| {$$ = new NoOpStm();}
| error {$$ = new ErrorStm();}
;

ifstm:
 IF exp blockstm {$$ = new IfStm($2, $3);}
| IF stm SEMICOLON exp blockstm {$$ = new IfStm($4, $5, $2);}
| IF exp blockstm ELSE ifstm {$$ = new IfStm($2, $3, nullptr, $5);}
| IF exp blockstm ELSE blockstm {$$ = new IfStm($2, $3, nullptr, $5);}
| IF stm SEMICOLON exp blockstm ELSE ifstm {$$ = new IfStm($4, $5, $2, $7);}
| IF stm SEMICOLON exp blockstm ELSE blockstm {$$ = new IfStm($4, $5, $2, $7);}
;

blockstm:
  LBRACE prog RBRACE {$$ = new BlockStm($2);}
;

realtype:
  INT {$$ = Type::intType;}
| BOOL {$$ = Type::boolType;}
| RUNE {$$ = Type::runeType;}
| STRING {$$ = Type::stringType;}
;
type:
  realtype
| {$$ = Type::voidType;}
;

exp:
  rel_exp
| exp binary_op rel_exp {$$ = new OpExp($1, $2, $3);}
;
rel_exp:
  add_exp
| rel_exp rel_op add_exp {$$ = new OpExp($1, $2, $3);}
;
add_exp:
  mul_exp
| add_exp add_op mul_exp {$$ = new OpExp($1, $2, $3);}
;
mul_exp:
  index_exp
| mul_exp mul_op operand {$$ = new OpExp($1, $2, $3);}
;
index_exp:
  operand
| index_exp LBRACK exp RBRACK {$$ = new IndexExp($1, $3);}

operand:
  IDENTIFIER {$$ = new IdExp($1);}
| IDENTIFIER LPAREN arguments RPAREN {$$ = new CallExp($1, $3);}
| LPAREN exp RPAREN {$$ = $2;}
| BOOLLITERAL {$$ = new BoolLiteralExp($1);}
| INTLITERAL {$$ = new IntLiteralExp($1);} 
| RUNELITERAL {$$ = new RuneLiteralExp($1);}
| STRINGLITERAL {$$ = new StringLiteralExp($1);}
| unary_op operand %prec UNARY {$$ = new OpExp(nullptr,$1, $2);}
;

binary_op:
 AND {$$ = Operator::And;} 
| OR {$$ = Operator::Or;} 
;
add_op:
  PLUS {$$ = Operator::Plus;} 
| MIN {$$ = Operator::Minus;}
;
mul_op:
 MUL {$$ = Operator::Mul;} 
| DIV {$$ = Operator::Div;}
;
rel_op:
 GT {$$ = Operator::Greater;} 
| GE {$$ = Operator::GreaterOrEqual;} 
| LT {$$ = Operator::Lesser;} 
| LE {$$ = Operator::LesserOrEqual;} 
| EQ {$$ = Operator::Equal;} 
| NE {$$ = Operator::NotEqual;}
;
unary_op:
  PLUS {$$ = Operator::Plus;} 
| MIN {$$ = Operator::Minus;}
| NOT {$$ = Operator::Not;}
;

signature:
  LPAREN parameters RPAREN type {$$ = new Signature($2, $4);}
;

parameters:
  parameter COMMA parameters {$$ = new ParametersList($1, $3);}
| parameter {$$ = new ParametersLast($1);}
| {$$ = nullptr;}
;

parameter:
  IDENTIFIER realtype {$$ = new Parameter($1, $2);}
;

arguments:
  exp COMMA arguments {$$ = new ArgumentsList($1, $3);}
| exp {$$ = new ArgumentsLast($1);}
| {$$ = nullptr;}
;

assignment:
  IDENTIFIER ASSIGN exp {$$ = new VarAssignStm($1, $3);}
| IDENTIFIER PLUSASSIGN exp {$$ = new PlusAssignStm($1, $3);}
| IDENTIFIER MINASSIGN exp {$$ = new IntMinAssignStm($1, $3);}
| IDENTIFIER MULASSIGN exp {$$ = new IntMulAssignStm($1, $3);}
| IDENTIFIER DIVASSIGN exp {$$ = new IntDivAssignStm($1, $3);}
;

%%
extern int line_nr;
extern int col_nr;
void yyerror(const char *s)
{
  // vul aan
  fprintf(stderr,"%s at line %d\n",s, line_nr);
  parseSuccess = false;
}
