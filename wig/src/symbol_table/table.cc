/*
 * table.cc
 *
 *  Created on: Oct 26, 2013
 *      Author: user
 */

#include "table.h"

namespace st{

Table::~Table(){

};

void Table::Scope(){

};

void Table::UnScope(){

};

void Table::PutSymbol(std::string name, Symbol sym, const ast::Base &node){

};

bool Table::ExistsSymbol(std::string name) const{
	return false;
};

void Table::PrettyPrint(std::ostream &out) const{

};

SymTable Table::get_table(){
	return SymTable(table_);
};

}
