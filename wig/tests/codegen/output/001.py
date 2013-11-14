#!/usr/bin/env python
import cgi
import cgitb
import os
import uuid
import pickle
cgitb.enable()
__cg_input = cgi.FieldStorage()
__session = os.environ["QUERY_STRING"].split("&")[0]
__vars = {}
__sid = 0
__next_logic = 1

class Item():
	name = ""
	available = False
	price = 0

	def __init__(self, dict):
		for k, v in dict.items():
			setattr(self, k, v)

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

def __save_session_b():
	session_file = "b$"+str(__sid)
	open(session_file, 'w').close()
	with open(session_file, "w") as f:
		pickle.dump(__vars, f)
		pickle.dump(__next_logic, f)
	return

def __init_session_b():
	global __sid
	global __next_logic
	__sid = str(uuid.uuid4())
	__next_logic = 1
	__save_session_b()
	__logic_session_b_1()

def __load_session_b(session_id):
	global __vars
	global __next_logic
	global __sid
	__sid = session_id
	with open("b$"+str(__sid), "r") as f:
		__vars = pickle.load(f)
		__next_logic = pickle.load(f)
	globals()["__logic_session_b_"+str(__next_logic)]()

def __session_b():
	sid = __cg_input.getvalue("sid", "")
	if sid == "":
		__init_session_b()
	else:
		__load_session_b(sid)

def __logic_session_b_1():
	global __vars
	global __next_logic
	__vars["counter_14_8"]=4
	__vars["a_15_8"]=3
	print(__layout(__a({'gap':__vars["counter_14_8"]})))
	__next_logic = 2
	__save_session_b()
	__logic_session_b_2()
print "Content-type: text/html"
print
if __session == "b":
	__session_b()
else:
	print __layout("Please select one of the following sessions: b")

