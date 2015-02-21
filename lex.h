#pragma once
//**************************************
// lex.h
//
// Defines global symbols used the the flex generated lexer and 
// bison generated parser.
//
// Author: Daniel Stelle daniel.stelle@oit.edu
//

#include "cSymbolTable.h"
#include "cAstNode.h"
#include "BlockNode.h"
#include "PrintNode.h"
#include "StmtsNode.h"
#include "StmtNode.h"
#include "ExprNode.h"
#include "IntExprNode.h"
#include "FloatExprNode.h"
#include "BinaryExprNode.h"
#include "VarRef.h"
#include "VarDecl.h"
#include "VarPart.h"
#include "DeclNode.h"
#include "DeclsNode.h"
#include "ArrayDecl.h"
#include "ArraySpec.h"
#include "ArrayVal.h"
#include "IfNode.h"
#include "WhileNode.h"
#include "ScanNode.h"
#include "ReturnNode.h"
#include "AssignNode.h"
#include "StructDecl.h"
#include "FuncPrefix.h"
#include "FuncHeader.h"
#include "FuncCall.h"
#include "FuncDecl.h"
#include "ParamNode.h"
#include "ParamSpec.h"
#include "ParamsNode.h"
#include "ParamsSpec.h"
#include "parser.h"
#include "langparse.h"

extern char *yytext;
extern int yylineno;
extern cSymbolTable *symbolTableRoot;
extern FILE *yyin;          // input file for lexer
extern int yyparse();
extern int yylex();
extern int yynerrs;
