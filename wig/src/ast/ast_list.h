#ifndef AST_LIST_H
#define AST_LIST_H

#include <list>
#include "ast.h"

namespace ast {

class List : public Base{
public:
    List(std::list<Base *> *exps_ = new std::list<Base *>);
    void accept(Visitor *v) override;
    std::list<Base *> *getList();

    std::list<Base *> *exps_;
};

}

#endif // AST_LIST_H
