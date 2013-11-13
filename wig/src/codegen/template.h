/*
 * template.h
 *
 *  Created on: Nov 13, 2013
 *      Author: user
 */

#ifndef TEMPLATE_H_
#define TEMPLATE_H_

#include <string>
#include <list>

std::string _t_env();
std::string _t_imports(std::list<std::string> to_import);
std::string _t_enable_cgi();


#endif /* TEMPLATE_H_ */
