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

class A():
	name = ""
	a = ""
	b = ""
	a = False
	price = 0

	def __init__(self, dict):
		for k, v in dict.items():
			setattr(self, k, v)

def layout(page):
	return """<html><form action="" method="POST">
	{page} <input type="submit" value="go">
	</form></html>""".format(page=page)

def a(__varDict):
	return """""".format(**(__varDict))

def b(__varDict):
	return """{gap}""".format(**(__varDict))

def save_session_b():
	session_file = "b$"+str(sid)
	open(session_file, 'w').close()
	with open(session_file, "w") as f:
		pickle.dump(__vars, f)
		pickle.dump(__next_logic, f)
	return

def init_b_shop():
	global __sid
	global __next_logic
	__sid = str(uuid.uuid4())
	__next_logic = 1
	save_session_b
	_logic_session_b_1()

def load_session_b(session_id):
	__vars
	__next_logic
	__sid
	__sid = session_id
	with open("b$"+str(sid), "r") as f:
		__vars = pickle.load(f)
		__next_logic = pickle.load(f)
	globals()["_logic_session_b_"+str(next_logic)]()

def session_b():
	sid = cgi_input.getvalue("sid", "")
	if sid == :
		init_session_b()
	else:
		load_session_b(sid)

