/*
 * template.cc
 *
 *  Created on: Nov 13, 2013
 *      Author: user
 */

#include "template.h"
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include <sstream>

using namespace std;

string cgi_input = "__cg_input";
string session = "__session";
string vars = "__vars";
string sids = "__sids";
string next_logics = "__next_logics";

std::string indent(int number){
	return string(number, '\t');
}

std::string indent(const std::string &str, int number){
	auto copy = indent(number)+string(str);
	boost::replace_all(copy, "\n","\n"+indent(number));
	return copy;
}
std::string deindent(const std::string &str, int number){
	auto copy = string(str);
	if(boost::starts_with(copy, indent(number))){
		boost::replace_first(copy, indent(number), "");
	}
	boost::replace_all(copy, "\n"+indent(number),"\n");
	return copy;
}

std::string _t_env(){
	return "#!/usr/bin/env python\n";
}

std::string _t_imports(const std::list<std::string> &to_import){
	string import = "import %s";
	std::stringstream ss;
	for(auto i : to_import){
		ss<<boost::format(import)%i<<endl;
	}
	return ss.str();
}

std::string _t_enable_cgi(){
	stringstream ss;
	ss<<"cgitb.enable()"<<endl
		<<cgi_input<<" = cgi.FieldStorage()"<<endl
		<<session<<" = os.environ[\"QUERY_STRING\"].split(\"&\")[0]"<<endl;
	return ss.str();
}

std::string _t_state_vars(){
	/* vars: represents differents variables at different scopes using a dictionary.
	 *
	 * sids: unique ids for each session
	 *
	 * next_logics: next_logics for each session
	 *
	 */
	stringstream ss;
	ss<<vars<<" = {}"<<endl
		<<sids<<" = {}"<<endl
		<<next_logics<<" = {}"<<endl;
	return ss.str();
}

std::string _t_schema_class(const std::string &name,
							const std::list<std::pair<std::string, std::string>> &fields){
	std::stringstream ss;
	ss<<"class "<<name<<"():"<<endl;
	for(auto field : fields){
		ss<<indent(1)<<field.first<<" = "<<field.second<<endl;
	}
	ss<<endl;
	ss<<indent(1)<<"def __init__(self, dict):"<<endl;
	ss<<indent(2)<<"for k, v in dict.items():"<<endl;
	ss<<indent(3)<<"setattr(self, k, v)"<<endl;
	return ss.str();
}

std::string _t_html_function(const std::string &name,
							 const std::string &html_text){
	stringstream ss;
	auto copy = string(html_text);
	ss<<"def "<<name<<"(__varDict):"<<endl;

	//Replace gaps with "{" and "}" for python string interpolation
	boost::replace_all(copy, "<[", "{");
	boost::replace_all(copy, "]>", "}");

	ss<<indent(1)<<"return \"\"\""<<copy<<"\"\"\".format(**(__varDict))";
	ss<<endl;
	return ss.str();
}
