/*
 * table.cc
 *
 *  Created on: Oct 26, 2013
 *      Author: user
 */

#include "table.h"

namespace st{

Table::~Table(){};

void Table::Scope(){
	table_.push(std::map<std::string, const ast::Base &>());
};

void Table::UnScope(){
	table_.pop();
};

bool Table::PutSymbol(std::string name, Symbol sym, const ast::Base &node){
	auto scope = table_.top();
	if(scope.find(name) != scope.end()){
		table_.top().insert(std::pair<std::string, const ast::Base &>(name, node));
		return true;
	}else{
		return false;
	}
};

bool Table::ExistsSymbol(std::string name) const{
	auto copy = table_; //copy table
	auto scope = table_.top();
	while(!copy.empty()){
		scope = table_.top();
		if(scope.find(name) != scope.end()){
			return true;
		}
		copy.pop();
	}
	return false;
};

void Table::PrettyPrint(std::ostream &out) const{
	std::string offset = "          ------||| ";
	std::string scope_separator = offset + "--------------";
	auto copy = table_;
	auto scope = table_.top();
	while(!copy.empty()){
		scope = table_.top();
		for(auto it = scope.begin(); it != scope.end(); ++it){
			out<<offset<<it->first<<std::endl;
		}
		copy.pop();
		out<<scope_separator<<std::endl;
	}
};

SymTable Table::get_table(){
	return SymTable(table_);
};

}
