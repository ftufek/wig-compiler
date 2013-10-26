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

typedef std::stack<std::map<std::string, std::string>> SymTable;

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
	bool PutSymbol(std::string name, Symbol sym);
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
