#include <iostream>
#include "ast_html.h"
#include "../ast_visitor.h"

using namespace std;

namespace ast {

HtmlTag::HtmlTag
(string id, map<string, string> *attrs, bool isClosing, bool isGap)
    :id_(id), attrs_(attrs), is_closing_(isClosing), is_gap_(isGap) {}

void HtmlTag::accept(class Visitor *v){ v->visit(this); }

}
