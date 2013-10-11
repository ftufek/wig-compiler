#ifndef AST_FUNCTION_H
#define AST_FUNCTION_H

#include <list>
#include "ast.h"
#include "ast_type.h"
#include "ast_argument.h"
#include "ast_stm.h"

namespace ast {

class Function : public Base{
public:
    Function(Type *type,
             std::string id,
             std::list<Argument *> *args,
             CompoundStm *stm);
    void accept(Visitor *v) override;

    Type *type_;
    std::string id_;
    std::list<Argument *> *args_;
    CompoundStm *stm_;
};

}

#endif // AST_FUNCTION_H
