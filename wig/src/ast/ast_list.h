#ifndef AST_LIST_H
#define AST_LIST_H

#include <list>
#include "ast.h"

namespace ast {

class List : public Base{
public:
  List(std::list<Base *> *exps_ = new std::list<Base *>);
  void PrettyPrint() override;
  std::list<Base *> *getList();

protected:
  std::list<Base *> *exps_;
};

}

#endif // AST_LIST_H
