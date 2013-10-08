#ifndef AST_TYPE_H
#define AST_TYPE_H

#include <string>
#include "ast.h"

enum class Type{
  INT, BOOL, STRING, VOID, TUPLE, HTML
};

class TypeExpression : public Expression
{
public:
    TypeExpression(Type type_, std::string tuple_id_ = "");
    void PrettyPrint() override;

protected:
    Type type_;
    std::string tuple_id_;
};

#endif // AST_TYPE_H
