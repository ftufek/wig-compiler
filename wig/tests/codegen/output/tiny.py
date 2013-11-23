#!/usr/bin/env python
import cgi
import cgitb
import os
import uuid
import pickle
cgitb.enable()
__cgi_input = cgi.FieldStorage()
__session = os.environ["QUERY_STRING"].split("&")[0]
__vars = {}
__sid = 0
__next_logic = 1

def __str_sid():
	if __sid != 0:
		return "&sid="+str(__sid)
	else:
		return ""

def __action_name():
	return os.path.basename(__file__)+"?"+__session+__str_sid()

def __layout(page):
	return """<html><form action="{action}" method="POST">
	{page} <input type="submit" value="go">
	</form></html>""".format(action=__action_name(),page=page)

def __Welcome(__varDict):
	return """ <body>
    Welcome!
  </body> """.format(**(__varDict))

def __Pledge(__varDict):
	return """ <body>
    How much do you want to contribute?
    <input name="contribution" size=4 type="text">
  </body> """.format(**(__varDict))

def __Total(__varDict):
	return """ <body>
    The total is now {total}.
  </body> """.format(**(__varDict))

__global_vars = []
def __save_global_vars():
	global_vars_file = "GLOBAL_cc537bd3-6c57-4dc5-92be-f4e44d7e1458"
	open(global_vars_file, 'w').close()
	global_vars = dict((k, __vars[k]) for k in __global_vars if k in __vars)
	with open(global_vars_file, "w") as f:
		pickle.dump(global_vars, f)
	return

def __load_global_vars():
	global __vars
	global_vars_file = "GLOBAL_cc537bd3-6c57-4dc5-92be-f4e44d7e1458"
	try:
		with open(global_vars_file, "r") as f:
			global_vars = pickle.load(f)
			__vars = dict(__vars.items() + global_vars.items())
	except IOError:
		return

__vars["amount_15_7"] = 0
__global_vars.append("amount_15_7")
def __save_session_Contribute():
	session_file = "Contribute$"+str(__sid)
	open(session_file, 'w').close()
	session_vars = dict((k, __vars[k]) for k in __vars if k not in __global_vars)
	with open(session_file, "w") as f:
		pickle.dump(session_vars, f)
		pickle.dump(__next_logic, f)
	return

def __init_session_Contribute():
	global __sid
	global __next_logic
	__sid = str(uuid.uuid4())
	__next_logic = 1
	__save_session_Contribute()
	__logic_session_Contribute_1()

def __load_session_Contribute(session_id):
	global __vars
	global __next_logic
	global __sid
	__sid = session_id
	with open("Contribute$"+str(__sid), "r") as f:
		session_vars = pickle.load(f)
		__next_logic = pickle.load(f)
		__vars = dict(__vars.items() + session_vars.items())
	globals()["__logic_session_Contribute_"+str(__next_logic)]()

def __session_Contribute():
	sid = __cgi_input.getvalue("sid", "")
	if sid == "":
		__init_session_Contribute()
	else:
		__load_session_Contribute(sid)

def __logic_session_Contribute_1():
	global __vars
	global __next_logic
	__vars["i_18_8"]=87
	print(__layout(__Welcome({})))
	__next_logic = 2
	__save_session_Contribute()
def __logic_session_Contribute_2():
	global __vars
	global __next_logic
	print(__layout(__Pledge({})))
	__next_logic = 3
	__save_session_Contribute()
def __logic_session_Contribute_3():
	global __vars
	global __next_logic
	__vars["i_18_8"] = __cgi_input.getvalue("contribution")
	__vars["amount_15_7"]=__vars["amount_15_7"]+__vars["i_18_8"]
	print(__layout(__Total({'total':__vars["amount_15_7"]})))
	__next_logic = 4
	__save_session_Contribute()
print "Content-type: text/html"
print
__load_global_vars()
if __session == "Contribute":
	__session_Contribute()
else:
	print __layout("Please select one of the following sessions: Contribute")
__save_global_vars()

