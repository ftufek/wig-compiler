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

def __a(__varDict):
	return """{gap}""".format(**(__varDict))

def __going_to_add(__varDict):
	return """
		We're going to add: {n1} + {n2}""".format(**(__varDict))

def __result(__varDict):
	return """The result is: {result}""".format(**(__varDict))

def __only_positive(__varDict):
	return """
		We can only add positive integer!""".format(**(__varDict))

__global_vars = []
def __save_global_vars():
	global_vars_file = "GLOBAL_146b5caf-101a-4d53-bc91-2c15e496985e"
	open(global_vars_file, 'w').close()
	global_vars = dict((k, __vars[k]) for k in __global_vars if k in __vars)
	with open(global_vars_file, "w") as f:
		pickle.dump(global_vars, f)
	return

def __load_global_vars():
	global __vars
	global_vars_file = "GLOBAL_146b5caf-101a-4d53-bc91-2c15e496985e"
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

def __logic_fn_recursive_add_1(_arg_a, _arg_b):
	global __vars
	global __next_logic
	
	__call_fn("recursive_add")
	__vars["a_13_10"] = _arg_a
	__vars["b_13_10"] = _arg_b
	__set_fn_logic(2)
	__logic_fn_recursive_add_2()
def __logic_fn_recursive_add_3():
	global __vars
	global __next_logic
	
	print(__layout(__only_positive({})))
	__set_fn_logic(4)
def __logic_fn_recursive_add_4():
	global __vars
	global __next_logic
	
	__return_from_fn(0)
def __logic_fn_recursive_add_5():
	global __vars
	global __next_logic
	
	print(__layout(__going_to_add({'n1':__vars["a_13_10"],'n2':__vars["b_13_10"]
	})))
	__set_fn_logic(6)
def __logic_fn_recursive_add_7():
	global __vars
	global __next_logic
	
	global __vars
	__set_fn_logic(8)
	
	__logic_fn_recursive_add_1(__vars["a_13_10"], __vars["b_13_10"] - 1)
	__logic_fn_recursive_add_8()
def __logic_fn_recursive_add_8():
	global __vars
	global __next_logic
	
	global __returned_from_fn
	if __returned_from_fn:
		__returned_from_fn = False
		__vars["e2ab73d4-5e61-44c1-abab-c9ff750482c1"] = __vars["__return_value"]
		__set_fn_logic(9)
		__logic_fn_recursive_add_9()
	
def __logic_fn_recursive_add_9():
	global __vars
	global __next_logic
	
	__return_from_fn(__vars["e2ab73d4-5e61-44c1-abab-c9ff750482c1"] + 1)
def __logic_fn_recursive_add_10():
	global __vars
	global __next_logic
	
	__return_from_fn(__vars["a_13_10"])
def __logic_fn_recursive_add_11():
	global __vars
	global __next_logic
	
	__set_fn_logic(13)
	__logic_fn_recursive_add_13()
def __logic_fn_recursive_add_12():
	global __vars
	global __next_logic
	
	__set_fn_logic(13)
	__logic_fn_recursive_add_13()
def __logic_fn_recursive_add_6():
	global __vars
	global __next_logic
	
	if __vars["b_13_10"] > 0:
		__set_fn_logic(7)
		__logic_fn_recursive_add_7()
	else:
		__set_fn_logic(10)
		__logic_fn_recursive_add_10()
	
def __logic_fn_recursive_add_13():
	global __vars
	global __next_logic
	
	__set_fn_logic(15)
	__logic_fn_recursive_add_15()
def __logic_fn_recursive_add_14():
	global __vars
	global __next_logic
	
	__set_fn_logic(15)
	__logic_fn_recursive_add_15()
def __logic_fn_recursive_add_2():
	global __vars
	global __next_logic
	
	if __vars["a_13_10"] < 0 or __vars["b_13_10"] < 0:
		__set_fn_logic(3)
		__logic_fn_recursive_add_3()
	else:
		__set_fn_logic(5)
		__logic_fn_recursive_add_5()
	
def __save_session_A():
	session_file = "A$"+str(__sid)
	open(session_file, 'w').close()
	session_vars = dict((k, __vars[k]) for k in __vars if k not in __global_vars)
	with open(session_file, "w") as f:
		pickle.dump(session_vars, f)
		pickle.dump(__next_logic, f)
	return

def __init_session_A():
	global __sid
	global __next_logic
	__sid = str(uuid.uuid4())
	__next_logic = 1
	__save_session_A()
	__logic_session_A_1()

def __load_session_A(session_id):
	global __vars
	global __next_logic
	global __sid
	__sid = session_id
	with open("A$"+str(__sid), "r") as f:
		session_vars = pickle.load(f)
		__next_logic = pickle.load(f)
		__vars = dict(__vars.items() + session_vars.items())
	__continue_stack_execution()
	globals()["__logic_session_A_"+str(__next_logic)]()

def __session_A():
	sid = __cgi_input.getvalue("sid", "")
	if sid == "":
		__init_session_A()
	else:
		__load_session_A(sid)

def __logic_session_A_1():
	global __vars
	global __next_logic
	global __vars
	__logic_fn_recursive_add_1(2, 2)
	__next_logic = 2
	__save_session_A()
	__logic_session_A_2()
def __logic_session_A_2():
	global __vars
	global __next_logic
	global __returned_from_fn
	if __returned_from_fn:
		__returned_from_fn = False
		__vars["a153a52c-4adc-4ec9-8ac0-3825730283df"] = __vars["__return_value"]
		__next_logic = 3
		__save_session_A()
		__logic_session_A_3()
	else:
		__save_session_A()
	
def __logic_session_A_3():
	global __vars
	global __next_logic
	__vars["result_28_20"] = __vars["a153a52c-4adc-4ec9-8ac0-3825730283df"]
	print(__layout(__a({'gap':__vars["result_28_20"]})))
	__next_logic = 4
	__save_session_A()
def __logic_session_A_4():
	global __vars
	global __next_logic
	__next_logic = 3
	__save_session_A()
	__logic_session_A_3()
print "Content-type: text/html"
print
__load_global_vars()
if __session == "A":
	__session_A()
else:
	print __layout("Please select one of the following sessions: A")
__save_global_vars()

