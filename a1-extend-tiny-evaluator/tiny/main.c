#include "tree.h"
#include "pretty.h"
#include "eval.h"
#include "reduce.h"
#include <stdio.h>

void yyparse();

EXP *theexpression;

int lineno;

int main()
{ lineno = 1;
  printf("Type in a tiny exp folowed by one or two Ctrl-d's:\n");
  yyparse();
  printf("\nThe result of evaluating:\n");
  prettyEXP(theexpression);
  printf("\n");
  /*printf("is: %g\n",evalEXP(theexpression));*/
  prettyEXP(reduceEXP(theexpression));
  printf("\n");
  return(1);
}

int test_main()
{ lineno = 1;
	yyparse();
	prettyEXP(theexpression);
	printf(" : ");
	prettyEXP(reduceEXP(theexpression));
	printf("\n");
	return(1);
}
