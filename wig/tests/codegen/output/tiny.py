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

def __Welcome(__varDict):
	return """ <body>
    Welcome!
  </body> """.format(**(__varDict))

def __Pledge(__varDict):
	return """ <body>
    How much do you want to contribute?
    <input name="contribution" size=4 type="text">
  </body> """.format(**(__varDict))

def __Total(__varDict):
	return """ <body>
    The total is now {total}.
  </body> """.format(**(__varDict))

def __save_session_Contribute():
	session_file = "Contribute$"+str(__sid)
	open(session_file, 'w').close()
	with open(session_file, "w") as f:
		pickle.dump(__vars, f)
		pickle.dump(__next_logic, f)
	return

def __init_session_Contribute():
	global __sid
	global __next_logic
	__sid = str(uuid.uuid4())
	__next_logic = 1
	__save_session_Contribute()
	__logic_session_Contribute_1()

def __load_session_Contribute(session_id):
	global __vars
	global __next_logic
	global __sid
	__sid = session_id
	with open("Contribute$"+str(__sid), "r") as f:
		__vars = pickle.load(f)
		__next_logic = pickle.load(f)
	globals()["__logic_session_Contribute_"+str(__next_logic)]()

def __session_Contribute():
	sid = __cg_input.getvalue("sid", "")
	if sid == "":
		__init_session_Contribute()
	else:
		__load_session_Contribute(sid)

def __logic_session_Contribute_1():
	global __vars
	global __next_logic
	__vars["i_18_8"]=87
	print(__layout(__Welcome({})))
	__next_logic = 2
	__save_session_Contribute()
	__logic_session_Contribute_2()
def __logic_session_Contribute_2():
	global __vars
	global __next_logic
	print(__layout(__Pledge({})))
	__next_logic = 3
	__save_session_Contribute()
	__logic_session_Contribute_3()
def __logic_session_Contribute_3():
	global __vars
	global __next_logic
	__vars["amount_15_7"]=__vars["amount_15_7"]+__vars["i_18_8"]
	print(__layout(__Total({'total':__vars["amount_15_7"]})))
	__next_logic = 4
	__save_session_Contribute()
	__logic_session_Contribute_4()
print "Content-type: text/html"
print
if __session == "Contribute":
	__session_Contribute()
else:
	print __layout("Please select one of the following sessions: Contribute")

