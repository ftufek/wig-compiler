#!/usr/bin/env python
import cgi
import cgitb
import os
import uuid
import pickle
cgitb.enable()
__cgi_input = cgi.FieldStorage(keep_blank_values=1)
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

def __status(__varDict):
	return """<body>Computing 10! ...</body>""".format(**(__varDict))

def __wrong(__varDict):
	return """<body>You calculated 10! = {n}<br>You have <b>failed</b> the show inside functions test!</body>""".format(**(__varDict))

def __right(__varDict):
	return """<body>You calculated 10! = {n}<br>Congratulations! You have <b>passed</b> the show inside functions test!</body>""".format(**(__varDict))

__global_vars = []
def __save_global_vars():
	global_vars_file = "GLOBAL_632ffc7d-6907-4b91-aa98-093be9f653f3"
	open(global_vars_file, 'w').close()
	global_vars = dict((k, __vars[k]) for k in __global_vars if k in __vars)
	with open(global_vars_file, "w") as f:
		pickle.dump(global_vars, f)
	return

def __load_global_vars():
	global __vars
	global_vars_file = "GLOBAL_632ffc7d-6907-4b91-aa98-093be9f653f3"
	try:
		with open(global_vars_file, "r") as f:
			global_vars = pickle.load(f)
			__vars = dict(__vars.items() + global_vars.items())
	except IOError:
		return

__vars["__call_stack"] = []
__vars["__return_value"] = 0
__returned_from_fn = False

def __call_fn(fn_name):
	global __vars
	__vars["__call_stack"].append({"name":fn_name,"next_logic":1})

def __inc_fn_logic():
	global __vars
	__vars["__call_stack"][-1]["next_logic"] += 1

def __return_from_fn(return_value):
	global __returned_from_fn
	global __vars
	__returned_from_fn = True
	__vars["__return_value"] = return_value
	__vars["__call_stack"].pop()

def __logic_fn_factorial_1(_arg_n):
	global __vars
	global __next_logic
	__vars["n_9_8"] = _arg_n
	__call_fn("factorial")
	__logic_fn_factorial_2()
def __logic_fn_factorial_3():
	global __vars
	global __next_logic
	__return_from_fn(1)
def __logic_fn_factorial_4():
	global __vars
	global __next_logic
	__logic_fn_factorial_5()
def __logic_fn_factorial_2():
	global __vars
	global __next_logic
	if __vars["n_9_8"] == 0:
		__logic_fn_factorial_3()
	else:
		__logic_fn_factorial_5()
	
def __logic_fn_factorial_5():
	global __vars
	global __next_logic
	__logic_fn_factorial_1(__vars["n_9_8"] - 1)
	__logic_fn_factorial_6()
def __logic_fn_factorial_6():
	global __vars
	global __next_logic
	global __returned_from_fn
	if __returned_from_fn:
		__vars["aee0db27-532d-49d7-9199-693d2a546163"] = __vars["__return_value"]
		__logic_fn_factorial_7()
	
def __logic_fn_factorial_7():
	global __vars
	global __next_logic
	__return_from_fn(__vars["n_9_8"] * __vars["aee0db27-532d-49d7-9199-693d2a546163"])
def __save_session_Test():
	session_file = "Test$"+str(__sid)
	open(session_file, 'w').close()
	session_vars = dict((k, __vars[k]) for k in __vars if k not in __global_vars)
	with open(session_file, "w") as f:
		pickle.dump(session_vars, f)
		pickle.dump(__next_logic, f)
	return

def __init_session_Test():
	global __sid
	global __next_logic
	__sid = str(uuid.uuid4())
	__next_logic = 1
	__save_session_Test()
	__logic_session_Test_1()

def __load_session_Test(session_id):
	global __vars
	global __next_logic
	global __sid
	__sid = session_id
	with open("Test$"+str(__sid), "r") as f:
		session_vars = pickle.load(f)
		__next_logic = pickle.load(f)
		__vars = dict(__vars.items() + session_vars.items())
	globals()["__logic_session_Test_"+str(__next_logic)]()

def __session_Test():
	sid = __cgi_input.getvalue("sid", "")
	if sid == "":
		__init_session_Test()
	else:
		__load_session_Test(sid)

def __logic_session_Test_1():
	global __vars
	global __next_logic
	__logic_fn_factorial_1(2)
	__next_logic = 2
	__save_session_Test()
	__logic_session_Test_2()
def __logic_session_Test_2():
	global __vars
	global __next_logic
	global __returned_from_fn
	if __returned_from_fn:
		__vars["e9b92d9e-a55c-4796-b024-411210e267e5"] = __vars["__return_value"]
		__next_logic = 3
		__save_session_Test()
		__logic_session_Test_3()
	
def __logic_session_Test_3():
	global __vars
	global __next_logic
	__vars["n_20_12"] = __vars["e9b92d9e-a55c-4796-b024-411210e267e5"]
	__next_logic = 4
	__save_session_Test()
	__logic_session_Test_4()
def __logic_session_Test_5():
	global __vars
	global __next_logic
	print(__layout(__wrong({'n':__vars["n_20_12"]})))
	__next_logic = 6
	__save_session_Test()
def __logic_session_Test_6():
	global __vars
	global __next_logic
	__next_logic = 7
	__save_session_Test()
	__logic_session_Test_7()
def __logic_session_Test_4():
	global __vars
	global __next_logic
	if __vars["n_20_12"] != 2:
		__next_logic = 5
		__save_session_Test()
		__logic_session_Test_5()
	else:
		__next_logic = 7
		__save_session_Test()
		__logic_session_Test_7()
	
def __logic_session_Test_7():
	global __vars
	global __next_logic
	print(__layout(__right({'n':__vars["n_20_12"]})))
	__next_logic = 8
	__save_session_Test()
def __logic_session_Test_8():
	global __vars
	global __next_logic
	__next_logic = 7
	__save_session_Test()
	__logic_session_Test_7()
print "Content-type: text/html"
print
__load_global_vars()
if __session == "Test":
	__session_Test()
else:
	print __layout("Please select one of the following sessions: Test")
__save_global_vars()

