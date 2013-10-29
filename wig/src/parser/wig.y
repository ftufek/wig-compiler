%{
  #include <iostream>
  #include <string>
  #include <list>
  #include <map>
  #include "../ast.h"

  extern "C" int yylex();
  extern ast::Base *EXP;
  extern char* yytext;
  extern bool success;
  extern int yylineno;

  void yyerror(const char* str){
    std::cout<<"Error happened on line "<<yylineno<<" : "<<str<<std::endl;
    std::cout<<" before: "<<yytext<<std::endl;
    success = false;
  }
%}

%union{
  int integer;
  std::string *str;
  std::map<std::string, std::string> *dict;
  std::list<std::string> *strList;
  std::list<ast::Argument*> *argList;
  std::list<ast::PlugStm*> *plugList;
  ast::Stm *stm;
  ast::Exp *exp;
  std::list<ast::Stm*> *stmList;
  std::list<ast::Exp*> *expList;
  ast::CompoundStm *compoundStm;
  ast::DocumentStm *docStm;
  ast::PlugStm *plugStm;
  ast::ReceiveStm *receiveStm;
  ast::Base *base;
  ast::List *listExp;
  ast::Type *typeExp;
  ast::Argument *argExp;
  ast::kType type;
}

%token tSERVICE tCONST tSESSION

%token ttHTML
%token <str> tID tWHATEVER tSTR tInputType
%token <integer> tINT


/* HTML RELATED TOKENS */
%token tHtmlOpen /* "<html>" */
%token tHtmlClose /* "</html>" */
%token tTagClose /* "</" */
%token tGapOpen /* "<[" */
%token tGapClose /* "]>" */
%token tMetaOpen
%token tMetaClose
%token tInput
%token tSelect
%token tName
%token tType
/* END OF HTML RELATED TOKENS */

%token tSchema tInt tBool tString tVoid tTuple
%token tSHOW tPLUG tRECEIVE tEXIT tRETURN tIF tELSE tWHILE

%token tEQ tNEQ tLEQ tHEQ tLAND tLOR tTCOMBINE tTKEEP tTDISCARD
%token tTRUE tFALSE

%type <base> service html htmlbody schema field function session
%type <listExp> htmls nehtmlbodies schemas neschemas fields nefields nevariables
%type <listExp> variable functions nefunctions sessions
%type <typeExp> type
%type <dict> attributes neattributes attribute inputattr inputattrs
%type <str> attr lvalue
%type <type> simpletype
%type <strList> identifiers
%type <argList> arguments nearguments
%type <argExp> argument
%type <compoundStm> compoundstm
%type <stm> stm receive input
%type <stmList> stms nestms inputs neinputs
%type <docStm> document
%type <plugList> plugs
%type <plugStm> plug
%type <exp> exp fieldvalue
%type <expList> exps neexps fieldvalues nefieldvalues

%start service

%left '-' '+'
%left '*' '/' '%'
%left tLOR
%left tLAND '!'
%left tTCOMBINE tTKEEP tTDISCARD
%left tEQ tNEQ tLEQ tHEQ '<' '>'
%left '='
%left UMINUS

%%

service: tSERVICE '{' htmls schemas nevariables functions sessions '}'
       { EXP = new ast::Service($3, $4, $6, $7, $5); }
     | tSERVICE '{' htmls schemas functions sessions '}'
       { EXP = new ast::Service($3, $4, $5, $6); }
     | /* empty */
       { yyerror("Error: doesn't contain any service."); }

htmls: html
       { $$ = new ast::List($1); }
      | htmls html
       { $$ = $1; $1->AddBack($2); }

html: tCONST ttHTML tID '=' tHtmlOpen nehtmlbodies tHtmlClose ';'
       { $$ = new ast::Variable(*$3,
                                      new ast::Type(ast::kType::HTML),
                                      ast::kConstVar,
                                      ast::wrapHtml($6));
          delete($3); }
	| tCONST ttHTML tID '=' tHtmlOpen tHtmlClose ';'
       {$$ = new ast::Variable(*$3, new ast::Type(ast::kType::HTML), ast::kConstVar,
                                    ast::wrapHtml(new ast::List()));
        delete($3); } 

nehtmlbodies: htmlbody
            { ast::List *l = new ast::List();
              l->getList()->push_front($1);
              $$ = l; }
            | nehtmlbodies htmlbody
            { $1->getList()->push_back($2);
              $$ = $1; }

htmlbody: '<' tID attributes '>' 
        { $$ = new ast::HtmlTag(*$2, $3); delete($2); }
        | tTagClose tID '>'
        { $$ = new ast::HtmlTag(*$2, ast::emptyMap(), true); delete($2); }
        | tGapOpen tID tGapClose
        { $$ = new ast::HtmlTag(*$2, ast::emptyMap(), false, true); delete($2); }
        | tWHATEVER
        { $$ = new ast::Whatever(*$1); delete($1); }
        | tMetaOpen tWHATEVER tMetaClose
        { $$ = new ast::MetaTag(*$2); delete($2); }
        | '<' tInput inputattrs '>'
        { $$ = new ast::HtmlTag("input", $3); }
        | '<' tSelect inputattrs '>' nehtmlbodies tTagClose tSelect '>'
        { $$ = ast::wrapAround("select", $3, $5); }
        | '<' tSelect inputattrs '>' tTagClose tSelect '>'
        { $$ = ast::wrapAround("select", $3, new ast::List()); }

inputattrs: inputattr
        { $$ = $1; }
        | inputattrs inputattr
        { $$ = ast::mergeMap($1, $2); }

inputattr: tName '=' attr
         { $$ = ast::initMap("name", *$3); delete($3); }
         | tType '=' tInputType
         { $$ = ast::initMap("type", *$3); delete($3); }
         | attribute
         { $$ = $1; }

attributes: /* emtpy */
          { $$ = ast::emptyMap(); }
          | neattributes
          { $$ = $1; }

neattributes: attribute
            { $$ = $1; }
            | neattributes attribute
            { $$ = ast::mergeMap($1, $2); }

attribute: attr
         { $$ = ast::initMap(*$1, ""); delete($1); }
         | attr '=' attr
         { $$ = ast::initMap(*$1, *$3); delete($1); delete($3); }

attr: tID
    { $$ = $1; }
    | tSTR
    { $$ = $1; }

schemas: /* empty */
       { $$ = new ast::List(); }
       | neschemas
       { $$ = $1; }

neschemas: schema
         { $$ = new ast::List($1); }
         | neschemas schema
         { $$ = $1; $1->AddBack($2); }

schema: tSchema tID '{' fields '}'
      { $$ = new ast::Schema(*$2, $4); delete($2); }

fields: /* empty */
      { $$ = new ast::List(); }
      | nefields
      { $$ = $1; }

nefields: field
        { $$ = new ast::List($1); }
        | nefields field
        { $$ = $1; $1->AddBack($2); }

field: simpletype tID ';'
     { $$ = new ast::Field(new ast::Type($1), *$2); delete($2); }

simpletype: tInt
           { $$ = ast::kType::INT; }
           | tBool
           { $$ = ast::kType::BOOL; }
           | tString
           { $$ = ast::kType::STRING; }
           | tVoid
           { $$ = ast::kType::VOID; }

type: simpletype
    { $$ = new ast::Type($1); }
    | tTuple tID
    { $$ = new ast::Type(ast::kType::TUPLE, *$2); delete($2); }

nevariables: variable
    { $$ = $1; }
    | nevariables variable
    { $$ = $1; $1->AddBack($2); }

variable: type identifiers ';'
    { $$ = new ast::List();
      std::list<std::string>::const_iterator it;
      for(it = $2->begin(); it != $2->end(); ++it){
        $$->AddBack(new ast::Variable(*it,
                         $1,
                         ast::kNoConstVar,
                         ast::kNoVal));
      }
      delete($2);
     }

identifiers: tID
    { $$ = new std::list<std::string>{*$1}; delete($1); }
    | identifiers ',' tID
    { $1->push_back(*$3); delete($3);
      $$ = $1; }

functions: /* empty */
    { $$ = new ast::List(new ast::Empty()); }
    | nefunctions
    { $$ = $1; }

nefunctions: function
    { $$ = new ast::List($1); }
    | nefunctions function
    { $$ = $1; $1->AddBack($2); }

function: type tID '(' arguments ')' compoundstm
    { $$ = new ast::Function($1, *$2, $4, $6); delete($2); }

arguments: /* empty */
    { $$ = new std::list<ast::Argument*>; }
    | nearguments
    { $$ = $1; }

nearguments: argument
    { $$ = new std::list<ast::Argument*>{$1}; }
    | nearguments ',' argument
    { $1->push_back($3); $$ = $1; }

argument: type tID
    { $$ = new ast::Argument($1, *$2); delete($2); }

compoundstm: '{' nevariables stms '}'
            { $$ = new ast::CompoundStm($3, $2->getList()); }
            | '{' stms '}'
            { $$ = new ast::CompoundStm($2); }

sessions: session
    { $$ = new ast::List($1); }
    | sessions session
    { $$ = $1; $1->AddBack($2); }

session: tSESSION tID '(' ')' compoundstm
    { $$ = new ast::Session(*$2, $5); delete($2); }

stms: /* empty */
    { $$ = new std::list<ast::Stm *>{new ast::EmptyStm()}; }
    | nestms
    { $$ = $1; }

nestms: stm
    { $$ = new std::list<ast::Stm *>{$1}; }
    | nestms stm
    { $1->push_back($2); $$ = $1; }

stm: ';'
    { $$ = new ast::EmptyStm(true); }
    | tSHOW document receive ';'
    { $$ = new ast::ShowStm($2, $3); }
    | tEXIT document ';'
    { $$ = new ast::ExitStm($2); }
    | tRETURN ';'
    { $$ = new ast::ReturnStm(); }
    | tRETURN exp ';'
    { $$ = new ast::ReturnStm($2); }
    | tIF '(' exp ')' stm
    { $$ = new ast::IfStm($3, $5); }
    | tIF '(' exp ')' stm tELSE stm
    { $$ = new ast::IfStm($3, $5, $7); }
    | tWHILE '(' exp ')' stm
    { $$ = new ast::WhileStm($3, $5); }
    | compoundstm
    { $$ = $1; }
    | exp ';'
    { $$ = new ast::ExpStm($1); }

document: tID
    { $$ = new ast::DocumentStm(*$1); delete($1); }
    | tPLUG tID '[' plugs ']'
    { $$ = new ast::DocumentStm(*$2, true, $4); delete($2); }

plugs: plug
    { $$ = new std::list<ast::PlugStm *>{$1}; }
    | plugs ',' plug
    { $1->push_back($3); $$ = $1; }

plug: tID '=' exp
    { $$ = new ast::PlugStm(*$1, $3); delete($1); }

receive: /* empty */
    { $$ = new ast::EmptyStm(); }
    | tRECEIVE '[' inputs ']'
    { $$ = new ast::ReceiveStm($3); }

exp: lvalue
    { $$ = new ast::LValExp(*$1); }
    | lvalue '=' exp
    { $$ = new ast::BinopExp(new ast::LValExp(*$1),
                             ast::kBinopType::Assignment,
                             $3); }
    | exp tEQ exp
    { $$ = new ast::BinopExp($1, ast::kBinopType::Equals, $3); }
    | exp tNEQ exp
    { $$ = new ast::BinopExp($1, ast::kBinopType::NotEquals, $3); }
    | exp '<' exp
    { $$ = new ast::BinopExp($1, ast::kBinopType::LowerThan, $3); }
    | exp '>' exp
    { $$ = new ast::BinopExp($1, ast::kBinopType::HigherThan, $3); }
    | exp tLEQ exp
    { $$ = new ast::BinopExp($1, ast::kBinopType::LowerEquals, $3); }
    | exp tHEQ exp
    { $$ = new ast::BinopExp($1, ast::kBinopType::HigherEquals, $3); }
    | '-' exp %prec UMINUS
    { $$ = new ast::UnopExp(ast::kUnopType::Minus, $2); }
    | '!' exp
    { $$ = new ast::UnopExp(ast::kUnopType::LogicNegate, $2); }
    | exp '+' exp
    { $$ = new ast::BinopExp($1, ast::kBinopType::Add, $3); }
    | exp '-' exp
    { $$ = new ast::BinopExp($1, ast::kBinopType::Sub, $3); }
    | exp '*' exp
    { $$ = new ast::BinopExp($1, ast::kBinopType::Mult, $3); }
    | exp '/' exp
    { $$ = new ast::BinopExp($1, ast::kBinopType::Div, $3); }
    | exp '%' exp
    { $$ = new ast::BinopExp($1, ast::kBinopType::Mod, $3); }
    | exp tLAND exp
    { $$ = new ast::BinopExp($1, ast::kBinopType::And, $3); }
    | exp tLOR exp
    { $$ = new ast::BinopExp($1, ast::kBinopType::Or, $3); }
    | exp tTCOMBINE exp
    { $$ = new ast::BinopExp($1, ast::kBinopType::Combine, $3); }
    | exp tTKEEP tID
    { $$ = new ast::TupleopExp($1,
                               ast::kTupleopType::Keep,
                               new std::list<std::string>{*$3}); delete($3); }
    | exp tTKEEP '(' identifiers ')'
    { $$ = new ast::TupleopExp($1, ast::kTupleopType::Keep, $4); }
    | exp tTDISCARD tID
    { $$ = new ast::TupleopExp($1, ast::kTupleopType::Discard,
                                   new std::list<std::string>{*$3}); delete($3); }
    | exp tTDISCARD '(' identifiers ')'
    { $$ = new ast::TupleopExp($1, ast::kTupleopType::Discard, $4); }
    | tID '(' exps ')'
    { $$ = new ast::FunctionExp(*$1, $3); delete($1); }
    | tINT
    { $$ = new ast::IntegerExp($1); }
    | tTRUE
    { $$ = new ast::TrueExp(); }
    | tFALSE
    { $$ = new ast::FalseExp(); }
    | tSTR
    { $$ = new ast::StringExp(*$1); delete($1); }
    | tTuple '{' fieldvalues '}'
    { $$ = new ast::TupleExp($3); }
    | '(' exp ')'
    { $$ = $2; }

fieldvalues: /* empty */
    { $$ = new std::list<ast::Exp *>{new ast::Exp()}; }
    | nefieldvalues
    { $$ = $1; }

nefieldvalues: fieldvalue
    { $$ = new std::list<ast::Exp *>{$1}; }
    | nefieldvalues ',' fieldvalue
    { $1->push_back($3); $$ = $1; }

fieldvalue: tID '=' exp
    { $$ = new ast::FieldValExp(*$1, $3); delete($1); }

exps: /* empty */
    { $$ = new std::list<ast::Exp *>{new ast::Exp()}; }
    | neexps
    { $$ = $1; }

neexps: exp
    { $$ = new std::list<ast::Exp *>{$1}; }
    | neexps ',' exp
    { $1->push_back($3); $$ = $1; }

inputs: /* empty */
    { $$ = new std::list<ast::Stm *>{new ast::EmptyStm()}; }
    | neinputs
    { $$ = $1; }

neinputs: input
    { $$ = new std::list<ast::Stm *>{$1}; }
    | neinputs ',' input
    { $1->push_back($3); $$ = $1; }

input: lvalue '=' tID
    { $$ = new ast::InputStm(*$1, *$3); delete($1); delete($3); }

lvalue: tID
    { $$ = $1; }
    | tID '.' tID
    { $$ = new std::string(*$1+"."+*$3); delete($1); delete($3); }
