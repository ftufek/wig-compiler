#include <iostream>
#include "ast_meta.h"

namespace ast {

MetaTag::MetaTag(std::string content)
    :content_(content){}

void MetaTag::PrettyPrint(){
    std::cout<<"<!-- ";
    std::cout<<content_;
    std::cout<<" -->";
}

}
