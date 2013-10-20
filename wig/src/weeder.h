/*
 * weeder.h
 *
 *  Created on: Oct 13, 2013
 *      Author: user
 */

#ifndef WEEDER_H_
#define WEEDER_H_

#include "ast_visitor.h"

namespace visitors {

class Weeder : public ast::MultipleVisitors{
public:
	Weeder();
	virtual ~Weeder();
};

}

#endif /* WEEDER_H_ */
