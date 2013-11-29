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

def __status(__varDict):
	return """<body>Computing 10! ...</body>""".format(**(__varDict))

def __wrong(__varDict):
	return """<body>You calculated 10! = {n}<br>You have <b>failed</b> the show inside functions test!</body>""".format(**(__varDict))

def __right(__varDict):
	return """<body>You calculated 10! = {n}<br>Congratulations! You have <b>passed</b> the show inside functions test!</body>""".format(**(__varDict))

__global_vars = []
def __save_global_vars():
	global_vars_file = "GLOBAL_3fcf73ca-c4e8-4104-baae-d91c5ce67f07"
	open(global_vars_file, 'w').close()
	global_vars = dict((k, __vars[k]) for k in __global_vars if k in __vars)
	with open(global_vars_file, "w") as f:
		pickle.dump(global_vars, f)
	return

def __load_global_vars():
	global __vars
	global_vars_file = "GLOBAL_3fcf73ca-c4e8-4104-baae-d91c5ce67f07"
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

def __logic_fn_factorial_1(_arg_n):
	global __vars
	global __next_logic
	
	__call_fn("factorial")
	__vars["n_9_8"] = _arg_n
	__set_fn_logic(2)
	__logic_fn_factorial_2()
def __logic_fn_factorial_3():
	global __vars
	global __next_logic
	
	print(__layout(__status({})))
	__set_fn_logic(4)
def __logic_fn_factorial_4():
	global __vars
	global __next_logic
	
	__return_from_fn(1)
def __logic_fn_factorial_5():
	global __vars
	global __next_logic
	
	__set_fn_logic(6)
	__logic_fn_factorial_6()
def __logic_fn_factorial_2():
	global __vars
	global __next_logic
	
	if __vars["n_9_8"] == 0:
		__set_fn_logic(3)
		__logic_fn_factorial_3()
	else:
		__set_fn_logic(6)
		__logic_fn_factorial_6()
	
def __logic_fn_factorial_6():
	global __vars
	global __next_logic
	
	global __vars
	__set_fn_logic(7)
	
	__logic_fn_factorial_1(__vars["n_9_8"] - 1)
	__logic_fn_factorial_7()
def __logic_fn_factorial_7():
	global __vars
	global __next_logic
	
	global __returned_from_fn
	if __returned_from_fn:
		__returned_from_fn = False
		__vars["7fba1d6f-361b-45b1-bcd0-a256dc8b27d3"] = __vars["__return_value"]
		__set_fn_logic(8)
		__logic_fn_factorial_8()
	
def __logic_fn_factorial_8():
	global __vars
	global __next_logic
	
	__return_from_fn(__vars["n_9_8"] * __vars["7fba1d6f-361b-45b1-bcd0-a256dc8b27d3"])
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
	__continue_stack_execution()
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
	global __vars
	__logic_fn_factorial_1(10)
	__next_logic = 2
	__save_session_Test()
	__logic_session_Test_2()
def __logic_session_Test_2():
	global __vars
	global __next_logic
	global __returned_from_fn
	if __returned_from_fn:
		__returned_from_fn = False
		__vars["2ff2ff0b-c5c5-43cf-a554-b8fb14790945"] = __vars["__return_value"]
		__next_logic = 3
		__save_session_Test()
		__logic_session_Test_3()
	else:
		__save_session_Test()
	
def __logic_session_Test_3():
	global __vars
	global __next_logic
	__vars["n_21_12"] = __vars["2ff2ff0b-c5c5-43cf-a554-b8fb14790945"]
	__next_logic = 4
	__save_session_Test()
	__logic_session_Test_4()
def __logic_session_Test_5():
	global __vars
	global __next_logic
	print(__layout(__wrong({'n':__vars["n_21_12"]})))
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
	if __vars["n_21_12"] != 3628800:
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
	print(__layout(__right({'n':__vars["n_21_12"]})))
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

