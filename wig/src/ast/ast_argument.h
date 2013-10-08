#ifndef AST_ARGUMENT_H
#define AST_ARGUMENT_H

#include "ast.h"
#include "ast_type.h"

class ArgumentExpression : public Expression
{
public:
    ArgumentExpression(TypeExpression *type,
                       std::string id);
    void PrettyPrint() override;

protected:
    TypeExpression *type_;
    std::string id_;
};

#endif // AST_ARGUMENT_H
