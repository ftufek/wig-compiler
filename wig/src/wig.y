%{
  #include <iostream>
  #include <string>
  #include <list>
  #include <map>
  #include "ast.h"

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
  std::string *str;
  std::map<std::string, std::string> *dict;
  std::list<std::string> *strList;
  std::list<ast::Argument*> *argList;
  std::list<ast::PlugStm*> *plugList;
  ast::Stm *stm;
  ast::Exp *exp;
  std::list<ast::Stm*> *stmList;
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

%token tSERVICE tCONST

%token ttHTML
%token <str> tID tWHATEVER tSTR tInputType


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

%token tEQ

%type <base> service html htmlbody schema field function
%type <listExp> htmls nehtmlbodies schemas neschemas fields nefields nevariables
%type <listExp> variable functions nefunctions
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
%type <exp> exp

%start service
%%

service: tSERVICE '{' htmls schemas nevariables functions '}'
       { EXP = new ast::Service($3, $4, $6, $5); }
     | tSERVICE '{' htmls schemas functions '}'
       { EXP = new ast::Service($3, $4, $5); }
     | /* empty */
       { EXP = new ast::Empty(); }

htmls : html
       { $$ = ast::initList($1); }
      | htmls html
       { $$ = ast::addBack($1, $2); }

html: tCONST ttHTML tID '=' tHtmlOpen tHtmlClose ';'
       {$$ = new ast::Variable(*$3, new ast::Type(ast::kType::HTML), ast::kConstVar,
                                    ast::wrapHtml(new ast::List())); }
    | tCONST ttHTML tID '=' tHtmlOpen nehtmlbodies tHtmlClose ';'
       { $$ = new ast::Variable(*$3,
                                      new ast::Type(ast::kType::HTML),
                                      ast::kConstVar,
                                      ast::wrapHtml($6)); }

nehtmlbodies: htmlbody
            { ast::List *l = new ast::List();
              l->getList()->push_front($1);
              $$ = l; }
            | nehtmlbodies htmlbody
            { $1->getList()->push_back($2);
              $$ = $1; }

htmlbody: '<' tID attributes '>' 
        { $$ = new ast::HtmlTag(*$2, $3);}
        | tTagClose tID '>' /* "</tID>" */
        { $$ = new ast::HtmlTag(*$2, ast::emptyMap(), true); }
        | tGapOpen tID tGapClose
        { $$ = new ast::HtmlTag(*$2, ast::emptyMap(), false, true); }
        | tWHATEVER
        { $$ = new ast::Whatever(*$1); }
        | tMetaOpen tWHATEVER tMetaClose
        { $$ = new ast::MetaTag(*$2); }
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
         { $$ = ast::initMap("name", *$3); }
         | tType '=' tInputType
         { $$ = ast::initMap("type", *$3); }
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
         { $$ = ast::initMap(*$1, ""); }
         | attr '=' attr
         { $$ = ast::initMap(*$1, *$3); }

attr: tID
    { $$ = $1; }
    | tSTR
    { $$ = $1; }

schemas: /* empty */
       { $$ = new ast::List(); }
       | neschemas
       { $$ = $1; }

neschemas: schema
         { $$ = ast::initList($1); }
         | neschemas schema
         { $$ = ast::addBack($1, $2); }

schema: tSchema tID '{' fields '}'
      { $$ = new ast::Schema(*$2, $4); }

fields: /* empty */
      { $$ = new ast::List(); }
      | nefields
      { $$ = $1; }

nefields: field
        { $$ = ast::initList($1); }
        | nefields field
        { $$ = ast::addBack($1, $2); }

field: simpletype tID ';'
     { $$ = new ast::Field(new ast::Type($1), *$2); }

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
    { $$ = new ast::Type(ast::kType::TUPLE, *$2); }

nevariables: variable
    { $$ = $1; }
    | nevariables variable
    { $$ = ast::addBack($1, $2); }

variable: type identifiers ';'
    { $$ = new ast::List();
      std::list<std::string>::const_iterator it;
      for(it = $2->begin(); it != $2->end(); ++it){
        $$ = ast::addBack($$, new ast::Variable(*it,
                         $1,
                         ast::kNoConstVar,
                         ast::kNoVal));
      }
     }

identifiers: tID
    { $$ = new std::list<std::string>{*$1}; }
    | identifiers ',' tID
    { $1->push_back(*$3);
      $$ = $1; }

functions: /* empty */
    { $$ = ast::initList(new ast::Empty()); }
    | nefunctions
    { $$ = $1; }

nefunctions: function
    { $$ = ast::initList($1); }
    | nefunctions function
    { $$ = ast::addBack($1, $2); }

function: type tID '(' arguments ')' compoundstm
    { $$ = new ast::Function($1, *$2, $4, $6);}

arguments: /* empty */
    { $$ = new std::list<ast::Argument*>; }
    | nearguments
    { $$ = $1; }

nearguments: argument
    { $$ = new std::list<ast::Argument*>{$1}; }
    | nearguments ',' argument
    { $1->push_back($3); $$ = $1; }

argument: type tID
    { $$ = new ast::Argument($1, *$2); }

compoundstm: '{' nevariables stms '}'
            { $$ = new ast::CompoundStm($3, $2->getList()); }
            | '{' stms '}'
            { $$ = new ast::CompoundStm($2); }

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
    { $$ = new ast::DocumentStm(*$1); }
    | tPLUG tID '[' plugs ']'
    { $$ = new ast::DocumentStm(*$2, true, $4); }

plugs: plug
    { $$ = new std::list<ast::PlugStm *>{$1}; }
    | plugs ',' plug
    { $1->push_back($3); $$ = $1; }

plug: tID '=' exp
    { $$ = new ast::PlugStm(*$1, $3); }

receive: /* empty */
    { $$ = new ast::EmptyStm(); }
    | tRECEIVE '[' inputs ']'
    { $$ = new ast::ReceiveStm($3); }

exp: /* empty */
    { $$ = new ast::Exp(); }
    | lvalue
    { $$ = new ast::LValExp(*$1); }
    | lvalue '=' exp
    { $$ = new ast::BinopExp(new ast::LValExp(*$1),
                             ast::kBinopType::Assignment,
                             $3); }
    | exp tEQ exp
    { $$ = new ast::BinopExp($1, ast::kBinopType::Equals, $3); }

inputs: /* empty */
    { $$ = new std::list<ast::Stm *>{new ast::EmptyStm()}; }
    | neinputs
    { $$ = $1; }

neinputs: input
    { $$ = new std::list<ast::Stm *>{$1}; }
    | neinputs ',' input
    { $1->push_back($3); $$ = $1; }

input: lvalue '=' tID
    { $$ = new ast::InputStm(*$1, *$3); }

lvalue: tID
    { $$ = $1; }
    | tID '.' tID
    { $$ = new std::string(*$1+"."+*$3); }
