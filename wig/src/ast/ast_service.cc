#include "../ast.h"

using namespace std;

namespace ast {

Service::Service(List *htmls, List *schemas, List *functions,
                 List *globalVariables)
    :htmls_(htmls), schemas_(schemas),functions_(functions),
      global_variables_(globalVariables){}

//void Service::PrettyPrint(){
//    cout<<"service {"<<endl;
//    htmls_->PrettyPrint();
//    cout<<endl;
//    schemas_->PrettyPrint();
//    cout<<endl;
//    global_variables_->PrettyPrint();
//    cout<<endl;
//    functions_->PrettyPrint();
//    cout<<"}"<<endl;
//}

void Service::accept(class Visitor *v){
    v->visit(this);
}

}
