#!/usr/bin/env python
import cgi
import cgitb
import os
import uuid
import pickle
import copy
import sys
import traceback
cgitb.enable()
__cgi_input = cgi.FieldStorage(keep_blank_values=1)
__session = os.environ["QUERY_STRING"].split("&")[0]
sys.stderr = sys.stdout
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

def __Nikolaj(__varDict):
	return """ <body>
     <img src="http://www.brics.dk/~mis/babybath.jpg">
     <p>
     <i>You are visitor number {no}</i>
  </body> """.format(**(__varDict))

__global_vars = []
def __save_global_vars():
	global_vars_file = "GLOBAL_935d497e-626d-4ec2-b5e0-df81ef72a8b9"
	open(global_vars_file, 'w').close()
	global_vars = dict((k, __vars[k]) for k in __global_vars if k in __vars)
	with open(global_vars_file, "w") as f:
		pickle.dump(global_vars, f)
	return

def __load_global_vars():
	global __vars
	global_vars_file = "GLOBAL_935d497e-626d-4ec2-b5e0-df81ef72a8b9"
	try:
		with open(global_vars_file, "r") as f:
			global_vars = pickle.load(f)
			__vars = dict(__vars.items() + global_vars.items())
	except IOError:
		return

__vars["counter_8_3"] = 0
__global_vars.append("counter_8_3")
__vars["__call_stack"] = []
__vars["__return_value"] = 0
__returned_from_fn = False

def __call_fn(fn_name):
	global __vars
	call_stack_copy = copy.deepcopy(__vars["__call_stack"])
	del __vars["__call_stack"]
	old_vars = copy.deepcopy(__vars)
	__vars["__call_stack"] = call_stack_copy
	__vars["__call_stack"].append({"name":fn_name,"next_logic":1, "old_vars":old_vars})

def __set_fn_logic(n):
	global __vars
	__vars["__call_stack"][-1]["next_logic"] = n

def __return_from_fn(return_value):
	global __returned_from_fn
	global __vars
	call_stack_copy = copy.deepcopy(__vars["__call_stack"])
	__vars = __vars["__call_stack"][-1]["old_vars"]
	call_stack_copy.pop()
	__vars["__call_stack"] = call_stack_copy
	__returned_from_fn = True
	__vars["__return_value"] = return_value

def __continue_stack_execution():
	while True:
		if __vars["__call_stack"]:
			fn_name = __vars["__call_stack"][-1]["name"]
			fn_ln = __vars["__call_stack"][-1]["next_logic"]
			globals()["__logic_fn_"+fn_name+"_"+str(fn_ln)]()
		else:
			break
		if not __returned_from_fn:
			break

def __save_session_Access():
	session_file = "Access$"+str(__sid)
	open(session_file, 'w').close()
	session_vars = dict((k, __vars[k]) for k in __vars if k not in __global_vars)
	with open(session_file, "w") as f:
		pickle.dump(session_vars, f)
		pickle.dump(__next_logic, f)
	return

def __init_session_Access():
	global __sid
	global __next_logic
	__sid = str(uuid.uuid4())
	__next_logic = 1
	__save_session_Access()
	__logic_session_Access_1()

def __load_session_Access(session_id):
	global __vars
	global __next_logic
	global __sid
	__sid = session_id
	with open("Access$"+str(__sid), "r") as f:
		session_vars = pickle.load(f)
		__next_logic = pickle.load(f)
		__vars = dict(__vars.items() + session_vars.items())
	__continue_stack_execution()
	globals()["__logic_session_Access_"+str(__next_logic)]()

def __session_Access():
	sid = __cgi_input.getvalue("sid", "")
	if sid == "":
		__init_session_Access()
	else:
		__load_session_Access(sid)

def __logic_session_Access_1():
	global __vars
	global __next_logic
	__vars["counter_8_3"] = __vars["counter_8_3"] + 1
	print(__layout(__Nikolaj({'no':__vars["counter_8_3"]})))
	__next_logic = 2
	__save_session_Access()
def __logic_session_Access_2():
	global __vars
	global __next_logic
	__next_logic = 1
	__save_session_Access()
	__logic_session_Access_1()
print "Content-type: text/html"
print
__load_global_vars()
if __session == "Access":
	__session_Access()
else:
	print __layout("Please select one of the following sessions: Access")
__save_global_vars()

