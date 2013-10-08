#ifndef AST_EMPTY_H
#define AST_EMPTY_H

#include "ast.h"

namespace ast {

class Empty : public Base {
public:
    Empty();
    void PrettyPrint() override;
};

}

#endif // AST_EMPTY_H
