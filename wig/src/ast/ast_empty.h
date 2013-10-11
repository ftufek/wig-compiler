#ifndef AST_EMPTY_H
#define AST_EMPTY_H

#include "ast.h"

namespace ast {

class Empty : public Base {
public:
    Empty();
    void accept(Visitor *v) override;
};

}

#endif // AST_EMPTY_H
