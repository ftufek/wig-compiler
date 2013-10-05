#include <iostream>
#include "../ast.h"

using namespace std;

ServiceExpression::ServiceExpression(){
}

void ServiceExpression::prettyPrint(){
  cout<<"service {"<<endl;
  cout<<"}"<<endl;
}
