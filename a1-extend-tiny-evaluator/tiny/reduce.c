/*
 * reduce.c
 *
 *  Created on: 2013-09-21
 *      Author: user
 */

#include "reduce.h"

EXP* reduceEXP(EXP *e){
	if(!containsId(e)){
		return makeEXPintconst(evalEXP(e));
	}
	switch (e->kind) {
	    case idK:
	    case intconstK:
	    	return e;
	    case timesK:
			return makeEXPtimes(reduceEXP(e->val.timesE.left),
								reduceEXP(e->val.timesE.right));
	    case divK:
			return makeEXPdiv(reduceEXP(e->val.divE.left),
							  reduceEXP(e->val.divE.right));
	    case moduloK:
			return makeEXPmodulo(reduceEXP(e->val.moduloE.left),
								 reduceEXP(e->val.moduloE.right));
	    case plusK:
			return makeEXPplus(reduceEXP(e->val.plusE.left),
								reduceEXP(e->val.plusE.right));
	    case minusK:
	    	return makeEXPminus(reduceEXP(e->val.minusE.left),
	    						reduceEXP(e->val.minusE.right));
	    case powerK:
	    	return makeEXPpower(reduceEXP(e->val.powerE.left),
	    						reduceEXP(e->val.powerE.right));
	    case absoluteK:
	    	return makeEXPabsolute(reduceEXP(e->val.absoluteE.inside));
	    default:
			 printf("ERROR: Impossible type for an expression node.");
			 return 0;
	  }
}

bool containsId(EXP *e)
{ switch (e->kind) {
    case idK:
    	return true;
    case intconstK:
    	return false;
    case timesK:
    	return containsId(e->val.timesE.left) ||
    			containsId(e->val.timesE.right);
    case divK:
		return containsId(e->val.divE.left)||
				containsId(e->val.divE.right);
    case moduloK:
    	return containsId(e->val.moduloE.left)||
    			containsId(e->val.moduloE.right);
    case plusK:
    	return containsId(e->val.plusE.left)||
    			containsId(e->val.plusE.right);
    case minusK:
    	return containsId(e->val.minusE.left)||
    			containsId(e->val.minusE.right);
    case powerK:
    	return containsId(e->val.powerE.left)||
    			containsId(e->val.powerE.right);
    case absoluteK:
    	return containsId(e->val.absoluteE.inside);
    default:
		 printf("ERROR: Impossible type for an expression node.");
		 return 0;
  }
}
