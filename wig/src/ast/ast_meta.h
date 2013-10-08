#ifndef AST_META_H
#define AST_META_H

#include <string>
#include "ast.h"

class MetaTagExpression : public Expression {
public:
  MetaTagExpression(std::string content_);
  void PrettyPrint() override;

protected:
  std::string content_;
};

#endif // AST_META_H
