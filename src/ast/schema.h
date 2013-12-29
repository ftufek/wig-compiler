#ifndef AST_SCHEMA_H
#define AST_SCHEMA_H

#include <string>
#include "ast.h"
#include "field.h"
#include "list.h"

namespace ast {

class Schema : public Base {
public:
    Schema(std::string id_,
           List *fields_ = new List());
    ~Schema();
    Field *GetField(std::string field_name);
    void accept(Visitor *v) override;

    std::string id_;
    List *fields_;
};

}

#endif // AST_SCHEMA_H
