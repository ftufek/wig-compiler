#include "../ast.h"

using namespace std;

namespace ast {

Service::Service(List *htmls, List *schemas, List *functions,
                 List *sessions, List *globalVariables)
    :htmls_(htmls), schemas_(schemas),functions_(functions), sessions_(sessions),
      global_variables_(globalVariables){}

Service::~Service(){
	delete(htmls_);
	delete(schemas_);
	delete(functions_);
	delete(sessions_);
	delete(global_variables_);
}

void Service::accept(class Visitor *v){ v->visit(this); }

}
