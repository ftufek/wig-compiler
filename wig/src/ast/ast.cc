#include "ast.h"
#include "../ast.h"
#include "../symbol_table/table.h"

namespace ast{

Base::Base() :at_line_(yylineno), sym_table_(new st::Table()){}
Base::~Base(){
	delete sym_table_;
}

void Base::set_sym_table(st::Table *table){
	delete sym_table_;
	sym_table_ = table;
}

const st::Table* Base::get_sym_table() const{
	return sym_table_;
}

}
