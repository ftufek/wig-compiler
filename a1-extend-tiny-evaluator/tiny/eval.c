#include <stdio.h>
#include <stdlib.h>
#include "eval.h"

int evalEXP(EXP *e)
{ switch (e->kind) {
    case idK:
         printf("I can't evaluate the value of an identifier!");
	 return(0);
         break;
    case intconstK:
	 return(e->val.intconstE);
         break;
    case timesK:
	 return(evalEXP(e->val.timesE.left) * 
	        evalEXP(e->val.timesE.right));
         break;
    case divK:
     return (evalEXP(e->val.divE.left)/
             evalEXP(e->val.divE.right));
         break;
    case moduloK:
     return (evalEXP(e->val.moduloE.left)%
    		 evalEXP(e->val.moduloE.right));
    	 break;
    case plusK:
	 return(evalEXP(e->val.plusE.left) + 
	        evalEXP(e->val.plusE.right));
         break;
    case minusK:
	 return(evalEXP(e->val.minusE.left) -
	         evalEXP(e->val.minusE.right));
         break;
    case absoluteK:
     return(abs(evalEXP(e->val.absoluteE.inside)));
     	 break;
    default: 
	 printf("ERROR: Impossible type for an expression node.");
	 return(0);
  }
}
