/*
 * table.h
 *
 *  Created on: Oct 26, 2013
 *      Author: user
 */

#ifndef TABLE_H_
#define TABLE_H_

#include <iostream>
#include <map>
#include <stack>
#include <string>

#include "../ast.h"


namespace st{

enum class SymbolType{
	HTML,
	SELECT_TAG,
	INPUT_TAG,
	HOLE_TAG,
	SCHEMA,
	FIELD,
	VARIABLE,
	ARGUMENT,
	FUNCTION,
	SESSION,
};
std::string SymTypeToStr(SymbolType type);

class Symbol
{
public:
	~Symbol();

	const std::string get_name() const;
	const ast::Base *get_node() const;
	const ast::kType get_type() const;
	const SymbolType get_sym_type() const;

	static Symbol ForVariable(ast::Variable *var);
	static Symbol ForFunction(ast::Function *f);
	static Symbol ForHtmlTag(ast::HtmlTag *tag);
	static Symbol ForSession(ast::Session *session);

private:
	Symbol(std::string name, ast::Base *node, ast::kType type, SymbolType sym_type);

	std::string name_;
	ast::Base *node_;
	ast::kType type_;
	SymbolType sym_type_;
};

typedef std::stack<std::map<std::string, Symbol>> SymTable;

class Table
{
public:
	Table(SymTable table = SymTable());
	~Table();

	void Scope();
	void UnScope();

	/**
	 * PutSymbol
	 *
	 * @returns true if insertion was successful, insertion is successful
	 * 			when there's no symbol on the same name in the current scope
	 */
//	bool PutSymbol(ast::Base *node, std::string name, SymbolType sym);
	bool PutSymbol(Symbol sym);
	bool ExistsSymbol(std::string name) const;
	void PrettyPrint(std::ostream &out) const;

	Table get_table();
private:
	/**
	 * This table holds the symbols.
	 *
	 * Each level of the stack corresponds to a scope.
	 * Each element of the map inside a scope correspond
	 * to symbols in this scope.
	 */
	SymTable table_;
};

}


#endif /* TABLE_H_ */
