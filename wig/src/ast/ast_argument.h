#ifndef AST_ARGUMENT_H
#define AST_ARGUMENT_H

#include "ast.h"
#include "ast_type.h"

namespace ast{

class Argument : public Base
{
public:
    Argument(Type *type, std::string id);
    void accept(Visitor *v) override;
protected:
    Type *type_;
    std::string id_;
};

}

#endif // AST_ARGUMENT_H
