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
__vars["__exited_from"] = -1

class Item():
	def __init__(self, dict):
		setattr(self, "name", "")
		setattr(self, "available", False)
		setattr(self, "price", 0)
		for k, v in dict.items():
			setattr(self, k, v)

	def schema_vars(self):
		__schema_vars = []
		__schema_vars.append("name")
		__schema_vars.append("available")
		__schema_vars.append("price")
		return __schema_vars

	def keep(self, list_to_keep):
		__copy = copy.deepcopy(self)
		for keep in self.schema_vars():
			if keep not in list_to_keep:
				setattr(__copy, keep, None)
		return __copy

	def discard(self, list_to_discard):
		__copy = copy.deepcopy(self)
		for discard in list_to_discard:
			setattr(__copy, discard, None)
		return __copy

	def combine(self, other):
		__copy = copy.deepcopy(self)
		for v in other.schema_vars():
			setattr(__copy, v, getattr(other, v))
		return __copy


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
	return """""".format(**(__varDict))

def __b(__varDict):
	return """{gap}""".format(**(__varDict))

__global_vars = []
def __save_global_vars():
	global_vars_file = "GLOBAL_fe18d9b8-c349-4e8c-90a8-2f032cf76821"
	open(global_vars_file, 'w').close()
	global_vars = dict((k, __vars[k]) for k in __global_vars if k in __vars)
	with open(global_vars_file, "w") as f:
		pickle.dump(global_vars, f)
	return

def __load_global_vars():
	global __vars
	global_vars_file = "GLOBAL_fe18d9b8-c349-4e8c-90a8-2f032cf76821"
	try:
		with open(global_vars_file, "r") as f:
			global_vars = pickle.load(f)
			__vars = dict(__vars.items() + global_vars.items())
	except IOError:
		return

__vars["counter_12_7"] = 0
__global_vars.append("counter_12_7")
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

def __save_session_d():
	session_file = "d$"+str(__sid)
	open(session_file, 'w').close()
	session_vars = dict((k, __vars[k]) for k in __vars if k not in __global_vars)
	with open(session_file, "w") as f:
		pickle.dump(session_vars, f)
		pickle.dump(__next_logic, f)
	return

def __init_session_d():
	global __sid
	global __next_logic
	__sid = str(uuid.uuid4())
	__next_logic = 1
	__save_session_d()
	__logic_session_d_1()

def __load_session_d(session_id):
	global __vars
	global __next_logic
	global __sid
	__sid = session_id
	with open("d$"+str(__sid), "r") as f:
		session_vars = pickle.load(f)
		__next_logic = pickle.load(f)
		__vars = dict(__vars.items() + session_vars.items())
	if __vars["__exited_from"] != -1:
		__next_logic = __vars["__exited_from"]
		__save_session_d()
		globals()["__logic_session_d_"+str(__vars["__exited_from"])]()
		return
	__continue_stack_execution()
	globals()["__logic_session_d_"+str(__next_logic)]()

def __session_d():
	sid = __cgi_input.getvalue("sid", "")
	if sid == "":
		__init_session_d()
	else:
		__load_session_d(sid)

def __logic_session_d_1():
	global __vars
	global __next_logic
	__vars["counter_14_8"] = 4
	__vars["a_15_8"] = 3
	__next_logic = 2
	__save_session_d()
	__logic_session_d_2()
def __logic_session_d_3():
	global __vars
	global __next_logic
	__vars["counter_14_8"] = (__vars["counter_14_8"] - 1)
	print(__layout(__b({'gap':__vars["counter_14_8"]})))
	__next_logic = 4
	__save_session_d()
def __logic_session_d_4():
	global __vars
	global __next_logic
	__next_logic = 2
	__save_session_d()
	__logic_session_d_2()
def __logic_session_d_2():
	global __vars
	global __next_logic
	if (__vars["counter_14_8"] > 0):
		__next_logic = 3
		__save_session_d()
		__logic_session_d_3()
	else:
		__next_logic = 5
		__save_session_d()
		__logic_session_d_5()
	
def __logic_session_d_5():
	global __vars
	global __next_logic
	print(__layout(__b({'gap':__vars["counter_14_8"]})))
	__vars["__exited_from"] = 5
	__next_logic = 6
	__save_session_d()
def __logic_session_d_6():
	global __vars
	global __next_logic
	__next_logic = 5
	__save_session_d()
	__logic_session_d_5()
print "Content-type: text/html"
print
__load_global_vars()
if __session == "d":
	__session_d()
else:
	print __layout("Please select one of the following sessions: d")
__save_global_vars()

