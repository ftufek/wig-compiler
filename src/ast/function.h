#ifndef AST_FUNCTION_H
#define AST_FUNCTION_H

#include <list>
#include "ast.h"
#include "type.h"
#include "argument.h"
#include "stm.h"

namespace ast {

class Function : public Base{
public:
    Function(Type *type,
             std::string id,
             std::list<Argument *> *args,
             CompoundStm *stm);
    ~Function();
    void accept(Visitor *v) override;

    Type *type_;
    std::string id_;
    std::list<Argument *> *args_;
    CompoundStm *stm_;
};

}

#endif // AST_FUNCTION_H
