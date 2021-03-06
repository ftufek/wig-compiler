#include <iostream>
#include "html.h"
#include "../ast.h"

using namespace std;

namespace ast {

HtmlTag::HtmlTag
(string id, map<string, string> *attrs, bool isClosing, bool isGap)
    :id_(id), attrs_(attrs), is_closing_(isClosing), is_gap_(isGap) {}
HtmlTag::~HtmlTag(){
	attrs_->clear();
	delete(attrs_);
}

void HtmlTag::accept(class Visitor *v){ v->visit(this); }

std::string HtmlTag::get_arg(std::string arg_name){
	return attrs_->find(arg_name)->second;
}

}
