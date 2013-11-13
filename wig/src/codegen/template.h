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

std::string indent(int number); /* return '\t' number times */
std::string indent(const std::string &str, int number);
std::string deindent(const std::string &str, int number);

std::string _t_env();
std::string _t_imports(const std::list<std::string> &to_import);
std::string _t_enable_cgi();
std::string _t_state_vars();

std::string _t_schema_class(const std::string &name,
							const std::list<std::pair<std::string, std::string>> &fields);

std::string _t_html_layout();
std::string _t_html_function(const std::string &name,
							 const std::string &html_text);


std::string _t_save_session(const std::string &name);
std::string _t_init_session(const std::string &name);
std::string _t_load_session(const std::string &name);
std::string _t_session(const std::string &name);

#endif /* TEMPLATE_H_ */
