#include <iostream>
#include "schema.h"
#include "../ast.h"

namespace ast {

Schema::Schema(std::string id, List *fields)
    :id_(id), fields_(fields){}

Schema::~Schema(){
	delete(fields_);
}

Field *Schema::GetField(std::string field_name){
	auto exps = fields_->exps_;
	for(auto exp : *exps){
		ast::Field *field = dynamic_cast<ast::Field *>(exp);
		if(field->id_ == field_name){
			return field;
		}
	}
	return nullptr;
}

void Schema::accept(class Visitor *v){ v->visit(this); }

}
