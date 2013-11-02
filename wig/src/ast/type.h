#ifndef AST_TYPE_H
#define AST_TYPE_H

#include <string>
#include "ast.h"

namespace ast {

enum class kType{
    INT, BOOL, STRING, VOID, TUPLE, HTML, SCHEMA, UNDEFINED
};
std::string KTypeToStr(kType type);

class Type : public Base
{
public:
    Type(kType type_, std::string tuple_id_ = "");
    void accept(Visitor *v) override;

    kType type_;
    std::string tuple_id_;
};

}

#endif // AST_TYPE_H
