/*
 * weeder.cc
 *
 *  Created on: Oct 13, 2013
 *      Author: user
 */

#include <iostream>
#include <list>
#include "weeder.h"
#include "weeders/return_check.h"

using namespace std;

namespace visitors {

Weeder::Weeder(): MultipleVisitors(new std::list<ast::Visitor *>{new ReturnCheck()}) {}
Weeder::~Weeder() {}
}
