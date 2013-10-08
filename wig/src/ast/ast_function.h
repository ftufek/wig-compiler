#ifndef AST_FUNCTION_H
#define AST_FUNCTION_H

#include <list>
#include "ast.h"
#include "ast_type.h"
#include "ast_argument.h"

namespace ast {

class Function : public Base{
public:
    Function(Type *type,
             std::string id,
             std::list<Argument *> *args);
    void PrettyPrint() override;

protected:
    Type *type_;
    std::string id_;
    std::list<Argument *> *args_;
};

}

#endif // AST_FUNCTION_H
