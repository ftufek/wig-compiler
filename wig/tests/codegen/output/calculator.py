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

def __Setup(__varDict):
	return """ <body>
    <h1>A Simple Plus Minus Calculator</h1>
    <p>
    Enter your operator (+ or -):
    <input name="operator" size=1 type="text">
    <p>
    Enter the first integer (-99 to 999):
    <input name="int1" size=3 type="text">
    <p>
    Enter the second integer (-99 to 999):
    <input name="int2" size=3 type="text">
  </body> """.format(**(__varDict))

def __Return(__varDict):
	return """ <body>
    <h1>The Answer</h1>
    <p>
    <b>Your answer is : {Ans} </b>
    <p>
    Would you like to do another calculation (yes or no)?
    <input name="YorN" size=5 type="text">
  </body> """.format(**(__varDict))

def __ByeBye(__varDict):
	return """ <body>
    <h1>Thank you for using this calculator</h1>
  </body> """.format(**(__varDict))

__global_vars = []
def __save_global_vars():
	global_vars_file = "GLOBAL_eca7025c-9b02-4b01-a954-7682e8fc853e"
	open(global_vars_file, 'w').close()
	global_vars = dict((k, __vars[k]) for k in __global_vars if k in __vars)
	with open(global_vars_file, "w") as f:
		pickle.dump(global_vars, f)
	return

def __load_global_vars():
	global __vars
	global_vars_file = "GLOBAL_eca7025c-9b02-4b01-a954-7682e8fc853e"
	try:
		with open(global_vars_file, "r") as f:
			global_vars = pickle.load(f)
			__vars = dict(__vars.items() + global_vars.items())
	except IOError:
		return

__vars["Ans_28_7"] = 0
__global_vars.append("Ans_28_7")
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

def __save_session_Calculate():
	session_file = "Calculate$"+str(__sid)
	open(session_file, 'w').close()
	session_vars = dict((k, __vars[k]) for k in __vars if k not in __global_vars)
	with open(session_file, "w") as f:
		pickle.dump(session_vars, f)
		pickle.dump(__next_logic, f)
	return

def __init_session_Calculate():
	global __sid
	global __next_logic
	__sid = str(uuid.uuid4())
	__next_logic = 1
	__save_session_Calculate()
	__logic_session_Calculate_1()

def __load_session_Calculate(session_id):
	global __vars
	global __next_logic
	global __sid
	__sid = session_id
	with open("Calculate$"+str(__sid), "r") as f:
		session_vars = pickle.load(f)
		__next_logic = pickle.load(f)
		__vars = dict(__vars.items() + session_vars.items())
	__continue_stack_execution()
	globals()["__logic_session_Calculate_"+str(__next_logic)]()

def __session_Calculate():
	sid = __cgi_input.getvalue("sid", "")
	if sid == "":
		__init_session_Calculate()
	else:
		__load_session_Calculate(sid)

def __logic_session_Calculate_1():
	global __vars
	global __next_logic
	__vars["YorN_31_8"] = ""
	__next_logic = 2
	__save_session_Calculate()
	__logic_session_Calculate_2()
def __logic_session_Calculate_3():
	global __vars
	global __next_logic
	print(__layout(__Setup({})))
	__next_logic = 4
	__save_session_Calculate()
def __logic_session_Calculate_4():
	global __vars
	global __next_logic
	__vars["operator_33_8"] = __cgi_input.getvalue("operator")
	__vars["int1_32_8"] = int(__cgi_input.getvalue("int1"))
	__vars["int2_32_8"] = int(__cgi_input.getvalue("int2"))
	__next_logic = 5
	__save_session_Calculate()
	__logic_session_Calculate_5()
def __logic_session_Calculate_6():
	global __vars
	global __next_logic
	__vars["Ans_28_7"] = __vars["int1_32_8"] + __vars["int2_32_8"]
	__next_logic = 7
	__save_session_Calculate()
	__logic_session_Calculate_7()
def __logic_session_Calculate_5():
	global __vars
	global __next_logic
	if __vars["operator_33_8"] == "+":
		__next_logic = 6
		__save_session_Calculate()
		__logic_session_Calculate_6()
	else:
		__next_logic = 7
		__save_session_Calculate()
		__logic_session_Calculate_7()
	
def __logic_session_Calculate_8():
	global __vars
	global __next_logic
	__vars["Ans_28_7"] = __vars["int1_32_8"] - __vars["int2_32_8"]
	__next_logic = 9
	__save_session_Calculate()
	__logic_session_Calculate_9()
def __logic_session_Calculate_7():
	global __vars
	global __next_logic
	if __vars["operator_33_8"] == "-":
		__next_logic = 8
		__save_session_Calculate()
		__logic_session_Calculate_8()
	else:
		__next_logic = 9
		__save_session_Calculate()
		__logic_session_Calculate_9()
	
def __logic_session_Calculate_9():
	global __vars
	global __next_logic
	print(__layout(__Return({'Ans':__vars["Ans_28_7"]})))
	__next_logic = 10
	__save_session_Calculate()
def __logic_session_Calculate_10():
	global __vars
	global __next_logic
	__vars["YorN_31_8"] = __cgi_input.getvalue("YorN")
	__next_logic = 11
	__save_session_Calculate()
	__logic_session_Calculate_11()
def __logic_session_Calculate_11():
	global __vars
	global __next_logic
	__next_logic = 2
	__save_session_Calculate()
	__logic_session_Calculate_2()
def __logic_session_Calculate_2():
	global __vars
	global __next_logic
	if __vars["YorN_31_8"] != "no":
		__next_logic = 3
		__save_session_Calculate()
		__logic_session_Calculate_3()
	else:
		__next_logic = 12
		__save_session_Calculate()
		__logic_session_Calculate_12()
	
def __logic_session_Calculate_12():
	global __vars
	global __next_logic
	print(__layout(__ByeBye({})))
	__next_logic = 13
	__save_session_Calculate()
def __logic_session_Calculate_13():
	global __vars
	global __next_logic
	__next_logic = 12
	__save_session_Calculate()
	__logic_session_Calculate_12()
print "Content-type: text/html"
print
__load_global_vars()
if __session == "Calculate":
	__session_Calculate()
else:
	print __layout("Please select one of the following sessions: Calculate")
__save_global_vars()

