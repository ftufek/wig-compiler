#ifndef AST_STRING_H
#define AST_STRING_H

#include <string>
#include "ast.h"

namespace ast {

class String : public Base {
public:
  String(std::string content_);
  void PrettyPrint() override;

protected:
  std::string content_;
};

}

#endif // AST_STRING_H
