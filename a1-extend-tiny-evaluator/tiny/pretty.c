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

#define HIPRI(cpri, parenthesis) if (pri > cpri){printf(parenthesis);} \
		else if(pri == cpri && leftChild == false){printf(parenthesis);}
#define OPEN_PAREN(cpri) HIPRI(cpri, "(");
#define CLOSE_PAREN(cpri) HIPRI(cpri, ")");

#define BINOP(type, eType, priority) \
		 OPEN_PAREN(priority) \
		 _prettyEXP(e->val.eType.left, priority, true); \
		 printf(type); \
		 _prettyEXP(e->val.eType.right, priority, false); \
		 CLOSE_PAREN(priority)

static void _prettyEXP(EXP *e, priority pri, bool leftChild)
{ switch (e->kind) {
    case idK:
         printf("%s",e->val.idE);
         break;
    case intconstK:
         printf("%i",e->val.intconstE);
         break;
    case timesK:
    	 BINOP("*", timesE, mult_div_mod)
         break;
    case divK:
    	 BINOP("/", divE, mult_div_mod)
         break;
    case moduloK:
    	 BINOP("%%", moduloE, mult_div_mod)
    	 break;
    case plusK:
    	 BINOP("+", plusE, plus_minus)
         break;
    case minusK:
    	 BINOP("-", minusE, plus_minus)
         break;
    case powerK:
    	 BINOP("**", powerE, power)
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
#undef BINOP

void prettyEXP(EXP *e){
	_prettyEXP(e, min, true);
}
