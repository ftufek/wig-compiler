#ifndef __TREE_H
#define __TREE_H

class Expression{
public:
  void pretty(){};
};

class ServiceExpression : public Expression {
public:
  ServiceExpression(){
  }

  void pretty();
};

#endif
