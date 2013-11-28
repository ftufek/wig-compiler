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

def __a(__varDict):
	return """{gap}""".format(**(__varDict))

__global_vars = []
def __save_global_vars():
	global_vars_file = "GLOBAL_cb612d3c-09e4-47d3-93d6-5198ce363971"
	open(global_vars_file, 'w').close()
	global_vars = dict((k, __vars[k]) for k in __global_vars if k in __vars)
	with open(global_vars_file, "w") as f:
		pickle.dump(global_vars, f)
	return

def __load_global_vars():
	global __vars
	global_vars_file = "GLOBAL_cb612d3c-09e4-47d3-93d6-5198ce363971"
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
	__logic_fn_f_1(__vars["counter_12_8"])
	__next_logic = 3
	__save_session_A()
	__logic_session_A_3()
def __logic_session_A_3():
	global __vars
	global __next_logic
	global __returned_from_fn
	if __returned_from_fn:
		__vars["7c81a8ec-22c9-41a4-bc2a-bd2825a58165"] = __vars["__return_value"]
		__next_logic = 4
		__save_session_A()
		__logic_session_A_4()
	
def __logic_session_A_4():
	global __vars
	global __next_logic
	__logic_fn_add_1(__vars["counter_12_8"], 1)
	__next_logic = 5
	__save_session_A()
	__logic_session_A_5()
def __logic_session_A_5():
	global __vars
	global __next_logic
	global __returned_from_fn
	if __returned_from_fn:
		__vars["d84d3d11-bba9-48ba-8994-06883c628276"] = __vars["__return_value"]
		__next_logic = 6
		__save_session_A()
		__logic_session_A_6()
	
def __logic_session_A_7():
	global __vars
	global __next_logic
	__logic_fn_add_1(10, __vars["counter_12_8"])
	__next_logic = 8
	__save_session_A()
	__logic_session_A_8()
def __logic_session_A_8():
	global __vars
	global __next_logic
	global __returned_from_fn
	if __returned_from_fn:
		__vars["f9bca696-9c60-45b9-b6c9-b9ea1cab73af"] = __vars["__return_value"]
		__next_logic = 9
		__save_session_A()
		__logic_session_A_9()
	
def __logic_session_A_9():
	global __vars
	global __next_logic
	print(__layout(__a({'gap':__vars["f9bca696-9c60-45b9-b6c9-b9ea1cab73af"]})))
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
	if __vars["7c81a8ec-22c9-41a4-bc2a-bd2825a58165"] > 0 and __vars["d84d3d11-bba9-48ba-8994-06883c628276"] > 1:
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
	__logic_fn_f_1(3)
	__next_logic = 12
	__save_session_A()
	__logic_session_A_12()
def __logic_session_A_12():
	global __vars
	global __next_logic
	global __returned_from_fn
	if __returned_from_fn:
		__vars["126bcf07-f112-4fa1-9017-e5e992bf0adc"] = __vars["__return_value"]
		__next_logic = 13
		__save_session_A()
		__logic_session_A_13()
	
def __logic_session_A_13():
	global __vars
	global __next_logic
	print(__layout(__a({'gap':__vars["126bcf07-f112-4fa1-9017-e5e992bf0adc"]})))
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

