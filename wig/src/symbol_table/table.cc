/*
 * table.cc
 *
 *  Created on: Oct 26, 2013
 *      Author: user
 */

#include "table.h"

namespace st{

Table::Table(SymTable table) : table_(table){
}
Table::~Table(){};

void Table::Scope(){
	table_.push(std::map<std::string, std::string>());
};

void Table::UnScope(){
	table_.pop();
};

bool Table::PutSymbol(std::string name, Symbol sym){
	if(table_.size() <= 0) { return false; }
	auto scope = table_.top();
	if(scope.find(name) == scope.end()){
		scope.insert(std::make_pair(name, "empty"));
		table_.pop();
		table_.push(scope);
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
	out<<offset<<"Symbol table: "<<std::endl;
	while(!copy.empty()){
		scope = table_.top();
		for(auto it = scope.begin(); it != scope.end(); ++it){
			out<<offset<<it->first<<std::endl;
		}
		copy.pop();
		out<<scope_separator<<std::endl;
	}
};

Table Table::get_table(){
	return Table(table_);
};

}
