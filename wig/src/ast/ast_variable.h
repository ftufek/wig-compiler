#ifndef AST_VARIABLE_H
#define AST_VARIABLE_H

#include <cstddef>
#include <string>
#include "ast.h"
#include "ast_type.h"

namespace ast {

const bool kConstVar = true;
const bool kNoConstVar = false;
const std::nullptr_t kNoVal = nullptr;

class Variable : public Base {
public:
    Variable(std::string name_,
             Type *type_,
             bool is_const_,
             Base *value_);
    void accept(Visitor *v) override;

protected:
    std::string name_;
    Type *type_;
    bool is_const_;
    Base *value_;
};

}

#endif // AST_VARIABLE_H
