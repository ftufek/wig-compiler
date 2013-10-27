/*
 * table.cc
 *
 *  Created on: Oct 26, 2013
 *      Author: user
 */

#include "table.h"

namespace st{

std::string SymTypeToStr(SymbolType type){
	switch(type){
	case SymbolType::HTML:
		return "html_tag";
		break;

	case SymbolType::SELECT_TAG:
		return "select_tag";
		break;

	case SymbolType::INPUT_TAG:
		return "input_tag";
		break;

	case SymbolType::HOLE_TAG:
		return "hole_tag";
		break;

	case SymbolType::SCHEMA:
		return "schema";
		break;

	case SymbolType::FIELD:
		return "field";
		break;

	case SymbolType::VARIABLE:
		return "variable";
		break;

	case SymbolType::ARGUMENT:
		return "argument";
		break;

	case SymbolType::FUNCTION:
		return "function";
		break;

	case SymbolType::SESSION:
		return "session";
		break;

	default:
		break;
	}
	return "";
}

Symbol::Symbol(std::string name, ast::Base *node, ast::kType type, SymbolType sym_type)
	:name_(name), node_(node), type_(type), sym_type_(sym_type){}
Symbol::~Symbol(){};

Symbol Symbol::ForVariable(ast::Variable *var){
	return Symbol(var->name_, var, var->type_->type_, SymbolType::VARIABLE);
}
Symbol Symbol::ForFunction(ast::Function *f){
	return Symbol(f->id_, f, f->type_->type_, SymbolType::FUNCTION);
}
Symbol Symbol::ForHtmlTag(ast::HtmlTag *tag){
	SymbolType s;
	if(tag->is_gap_){
		s = SymbolType::HOLE_TAG;
	}else if(tag->id_ == "input"){
		s = SymbolType::INPUT_TAG;
	}else if(tag->id_ == "select"){
		s = SymbolType::SELECT_TAG;
	}else{
		s = SymbolType::HTML;
	}
	return Symbol(tag->id_, tag, ast::kType::HTML, s);
}
Symbol Symbol::ForSession(ast::Session *session){
	return Symbol(session->id_, session, ast::kType::VOID, SymbolType::SESSION);
}
Symbol Symbol::ForSchema(ast::Schema *schema){
	return Symbol(schema->id_, schema, ast::kType::SCHEMA, SymbolType::SCHEMA);
}
Symbol Symbol::ForField(ast::Field *field){
	return Symbol(field->id_, field, field->type_->type_, SymbolType::FIELD);
}

const std::string Symbol::get_name() const{
	return name_;
}
const ast::Base *Symbol::get_node() const{
	return node_;
}
const ast::kType Symbol::get_type() const{
	return type_;
}
const SymbolType Symbol::get_sym_type() const{
	return sym_type_;
}


Table::Table(SymTable table) : table_(table){
}
Table::~Table(){};

void Table::Scope(){
	table_.push(std::map<std::string, Symbol>());
};

void Table::UnScope(){
	table_.pop();
};

bool Table::PutSymbol(Symbol sym){
	if(table_.size() <= 0) { return false; }
	auto scope = table_.top();
	if(scope.find(sym.get_name()) == scope.end()){
		scope.insert(std::make_pair(sym.get_name(), sym));
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
		scope = copy.top();
		if(scope.find(name) != scope.end()){
			return true;
		}
		copy.pop();
	}
	return false;
};

void Table::PrettyPrint(std::ostream &out, bool last_scope_only) const{
	std::string offset = "          ------||| ";
	std::string scope_separator = offset + "--------------";
	if(table_.size() <= 0){return;}
	auto copy = table_;
	auto scope = table_.top();
	out<<offset<<"Symbol table: "<<std::endl;
	while(!copy.empty()){
		scope = copy.top();
		for(auto it = scope.begin(); it != scope.end(); ++it){
			out<<offset<<it->first;
			Symbol s = it->second;
			out<<"\t|sym_type: "<<SymTypeToStr(s.get_sym_type());
			out<<"\t|type: "<<ast::KTypeToStr(s.get_type());
			out<<std::endl;
		}
		copy.pop();
		out<<scope_separator<<std::endl;
		if(last_scope_only){break;}
	}
};

Table Table::get_table(){
	return Table(table_);
};

}
