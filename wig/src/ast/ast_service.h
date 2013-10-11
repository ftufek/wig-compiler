#ifndef AST_SERVICE_H
#define AST_SERVICE_H

#include "ast.h"
#include "ast_list.h"

namespace ast {

class Service : public Base{
public:
    Service(List *htmls_,
            List *schemas_,
            List *functions_,
            List *global_variables_ = new List());
    void accept(class Visitor *v) override;

    List *htmls_;
    List *schemas_;
    List *functions_;
    List *global_variables_;
};

}

#endif // AST_SERVICE_H
