#include <iostream>
#include "meta.h"
#include "../ast.h"

namespace ast {

MetaTag::MetaTag(std::string content)
    :content_(content){}
void MetaTag::accept(class Visitor *v){ v->visit(this); }

}
