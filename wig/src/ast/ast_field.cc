#include "../ast.h"

using namespace std;

namespace ast {

Field::Field(Type *type, string id)
    :type(type), id(id){}

void Field::PrettyPrint(){
    type->PrettyPrint();
    cout<<" "<<id<<";"<<endl;
}

}
