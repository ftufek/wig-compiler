#ifndef AST_HTML_H
#define AST_HTML_H

#include <string>
#include <map>
#include "ast.h"

namespace ast {

class HtmlTag : public Base{
public:
    HtmlTag(std::string id,
            std::map<std::string, std::string> *attrs =
            new std::map<std::string,std::string>,
            bool is_closing_ = false,
            bool is_gap_ = false);
    ~HtmlTag();
    void accept(Visitor *v) override;

    std::string get_arg(std::string arg_name);

    std::string id_;
    std::map<std::string, std::string> *attrs_;
    bool is_closing_;
    bool is_gap_;
};

}

#endif // AST_HTML_H
