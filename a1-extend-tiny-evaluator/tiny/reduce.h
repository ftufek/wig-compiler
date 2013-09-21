/*
 * reduce.h
 *
 *  Created on: 2013-09-21
 *      Author: user
 */

#ifndef REDUCE_H_
#define REDUCE_H_

#include <stdio.h>
#include "tree.h"
#include "pretty.h"
#include "eval.h"

EXP* reduceEXP(EXP *e);
bool containsId(EXP *e);

#endif /* REDUCE_H_ */
