#ifndef PRETTY_H
#define PRETTY_H

#include "tree.h"

typedef enum
{ min,
  abs_pri,
  plus_minus,
  mult_div_mod,
  power
} priority;


typedef enum
{ false,
  true
} bool;

void prettyEXP(EXP *e);


#endif /* !PRETTY_H */
