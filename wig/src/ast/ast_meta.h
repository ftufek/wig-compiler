#ifndef AST_META_H
#define AST_META_H

#include <string>
#include "ast.h"

namespace ast {

class MetaTag : public Base {
public:
    MetaTag(std::string content_);
    void accept(Visitor *v) override;

protected:
    std::string content_;
};

}

#endif // AST_META_H
