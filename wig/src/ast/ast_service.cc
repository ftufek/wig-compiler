#include "../ast.h"

using namespace std;

namespace ast {

Service::Service(List *htmls, List *schemas, List *functions,
                 List *globalVariables)
    :htmls_(htmls), schemas_(schemas),functions_(functions),
      global_variables_(globalVariables){}

void Service::accept(class Visitor *v){ v->visit(this); }

}
