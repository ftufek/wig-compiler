/*
 * template.cc
 *
 *  Created on: Nov 13, 2013
 *      Author: user
 */

#include "template.h"
#include <boost/format.hpp>
#include <sstream>

using namespace std;

std::string _t_env(){
	const char *env = "#!/usr/bin/env python\n";
	return env;
}

std::string _t_imports(std::list<std::string> to_import){
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
