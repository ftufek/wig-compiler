#ifndef __TREE_H
#define __TREE_H

class Expression{
public:
  Expression();
  virtual ~Expression();
  virtual void pretty();
};

class ServiceExpression : public Expression {
public:
  ServiceExpression();
  void pretty();
};

#endif
