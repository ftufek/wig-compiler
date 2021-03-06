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
#include <stack>

std::string indent(int number); /* return '\t' number times */
std::string indent(const std::string &str, int number);
std::string deindent(const std::string &str, int number);

std::string _t_env();
std::string _t_imports(const std::list<std::string> &to_import);
std::string _t_enable_cgi();
std::string _t_state_vars();
std::string _t_global_vars_helpers();
std::string _t_global_var(const std::string &name, const std::string &def_val);

std::string _t_schema_class(const std::string &name,
							const std::list<std::pair<std::string, std::string>> &fields);

std::string _t_html_layout();
std::string _t_html_function(const std::string &name,
							 const std::string &html_text);


std::string _t_save_session(const std::string &name);
std::string _t_init_session(const std::string &name);
std::string _t_load_session(const std::string &name);
std::string _t_session(const std::string &name);

std::string _t_session_stm_stack(const std::string &session_name,
								 const int label,
								 const std::list<std::string> &stms);
std::string _t_var(const std::string &uniq_key);
std::string _t_next_logic(const std::string &session_name, const int n);
std::string _t_call_next_logic(const std::string &session_name, const int n);
std::string _t_exit_from(const int n);

std::string _t_fn_helpers();
std::string _t_fn_decl(const std::string &name,
					   const int label,
					   const std::list<std::string> &stms,
					   const std::list<std::string> &args = {});
std::string _t_next_fn(const std::string &fn_name, const int n);
std::string _t_call_logic_fn(const std::string &fn_name, const int n);
std::string _t_set_next_fn_logic(const int n);

std::string _t_if_stm(const std::string &condition,
					  const std::list<std::string> &stms,
					  const std::list<std::string> &else_stms);
std::string _t_return_stm(const std::string &exp);
std::string _t_print_html(const std::string &name,
						  std::list<std::string> args);
std::string _t_cgi_input(const std::string &name);
std::string _t_cgi_input(const std::string &name, const std::string &typecast);

std::string _t_main_print_stms(const std::list<std::string> &sessions);

std::string _t_py_fn_call(const std::string &name,
						  std::list<std::string> args = {});

#endif /* TEMPLATE_H_ */
