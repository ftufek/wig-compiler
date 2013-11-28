#!/usr/bin/env python
import cgi
import cgitb
import os
import uuid
import pickle
import copy
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

def __a(__varDict):
	return """{gap}""".format(**(__varDict))

__global_vars = []
def __save_global_vars():
	global_vars_file = "GLOBAL_f1f2da46-0d92-407d-b12b-ecf7f0f1dda7"
	open(global_vars_file, 'w').close()
	global_vars = dict((k, __vars[k]) for k in __global_vars if k in __vars)
	with open(global_vars_file, "w") as f:
		pickle.dump(global_vars, f)
	return

def __load_global_vars():
	global __vars
	global_vars_file = "GLOBAL_f1f2da46-0d92-407d-b12b-ecf7f0f1dda7"
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

def __logic_fn_f_1(_arg_a):
	global __vars
	global __next_logic
	__vars["a_5_4"] = _arg_a
	__call_fn("f")
	__logic_fn_f_2()
def __logic_fn_f_2():
	global __vars
	global __next_logic
	__return_from_fn(__vars["a_5_4"] + 2)
def __logic_fn_add_1(_arg_a, _arg_b):
	global __vars
	global __next_logic
	__vars["a_8_6"] = _arg_a
	__vars["b_8_6"] = _arg_b
	__call_fn("add")
	__logic_fn_add_2()
def __logic_fn_add_2():
	global __vars
	global __next_logic
	__return_from_fn(__vars["a_8_6"] + __vars["b_8_6"])
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
	__vars["counter_12_8"] = 2
	__next_logic = 2
	__save_session_A()
	__logic_session_A_2()
def __logic_session_A_2():
	global __vars
	global __next_logic
	global __vars
	copy_of_vars = copy.deepcopy(__vars)
	__logic_fn_f_1(__vars["counter_12_8"])
	return_val = __vars["__return_value"]
	__vars = copy_of_vars
	__vars["__return_value"] = return_val
	__next_logic = 3
	__save_session_A()
	__logic_session_A_3()
def __logic_session_A_3():
	global __vars
	global __next_logic
	global __returned_from_fn
	if __returned_from_fn:
		__vars["9cd2a230-227f-46c3-8c87-573b28c4edf1"] = __vars["__return_value"]
		__next_logic = 4
		__save_session_A()
		__logic_session_A_4()
	
def __logic_session_A_4():
	global __vars
	global __next_logic
	global __vars
	copy_of_vars = copy.deepcopy(__vars)
	__logic_fn_add_1(__vars["counter_12_8"], 1)
	return_val = __vars["__return_value"]
	__vars = copy_of_vars
	__vars["__return_value"] = return_val
	__next_logic = 5
	__save_session_A()
	__logic_session_A_5()
def __logic_session_A_5():
	global __vars
	global __next_logic
	global __returned_from_fn
	if __returned_from_fn:
		__vars["12f1ff0c-38a1-41c8-8c20-4bba8570ee7b"] = __vars["__return_value"]
		__next_logic = 6
		__save_session_A()
		__logic_session_A_6()
	
def __logic_session_A_7():
	global __vars
	global __next_logic
	global __vars
	copy_of_vars = copy.deepcopy(__vars)
	__logic_fn_add_1(10, __vars["counter_12_8"])
	return_val = __vars["__return_value"]
	__vars = copy_of_vars
	__vars["__return_value"] = return_val
	__next_logic = 8
	__save_session_A()
	__logic_session_A_8()
def __logic_session_A_8():
	global __vars
	global __next_logic
	global __returned_from_fn
	if __returned_from_fn:
		__vars["469d5e72-60a6-4755-96ed-6c7f80b4e132"] = __vars["__return_value"]
		__next_logic = 9
		__save_session_A()
		__logic_session_A_9()
	
def __logic_session_A_9():
	global __vars
	global __next_logic
	print(__layout(__a({'gap':__vars["469d5e72-60a6-4755-96ed-6c7f80b4e132"]})))
	__next_logic = 10
	__save_session_A()
def __logic_session_A_10():
	global __vars
	global __next_logic
	__vars["counter_12_8"] = __vars["counter_12_8"] - 1
	__next_logic = 2
	__save_session_A()
	__logic_session_A_2()
def __logic_session_A_6():
	global __vars
	global __next_logic
	if __vars["9cd2a230-227f-46c3-8c87-573b28c4edf1"] > 0 and __vars["12f1ff0c-38a1-41c8-8c20-4bba8570ee7b"] > 1:
		__next_logic = 7
		__save_session_A()
		__logic_session_A_7()
	else:
		__next_logic = 11
		__save_session_A()
		__logic_session_A_11()
	
def __logic_session_A_11():
	global __vars
	global __next_logic
	global __vars
	copy_of_vars = copy.deepcopy(__vars)
	__logic_fn_f_1(3)
	return_val = __vars["__return_value"]
	__vars = copy_of_vars
	__vars["__return_value"] = return_val
	__next_logic = 12
	__save_session_A()
	__logic_session_A_12()
def __logic_session_A_12():
	global __vars
	global __next_logic
	global __returned_from_fn
	if __returned_from_fn:
		__vars["9f55a0e8-5881-40aa-977d-983c9d2fdf0b"] = __vars["__return_value"]
		__next_logic = 13
		__save_session_A()
		__logic_session_A_13()
	
def __logic_session_A_13():
	global __vars
	global __next_logic
	print(__layout(__a({'gap':__vars["9f55a0e8-5881-40aa-977d-983c9d2fdf0b"]})))
	__next_logic = 14
	__save_session_A()
def __logic_session_A_14():
	global __vars
	global __next_logic
	__next_logic = 13
	__save_session_A()
	__logic_session_A_13()
print "Content-type: text/html"
print
__load_global_vars()
if __session == "A":
	__session_A()
else:
	print __layout("Please select one of the following sessions: A")
__save_global_vars()

