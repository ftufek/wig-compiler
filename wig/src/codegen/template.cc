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
	const char *env = "#!/usr/bin/env python\n";
	return env;
}

std::string _t_imports(const std::list<std::string> &to_import){
	const char *import = "import %s";
	std::stringstream ss;
	for(auto i : to_import){
		ss<<boost::format(import)%i<<endl;
	}
	return ss.str();
}

std::string _t_enable_cgi(){
	const char *e = "cgitb.enable()\n"
			"cgi_input = cgi.FieldStorage()\n"
			"session = os.environ[\"QUERY_STRING\"].split(\"&\")[0]\n";
	return e;
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
