#ifndef AST_FIELD_H
#define AST_FIELD_H

#include <string>
#include "ast.h"
#include "ast_type.h"

namespace ast{

class Field : public Base {
public:
    Field(Type *type, std::string id);
    void accept(Visitor *v) override;

    Type *type_;
    std::string id_;
};

}

#endif // AST_FIELD_H
