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

class Scm1():
	def __init__(self, dict):
		for k, v in dict.items():
			setattr(self, k, v)

	def keep(self, list_to_keep):
		__copy = copy.deepcopy(self)
		__schema_vars = []
		__schema_vars.append("b")
		__schema_vars.append("i")
		__schema_vars.append("s")
		for keep in __schema_vars:
			if keep not in list_to_keep:
				__copy.keep = None
		return __copy

	def discard(self, list_to_discard):
		__copy = copy.deepcopy(self)
		for discard in list_to_discard:
			__copy.discard = None
		return __copy


class Scm2():
	def __init__(self, dict):
		for k, v in dict.items():
			setattr(self, k, v)

	def keep(self, list_to_keep):
		__copy = copy.deepcopy(self)
		__schema_vars = []
		__schema_vars.append("b")
		__schema_vars.append("i")
		for keep in __schema_vars:
			if keep not in list_to_keep:
				__copy.keep = None
		return __copy

	def discard(self, list_to_discard):
		__copy = copy.deepcopy(self)
		for discard in list_to_discard:
			__copy.discard = None
		return __copy


class Scm3():
	def __init__(self, dict):
		for k, v in dict.items():
			setattr(self, k, v)

	def keep(self, list_to_keep):
		__copy = copy.deepcopy(self)
		__schema_vars = []
		__schema_vars.append("b")
		__schema_vars.append("s")
		for keep in __schema_vars:
			if keep not in list_to_keep:
				__copy.keep = None
		return __copy

	def discard(self, list_to_discard):
		__copy = copy.deepcopy(self)
		for discard in list_to_discard:
			__copy.discard = None
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

def __ShowSchema1(__varDict):
	return """ <body>
    {message} b: {b}  i: {i}  s: {s}  </body> """.format(**(__varDict))

def __ShowSchema2(__varDict):
	return """ <body>
   {message}  b: {b}  i: {i}  </body> """.format(**(__varDict))

def __ShowSchema3(__varDict):
	return """ <body>
   {message}  b: {b}  s: {s}  </body> """.format(**(__varDict))

def __PrintString(__varDict):
	return """ <body>
   {message}  </body> """.format(**(__varDict))

def __Done(__varDict):
	return """ <body> Done! </body> """.format(**(__varDict))

__global_vars = []
def __save_global_vars():
	global_vars_file = "GLOBAL_1e8b924f-9885-4344-8e06-b1af23716249"
	open(global_vars_file, 'w').close()
	global_vars = dict((k, __vars[k]) for k in __global_vars if k in __vars)
	with open(global_vars_file, "w") as f:
		pickle.dump(global_vars, f)
	return

def __load_global_vars():
	global __vars
	global_vars_file = "GLOBAL_1e8b924f-9885-4344-8e06-b1af23716249"
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

def __save_session_test1():
	session_file = "test1$"+str(__sid)
	open(session_file, 'w').close()
	session_vars = dict((k, __vars[k]) for k in __vars if k not in __global_vars)
	with open(session_file, "w") as f:
		pickle.dump(session_vars, f)
		pickle.dump(__next_logic, f)
	return

def __init_session_test1():
	global __sid
	global __next_logic
	__sid = str(uuid.uuid4())
	__next_logic = 1
	__save_session_test1()
	__logic_session_test1_1()

def __load_session_test1(session_id):
	global __vars
	global __next_logic
	global __sid
	__sid = session_id
	with open("test1$"+str(__sid), "r") as f:
		session_vars = pickle.load(f)
		__next_logic = pickle.load(f)
		__vars = dict(__vars.items() + session_vars.items())
	__continue_stack_execution()
	globals()["__logic_session_test1_"+str(__next_logic)]()

def __session_test1():
	sid = __cgi_input.getvalue("sid", "")
	if sid == "":
		__init_session_test1()
	else:
		__load_session_test1(sid)

def __logic_session_test1_1():
	global __vars
	global __next_logic
	__vars["t1_34_18"] = Scm1({
			'b':True, 
			'i':87, 
			's':"foo"})
	print(__layout(__ShowSchema1({'message':"t1 is: ",'b':__vars["t1_34_18"].b
	,'i':__vars["t1_34_18"].i
	,'s':__vars["t1_34_18"].s
	})))
	__next_logic = 2
	__save_session_test1()
def __logic_session_test1_2():
	global __vars
	global __next_logic
	__vars["t2_35_18"] = __vars["t1_34_18"].keep(["b", "i"])
	print(__layout(__ShowSchema2({'message':"t2 is: ",'b':__vars["t2_35_18"].b
	,'i':__vars["t2_35_18"].i
	})))
	__next_logic = 3
	__save_session_test1()
def __logic_session_test1_3():
	global __vars
	global __next_logic
	__vars["t3_35_18"] = __vars["t1_34_18"].discard(["s"])
	print(__layout(__ShowSchema2({'message':"t3 is: ",'b':__vars["t3_35_18"].b
	,'i':__vars["t3_35_18"].i
	})))
	__next_logic = 4
	__save_session_test1()
def __logic_session_test1_4():
	global __vars
	global __next_logic
	print(__layout(__Done({})))
	__next_logic = 5
	__save_session_test1()
def __logic_session_test1_5():
	global __vars
	global __next_logic
	__next_logic = 4
	__save_session_test1()
	__logic_session_test1_4()
def __save_session_test2():
	session_file = "test2$"+str(__sid)
	open(session_file, 'w').close()
	session_vars = dict((k, __vars[k]) for k in __vars if k not in __global_vars)
	with open(session_file, "w") as f:
		pickle.dump(session_vars, f)
		pickle.dump(__next_logic, f)
	return

def __init_session_test2():
	global __sid
	global __next_logic
	__sid = str(uuid.uuid4())
	__next_logic = 1
	__save_session_test2()
	__logic_session_test2_1()

def __load_session_test2(session_id):
	global __vars
	global __next_logic
	global __sid
	__sid = session_id
	with open("test2$"+str(__sid), "r") as f:
		session_vars = pickle.load(f)
		__next_logic = pickle.load(f)
		__vars = dict(__vars.items() + session_vars.items())
	__continue_stack_execution()
	globals()["__logic_session_test2_"+str(__next_logic)]()

def __session_test2():
	sid = __cgi_input.getvalue("sid", "")
	if sid == "":
		__init_session_test2()
	else:
		__load_session_test2(sid)

def __logic_session_test2_1():
	global __vars
	global __next_logic
	__vars["g2_50_20"] = Scm2({
			'b':True, 
			'i':87})
	print(__layout(__ShowSchema2({'message':"g2 is: ",'b':__vars["g2_50_20"].b
	,'i':__vars["g2_50_20"].i
	})))
	__next_logic = 2
	__save_session_test2()
def __logic_session_test2_2():
	global __vars
	global __next_logic
	__vars["g3_51_20"] = Scm3({
			'b':False, 
			's':"foo"})
	print(__layout(__ShowSchema3({'message':"g3 is: ",'b':__vars["g3_51_20"].b
	,'s':__vars["g3_51_20"].s
	})))
	__next_logic = 3
	__save_session_test2()
def __logic_session_test2_3():
	global __vars
	global __next_logic
	__vars["g1_49_20"] = __vars["g2_50_20"] << __vars["g3_51_20"]
	print(__layout(__ShowSchema1({'message':"g1 is: ",'b':__vars["g1_49_20"].b
	,'i':__vars["g1_49_20"].i
	,'s':__vars["g1_49_20"].s
	})))
	__next_logic = 4
	__save_session_test2()
def __logic_session_test2_4():
	global __vars
	global __next_logic
	print(__layout(__Done({})))
	__next_logic = 5
	__save_session_test2()
def __logic_session_test2_5():
	global __vars
	global __next_logic
	__next_logic = 4
	__save_session_test2()
	__logic_session_test2_4()
print "Content-type: text/html"
print
__load_global_vars()
if __session == "test1":
	__session_test1()
elif __session == "test2":
	__session_test2()
else:
	print __layout("Please select one of the following sessions: test1, test2")
__save_global_vars()

