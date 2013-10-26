/*
 * table.h
 *
 *  Created on: Oct 26, 2013
 *      Author: user
 */

#ifndef TABLE_H_
#define TABLE_H_

#include <stack>
#include <map>
#include <string>
#include <iostream>
#include "../ast.h"

namespace st{

enum class Symbol{
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

typedef std::stack<std::map<std::string, const ast::Base &>> SymTable;

class Table
{
public:
	Table(SymTable table = SymTable()) : table_(table){};
	~Table();

	void Scope();
	void UnScope();
	void PutSymbol(std::string name, Symbol sym, const ast::Base &node);
	bool ExistsSymbol(std::string name) const;
	void PrettyPrint(std::ostream &out) const;

	SymTable get_table();
private:
	SymTable table_;
};

}


#endif /* TABLE_H_ */
