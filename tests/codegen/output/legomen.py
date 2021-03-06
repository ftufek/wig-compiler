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

def __Init(__varDict):
	return """ <body bgcolor="#4400ff">
		<br>
		<center>
		<h1>WELCOME!!!!</h1>
		<br>
		<table bgcolor="#CCCCCC" border=2 cellpadding=10 cellspacing=5 text="#000000">
		<tr><td><center>
		<img src="http://www.cs.mcgill.ca/~hendren/Images/LEGO_RED.gif">
		</td></tr>
		<tr><td>
		<br><center>
		Select the lego man of your choice below:
  		<br><br>
		<input name="man" type="radio" value="1">Red Man
                <br>
		<input name="man" type="radio" value="2">Blue Man
		<br>
		<input name="man" type="radio" value="3">Green Man
                <br>
		<input name="man" type="radio" value="4">Purple Man
		<br>
		<input name="man" type="radio" value="5">Exit
		</table>
		<br>
		<br>
		</center>
	</body>""".format(**(__varDict))

def __Red(__varDict):
	return """ <body bgcolor="#ff0000">
		<br>
		<center>
		<h1>RED LEGO MAN!!</h1>
		<br>
		<table bgcolor="#CCCCCC" border=2 cellpadding=10 cellspacing=5 text="#000000">
		<tr><td><center>
		<img src="http://www.cs.mcgill.ca/~hendren/Images/LEGO_RED.gif">
		</td></tr>
		<tr><td>
		<br><center>
		Select the lego man of your choice below:
		<br><br>
		<input name="man" type="radio" value="1">Red Man
                <br>
		<input name="man" type="radio" value="2">Blue Man
		<br>
		<input name="man" type="radio" value="3">Green Man
                <br>
		<input name="man" type="radio" value="4">Purple Man
		<br>
		<input name="man" type="radio" value="5">Exit
		</table>
		<br>
		<br>
		</center>
	</body>""".format(**(__varDict))

def __Blue(__varDict):
	return """ <body bgcolor="#4400ff">
		<br>
		<center>
		<h1>BLUE LEGO MAN!!</h1>
		<br>
		<table bgcolor="#CCCCCC" border=2 cellpadding=10 cellspacing=5 text="#000000">
		<tr><td><center>
		<img src="http://www.cs.mcgill.ca/~hendren/Images/LEGO_BLUE.gif">
		</td></tr>
		<tr><td>
		<br><center>
		Select the lego man of your choice below:
		<br><br>
		<input name="man" type="radio" value="1">Red Man
                <br>
		<input name="man" type="radio" value="2">Blue Man
		<br>
		<input name="man" type="radio" value="3">Green Man
                <br>
		<input name="man" type="radio" value="4">Purple Man
		<br>
		<input name="man" type="radio" value="5">Exit
		</table>
		<br>
		<br>
		</center>
	</body>""".format(**(__varDict))

def __Green(__varDict):
	return """ <body bgcolor="#22ff22">
		<br>
		<center>
		<h1>GREEN LEGO MAN!!</h1>
		<br>
		<table bgcolor="#CCCCCC" border=2 cellpadding=10 cellspacing=5 text="#000000">
		<tr><td><center>
		<img src="http://www.cs.mcgill.ca/~hendren/Images/LEGO_GREEN.gif">
		</td></tr>
		<tr><td>
		<br><center>
		Select the lego man of your choice below:
		<br><br>
		<input name="man" type="radio" value="1">Red Man
                <br>
		<input name="man" type="radio" value="2">Blue Man
		<br>
		<input name="man" type="radio" value="3">Green Man
                <br>
		<input name="man" type="radio" value="4">Purple Man
		<br>
		<input name="man" type="radio" value="5">Exit
		</table>
		<br>
		<br>
		</center>
	</body>""".format(**(__varDict))

def __Purple(__varDict):
	return """ <body bgcolor="#880099">
		<br>
		<center>
		<h1>PURPLE LEGO MAN!!</h1>
		<br>
		<table bgcolor="#CCCCCC" border=2 cellpadding=10 cellspacing=5 text="#000000">
		<tr><td><center>
		<img src="http://www.cs.mcgill.ca/~hendren/Images/LEGO_PURPLE.gif">
		</td></tr>
		<tr><td>
		<br><center>
		Select the lego man of your choice below:
		<br><br>
		<input name="man" type="radio" value="1">Red Man
                <br>
		<input name="man" type="radio" value="2">Blue Man
		<br>
		<input name="man" type="radio" value="3">Green Man
                <br>
		<input name="man" type="radio" value="4">Purple Man
		<br>
		<input name="man" type="radio" value="5">Exit
		</table>
		<br>
		<br>
		</center>
	</body>""".format(**(__varDict))

def __End(__varDict):
	return """ <body bgcolor="#334433">
        	<br>
		<center>
                <br><br><br><br>
		<h1>GOODBYE!</h1>
		<br>
		</center>
	</body>""".format(**(__varDict))

__global_vars = []
def __save_global_vars():
	global_vars_file = "GLOBAL_a37790f4-f5f7-4f91-9e17-cbf0b79e2dd7"
	open(global_vars_file, 'w').close()
	global_vars = dict((k, __vars[k]) for k in __global_vars if k in __vars)
	with open(global_vars_file, "w") as f:
		pickle.dump(global_vars, f)
	return

def __load_global_vars():
	global __vars
	global_vars_file = "GLOBAL_a37790f4-f5f7-4f91-9e17-cbf0b79e2dd7"
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

def __save_session_Access():
	session_file = "Access$"+str(__sid)
	open(session_file, 'w').close()
	session_vars = dict((k, __vars[k]) for k in __vars if k not in __global_vars)
	with open(session_file, "w") as f:
		pickle.dump(session_vars, f)
		pickle.dump(__next_logic, f)
	return

def __init_session_Access():
	global __sid
	global __next_logic
	__sid = str(uuid.uuid4())
	__next_logic = 1
	__save_session_Access()
	__logic_session_Access_1()

def __load_session_Access(session_id):
	global __vars
	global __next_logic
	global __sid
	__sid = session_id
	with open("Access$"+str(__sid), "r") as f:
		session_vars = pickle.load(f)
		__next_logic = pickle.load(f)
		__vars = dict(__vars.items() + session_vars.items())
	if __vars["__exited_from"] != -1:
		__next_logic = __vars["__exited_from"]
		__save_session_Access()
		globals()["__logic_session_Access_"+str(__vars["__exited_from"])]()
		return
	__continue_stack_execution()
	globals()["__logic_session_Access_"+str(__next_logic)]()

def __session_Access():
	sid = __cgi_input.getvalue("sid", "")
	if sid == "":
		__init_session_Access()
	else:
		__load_session_Access(sid)

def __logic_session_Access_1():
	global __vars
	global __next_logic
	print(__layout(__Init({})))
	__next_logic = 2
	__save_session_Access()
def __logic_session_Access_2():
	global __vars
	global __next_logic
	__vars["man_157_14"] = int(__cgi_input.getvalue("man"))
	__next_logic = 3
	__save_session_Access()
	__logic_session_Access_3()
def __logic_session_Access_3():
	global __vars
	global __next_logic
	__next_logic = 4
	__save_session_Access()
	__logic_session_Access_4()
def __logic_session_Access_6():
	global __vars
	global __next_logic
	print(__layout(__Red({})))
	__next_logic = 7
	__save_session_Access()
def __logic_session_Access_7():
	global __vars
	global __next_logic
	__vars["man_157_14"] = int(__cgi_input.getvalue("man"))
	__next_logic = 8
	__save_session_Access()
	__logic_session_Access_8()
def __logic_session_Access_9():
	global __vars
	global __next_logic
	print(__layout(__Blue({})))
	__next_logic = 10
	__save_session_Access()
def __logic_session_Access_10():
	global __vars
	global __next_logic
	__vars["man_157_14"] = int(__cgi_input.getvalue("man"))
	__next_logic = 11
	__save_session_Access()
	__logic_session_Access_11()
def __logic_session_Access_12():
	global __vars
	global __next_logic
	print(__layout(__Green({})))
	__next_logic = 13
	__save_session_Access()
def __logic_session_Access_13():
	global __vars
	global __next_logic
	__vars["man_157_14"] = int(__cgi_input.getvalue("man"))
	__next_logic = 14
	__save_session_Access()
	__logic_session_Access_14()
def __logic_session_Access_15():
	global __vars
	global __next_logic
	print(__layout(__Purple({})))
	__next_logic = 16
	__save_session_Access()
def __logic_session_Access_16():
	global __vars
	global __next_logic
	__vars["man_157_14"] = int(__cgi_input.getvalue("man"))
	__next_logic = 17
	__save_session_Access()
	__logic_session_Access_17()
def __logic_session_Access_17():
	global __vars
	global __next_logic
	__next_logic = 18
	__save_session_Access()
	__logic_session_Access_18()
def __logic_session_Access_14():
	global __vars
	global __next_logic
	if (__vars["man_157_14"] == 4):
		__next_logic = 15
		__save_session_Access()
		__logic_session_Access_15()
	else:
		__next_logic = 18
		__save_session_Access()
		__logic_session_Access_18()
	
def __logic_session_Access_18():
	global __vars
	global __next_logic
	__next_logic = 20
	__save_session_Access()
	__logic_session_Access_20()
def __logic_session_Access_19():
	global __vars
	global __next_logic
	__next_logic = 20
	__save_session_Access()
	__logic_session_Access_20()
def __logic_session_Access_11():
	global __vars
	global __next_logic
	if (__vars["man_157_14"] == 3):
		__next_logic = 12
		__save_session_Access()
		__logic_session_Access_12()
	else:
		__next_logic = 14
		__save_session_Access()
		__logic_session_Access_14()
	
def __logic_session_Access_20():
	global __vars
	global __next_logic
	__next_logic = 22
	__save_session_Access()
	__logic_session_Access_22()
def __logic_session_Access_21():
	global __vars
	global __next_logic
	__next_logic = 22
	__save_session_Access()
	__logic_session_Access_22()
def __logic_session_Access_8():
	global __vars
	global __next_logic
	if (__vars["man_157_14"] == 2):
		__next_logic = 9
		__save_session_Access()
		__logic_session_Access_9()
	else:
		__next_logic = 11
		__save_session_Access()
		__logic_session_Access_11()
	
def __logic_session_Access_22():
	global __vars
	global __next_logic
	__next_logic = 24
	__save_session_Access()
	__logic_session_Access_24()
def __logic_session_Access_23():
	global __vars
	global __next_logic
	__next_logic = 24
	__save_session_Access()
	__logic_session_Access_24()
def __logic_session_Access_5():
	global __vars
	global __next_logic
	if (__vars["man_157_14"] == 1):
		__next_logic = 6
		__save_session_Access()
		__logic_session_Access_6()
	else:
		__next_logic = 8
		__save_session_Access()
		__logic_session_Access_8()
	
def __logic_session_Access_24():
	global __vars
	global __next_logic
	__next_logic = 4
	__save_session_Access()
	__logic_session_Access_4()
def __logic_session_Access_4():
	global __vars
	global __next_logic
	if (__vars["man_157_14"] != 5):
		__next_logic = 5
		__save_session_Access()
		__logic_session_Access_5()
	else:
		__next_logic = 25
		__save_session_Access()
		__logic_session_Access_25()
	
def __logic_session_Access_25():
	global __vars
	global __next_logic
	print(__layout(__End({})))
	__vars["__exited_from"] = 25
	__next_logic = 26
	__save_session_Access()
def __logic_session_Access_26():
	global __vars
	global __next_logic
	__next_logic = 25
	__save_session_Access()
	__logic_session_Access_25()
print "Content-type: text/html"
print
__load_global_vars()
if __session == "Access":
	__session_Access()
else:
	print __layout("Please select one of the following sessions: Access")
__save_global_vars()

