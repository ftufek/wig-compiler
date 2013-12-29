#ifndef AST_LIST_H
#define AST_LIST_H

#include <list>
#include "ast.h"

namespace ast {

class List : public Base{
public:
	List(Base *e);
    List(std::list<Base *> *exps_ = new std::list<Base *>);
    ~List();
    void accept(Visitor *v) override;

    void AddBack(Base *exp);
    std::list<Base *> *getList();

    std::list<Base *> *exps_;
};

}

#endif // AST_LIST_H
