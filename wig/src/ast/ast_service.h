#ifndef AST_SERVICE_H
#define AST_SERVICE_H

#include "ast.h"
#include "ast_list.h"

class ServiceExpression : public Expression {
public:
  ServiceExpression(ExpressionList *htmls_,
                    ExpressionList *schemas_,
                    ExpressionList *global_variables_ = new ExpressionList());
  void PrettyPrint() override;

protected:
  ExpressionList *htmls_;
  ExpressionList *schemas_;
  ExpressionList *global_variables_;
};

#endif // AST_SERVICE_H
