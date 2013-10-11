#include <iostream>
#include "pretty_printer.h"

using namespace std;

namespace pp {

void PrettyPrintVisitor::visit(ast::Service *s){
    cout<<s->htmls_->getList()->front()->at_line();
}

}
