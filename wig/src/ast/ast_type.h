#ifndef AST_TYPE_H
#define AST_TYPE_H

#include <string>
#include "ast.h"

namespace ast {

enum class kType{
    INT, BOOL, STRING, VOID, TUPLE, HTML
};

class Type : public Base
{
public:
    Type(kType type_, std::string tuple_id_ = "");
    void PrettyPrint() override;

protected:
    kType type_;
    std::string tuple_id_;
};

}

#endif // AST_TYPE_H
