#include <iostream>
#include "type.h"
#include "../ast.h"

namespace ast {

std::string KTypeToStr(kType type){
	switch(type){
	case ast::kType::INT:
		return "int";
		break;

	case ast::kType::BOOL:
		return "bool";
		break;

	case ast::kType::STRING:
		return "string";
		break;

	case ast::kType::VOID:
		return "void";
		break;

	case ast::kType::TUPLE:
		return "tuple";
		break;

	case ast::kType::HTML:
		return "html";
		break;

	case ast::kType::SCHEMA:
		return "schema";
		break;
	}
	return "";
}

Type::Type(kType type, std::string tupleID)
    :type_(type), tuple_id_(tupleID) {}

void Type::accept(class Visitor *v){ v->visit(this); }

}
