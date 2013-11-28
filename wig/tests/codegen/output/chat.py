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

def __Logon(__varDict):
	return """ <body>
    <h1>Welcome to The Chat Room</h1>
    Please enter your on-line name:
    <input name="name" size=25 type="text">
  </body> """.format(**(__varDict))

def __Update(__varDict):
	return """ <body>
    <h1>The Chat Room Service</h1>
    <hr>
    <b>Messages so far:</b>
    <p>
    {msg0}<p>{msg1}<p>{msg2}<p>{msg3}<p>{msg4}<p>{msg5}<p>
    <hr>
    <b>Your new message:</b>
    <p>
    <input name="msg" size=40 type="text">
    <p>
    <hr>
    <p>
    <input name="quit" type="radio" value="yes"> Quit now
  </body> """.format(**(__varDict))

def __ByeBye(__varDict):
	return """ <body>
    <h1>Thanks for using The Chat Room</h1>
    You made {conns} connections
    and wrote {msgs} messages.
  </body> """.format(**(__varDict))

__global_vars = []
def __save_global_vars():
	global_vars_file = "GLOBAL_9f632a12-097d-4be4-90ba-ff42b8587b66"
	open(global_vars_file, 'w').close()
	global_vars = dict((k, __vars[k]) for k in __global_vars if k in __vars)
	with open(global_vars_file, "w") as f:
		pickle.dump(global_vars, f)
	return

def __load_global_vars():
	global __vars
	global_vars_file = "GLOBAL_9f632a12-097d-4be4-90ba-ff42b8587b66"
	try:
		with open(global_vars_file, "r") as f:
			global_vars = pickle.load(f)
			__vars = dict(__vars.items() + global_vars.items())
	except IOError:
		return

__vars["msg0_30_7"] = ""
__global_vars.append("msg0_30_7")
__vars["msg1_30_7"] = ""
__global_vars.append("msg1_30_7")
__vars["msg2_30_7"] = ""
__global_vars.append("msg2_30_7")
__vars["msg3_30_7"] = ""
__global_vars.append("msg3_30_7")
__vars["msg4_30_7"] = ""
__global_vars.append("msg4_30_7")
__vars["msg5_30_7"] = ""
__global_vars.append("msg5_30_7")
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

def __save_session_Chat():
	session_file = "Chat$"+str(__sid)
	open(session_file, 'w').close()
	session_vars = dict((k, __vars[k]) for k in __vars if k not in __global_vars)
	with open(session_file, "w") as f:
		pickle.dump(session_vars, f)
		pickle.dump(__next_logic, f)
	return

def __init_session_Chat():
	global __sid
	global __next_logic
	__sid = str(uuid.uuid4())
	__next_logic = 1
	__save_session_Chat()
	__logic_session_Chat_1()

def __load_session_Chat(session_id):
	global __vars
	global __next_logic
	global __sid
	__sid = session_id
	with open("Chat$"+str(__sid), "r") as f:
		session_vars = pickle.load(f)
		__next_logic = pickle.load(f)
		__vars = dict(__vars.items() + session_vars.items())
	globals()["__logic_session_Chat_"+str(__next_logic)]()

def __session_Chat():
	sid = __cgi_input.getvalue("sid", "")
	if sid == "":
		__init_session_Chat()
	else:
		__load_session_Chat(sid)

def __logic_session_Chat_1():
	global __vars
	global __next_logic
	__vars["connections_34_8"] = 0
	__vars["written_34_8"] = 0
	__vars["quit_33_8"] = "no"
	print(__layout(__Logon({})))
	__next_logic = 2
	__save_session_Chat()
def __logic_session_Chat_2():
	global __vars
	global __next_logic
	__vars["name_33_8"] = __cgi_input.getvalue("name")
	__next_logic = 3
	__save_session_Chat()
	__logic_session_Chat_3()
def __logic_session_Chat_3():
	global __vars
	global __next_logic
	__next_logic = 4
	__save_session_Chat()
	__logic_session_Chat_4()
def __logic_session_Chat_5():
	global __vars
	global __next_logic
	print(__layout(__Update({'msg0':__vars["msg0_30_7"],'msg1':__vars["msg1_30_7"]
	,'msg2':__vars["msg2_30_7"]
	,'msg3':__vars["msg3_30_7"]
	,'msg4':__vars["msg4_30_7"]
	,'msg5':__vars["msg5_30_7"]
	})))
	__next_logic = 6
	__save_session_Chat()
def __logic_session_Chat_6():
	global __vars
	global __next_logic
	__vars["msg_33_8"] = __cgi_input.getvalue("msg")
	__vars["quit_33_8"] = __cgi_input.getvalue("quit")
	__next_logic = 7
	__save_session_Chat()
	__logic_session_Chat_7()
def __logic_session_Chat_7():
	global __vars
	global __next_logic
	__vars["connections_34_8"] = __vars["connections_34_8"] + 1
	__next_logic = 8
	__save_session_Chat()
	__logic_session_Chat_8()
def __logic_session_Chat_9():
	global __vars
	global __next_logic
	__vars["written_34_8"] = __vars["written_34_8"] + 1
	__vars["msg0_30_7"] = __vars["msg1_30_7"]
	__vars["msg1_30_7"] = __vars["msg2_30_7"]
	__vars["msg2_30_7"] = __vars["msg3_30_7"]
	__vars["msg3_30_7"] = __vars["msg4_30_7"]
	__vars["msg4_30_7"] = __vars["msg5_30_7"]
	__vars["msg5_30_7"] = __vars["name_33_8"] + "> " + __vars["msg_33_8"]
	__next_logic = 10
	__save_session_Chat()
	__logic_session_Chat_10()
def __logic_session_Chat_8():
	global __vars
	global __next_logic
	if __vars["msg_33_8"] != "":
		__next_logic = 9
		__save_session_Chat()
		__logic_session_Chat_9()
	else:
		__next_logic = 10
		__save_session_Chat()
		__logic_session_Chat_10()
	
def __logic_session_Chat_10():
	global __vars
	global __next_logic
	__next_logic = 4
	__save_session_Chat()
	__logic_session_Chat_4()
def __logic_session_Chat_4():
	global __vars
	global __next_logic
	if __vars["quit_33_8"] != "yes":
		__next_logic = 5
		__save_session_Chat()
		__logic_session_Chat_5()
	else:
		__next_logic = 11
		__save_session_Chat()
		__logic_session_Chat_11()
	
def __logic_session_Chat_11():
	global __vars
	global __next_logic
	print(__layout(__ByeBye({'conns':__vars["connections_34_8"],'msgs':__vars["written_34_8"]
	})))
	__next_logic = 12
	__save_session_Chat()
def __logic_session_Chat_12():
	global __vars
	global __next_logic
	__next_logic = 11
	__save_session_Chat()
	__logic_session_Chat_11()
print "Content-type: text/html"
print
__load_global_vars()
if __session == "Chat":
	__session_Chat()
else:
	print __layout("Please select one of the following sessions: Chat")
__save_global_vars()

