/*
 * reduce.c
 *
 *  Created on: 2013-09-21
 *      Author: user
 */

#include "reduce.h"

/* It's not very efficient in the sense
 * that the helper methods (containsId
 * and evalEXP) also traverse the tree.
 * But was easier to code and understand
 * than the alternative of modifying
 * evalEXP directly.
 */
EXP* reduceEXP(EXP *e){
	if(!containsId(e)){
		return makeEXPintconst(evalEXP(e));
	}
	switch (e->kind) {
	    case idK:
	    case intconstK:
	    	return e;
	    case timesK:{
	    	EXP *left = e->val.timesE.left;
	    	EXP *right = e->val.timesE.right;

	    	/* Basic times arithmetic simplification */
	    	if(!containsId(left) && evalEXP(left) == 0){
	    		/* 0*something */
	    		return makeEXPintconst(0);
	    	}else if(!containsId(left) && evalEXP(left) == 1){
	    		/* 1*something */
	    		return reduceEXP(right);
	    	}else if(!containsId(right) && evalEXP(right) == 0){
	    		/* something*0 */
	    		return makeEXPintconst(0);
	    	}else if(!containsId(right) && evalEXP(right) == 1){
	    		/* something*1 */
	    		return reduceEXP(left);
	    	}

	    	/* Advanced times simplification for cases like:
	    	 *  a*2*3*4*b
	    	 */
	    	if(left->kind == timesK && !containsId(left->val.timesE.right)){
	    		if(!containsId(right)){
					return reduceEXP(makeEXPtimes(reduceEXP(left->val.timesE.left),
										reduceEXP(makeEXPtimes(left->val.timesE.right,
																right))));
	    		}
	    	}

	    	/* Default case */
			return makeEXPtimes(reduceEXP(e->val.timesE.left),
								reduceEXP(e->val.timesE.right));
	    }
	    case divK:{
	    	EXP *left = e->val.divE.left;
			EXP *right = e->val.divE.right;
			if(!containsId(right) && evalEXP(right) == 1){
				/* something/1 */
				return reduceEXP(left);
			}else if(!containsId(left) && evalEXP(left) == 0){
				/* 0/something */
				return makeEXPintconst(0);
			}else{
				return makeEXPdiv(reduceEXP(e->val.divE.left),
								  reduceEXP(e->val.divE.right));
			}
	    }
	    case moduloK:
			return makeEXPmodulo(reduceEXP(e->val.moduloE.left),
								 reduceEXP(e->val.moduloE.right));
	    case plusK:{
	    	EXP *left = e->val.plusE.left;
	    	EXP *right = e->val.plusE.right;

	    	/* Basic addition simplification */
	    	if(!containsId(left) && evalEXP(left) == 0){
	    		/* 0+something = something */
	    		return reduceEXP(right);
	    	}else if(!containsId(right) && evalEXP(right) == 0){
	    		/* something+0 = something */
	    		return reduceEXP(left);
	    	}

	    	/* Advanced addition simplification for cases like:
	    	 * a+2+3+4+b
	    	 */
	    	if(left->kind == plusK && !containsId(left->val.plusE.right)){
				if(!containsId(right)){
					return reduceEXP(makeEXPplus(reduceEXP(left->val.plusE.left),
										reduceEXP(makeEXPplus(left->val.plusE.right,
																right))));
				}
			}
			return makeEXPplus(reduceEXP(e->val.plusE.left),
								reduceEXP(e->val.plusE.right));
	    }
	    case minusK:{
	    	EXP *left = e->val.minusE.left;
	    	EXP *right = e->val.minusE.right;

	    	/* Basic substraction simplification */
	    	if(!containsId(right) && evalEXP(right) == 0){
	    		/* something-0 = something */
	    		return reduceEXP(left);
	    	}

	    	return makeEXPminus(reduceEXP(e->val.minusE.left),
	    						reduceEXP(e->val.minusE.right));
	    }
	    case powerK:{
	    	EXP *right = e->val.powerE.right;
	    	if(!containsId(right) && evalEXP(right) == 0){
	    		/* something**0 = 1 */
	    		return makeEXPintconst(1);
	    	}
	    	return makeEXPpower(reduceEXP(e->val.powerE.left),
	    						reduceEXP(right));
	    }
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
