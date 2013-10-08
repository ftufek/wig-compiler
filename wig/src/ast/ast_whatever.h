#ifndef AST_WHATEVER_H
#define AST_WHATEVER_H

#include <string>
#include "ast.h"

namespace ast {

class Whatever : public Base {
public:
  Whatever(std::string whatever_);
  void PrettyPrint() override;

protected:
  std::string whatever_;
};

}

#endif // AST_WHATEVER_H
