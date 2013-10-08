#include <iostream>
#include "ast_string.h"

namespace ast {

String::String(std::string content)
  :content_(content){}

void String::PrettyPrint(){
  std::cout<<"\""<<content_<<"\"";
}

}
