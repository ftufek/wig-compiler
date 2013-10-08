#ifndef AST_FUNCTION_H
#define AST_FUNCTION_H

#include <list>
#include "ast.h"
#include "ast_type.h"
#include "ast_argument.h"

class FunctionExpression : public Expression{
public:
    FunctionExpression(TypeExpression *type,
                       std::string id,
                       std::list<ArgumentExpression *> *args);
    void PrettyPrint() override;

protected:
    TypeExpression *type_;
    std::string id_;
    std::list<ArgumentExpression *> *args_;
};

#endif // AST_FUNCTION_H
