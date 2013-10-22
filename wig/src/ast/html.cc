#include <iostream>
#include "html.h"
#include "../ast_visitor.h"

using namespace std;

namespace ast {

HtmlTag::HtmlTag
(string id, map<string, string> *attrs, bool isClosing, bool isGap)
    :id_(id), attrs_(attrs), is_closing_(isClosing), is_gap_(isGap) {}
HtmlTag::~HtmlTag(){
	attrs_->erase(attrs_->begin(), attrs_->end());
	delete(attrs_);
}

void HtmlTag::accept(class Visitor *v){ v->visit(this); }

}
