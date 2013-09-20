#include <stdio.h>
#include "pretty.h"

typedef enum
{ min,
  abs,
  plus_minus, /* +, - */
  mult_div_mod, /* *, /, % */
  power /* ** */
} priority;

typedef enum
{ false,
  true
} bool;

#define HIPRI(cpri, parent) if (pri > cpri){printf(parent);} \
		else if(pri == cpri && leftChild == false){printf(parent);}
#define OPEN_PAREN(cpri) HIPRI(cpri, "(");
#define CLOSE_PAREN(cpri) HIPRI(cpri, ")");

static void _prettyEXP(EXP *e, priority pri, bool leftChild)
{ switch (e->kind) {
    case idK:
         printf("%s",e->val.idE);
         break;
    case intconstK:
         printf("%i",e->val.intconstE);
         break;
    case timesK:
         OPEN_PAREN(mult_div_mod)
         _prettyEXP(e->val.timesE.left, mult_div_mod, true);
         printf("*");
         _prettyEXP(e->val.timesE.right, mult_div_mod, false);
         CLOSE_PAREN(mult_div_mod)
         break;
    case divK:
    	 OPEN_PAREN(mult_div_mod)
         _prettyEXP(e->val.divE.left, mult_div_mod, true);
         printf("/");
         _prettyEXP(e->val.divE.right, mult_div_mod, false);
         CLOSE_PAREN(mult_div_mod)
         break;
    case moduloK:
    	 OPEN_PAREN(mult_div_mod)
    	 _prettyEXP(e->val.moduloE.left, mult_div_mod, true);
    	 printf("%%");
    	 _prettyEXP(e->val.moduloE.right, mult_div_mod, false);
    	 CLOSE_PAREN(mult_div_mod)
    	 break;
    case plusK:
    	 OPEN_PAREN(plus_minus)
         _prettyEXP(e->val.plusE.left, plus_minus, true);
         printf("+");
         _prettyEXP(e->val.plusE.right, plus_minus, false);
         CLOSE_PAREN(plus_minus)
         break;
    case minusK:
         OPEN_PAREN(plus_minus)
         _prettyEXP(e->val.minusE.left, plus_minus, true);
         printf("-");
         _prettyEXP(e->val.minusE.right, plus_minus, false);
         CLOSE_PAREN(plus_minus)
         break;
    case powerK:
    	 OPEN_PAREN(power)
		 _prettyEXP(e->val.powerE.left, power, true);
		 printf("**");
		 _prettyEXP(e->val.powerE.right, power, false);
		 CLOSE_PAREN(power)
    	 break;
    case absoluteK:
    	 printf("abs(");
    	 _prettyEXP(e->val.absoluteE.inside, abs, true);
    	 printf(")");
    	 break;
  }
}

#undef HIPRI
#undef OPEN_PAREN
#undef CLOSE_PAREN

void prettyEXP(EXP *e){
	_prettyEXP(e, min, true);
}
