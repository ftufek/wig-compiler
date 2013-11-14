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

def __save_session_Calculate():
	session_file = "Calculate$"+str(__sid)
	open(session_file, 'w').close()
	with open(session_file, "w") as f:
		pickle.dump(__vars, f)
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
		__vars = pickle.load(f)
		__next_logic = pickle.load(f)
	globals()["__logic_session_Calculate_"+str(__next_logic)]()

def __session_Calculate():
	sid = __cg_input.getvalue("sid", "")
	if sid == "":
		__init_session_Calculate()
	else:
		__load_session_Calculate(sid)

def __logic_session_Calculate_1():
	global __vars
	global __next_logic
	__vars["YorN_31_8"]=""
	print(__layout(__ByeBye({})))
	__next_logic = 2
	__save_session_Calculate()
	__logic_session_Calculate_2()
print "Content-type: text/html"
print
if __session == "Calculate":
	__session_Calculate()
else:
	print __layout("Please select one of the following sessions: Calculate")

