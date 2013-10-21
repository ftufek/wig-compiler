#ifndef AST_ARGUMENT_H
#define AST_ARGUMENT_H

#include "ast.h"
#include "type.h"

namespace ast{

class Argument : public Base
{
public:
    Argument(Type *type, std::string id);
    ~Argument();
    void accept(Visitor *v) override;

    Type *type_;
    std::string id_;
};

}

#endif // AST_ARGUMENT_H
