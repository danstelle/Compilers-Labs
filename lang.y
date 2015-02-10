/***********************************
*lang.y
*
*Daniel Stelle
*daniel.stelle@oit.edu
************************************/

%{
#include <iostream>
#include "lex.h"
%}

%locations

%union{
    int             int_val;
    double          float_val;
    cAstNode*       ast_node;
    cSymbol*        symbol;
    cSymbolTable*   sym_table;
    BlockNode*      block_node;
    PrintNode*      print_node;
    ExprNode*       expr_node;
    StmtsNode*      stmts_node;
    VarRef*         var_ref;
    DeclsNode*      decls_node;
    DeclNode*       decl_node;
    ArraySpec*      aspec_node;
    VarPart*        var_part;
    ArrayVal*       aval_node;
    StmtNode*       stmt_node;
    FuncHeader*     func_header;
    FuncCall*       func_call;
    FuncPrefix*     func_prefix;
    ParamNode*      param_node;
    ParamsNode*     params_node;
    ParamSpec*      param_spec;
    ParamsSpec*     params_spec;
    }

%{
    int yyerror(const char *msg);

    void *yyast_root;
%}

%start  program

%token <symbol>    IDENTIFIER
%token <symbol>    TYPE_ID
%token <int_val>    INT_VAL
%token <float_val>  FLOAT_VAL

%token  SCAN PRINT
%token  WHILE IF ELSE 
%token  STRUCT
%token  RETURN_TOK
%token  JUNK_TOKEN

%type <ast_node> program
%type <block_node> block
%type <sym_table> open
%type <sym_table> close
%type <decls_node> decls
%type <decl_node> decl
%type <decl_node> var_decl
%type <decl_node> struct_decl
%type <decl_node> func_decl
%type <func_header>  func_header
%type <func_prefix>  func_prefix
%type <func_call> func_call
%type <params_spec> paramsspec
%type <param_spec> paramspec
%type <aspec_node> arrayspec
%type <stmts_node> stmts
%type <stmt_node> stmt
%type <expr_node> lval
%type <aval_node> arrayval
%type <params_node> params
%type <param_node> param
%type <expr_node> expr
%type <expr_node> term
%type <expr_node> fact
%type <var_ref> varref
%type <var_part> varpart

%%

program: block                  { 
                                    $$ = $1;
                                    yyast_root = $$;
                                    if (yynerrs == 0) 
                                        YYACCEPT;
                                    else
                                        YYABORT;
                                }
block:  open decls stmts close  { $$ = new BlockNode($2, $3); }
    |   open stmts close        { $$ = new BlockNode(nullptr, $2); }
open:   '{'                     {
                                    symbolTableRoot->IncreaseScope();
                                    $$ = NULL;
                                }
close:  '}'                     {
                                    symbolTableRoot->DecreaseScope();
                                    $$ = NULL;
                                }
decls:      decls decl          {
                                    if ($1 != nullptr)
                                    {
                                        $$ = $1;
                                    }
                                    else
                                    {
                                        $$ = new DeclsNode();
                                    }
                                    
                                    $$->AddNode($2);
                                }
        |   decl                {
                                    $$ = new DeclsNode();
                                    $$->AddNode($1);
                                }
decl:       var_decl ';'        { $$ = $1; }
        |   struct_decl ';'     { $$ = $1; }
        |   func_decl           { $$ = $1; }
        |   error ';'           {}
var_decl:   TYPE_ID IDENTIFIER arrayspec    
                                {
                                    $2 = symbolTableRoot->Insert($2->GetName());
                                    $$ = new VarDecl($1, $2, $3); 
                                }
        |   struct_decl IDENTIFIER arrayspec
                                {}
struct_decl:  STRUCT open decls close IDENTIFIER    
                                {
                                    $5->MakeType();
                                    $$ = new StructDecl($3, $5);
                                }
func_decl:  func_header ';'     { 
                                    $$ = new FuncDecl($1, nullptr, nullptr);
                                    symbolTableRoot->DecreaseScope();
                                }
        |   func_header  '{' decls stmts '}'
                                {
                                    $$ = new FuncDecl($1, $3, $4);
                                    symbolTableRoot->DecreaseScope();
                                }
        |   func_header  '{' stmts '}'
                                {
                                    $$ = new FuncDecl($1, nullptr, $3);
                                    symbolTableRoot->DecreaseScope();
                                }
                                
func_header: func_prefix paramsspec ')'
                                { $$ = new FuncHeader($1, $2); }
        |    func_prefix ')'    { $$ = new FuncHeader($1, nullptr); }
        
func_prefix: TYPE_ID IDENTIFIER '('
                                {
                                    symbolTableRoot->IncreaseScope();
                                    $$ = new FuncPrefix($1, $2);
                                }
                                
paramsspec:     
            paramsspec',' paramspec 
                                {
                                    if ($1 == nullptr)
                                        $1 = new ParamsSpec();
                                    $$ = $1;
                                    $$->AddNode($3);
                                }
        |   paramspec           {
                                    $$ = new ParamsSpec();
                                    $$->AddNode($1);
                                }

paramspec:  var_decl            { $$ = new ParamSpec((VarDecl*)$1); }

arrayspec:  arrayspec '[' INT_VAL ']'
                                {
                                    if ($1 == nullptr)
                                        $1 = new ArraySpec();
                                    $$ = $1;
                                    $$->AddNode($3);
                                }
        |   /* empty */         { $$ = NULL; }

stmts:      stmts stmt          {
                                    if($1 == nullptr)
                                        $1 = new StmtsNode();
                                    $$ = $1;
                                    $$->AddNode($2);
                                }
        |   stmt                { 
                                    $$ = new StmtsNode();
                                    $$->AddNode($1);
                                }
        
stmt:       IF '(' expr ')' stmt 
                                { $$ = new IfNode($3, $5, nullptr); }
        |   IF '(' expr ')' stmt ELSE stmt
                                { $$ = new IfNode($3, $5, $7); }
        |   WHILE '(' expr ')' stmt
                                { $$ = new WhileNode($3, $5); }
        |   PRINT '(' expr ')' ';'
                                { $$ = new PrintNode($3); }
        |   SCAN '(' lval ')' ';'
                                { $$ = new ScanNode($3); }
        |   lval '=' expr ';'   { $$ = new AssignNode((VarRef*)$1, $3); }
        |   func_call ';'       { $$ = $1; }
        |   block               { $$ = $1; }
        |   RETURN_TOK expr ';' { $$ = new ReturnNode($2); }
        |   error ';'           {}

func_call:  IDENTIFIER '(' params ')' 
                                { $$ = new FuncCall($1, $3); }
varref:   varref '.' varpart    { 
                                    if ($1 == nullptr)
                                        $1 = new VarRef();
                                    $$ = $1;
                                    $$->AddNode($3);
                                }
        | varpart               { 
                                    $$ = new VarRef();
                                    $$->AddNode($1);
                                }

varpart:  IDENTIFIER arrayval   { $$ = new VarPart($1, $2); }

lval:     varref                { $$ = $1; }

arrayval: arrayval '[' expr ']' {
                                    if ($1 == nullptr)
                                        $1 = new ArrayVal();
                                    $$ = $1;
                                    $$->AddNode($3);
                                }
        |   /* empty */         { $$ = NULL; }

params:     params',' param     {
                                    if ($1 == nullptr)
                                        $1 = new ParamsNode();
                                    $$ = $1;
                                    $$->AddNode($3);
                                }
        |   param               {
                                    $$ = new ParamsNode();
                                    $$->AddNode($1);
                                }

param:      expr                { $$ = new ParamNode($1); }
        |   /* empty */         { $$ = NULL; }

expr:       expr '+' term       { $$ = new BinaryExprNode($1, '+', $3); }
        |   expr '-' term       { $$ = new BinaryExprNode($1, '-', $3); }
        |   term                { $$ = $1; }
        
term:       term '*' fact       { $$ = new BinaryExprNode($1, '*', $3); }
        |   term '/' fact       { $$ = new BinaryExprNode($1, '/', $3); }
        |   term '%' fact       { $$ = new BinaryExprNode($1, '%', $3); }
        |   fact                { $$ = $1; }

fact:       '(' expr ')'        { $$ = $2; }
        |   INT_VAL             { $$ = new IntExprNode($1); }
        |   FLOAT_VAL           { $$ = new FloatExprNode($1); }
        |   varref              { $$ = $1; }
        |   func_call           { $$ = $1; }

%%

int yyerror(const char *msg)
{
    std::cerr << "ERROR: " << msg << " at symbol \'"
        << yytext << "\' on line " << yylineno << "\n";

    return 0;
}
