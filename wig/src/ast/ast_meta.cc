#include <iostream>
#include "ast_meta.h"
#include "../ast_visitor.h"

namespace ast {

MetaTag::MetaTag(std::string content)
    :content_(content){}
void MetaTag::accept(class Visitor *v){ v->visit(this); }

}
