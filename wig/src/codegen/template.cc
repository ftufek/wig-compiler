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
#include "../codegen.h"

using namespace std;

string cgi_input = "__cg_input";
string session = "__session";
string vars = "__vars";
string sid = "__sid";
string next_logic = "__next_logic";

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

std::string _t_py_fn_call(const std::string &name,
						  std::list<std::string> args){
	stringstream ss;
	ss<<name<<"(";
	if(args.size() > 0){
		ss<<args.front();
		args.pop_front();
	}
	for(auto arg : args){
		ss<<","<<arg;
	}
	ss<<")";
	return ss.str();
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
		<<sid<<" = 0"<<endl
		<<next_logic<<" = 1"<<endl;
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

std::string _t_layout_helpers(){
	stringstream ss;
	ss<<"def __str_sid():"<<endl;
	ss<<indent(1)<<"if "<<sid<<" != 0:"<<endl;
	ss<<indent(2)<<"return \"&sid=\"+str("<<sid<<")"<<endl;
	ss<<indent(1)<<"else:"<<endl;
	ss<<indent(2)<<"return \"\""<<endl;
	ss<<endl;
	ss<<"def __action_name():"<<endl;
	ss<<indent(1)<<"return os.path.basename(__file__)+\"?\"+"<<session
			<<"+__str_sid()"<<endl;
	return ss.str();
}

std::string _t_html_layout(){
	stringstream ss;
	ss<<_t_layout_helpers()<<endl;
	ss<<"def __layout(page):"<<endl
	  <<indent(1)<<"return \"\"\"<html><form action=\"{action}\" method=\"POST\">\n"
	  <<indent(1)<<"{page} <input type=\"submit\" value=\"go\">"<<endl
	  <<indent(1)<<"</form></html>\"\"\".format(action=__action_name(),page=page)"<<endl;
	return ss.str();
}

std::string _t_html_function(const std::string &name,
							 const std::string &html_text){
	stringstream ss;
	auto copy = string(html_text);
	ss<<"def __"<<name<<"(__varDict):"<<endl;

	//Replace gaps with "{" and "}" for python string interpolation
	boost::replace_all(copy, "<[", "{");
	boost::replace_all(copy, "]>", "}");

	//Remove html tags because there's a layout function that will add them
	boost::replace_all(copy, "<html>","");
	boost::replace_all(copy, "</html>","");

	ss<<indent(1)<<"return \"\"\""<<copy<<"\"\"\".format(**(__varDict))";
	ss<<endl;
	return ss.str();
}

std::string _t_save_session(const std::string &name){
	stringstream ss;

	ss<<"def __save_session_"<<name<<"():"<<endl;
	ss<<indent(1)<<"session_file = \""<<name<<"$\"+str("<<sid<<")"<<endl;
	ss<<indent(1)<<"open(session_file, 'w').close()"<<endl;
	ss<<indent(1)<<"with open(session_file, \"w\") as f:"<<endl;

	ss<<indent(2)<<"pickle.dump("<<vars<<", f)"<<endl;
	ss<<indent(2)<<"pickle.dump("<<next_logic<<", f)"<<endl;

	ss<<indent(1)<<"return"<<endl;

	return ss.str();
}
std::string _t_init_session(const std::string &name){
	stringstream ss;
	ss<<"def __init_session_"<<name<<"():"<<endl;
	ss<<indent(1)<<"global "<<sid<<endl;
	ss<<indent(1)<<"global "<<next_logic<<endl;
	ss<<indent(1)<<sid<<" = str(uuid.uuid4())"<<endl;
	ss<<indent(1)<<next_logic<<" = 1"<<endl;
	ss<<indent(1)<<"__save_session_"<<name<<"()"<<endl;
	ss<<indent(1)<<"__logic_session_"<<name<<"_1()"<<endl;
	return ss.str();
}
std::string _t_load_session(const std::string &name){
	stringstream ss;
	ss<<"def __load_session_"<<name<<"(session_id):"<<endl;
	for(auto global : list<string>{vars, next_logic, sid}){
		ss<<indent(1)<<"global "<<global<<endl;
	}
	ss<<indent(1)<<sid<<" = session_id"<<endl;
	ss<<indent(1)<<"with open(\""<<name<<"$\"+str("<<sid<<"), \"r\") as f:"<<endl;
	for(auto load : list<string>{vars, next_logic}){
		ss<<indent(2)<<load<<" = pickle.load(f)"<<endl;
	}
	ss<<indent(1)<<"globals()[\"__logic_session_"<<name<<"_\"+str("<<next_logic<<")]()"<<endl;
	return ss.str();
}

std::string _t_session(const std::string &name){
	stringstream ss;
	ss<<"def __session_"<<name<<"():"<<endl;
	ss<<indent(1)<<"sid = "<<cgi_input<<".getvalue(\"sid\", \"\")"<<endl;
	ss<<indent(1)<<"if sid == \"\":"<<endl;
	ss<<indent(2)<<"__init_session_"<<name<<"()"<<endl;
	ss<<indent(1)<<"else:"<<endl;
	ss<<indent(2)<<"__load_session_"<<name<<"(sid)"<<endl;
	return ss.str();
}

std::string _t_session_stm_stack(const std::string &session_name,
								 const int label,
								 const std::list<std::string> &stms){
	stringstream ss;
	ss<<"def __logic_session_"<<session_name<<"_"<<label<<"():"<<endl;
	for(auto stm : stms){
		ss<<indent(stm, 1)<<endl;
	}
	return ss.str();
}

std::string _t_print_html(const std::string &name,
						  std::list<std::string> args){
	string args_str = "{";
	if(args.size()){
		args_str.append(args.front());
		args.pop_front();
	}
	for(auto arg : args){
		args_str.append(","+arg+"\n");
	}
	args_str.append("}");
	auto layout = _t_py_fn_call("__layout",
			list<string>{_t_py_fn_call("__"+name,list<string>{args_str})});
	return _t_py_fn_call("print", list<string>{layout});
}

std::string _t_main_print_stms(const std::list<std::string> &sessions){
	if(sessions.size() <= 0){
		return "ERROR: no sessions are passed to code generation!";
	}
	stringstream ss;
	ss<<"print \"Content-type: text/html\""<<endl;
	ss<<"print"<<endl;
	bool firstif = true;
	for(auto session_name : sessions){
		if(!firstif){ss<<"el";}
		firstif=false;
		ss<<"if "<<session<<" == \""<<session_name<<"\":"<<endl;
		ss<<indent(1)<<"__session_"<<session_name<<"()"<<endl;
	}
	ss<<"else:"<<endl;
	ss<<indent(1)<<"print __layout(\"Please select one of the following sessions: ";
	auto it = sessions.begin();
	ss<<*it;
	++it;
	while(it != sessions.end()){
		ss<<", "<<*it;
		++it;
	}
	ss<<"\")"<<endl;
	return ss.str();
}
