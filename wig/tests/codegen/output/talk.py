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

def __Login(__varDict):
	return """ <body>
    <h1>Welcome to The Talk Room</h1>
    <p>
    Enter your user name:
    <input name="username" size=25 type="text">
    <p>
    Enter your password:
    <input name="password" size=25 type="text">
  </body> """.format(**(__varDict))

def __incorrect(__varDict):
	return """ <body>
    <h1>I'm sorry {username}, permission denied! </h1>

  </body> """.format(**(__varDict))

def __Update(__varDict):
	return """ <body>
    <h1>The Talk Room Service</h1>
    <hr>
    <b>Messages so far:</b>
    <p>
    {msg0}<p>{msg1}<p>{msg2}<p>
    <hr>
    <b>Your new message:</b>
    <p>
    <input name="msg" size=70 type="text">
    <p>
    <hr>
    <p>
    <input name="quit" type="radio" value="yes"> Quit now
  </body> """.format(**(__varDict))

def __ByeBye(__varDict):
	return """ <body>
    <h1>Thanks for visiting, {username}. </h1>
    There have been {conns} connections so far.
     <p>
    You wrote {msgs} messages this time.
  </body> """.format(**(__varDict))

__global_vars = []
def __save_global_vars():
	global_vars_file = "GLOBAL_d8e66eac-9c78-40e9-87a0-f48873ea9b2c"
	open(global_vars_file, 'w').close()
	global_vars = dict((k, __vars[k]) for k in __global_vars if k in __vars)
	with open(global_vars_file, "w") as f:
		pickle.dump(global_vars, f)
	return

def __load_global_vars():
	global __vars
	global_vars_file = "GLOBAL_d8e66eac-9c78-40e9-87a0-f48873ea9b2c"
	try:
		with open(global_vars_file, "r") as f:
			global_vars = pickle.load(f)
			__vars = dict(__vars.items() + global_vars.items())
	except IOError:
		return

__vars["msg0_41_9"] = ""
__global_vars.append("msg0_41_9")
__vars["msg1_41_9"] = ""
__global_vars.append("msg1_41_9")
__vars["msg2_41_9"] = ""
__global_vars.append("msg2_41_9")
__vars["connections_42_9"] = 0
__global_vars.append("connections_42_9")
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

def __save_session_Talk():
	session_file = "Talk$"+str(__sid)
	open(session_file, 'w').close()
	session_vars = dict((k, __vars[k]) for k in __vars if k not in __global_vars)
	with open(session_file, "w") as f:
		pickle.dump(session_vars, f)
		pickle.dump(__next_logic, f)
	return

def __init_session_Talk():
	global __sid
	global __next_logic
	__sid = str(uuid.uuid4())
	__next_logic = 1
	__save_session_Talk()
	__logic_session_Talk_1()

def __load_session_Talk(session_id):
	global __vars
	global __next_logic
	global __sid
	__sid = session_id
	with open("Talk$"+str(__sid), "r") as f:
		session_vars = pickle.load(f)
		__next_logic = pickle.load(f)
		__vars = dict(__vars.items() + session_vars.items())
	globals()["__logic_session_Talk_"+str(__next_logic)]()

def __session_Talk():
	sid = __cgi_input.getvalue("sid", "")
	if sid == "":
		__init_session_Talk()
	else:
		__load_session_Talk(sid)

def __logic_session_Talk_1():
	global __vars
	global __next_logic
	__vars["connections_42_9"] = __vars["connections_42_9"] + 1
	__vars["correct_47_10"] = False
	__vars["written_46_10"] = 0
	__next_logic = 2
	__save_session_Talk()
	__logic_session_Talk_2()
def __logic_session_Talk_3():
	global __vars
	global __next_logic
	print(__layout(__Login({})))
	__next_logic = 4
	__save_session_Talk()
def __logic_session_Talk_4():
	global __vars
	global __next_logic
	__vars["username_45_10"] = __cgi_input.getvalue("username")
	__vars["password_45_10"] = __cgi_input.getvalue("password")
	__next_logic = 5
	__save_session_Talk()
	__logic_session_Talk_5()
def __logic_session_Talk_6():
	global __vars
	global __next_logic
	__vars["correct_47_10"] = True
	__next_logic = 7
	__save_session_Talk()
	__logic_session_Talk_7()
def __logic_session_Talk_5():
	global __vars
	global __next_logic
	if __vars["username_45_10"] == "Ebrahim" and __vars["password_45_10"] == "group5" or __vars["username_45_10"] == "Abbas" and __vars["password_45_10"] == "password" or __vars["username_45_10"] == "guest" and __vars["password_45_10"] == "guest":
		__next_logic = 6
		__save_session_Talk()
		__logic_session_Talk_6()
	else:
		__next_logic = 7
		__save_session_Talk()
		__logic_session_Talk_7()
	
def __logic_session_Talk_8():
	global __vars
	global __next_logic
	print(__layout(__incorrect({'username':__vars["username_45_10"]})))
	__next_logic = 9
	__save_session_Talk()
def __logic_session_Talk_9():
	global __vars
	global __next_logic
	__next_logic = 10
	__save_session_Talk()
	__logic_session_Talk_10()
def __logic_session_Talk_7():
	global __vars
	global __next_logic
	if not __vars["correct_47_10"]:
		__next_logic = 8
		__save_session_Talk()
		__logic_session_Talk_8()
	else:
		__next_logic = 10
		__save_session_Talk()
		__logic_session_Talk_10()
	
def __logic_session_Talk_10():
	global __vars
	global __next_logic
	__next_logic = 2
	__save_session_Talk()
	__logic_session_Talk_2()
def __logic_session_Talk_2():
	global __vars
	global __next_logic
	if not __vars["correct_47_10"]:
		__next_logic = 3
		__save_session_Talk()
		__logic_session_Talk_3()
	else:
		__next_logic = 11
		__save_session_Talk()
		__logic_session_Talk_11()
	
def __logic_session_Talk_11():
	global __vars
	global __next_logic
	__vars["quit_45_10"] = "no"
	__next_logic = 12
	__save_session_Talk()
	__logic_session_Talk_12()
def __logic_session_Talk_13():
	global __vars
	global __next_logic
	print(__layout(__Update({'msg0':__vars["msg0_41_9"],'msg1':__vars["msg1_41_9"]
	,'msg2':__vars["msg2_41_9"]
	})))
	__next_logic = 14
	__save_session_Talk()
def __logic_session_Talk_14():
	global __vars
	global __next_logic
	__vars["msg_45_10"] = __cgi_input.getvalue("msg")
	__vars["quit_45_10"] = __cgi_input.getvalue("quit")
	__next_logic = 15
	__save_session_Talk()
	__logic_session_Talk_15()
def __logic_session_Talk_16():
	global __vars
	global __next_logic
	__vars["written_46_10"] = __vars["written_46_10"] + 1
	__vars["msg0_41_9"] = __vars["msg1_41_9"]
	__vars["msg1_41_9"] = __vars["msg2_41_9"]
	__vars["msg2_41_9"] = __vars["username_45_10"] + "> " + __vars["msg_45_10"]
	__next_logic = 17
	__save_session_Talk()
	__logic_session_Talk_17()
def __logic_session_Talk_15():
	global __vars
	global __next_logic
	if __vars["msg_45_10"] != "":
		__next_logic = 16
		__save_session_Talk()
		__logic_session_Talk_16()
	else:
		__next_logic = 17
		__save_session_Talk()
		__logic_session_Talk_17()
	
def __logic_session_Talk_17():
	global __vars
	global __next_logic
	__next_logic = 12
	__save_session_Talk()
	__logic_session_Talk_12()
def __logic_session_Talk_12():
	global __vars
	global __next_logic
	if __vars["quit_45_10"] != "yes":
		__next_logic = 13
		__save_session_Talk()
		__logic_session_Talk_13()
	else:
		__next_logic = 18
		__save_session_Talk()
		__logic_session_Talk_18()
	
def __logic_session_Talk_18():
	global __vars
	global __next_logic
	print(__layout(__ByeBye({'username':__vars["username_45_10"],'conns':__vars["connections_42_9"]
	,'msgs':__vars["written_46_10"]
	})))
	__next_logic = 19
	__save_session_Talk()
def __logic_session_Talk_19():
	global __vars
	global __next_logic
	__next_logic = 18
	__save_session_Talk()
	__logic_session_Talk_18()
print "Content-type: text/html"
print
__load_global_vars()
if __session == "Talk":
	__session_Talk()
else:
	print __layout("Please select one of the following sessions: Talk")
__save_global_vars()

