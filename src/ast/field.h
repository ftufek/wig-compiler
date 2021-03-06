#ifndef AST_FIELD_H
#define AST_FIELD_H

#include <string>
#include "ast.h"
#include "type.h"

namespace ast{

class Field : public Base {
public:
    Field(Type *type, std::string id);
    ~Field();
    void accept(Visitor *v) override;

    Type *type_;
    std::string id_;
};

}

#endif // AST_FIELD_H
