#ifndef AST_VARIABLE_H
#define AST_VARIABLE_H

#include <cstddef>
#include <string>
#include "ast.h"
#include "type.h"

namespace ast {

const bool kConstVar = true;
const bool kNoConstVar = false;
const auto kNoVal = nullptr;

class Variable : public Base {
public:
    Variable(std::string name_,
             Type *type_,
             bool is_const_,
             Base *value_);
    ~Variable();
    void accept(Visitor *v) override;

    std::string name_;
    Type *type_;
    bool is_const_;
    Base *value_;
};

}

#endif // AST_VARIABLE_H
